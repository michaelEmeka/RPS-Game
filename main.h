#ifndef _MAIN_
#define _MAIN_

#include <iostream>
#include <ctime>
#include <cstdlib>
//#include <conio.h>
#include <sstream>

#ifdef _MSDOS_
#include <io.h>//Windows
#else
#include <unistd.h>//UNIX
#endif
//defines system functions e.g sleep()

#define L 3
using std::cin;
using std::cout;
using std::endl;
using std::flush;
using std::string;
using std::stringstream;

extern string play[3];

typedef struct rec
{
	string you;
	string CPU;
	string result;
	struct rec *next;
} rT;

extern rT *first;

void clear(int st);
void clearRecords();
void result(int d, int u, int comp, int *pS, int *cS);
void getRecord();
int prompt();
int logic(int p, int *comp);

#endif
