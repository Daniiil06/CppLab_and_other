#include "pch.h"
#include <iostream>
#include<iomanip>
#include <math.h>

using namespace std;


typedef double (*uf)(double, double, int &);
void tabl(double, double, double, double, uf);
double y(double, double, int &);
double s(double, double, int &);

int main()
{
	cout << setw(15) << "X" << setw(15) << "y(X)" << setw(10) << "k" << endl;
	tabl(-1, 1, 0.2, 0.001, y);
	cout << endl;
	cout << setw(15) << "X" << setw(15) << "s(X)" << setw(10) << "k" << endl;
	tabl(-1, 1, 0.2, 0.001, s);
	return 0;
}


void tabl(double a, double b, double h, double eps, uf fun) {
	int k = 0;
	double sum;
	for (double x = a; x < b + h / 2; x += h) {
		sum = fun(x, eps, k);
		cout << setw(15) << x << setw(15) << sum << setw(10) << k << endl;
	}
}


double y(double x, double eps, int &k) {
	return -x + asin(x);
}


double s(double x, double eps, int &k) {
	double a, c, sum;
	sum = 0;
	c = 1;
	a = 1;
	k = 1;
	while (fabs(a) > eps) {
		c *= (2 * k - 1) / double(2 * k);
		a = c * pow(x, 2 * k + 1) / (2 * k + 1);
		sum += a;
		k++;
	}
	return sum;
}