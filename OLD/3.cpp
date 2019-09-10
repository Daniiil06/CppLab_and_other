#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

long double fact(long double f) {

	if (f == 0)return 1;
	else return f * fact(f - 1);

}



int main() {

	double a, b, x, n, res, z, p;
	int i;

	cout << "_________________" << endl << endl;
	cout << "a b n" << endl;
	cin >> a >> b >> n;
	cout << "_________________" << endl << endl;

	for (x = a; x <= b; x += (b - a) / 10) {

		res = (1 + 2 * (pow(x, 2))) * exp(pow(x, 2));

		p = 1; z = 0;

		for (int i = 1; i <= n; ++i)

		{
			p *= pow(x, 2) / i;
			z += p * (2 * i + 1);
		}

		z += 1;

		cout << x << setw(15) << z << setw(15) << res << endl;
	}

	cout << "_________________" << endl << endl;

	return (0);
}
