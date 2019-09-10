#include <iostream>
#include <cmath>

using namespace std;


double lab1(double x, double y, double z)

{

	double h;
	h = log(pow(y, -sqrt(fabs(x)))) * (x - (y / 2)) + sqrt(sin(atan((z))));
	return (h);

}

int main()

{

	double x, y, z;
	cout << "X= ";
	cin >> x;
	cout << "Y= ";
	cin >> y;
	cout << "Z= ";
	cin >> z;
	cout << endl << "H= " << lab1(x, y, z) << endl;
	return (0);

}