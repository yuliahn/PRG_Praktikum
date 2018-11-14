Milestone1_README.txt
==================================================================
Milestone 1: Game of life and visual cryptography
version 1.0 12/12/2018

"Copyright© 2018/2019 PRG-PR GOETHE UNI - 
Blerton Osmani, Zeynep Yavas, Yulia Kim, Ischa Tahir"
==================================================================

AUTHORS / CONTACT INFORMATION:

Blerton Osmani, 6562597
Zeynep Yavas, 6534774, s4138801@stud.uni-frankfurt.de
Yulia Kim, 6289317, s0589981@stud.uni-frankfurt.de
Ischa Tahir, 5935200, s1122618@stud.uni-frankfurt.de

==================================================================

PROGRAMS NEED TO BE INSTALLED TO RUN:

- Qt Creator 4.7.1

------------------------------------------------------------------

GENERAL NOTES:

This program includes a cellular automaton with Cornway's 
Game of Life and a system for visual cryptography for
encoding and decoding pictures.

------------------------------------------------------------------

FILES LIST:

- "GameOfLifeCode" (PROGRAM CODE)
	- "main.cpp"
	- "matrix.cpp"
	- "matrix.h"
- "app" (GUI)
	- "beispielbild.qrc"
	- "decode_widget.cpp"
	- "decode_widget.h"
	- "decode_widget.ui"
	- "encode_widget.cpp"
	- "encode_widget.h"
	- "encode_widget.ui"
	- "main.cpp"
	- "mainwindow.cpp"
	- "mainwindow.h"
	- "mainwindow.ui"
	- "milestone1.pro"
	- "milestone1-pro.user"
	- "overlay_widget.cpp"
	- "overlay_widget.h"
	- "overlay_widget.ui"
	- "visualcrypt.cpp"
	- "visualcrypt.h"
- "sources" (for import/export used textfiles)
	- "A2f.image1.txt"
	- "A2f.image2.txt"
	- "A2f.overlay.txt"
	- "beispielbild_1.txt"
	- "beispielbild_2.txt"
	- "beispielbild_3.txt"
	- "key.txt"
	- "overlay.txt"
	- "result.txt"
	- "test_app_key.txt"
	- "test_app_result.txt"
- "visualcrypt" (PROGRAM CODE)
	- "main.cpp"
	- "visualcrypt.cpp"
	- "visualcrypt.h"
	- "visualcrypt.ui"
	- "visualcrypt.pro"
	- "visualcrypt.pro.user"
	- "visualcrypt.user"
- "Milestone1_README.txt"

------------------------------------------------------------------

HOW TO RUN PROGRAM ON CONSOLE:

Game of life:
...................
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
as IMAGE1 with IMAGE2 (which is the generated key from ENCODING)
decodes the original picture as "decrypted image" (RESULT).
OVERLAY:
Import two files: IMAGE1 and IMAGE2 (two random 10x10 matrices)
which are coded by the same (random) key, overlayed.
You get the 20x20 matrix as RESULT (represented as blocks A B).

STEPS TO START:

First: change "save_dir" in your individual source path where
you saved the local files which will be used (in main.cpp and
in "mainwindow.h" for task 3).

STEPS FOR ENCODE:
	- open console
	- insert source path "virtualscript.exe"
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
	  (example: "key.txt" and "result.txt" from "sources")
	  enter source path of the files
	on screen is shown:
	- "Encrypted image" (IMAGE1)
	- "Generated key" - this is the key for decoding (IMAGE2)
	- "Decrypted Image" - original picture decoded (RESULT)

STEPS FOR OVERLAY:
	- type "overlay"
	- choose two ".txt" files: as IMAGE1 and IMAGE2
	  ("A2f.image1" and "A2f.image2.txt" from "sources")
	  enter source path of the files
	- type "2f"
	on screen is shown:
	- IMAGE1 - random 10x10 matrix
	- IMAGE2 - random 10x10 matrix
	- RESULT - the 20x20 matrix (represented as blocks A B)

Qt GUI:
...................
Before you start: set a default folder for browsing files under
"save_dir" in the "mainwindow.h" file.
Switch between tabs to choose programs: "Game of Life",

"Virtual cryptography":

Use a dropdown list to choose a crypting mode.

Encode
1. Import an image to encrypt
2. Generate a random key
3. Encode the image
4. Save the generated key and/or the encrypted image.

Decode
1. Import an image to decode
2. Import a key
3. Decode the image
4. Save the result

Overlay
1. Import the first image to overlay
2. Import the second image to overlay
3. Overlay images
4. Save the result


------------------------------------------------------------------

Working time:
- Blerton Osmani - 20h per week (3 weeks)
- Zeynep Yavas - 20h per week (3 weeks)
- Yulia Kim  - 20h per week (3 weeks)
- Ischa Tahir  - 20h per week (3 weeks)

Distribution of work:

Game of life (task 1):
Blerton Osmani (1 a, b, c, d, e)
	- matrix_creator()
	- matrix_printer()
	- matrix_printer2()
	- interface(), interface_class()
	- timestep()
Zeynep Yavas (1 a, b, c, d, e)
	- matrix_creator()
	- matrix_printer()
	- matrix_printer2()
	- interface(), interface_class()
	- timestep(m)

Visual cryptography (task 2):
Ischa Tahir (2 a, b)
	- class NBild
		- NBild::importData
		- NBild::exportData
	- class CBild
		- CBild::importData
		- CBild::exportData
Yulia Kim (2 c, d, e, f, g)
	- vector<vector <int>> genMatrix
	- check()
	- vector<vector <int>> encode
	- vector<vector <int>> decode
	- vector<vector <int>> overlay

Visualisation in QT (task 3):
Blerton Osmani (3b)
Zeynep Yavas (3b)
Yulia Kim (3 a, b, c)
	- encode_widget()
	- decode_widget()
	- overlay_widget()
	- MainWindow()
Ischa Tahir (3c)
	- decode_widget()
	- overlay_widget()

README:
Yulia Kim, Ischa Tahir

==================================================================
