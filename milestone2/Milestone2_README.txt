Milestone2_README.txt
==================================================================
Milestone 2: Traveling Salesman Problem - creating elastic nets
version 1.0 03/12/2018

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

This program creates an elastic net based on a journey route which
is travelled by a "salesman" ("The Traveling Salesman Problem").

------------------------------------------------------------------

FILES LIST:

- code_draft.cpp
- elasticnet.cpp
- elasticnet.h
- iterable.cpp
- iterable.h
- iterator.cpp
- iterator.h
- main.cpp
- mainwindow.cpp
- mainwindow.h
- mainwindow.ui
- milestone2.pro
- milestone2.pro.user
- steuerung.cpp
- steuerung.h
- steuerung.ui
- tspwidget.cpp
- tspwidget.h
- unittest.cpp
- "Milestone2_README.txt"

------------------------------------------------------------------

HOW TO RUN PROGRAM ON CONSOLE:

- 


------------------------------------------------------------------

Working time:
- Blerton Osmani - 20h per week (2 weeks)
- Zeynep Yavas - 20h per week (2 weeks)
- Yulia Kim  - 20h per week (2 weeks)
- Ischa Tahir  - 20h per week (2 weeks)

Distribution of work:

Blerton Osmani (1 a, b, c, f, 2 b)
	- class elasticnet
		- addcity()
		- setCentroid()
		- addNodes()
		- setNumofNodes()
		- preprocess()

Zeynep Yavas (1 a, b, c, f, 2 b)
	- class elasticnet
		- addcity()
		- setCentroid()
		- addNodes()
		- setNumofNodes()
		- preprocess()

Ischa Tahir (1 g, 2 a)
	- unittest: class TestSalesman
		    benchmark()
	- "steuerung" UI
	- Milestone2_README.txt

Yulia Kim (1 d, e, f, 2 b)
	- class iterable
		- euclDistance()
		- updateK(), updateT(), updateV()
		- add(), subtract(), multiply()
	- class iterator
		- solve()
		- updateIter(), update()
		- setIterObject, setIterMax(), setEtaZiel(),
		- getIterMax(), getIterObject(), getEtaZiel()
	- tspwidget
		- newIteration()
		- paintEvent(), paintGrid(), paintField(),
		  paintFieldNode()
		- mousePressEvent(), mouseMoveEvent()

------------------------------------------------------------------

CREDITS:

Functions in the tspwidget were partly (completely: paintGrid()) 
reused from the "Milestone 1 Grundlage" project, gamewidget.cpp.

==================================================================
