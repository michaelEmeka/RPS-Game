A simple Rock, Paper, Scissors CLI game built with C++.

#Libraries Used:
*iostream //input, output stream.
*cstdlib //for srand() definitions.
*ctime //for timing functions.
*sstream //stringstream to convert int to string data type.
*unistd.h //for system function sleep() in Linux based os.

#Concepts Used:
*Data Structures and Algorithms(DSA): Singly Linked Lists data structure to store instances of a play.
*Global Variables using inbuilt C++ extern property.
*Macros definitions and logic.

#Programming Paradigm: Functions Based.

#Functions Used:
main: this is the programme's starting point/init.

int prompt(): displays a menu and prompts user for valid response.

int logic(): a winner is decided based on: R vs P = P, R vs S = R, S vs P = S.

void result(): handles scoreboard, creates a struct instance to save the current play, and add it to the list.

void getRecord(): displays a list of previous records.

void clearRecord(): wipes the entire list.

void clear(): clears screen. (only applicable to Linux based OS's.

~All functions having error handling.
