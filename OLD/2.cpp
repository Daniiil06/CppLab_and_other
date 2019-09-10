#include <iostream>
#include <cmath>
#define elif else if

using namespace std;

double first(double x, double y, double f) {
	return (y * sqrt(f) + 3 * sin(x));
}

double second(double x, double y, double f) {
	return (x * sqrt(fabs(f)));
}

double def(double x, double y, double f) {
	return (pow(fabs(f), 1. / 3) + pow(x, 3) / y);
}


int main()

{

	double x, y, f, f2;
	int k;

	cout << "X= ";
	cin >> x;
	cout << "Y= ";
	cin >> y;
	cout << "f= ";
	cin >> k;

	switch (k) {

	case 1: f = sinh(x); break;
	case 2: f = pow(x, 2); break;
	case 3: f = exp(x); break;
	default: cout << "Error"; return (1);

	}

	if (x > y) f2 = first(x, y, f);
	elif(x < y) f2 = second(x, y, f);
	else f2 = def(x, y, f);

	cout << f2;
	cout << endl;
	return (0);


}