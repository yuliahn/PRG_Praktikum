Milestone1_README.txt
==================================================================
Milestone 1: Game of life and visual cryptography
version 1.0 12/12/2018

"Copyright© 2018/2019 PRG-PR GOETHE UNI - 
Blerton Osmani, Zeynep Yavas, Yulia Kim, Ischa Tahir"
==================================================================

AUTHORS / CONTACT INFORMATION:

Blerton Osmani, 6562597
Zeynep Yavas, 6534774
Yulia Kim, 6289317, s0589981@stud.uni-frankfurt.de
Ischa Tahir, 5935200, s1122618@stud.uni-frankfurt.de

==================================================================

PROGRAMS NEED TO BE INSTALLED TO RUN:

- Qt Creator 4.7.1

------------------------------------------------------------------

GENERAL NOTES:

This program includes a cellular automaton with Cornway's 
Game of Life and a system for virtual cryptography for
encoding and decoding pictures.

------------------------------------------------------------------

FILES LIST:




------------------------------------------------------------------

HOW TO RUN PROGRAM ON CONSOLE:

Game of life:
	- open "main.cpp" and run program
	- STEP1) type "1" shows a generated
	  random static 30x30x matrix
	- STEP2) type "2" shows the dynamic matrix of the
	  previous generated matrix
	- with type "3": Program ended

Visual cryptography:
....................
ENCODING:
This program takes a file for import as original picture
("Image to script") and encodes it with random generated matrix
("encrypted image"). The result is a key ("generated key").
DECODING:
The steps for decoding is reversal. Two files need to be imported
and IMAGE1 with IMAGE2 (which is the generated key from ENCODING)
decodes us the original picture.
OVERLAY:
Import two files for IMAGE1 and IMAGE2 and generated the RESULT.
(analog to DECODING)
.....................
STEPS TO START:
.....................
First: change "save_dir" in your individual source path where
you saved the local files which will be used (in main.cpp)

STEPS FOR ENCODE:
	- open console
	- type "encode"
	- choose ".txt" file you want to decode
	  (in "sources": "Beispielbild.2.txt"):
	  enter the source path of that file
	- on screen is shown:
	  "Image to script" -  original picture (SOURCE)
	  "Encrypted image" - random generated picture
	  in the structures of A and B Blocks coded (RESULT)
	  "Generated key" - this is the generated KEY

STEPS FOR DECODE:
	- type "decode"
	- choose two ".txt" files: as IMAGE1 and IMAGE2
	  from "source" and enter source path of the files
	- "Encrypted image" (IMAGE1)
	- "Generated key" - this is the key for decoding (IMAGE2)
	- "Image" - our original picture decoded (RESULT)

STEPS FOR OVERLAY:
	- type "overlay"
	- choose two ".txt" files: as IMAGE1 and IMAGE2
	  from "source" and enter source path of the files
	- "Encrypted image" (IMAGE1)
	- "Generated key" (IMAGE2)
	- "Image" - (RESULT)

------------------------------------------------------------------

It may come to problems:

-
-
-

------------------------------------------------------------------

Distribution of work:

Game of life (task 1):
Blerton Osmani (1 a, b, c, d, e)
Zeynep Yavas (1 a, b, c, d, e)

Visual cryptography (task 2):
Ischa Tahir (2 a, b)
Yulia Kim (2 c, d, e, f, g)

Visualisation in QT (task 3):
Blerton Osmani (3b)
Zeynep Yavas (3b)
Yulia Kim (3a, c)
Ischa Tahir (3c)
