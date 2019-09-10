//-----------------------------------------------------------------------------------------
#include <iostream>
#include <time.h>
#include <math.h>
#include "my.h"
//-----------------------------------------------------------------------------------------

using namespace std;

int n;
double eps = 0.0001;

//-----------------------------------------------------------------------------------------

bool converge(double *xk, double *xkp)
{
	double norm = 0;
	for (int i = 0; i < n; i++)
	{
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
	}
	return (sqrt(norm) < eps);
}

//-----------------------------------------------------------------------------------------

int main()
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));

	cout << "Введите количество неизвестных: ";
	cin >> n;

	double a[n][n];
	double b[n];
	double x[n];
	double p[n];
	int D = 0;

	for (int i = 0; i < n; i++)
	{
		x[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "a[" << i + 1 << "][" << j + 1 << "]= ";
			cin >> a[i][j];
		}
		cout << "b[" << i + 1 << "]= ";
		cin >> b[i];
	}

	int k = 0, q = 0, w = 0;
	do
	{
		q = rand() % n;
		w = rand() % n;
		for (int i = 0; i < n; i++)
		{
			int temp = a[q][i];
			a[q][i] = a[w][i];
			a[w][i] = temp;
		}
		int temp = b[q];
		b[q] = b[w];
		b[w] = temp;
		for (int i = 0; i < n; i++)
		{
			x[i] = 0;
		}
		k = 0;
		do
		{
			for (int i = 0; i < n; i++)
			{
				p[i] = x[i];
			}
			for (int i = 0; i < n; i++)
			{
				double sum = 0;
				for (int j = 0; j < i; j++)
				{
					sum += (a[i][j] * x[j]);
				}
				for (int j = i + 1; j < n; j++)
				{
					sum += (a[i][j] * p[j]);
				}
				x[i] = (b[i] - sum) / a[i][i];
			}
			k++;
			D++;
			cout << ColorRedB << D << ColorEnd;
			Endl();
		}
		while (!converge(x, p) && k <= 10000);

	}
	while (k > 10000);

	Clear();
	Line(20);
	cout << ColorGreenB;
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i + 1 << "]= " << x[i] << endl;
	}
	cout << ColorEnd;
	Line(20);
	cout << ColorRedB << D << ColorEnd;
	Endl();
	Line(20);
	return 0;
}

//-----------------------------------------------------------------------------------------