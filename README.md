# Bank-Simulation Program

##DISCLAIMER
The data provided in the sample input absolutely has no connection with real people.

##Setup
<strong>For Linux: </strong><br/>
&nbsp;&nbsp;&nbsp;* Ensure ```g++``` and ```make``` is installed.<br/>
&nbsp;&nbsp;&nbsp;* Clone the repository and ```cd``` into the working directory.<br/>
&nbsp;&nbsp;&nbsp;* run ```make``` then ```./main.out```. <br/>

<strong>For Windows </strong></br>
&nbsp;&nbsp;&nbsp;* Ensure MinGW is installed or a similar C++ compiler. <br/>
&nbsp;&nbsp;&nbsp;* Ensure PATH variables are set, pointing to MinGW. <br/>
&nbsp;&nbsp;&nbsp;* Clone the repository and move into the working directory in command prompt. <br/>
&nbsp;&nbsp;&nbsp;* Type ```make``` or ```mingw32-make``` to compile all the files then run ```./main.out```.

##Overview
The purpose of this bank program is designing and implementing a bank's behavior by demonstrating concepts such as:<br/>
&nbsp;&nbsp;&nbsp;* Object-oriented and functional designs <br/>
&nbsp;&nbsp;&nbsp;* Multiple file compilation: separate header and source files <br/>
&nbsp;&nbsp;&nbsp;* Database manipulation<br/>
&nbsp;&nbsp;&nbsp;* Dynamic Memory management<br/>
&nbsp;&nbsp;&nbsp;* Data Structures: Doubly Linked Lists <br/>

##Input
Sample input file: database.txt<br/>
Format:<br/>

Last Name | First Name | SSN | Account Number | Balance | Type | Status
--------- | ---------- | --- | -------------- | ------- | ---- | ------
Doe | John | 00-00-0000 | 1234 | 1000.00 | Checking | Open

Member Variables | Options
---------------- | -------
Account Number | Any four digit numbers
SSN | Any string <strong>including</strong> the hyphens (e.g. 12-34-5678)
Type | Checking, CD, Savings
Status | Open, Closed
