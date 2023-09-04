#include "main.h"

string play[3] = {"Rock", "Paper", "Scissors"};
rT *first = NULL;

void clear(int st)
{
	sleep(st);
	system("clear");
}

void clearRecords()
{
	rT *temp;
	if (!first)
		return;
	temp = first;
	while ((first = first->next))
	{
		delete (temp);
		temp = first;
	}
}

void result(int d, int u, int comp, int *pS, int *cS)
{
	int score = 0;
	stringstream s1, s2;
	rT *newRec, *temp, *head;
	string Res, temp1, temp2;
	string res[L] = {"You Loss", "You Won", "Draw"};

	if (d == 1)
		(*pS)++;
	if (!d)
		(*cS)++;
	Res = res[d] + "!!";
	//pS = (string) pS;
	s1 << *pS, s2 << *cS;
	s1 >> temp1, s2 >> temp2;
	Res += "\nYou: " + temp1 + " || CPU : " + temp2;
	cout << "\nResult: " << Res << endl
		 << endl;

	//Record result
	if (!first)
	{
		first = new rT;
		first->you = play[u];
		first->CPU = play[comp];
		first->result = Res;
		first->next = NULL;
		clear(2);
		return;
	}
	temp = head = first;
	while ((first = first->next))
	{
		temp = first;
	}
	newRec = new rT;
	newRec->you = play[u];
	newRec->CPU = play[comp];
	newRec->result = Res;
	newRec->next = NULL;
	temp->next = newRec;
	first = head;

	//Clear buffer(stdout)
	clear(2);
}

void getRecord()
{
	int i = 1;
	rT *temp = first;

	cout << endl
		 << "||Score Board||\n"
		 << endl;
	if (!first)
	{
		cout << "You have no records yet. Make a move!" << endl;
		clear(3);
		return;
	}
	while (first)
	{
		cout << i++ << ". Your move: " << first->you << endl;
		cout << "CPU move: " << first->CPU << endl;
		cout << first->result << endl
			 << endl;
		first = first->next;
	}
	first = temp;

	system("pause");
	clear(0);
}

int prompt()
{
	int i;
	char keys[L] = {'R', 'P', 'S'}, move;

	cout << "________________________" << endl;
	cout << "^ROCK, PAPER, SCISSORS^" << endl;

	cout << "________________________" << endl;
	cout << endl
		 << endl;
	cout << "[G]~Score Board | [Q]~Quit" << endl
		 << endl;
	cout << "[R]~Rock | [P]~Paper | [S]~Scissors" << endl;
	cout << "Make Your Move: ";
	cin >> move;

	switch (move)
	{
	case 'Q':
		return 9;
		break;
	case 'G':
		getRecord();
		return 8;
		break;
	}
	for (i = 0; i < L; i++)
	{
		if (move == keys[i] || move == keys[i] + 32)
		{
			cout << play[i] << endl;
			break;
		}
	}
	if (i == L)
	{
		cout << "Invalid Move." << endl;
		clear(2);
		return 0;
	}

	return (i + 1);
}

int logic(int p, int *comp)
{
	int W;
	srand(time(0));
	p--;
	string CPU, user;

	*comp = (rand() % 3);

	cout << "You: " << play[p] << endl;
	cout << "CPU: " << flush;
	//flushes the buffer to avoid sleep() happening prematurely

	sleep(1);
	cout << play[*comp] << endl;

	//R vs P = P
	//R vs S = R
	//S vs P = S
	if (p == (*comp))
		return 2;
	if (p == (*comp) + 2 || (*comp) == p + 2)
		W = (p) < (*comp) ? (p) : (*comp);
	else
		W = (p) > (*comp) ? (p) : (*comp);
	if (p == W)
		return 1;
	return 0;
}
