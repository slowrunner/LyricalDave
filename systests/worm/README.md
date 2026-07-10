# My C. Elegans "Worm" Simulation on GoPiGo3 Robots

Back in 2015 the C.Elegans "worm" was first simulated on   
the GoPiGo robot and subsequently in 2019 on the GoPiGo3 robot with a  
linear neural net model with input from:  
- Ultrasonic distance sensor on GoPiGo  
- DI Time-of-Flight IR distance sensor on the GoPiGo3  
and outputs of:  
- left motor speed   
- right motor speed  

The actual C. Elegans "Worm" has an unchanging "parallel" neural net,
and all the connections have been mapped.  Although the actual C. Elegans has  
more sensory inputs, more finely controlled effectors (mouth, muscles), and  
many more behaviors, the known properties of the neural net   
allows the GoPiGo3 to model some of the emergent behaviors.

The program was written when the Raspberry Pi only had a single core,  
so the modern 4-core architecture is not utilized.  The processor speed  
of the GoPiGo3 robot's  Raspberry Pi has doubled since the original simulation.  

First we should define the expected behaviors (Google Search edited for applicability):


> **C. elegans** is a millimeter-long soil nematode with a remarkably simple, mapped nervous system (302 neurons). Its behavioral repertoire is highly stereotyped, primarily consisting of sinusoidal locomotion, foraging, feeding, and basic sensory responses. [[1](https://animaldiversity.org/accounts/Caenorhabditis_elegans/), [2](https://www.brainfacts.org/thinking-sensing-and-behaving/movement/2024/c-elegans-have-special-multisensory-multitasking-neurons-for-movement-100924), [3](https://pubmed.ncbi.nlm.nih.gov/2191646/), [4](https://www.sciencedirect.com/science/article/pii/S0074774205690022), [5](https://www.bosterbio.com/blog/post/c-elegans-as-a-model-organism?srsltid=AfmBOoopobF4lt_ls7iTtVnTNOcivcND90nXQ9aq32skZvkYIP2AS4On)]
> 
> Explore its specific behaviors in greater detail:
> 
> 1. Locomotion and Movement
> 
> * **Sinusoidal Crawling:** *C. elegans* moves by propagating rhythmic, dorsoventral muscle contractions along its body, resulting in an "S-shaped" or sinusoidal wave pattern. [[1](https://www.brainfacts.org/thinking-sensing-and-behaving/movement/2024/c-elegans-have-special-multisensory-multitasking-neurons-for-movement-100924), [2](https://www.jove.com/v/20160/touch-habituation-assay-method-to-study-non-associative-learning-c), [3](https://pmc.ncbi.nlm.nih.gov/articles/PMC10274735/)]
> * **Foraging:** When searching for food, the worm exhibits ** klinotaxis**, sweeping its head from side to side to detect chemical gradients, before turning sharply to adjust direction. [[1](https://elifesciences.org/reviewed-preprints/96143), [2](https://pmc.ncbi.nlm.nih.gov/articles/PMC4229948/), [3](https://pmc.ncbi.nlm.nih.gov/articles/PMC11335288/), [4](https://www.sciencedirect.com/topics/biochemistry-genetics-and-molecular-biology/caenorhabditis-elegans), [5](https://pmc.ncbi.nlm.nih.gov/articles/PMC11488850/)]
> * **Reversal and Omega Turns:** Upon encountering aversive stimuli, it initiates an "omega turn" (bending into a sharp U-shape) or a reversal (backing up) to change its heading. [[1](https://elifesciences.org/reviewed-preprints/96143)]
> 
> 2. Sensory and Avoidance Responses
> 
> * **Chemosensation & Olfaction:** Its primary senses are chemical and olfactory. It relies on these to find nutrient-rich bacterial patches and to navigate away from noxious chemicals or pathogens. [[1](https://www.tandfonline.com/doi/full/10.1080/01677063.2020.1802724), [2](https://animaldiversity.org/accounts/Caenorhabditis_elegans/)]
> * **Mechanosensation:** The worm responds to touch. A gentle tap on the head causes it to reverse, while a tap on the tail prompts forward acceleration. It also exhibits proprioception, sensing its own body position. [[1](https://animaldiversity.org/accounts/Caenorhabditis_elegans/), [2](https://pubmed.ncbi.nlm.nih.gov/2191646/), [3](https://www.brainfacts.org/thinking-sensing-and-behaving/movement/2024/c-elegans-have-special-multisensory-multitasking-neurons-for-movement-100924), [4](https://pmc.ncbi.nlm.nih.gov/articles/PMC3437330/), [5](https://link.springer.com/article/10.1007/s00424-006-0187-x)]
> 
> 3. Feeding Behaviors
> 
> * **Pharyngeal Pumping:** The worm feeds on bacteria by using a muscular organ called the pharynx. It utilizes "pumping" (rapid suction and relaxation) to draw liquid and bacteria into its mouth, grinding the food before passing it to the intestine. [[1](https://www.ncbi.nlm.nih.gov/books/NBK116080/), [2](https://en.wikipedia.org/wiki/Caenorhabditis_elegans)]
> * **Quiescence:** When food is plentiful, the worm will eventually become satiated, slowing or halting its pumping and locomotion in a sleeplike state





