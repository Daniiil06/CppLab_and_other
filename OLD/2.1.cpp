#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

using namespace std;

int main()
{

	setlocale(LC_ALL, "Russian");
	printf("\033c");
	cout << "\033]2;Лаба 2.1\007";

	int i, j, n, m;

	cout << "M[N,M]" << endl << "N = ";
	cin >> n;
	cout << "M = ";
	cin >> m;
	cout << "_________________" << endl << endl;


	/*----------Ввод масива-----------*/

	cout << "M[" << n << "," << m << "] =" << endl << endl;
	float **mass = new float *[n];
	for (i = 0; i < n; i++)
		mass[i] = new float[m];
	for (i = 0; i < n; ++i)
	{
		int r = 0;

		for (j = 0; j < m; ++j)
		{
			cout << "\033[" << i + 10 << ";" << j + 10 + r << "H";
			cin >> mass[i][j];
			r += 3;
			//cout << "\033[32m\033[30;50H i = " << i << "\033[31;50H j = " << j << "\033[0m\n";
			//cout << "\033[" << K << ";" << N << "H";

		}

	}

	/*---------------Приведение к треуг виду-----------------*/

	float  tempX;
	int k;

	for (i = 0; i < n; i++)
	{
		tempX = mass[i][i];
		for (j = n; j >= i; j--)
			mass[i][j] /= tempX;
		for (j = i + 1; j < n; j++)
		{
			tempX = mass[j][i];
			for (k = n; k >= i; k--)
				mass[j][k] -= tempX * mass[i][k];
		}
	}

	//-----------------Решение---------------------
	/*

	^   	a1*x1 + a2*x2 + a3*x3 = b1
	|	    0   + a2*x2 + a3*x3 = b2
	|       0   +   0   + a3*x3 = b3

	*/

	float *mass2 = new float[m];
	mass2[n - 1] = mass[n - 1][n];
	for (i = n - 2; i >= 0; i--)
	{
		mass2[i] = mass[i][n];

		for (j = i + 1; j < n; j++)
			mass2[i] -= mass[i][j] * mass2[j];
	}

	//------------------Вывод ответа--------------------

	cout << endl << "_________________" << endl << endl;

	for (i = 0; i < n; i++)
		cout << "x[" << i << "] = " << "\033[32m" << mass2[i] << "\033[0m" << ";  ";

	cout << endl <<  "_________________" << endl << endl;


	return 0;
}