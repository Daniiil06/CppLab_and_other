

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

//--------------------------------Управление положением курсора--------->

//    \033[#A передвинуть курсор вверх на # строк
//    \033[#B передвинуть курсор вниз на # строк
//    \033[#С передвинуть курсор вправо на # столбцов
//    \033[#D передвинуть курсор влево на # столбцов
//    \033[#E передвинуть курсор вниз на # строк и поставить в начало строки
//    \033[#F передвинуть курсор вверх на # строк и поставить в начало строки
//    \033[#G переместить курсор в указанный столбец текущей строки
//    \033[#;#H задает абсолютные координаты курсора (строка, столбец)
//    \033]2;BLA_BLA\007   Заголовок окна xterm...

//	printf("\033[31m This is red. \033[0m\n");
//	printf("\033[32m This is green. \033[0m\n");
//	printf("\033[34m This is blue. \033[0m\n");


int main()
{
	int K, N, i, j, n, count;
	count = 0;

	cout << "M[K,N]" << endl << "K = ";
	cin >> K;
	cout << "N = ";
	cin >> N;
	cout << "_________________" << endl << endl;

	int mas[K][N];

	//int *mas2 = new int[k];

	/*----------Ввод масива-----------*/

	cout << "M[" << K << "," << N << "] =" << endl << endl;

	for (i = 0; i < K; ++i)
	{

		for (j = 0; j < N; ++j)
		{

			cout << "\033[" << i + 10 << ";" << j + 10 << "H";
			cin >> mas[i][j];
			//cout << "\033[32m\033[30;50H i = " << i << "\033[31;50H j = " << j << "\033[0m\n";
			//cout << "\033[" << K << ";" << N << "H";

		}

	}

	/*--------------------------------*/

	//cout<<"_________________" << endl << endl;


	for (i = 0; i < K; ++i)
	{
		for (j = 0; j < N; ++j)
		{

			cout << "\033[" << i + 20 << ";" << j + 10 << "H";

			if ( j != 0 && j != N - 1 && mas[i][j] < mas[i][j + 1] && mas[i][j] > mas[i][j - 1] ) {

				cout << "\033[32m" << mas[i][j] << "\033[0m\n";
				count++;

			}

			else {cout << mas[i][j];}
		}

	}

	cout << endl << "_________________" << endl  << endl << count << endl << "_________________" << endl;


	return 0;
}