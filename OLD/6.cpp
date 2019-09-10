
#include <iostream>
#include <cmath>
#include <iomanip>
#include <string.h>
#include <string>
#include <cctype>

#include <cstring>

#include <stdio.h>
#include <cctype>
#include <cstdio>

using namespace std;
#pragma warning(disable:4996)
int main()
{
	setlocale(LC_ALL, "Russian");
	printf("\033c");
	cout << "\033]2;6 лаба\007";

	int a, b, c, k, d, n, r;


	// cout << "Длина строки = ";
	// cin >> n;

	// char str[n];



	cout << "Длина строки = ";
	cin >> r;
	cout << endl;

	char str[r];

	fgets(str, sizeof( str ), stdin);

	cout << "Строка = ";

	n = strlen(str);
	a = b = c = k = d = 0;

	str[ std::strcspn( str, "\n" ) ] = '\0';

	// for (int i = 0; i < n; ++i)
	// {
	// 	cin >> str[i];
	// }

	while (a < n)
	{
		if (str[a] == '1')
		{

			b = a;
			k = 0;

			while (str[b] == '1')

			{
				k++;
				b++;
			}

			if (k % 2 == 1)	d += k;


			a = b;

		}
		a++;
	}

	cout << "Ответ: " << d << endl;

	cout << "\033[34m _________________ \033[0m\n" << endl;
	printf("\033[32m   Всё (= \033[0m\n");
	cout << "\033[34m _________________ \033[0m\n" << endl << endl;

	return 0;
}