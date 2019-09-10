#include "pch.h"
#include <iostream>
#include <time.h>
using namespace std;
struct tstk {
	int inf;
	tstk *a;
}*a;

tstk *AddStask(tstk  *sp, int inf) {
	tstk *spt = new tstk;
	spt->inf = inf;
	spt->a = sp;
	return spt;
}

tstk *ReadStackD(tstk *sp, int &inf) {
	if (sp == NULL) return NULL;
	tstk *spt = sp;
	inf = sp->inf;
	sp = sp->a;
	delete spt;
	return sp;
}

tstk *DelStackAll(tstk *sp) {
	tstk *spt; int inf;
	while (sp != NULL) {
		spt = sp;
		inf = sp->inf;
		cout << inf << " ";
		sp = sp->a;
		delete spt;
	}
	return NULL;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int n;
	cout << "Введите количество элементов ";
	cin >> n;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		int temp = rand() % 101 - 50;
		cout << temp << " ";
		sum += temp;
		a = AddStask(a, temp);
	}
	double sr = double(sum) / n;
	cout << endl;
	cout << "Среднее значение " << sr << endl;
	while (a != NULL) {
		int temp;
		a = ReadStackD(a, temp);
		if (temp > sr)cout << temp << " ";
	}

	DelStackAll(a);
	return 0;
}