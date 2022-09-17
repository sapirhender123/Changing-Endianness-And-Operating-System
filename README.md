# Changing-Endianness-And-Operating-System

Possible arguments: <br/>
1. Input file name and output file name. <br/>
2. Name of input file, name of output file, flag indicating the encoding of the operating system in the input file and
flag indicating the desired operating system encoding for the output file. <br/>
3. As in 2, with the addition of a flag indicating whether to change the endianness according to which the file is saved. <br/>

- It can be assumed that each character is saved within two bytes: the documents will be saved according to 16-UTF encoding. <br/>

Option 1 - Input file name and output file name without additional flags when the file names are received without additional flags, an output file must be created which is a copy of a file the input.
The arguments to main will be accepted in the following order: <br/>
<source-file-name> <new-file-name>
For example, running the following command on the command line:  <br/>
ofri$ ./a.out src.txt dst.txt ~  <br/>
The project creates a file called txt.dst which is identical in its content to the file txt.src.  <br/>
 <br/>
Option 2 - adding flags of the operating system of the input file and the operating system of the output file  <br/>
The possible flags are:  <br/>
A. –unix : New line character encoding in the file is \n (binary representation according to 0x000a: 16-UTF)
B. –mac : new line character encoding in the file is \r (binary representation according to 0x000d: 16-UTF)
C. –win : Newline character encoding in the file is \n\r .
 <br/>
 
Option 3 - in addition to option 2, adding a flag that determines whether to change the endianness that according to it the file is saved. <br/>
The input will be the same as in option 2, with the addition of one of the following flags: <br/>
1- .swap: the two bytes of each character must be swapped <br/>
2- .keep: Do not change the byte order of each character <br/>
