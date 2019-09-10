#include <iostream>
#include <time.h>
#include <math.h>

using namespace std;

int n;
double eps = 0.0001;

bool converge(double *xk, double *xkp)
{
	double norm = 0;
	for (int i = 0; i < n; i++)
	{
		norm += (xk[i] - xkp[i]) * (xk[i] - xkp[i]);
	}
	return (sqrt(norm) < eps);
}

int main()
{
	srand(time(NULL));
	double a[100][100];
	double b[100];
	double x[100];
	double p[100];
	cout << "Vvedite kolichestvo neizvestni: ";
	cin >> n;
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
				double var = 0;
				for (int j = 0; j < i; j++)
				{
					var += (a[i][j] * x[j]);
				}
				for (int j = i + 1; j < n; j++)
				{
					var += (a[i][j] * p[j]);
				}
				x[i] = (b[i] - var) / a[i][i];
			}
			k++;
		}
		while (!converge(x, p) && k <= 10000);

	}
	while (k > 10000);
	for (int i = 0; i < n; i++)
	{
		cout << "x[" << i + 1 << "]= " << x[i] << endl;
	}

//	system("pause");
	return 0;
}
