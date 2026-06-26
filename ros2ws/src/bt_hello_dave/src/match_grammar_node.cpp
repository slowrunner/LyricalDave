#include "bt_hello_dave/match_grammar_node.hpp"
#include "bt_hello_dave/types.hpp"
#include "bt_hello_dave/grammar_store.hpp"

#include <algorithm>
#include <memory>
#include <vector>

namespace bt_hello_dave
{

MatchGrammar::MatchGrammar(const std::string & name, const BT::NodeConfig & config)
: BT::SyncActionNode(name, config)
{
}

BT::PortsList MatchGrammar::providedPorts()
{
  return {
    BT::InputPort<int>("window"),
    BT::OutputPort<std::string>("matched_phrase"),
    BT::OutputPort<int>("consumed_count")
  };
}

std::string MatchGrammar::normalize(std::string s)
{
  std::transform(s.begin(), s.end(), s.begin(), ::tolower);
  return s;
}

BT::NodeStatus MatchGrammar::tick()
{
  auto queue = config().blackboard->get<SttQueue>("@stt_queue");

  int window = 1;
  getInput("window", window);

  if (static_cast<int>(queue.size()) < window) {
    return BT::NodeStatus::FAILURE;
  }

  std::string candidate_text;
  int consumed = window;

  if (window == 1) {
    // newest entry
    candidate_text = normalize(queue.back().text);
  } else {
    // oldest pair, in arrival order
    candidate_text = normalize(queue[0].text) + " " + normalize(queue[1].text);
  }

  auto store = config().blackboard->get<std::shared_ptr<GrammarStore>>("@grammar_store");
  YAML::Node grammar = store->snapshot();

  std::vector<std::string> phrases;
  for (const auto & p : grammar["grammar"]["list"]) {
    std::string phrase = p.as<std::string>();
    if (phrase != "[unk]") {
      phrases.push_back(normalize(phrase));
    }
  }

  for (const auto & phrase : phrases) {
    if (candidate_text.find(phrase) != std::string::npos) {
      setOutput("matched_phrase", phrase);
      setOutput("consumed_count", consumed);
      return BT::NodeStatus::SUCCESS;
    }
  }

  return BT::NodeStatus::FAILURE;
}

}  // namespace bt_hello_dave
