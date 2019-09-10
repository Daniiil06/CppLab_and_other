#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main()
{
	int k, i, j, n, count;

	cout << "M[k]" << endl << "k = ";
	cin >> k;
	cout << "_________________" << endl << endl;

	int *mas = new int[k];
	//int *mas2 = new int[k];

	/*----------Ввод масива-----------*/

	for (int i = 0; i < k; ++i)
	{
		cout << "M[" << i + 1 << "] = ";
		cin >> mas[i];
	}

	/*--------------------------------*/

	cout << "_________________" << endl << endl;

	for ( i = 0; i < k; i++ ) {

		count = 0;
		n = 0;

		for ( j = 0; j < k; j++ ) {

			if ( mas[i] == mas[j] ) { count++; }

		}
		if ( count == 1 ) { cout << mas[i] << "  ";}
	}

	cout << endl << endl;

	return 0;
}
