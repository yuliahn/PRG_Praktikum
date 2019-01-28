Milestone3_README.txt
==================================================================
Milestone 3: Neuronal networking and and recognition of numbers
through drawing field
version 1.0 28/01/2019

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

This program recognizes a number drew on draw field through neural
networking program. The drawing field is represented by pixels.
During drawing a pixel gets the value 1.0 when it is 'clicked' and
0.25 when it is neighboured. The value increases by clicking other
neighbours or by clicking direct on pixel.

The values in pixel can be controlled through parameter and can be
cleared by clicking on 'clear'-button.

------------------------------------------------------------------

FILES LIST:

NeuralNet (folder)
	- neuralnet.cpp
	- neuralnet.h
	- neuron.cpp
	- neuron.h
	- weights.cpp
	- weights.h
aufgabe2.cpp
aufgabe2.h
canvas.cpp
canvas.h
canvas.ui
main.cpp
mainwindow.cpp
mainwindow.h
mainwindow.ui
milestone4.pro
milestone4.pro.user
Milestone4_README.txt

------------------------------------------------------------------

HOW TO RUN PROGRAM ON CONSOLE:


------------------------------------------------------------------

Working time:
- Blerton Osmani - 15h per week (1 1/2 weeks)
- Zeynep Yavas - 15h per week (1 1/2 weeks)
- Yulia Kim  - 15h per week (1 1/2 weeks)
- Ischa Tahir  - 15h per week (1 1/2 weeks)

Distribution of work:

Blerton Osmani (1 a-c)
	- class canvas:
	on_setButton_clicked(), on_clearButton_clicked(),
	paintEvent(), mousePressEvent(), mouseMoveEvent(),
	createField(), paintField()
	                

Zeynep Yavas (1 a-c)
	- class canvas:
	on_setButton_clicked(), on_clearButton_clicked(),
	paintEvent(), mousePressEvent(), mouseMoveEvent(),
	createField(), paintField()

Ischa Tahir (1 d, Readme)
	- resetPixel()
	- Milestone3_README.txt

Yulia Kim (1 d, 2 a-d)
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
	- Canvas: setPixel(), on_clearButton_clicked(),
	          on_testData_clicked()
	- aufgabe2.cpp: copyData(), copyLabels(), 

==================================================================