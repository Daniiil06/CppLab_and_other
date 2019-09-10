#include <stdio.h>
#include <iostream>
#include "my.h"
#include <time.h>
//#include <unistd.h>

using namespace std;

//-----------------------------------------------------------------------------------------

struct Stack {
	int inf;
	Stack *next;
}*S1, *S2;

Stack *AddStask(Stack  *sp, int inf) {
	Stack *spt = new Stack;
	spt->inf = inf;
	spt->next = sp;
	return spt;
}

Stack *ReadStackD(Stack *sp, int &inf) {
	if (sp == NULL) return NULL;
	Stack *spt = sp;
	inf = sp->inf;
	sp = sp->next;
	delete spt;
	return sp;
}

Stack *DelStackAll(Stack *sp) {
	Stack *spt; int inf;
	while (sp != NULL) {
		spt = sp;
		inf = sp->inf;
		cout << inf << " ";
		sp = sp->next;
		delete spt;
	}
	return NULL;
}


void Dell2el(Stack *sp) {
	Stack *spt; Stack *spt2;
	spt = sp;
	spt2 = sp + 1;
	sp = sp -> next -> next;
	delete spt;
	delete spt2;
}

void Dell2LastEl(Stack *sp) {
	Stack *spt;
	Stack *spt2;
	spt = sp;
	while (spt->next->next != NULL) {
		spt = spt->next;
	}
	spt2 = spt->next;
	delete spt;
	delete spt2;
}
//-----------------------------------------------------------------------------------------

Stack *In1to2adnDell(Stack *sp) {
	Stack *spt; int inf;
	while (sp != NULL) {
		spt = sp;
		inf = sp->inf;
		S2 = AddStask(S2, inf);
		     sp = sp->next;
		delete spt;
	}
	return NULL;
}

//-----------------------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	Clear();
	Line(20);

	int n;
	cout << "Введите количество элементов ";
	cin >> n;

	Line(20);

	for (int i = 0; i < n; i++) {
		int temp = rand() % 101 - 50;
		cout << temp << " ";;
		S1 = AddStask(S1, temp);
	}



	In1to2adnDell(S1);
	Endl();
	Line(20);

	Dell2LastEl(S1);
	DelStackAll(S2);
	DelStackAll(S1);
	Endl();
	Line(20);
	Endl();

	int Q;
	cin >> Q;

	//execl("/bin/bash","exit",NULL);

	return 0;
}