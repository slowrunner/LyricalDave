#pragma once

#include <yaml-cpp/yaml.h>
#include <mutex>
#include <string>
#include <stdexcept>

namespace bt_hello_dave
{

/// Thread-safe holder for the grammar/responses YAML document.
/// Supports hot-reload via reload() without restarting the BT system.
/// BT nodes call snapshot() each tick to get a deep-copied, lock-free
/// view of the current document.
class GrammarStore
{
public:
  explicit GrammarStore(std::string path)
    : path_(std::move(path))
  {
    load();
  }

  /// Re-read the YAML file from disk. Throws on parse error; on
  /// success, atomically replaces the in-memory document.
  void reload()
  {
    YAML::Node fresh = YAML::LoadFile(path_);  // throws YAML::Exception on bad YAML
    std::lock_guard<std::mutex> lock(mutex_);
    data_ = fresh;
  }

  /// Deep copy of the current document. Safe to use without holding
  /// any lock afterwards.
  YAML::Node snapshot() const
  {
    std::lock_guard<std::mutex> lock(mutex_);
    return YAML::Clone(data_);
  }

  const std::string & path() const { return path_; }

private:
  void load()
  {
    data_ = YAML::LoadFile(path_);
  }

  std::string path_;
  YAML::Node data_;
  mutable std::mutex mutex_;
};

}  // namespace bt_hello_dave
