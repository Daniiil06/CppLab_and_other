//-----------------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include "my.h"
#include <time.h>
//#include <unistd.h>

using namespace std;

//-----------------------------------------------------------------------------------------

struct tochd
{
	int inf;
	tochd *left;
	tochd *rigth;
} *sp;

void NewOchd(tochd **sl, tochd **sr)
{
	*sl = new tochd;
	*sr = new tochd;
	(*sl)->left = NULL;
	(*sl)->rigth = *sr;
	(*sr)->left = *sl;
	(*sr)->rigth = NULL;
	return;
}

void AddOchdRigth(tochd *sp, int inf)
{
	tochd *spt = new tochd;
	spt->inf = inf; spt->left = sp;
	spt->rigth = sp->rigth;
	sp->rigth = spt;
	spt->rigth->left = spt;
	return;
}

void AddOchdLeft(tochd *sp, int inf)
{
	tochd *spt = new tochd;
	spt->inf = inf;
	spt->left = sp->left;
	spt->rigth = sp;
	spt->left->rigth = spt;
	sp->left = spt;
	return;
}

int ReadOchdD(tochd *sp)
{
	int inf = sp->inf;
	sp->left->rigth = sp->rigth;
	sp->rigth->left = sp->left;
	delete sp;
	return inf;
}

void DelOchdAll(tochd **sl, tochd **sr)
{
	tochd *spt = (*sl)->rigth;
	while (spt != *sr)
	{
		cout << ReadOchdD(spt) << endl;
		spt = (*sl)->rigth;
	}
	delete *sl; *sl = NULL;
	delete *sr; *sr = NULL;
	return;
}

//-----------------------------------------------------------------------------------------

int main()
{
	tochd *sl, *sr;
	NewOchd(&sl, &sr);

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
		AddOchdRigth(sl, temp);
	}
	Endl();
	Line(20);
	DelOchdAll(&sl, &sr);
	Line(20);
}
//-----------------------------------------------------------------------------------------