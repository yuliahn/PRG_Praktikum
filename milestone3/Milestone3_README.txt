Milestone3_README.txt
==================================================================
Milestone 3: Neuronal networking
version 1.0 11/01/2019

"Copyright© 2018/2019 PRG-PR GOETHE UNI - 
Blerton Osmani, Zeynep Yavas, Yulia Kim, Ischa Tahir"
==================================================================

AUTHORS / CONTACT INFORMATION:

Blerton Osmani, 6562597, s5875357@stud.uni-frankfurt.de
Zeynep Yavas, 6534774, s4138801@stud.uni-frankfurt.de
Yulia Kim, 6289317, s0589981@stud.uni-frankfurt.de
Ischa Tahir, 5935200, s1122618@stud.uni-frankfurt.de

==================================================================

PROGRAMS NEED TO BE INSTALLED TO RUN:

- Qt Creator 4.7.1

------------------------------------------------------------------

GENERAL NOTES:

This program creates an artificial neuronal network (ANN) based 
on feedforward ANN with open topology which works through back
propagation.

------------------------------------------------------------------

FILES LIST:

.gitignore
main.cpp
milestone3.pro
neuralnet.cpp
neuralnet.h
neuron.cpp
neuron.h
weights.cpp
weights.h
Milestone3_README.txt

------------------------------------------------------------------

HOW TO RUN PROGRAM ON CONSOLE:


------------------------------------------------------------------

Working time:
- Blerton Osmani - 20h per week (2 weeks)
- Zeynep Yavas - 20h per week (2 weeks)
- Yulia Kim  - 20h per week (2 weeks)
- Ischa Tahir  - 20h per week (2 weeks)

Distribution of work:

Blerton Osmani (2 f)
	- NeuralNet::importState()
	- NeuralNet::split() 
	- NeuralNet::importNeuralNet()

Zeynep Yavas (2 e, f)
	- NeuralNet::exportState()
	- NeuralNet::importState()
	- NeuralNet::split() 
	- NeuralNet::importNeuralNet()

Ischa Tahir (2 f)
	- NeuralNet::importState()
	- NeuralNet::split()
	- Milestone3_README.txt
	- NeuralNet::importNeuralNet()

Yulia Kim (1 a-e, 2 a-f)
	- class NeuralNet:
          NeuralNet(), setInput, getOutput, back(),
	  exportState(), importState(), split(), importNeuralNet()
	- class Neuron:
	  setValue(), setActivation(), setDerivation(),
	  getValue(), getActivationOutput(), getDerivation()
	- class Weights:
	  getWeight(), setWeight(), getMatrix(), getInLayer(),
	  getOutLayer(), updateValues(),
	  hiddenGradient(), outputGradient()

==================================================================
