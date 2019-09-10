#include <iostream>

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	printf("\033c");
	cout << "\033]2;7 лаба\007";

	struct razg {

		char dat[10];
		int cod;
		char name[30];
		int time;
		int tar;
		int nom;
		int ab;

	} r[100];

	int n, z, S, sT;
	S = 0;
	sT = 0;

	cout << "_________________" << endl << endl;
	cout << "Введите кол-во разговоров:";
	cin >> n;
	cout	<< "_________________" << endl << endl;

	for (int i = 0; i < n; ++i)
	{
		cout	<< "_________________" << endl << endl;
		cout << "Дата в формате дд.мм.гггг : ";
		cin >> r[i].dat;
		cout << endl;

		cout	<< "_________________" << endl << endl;
		cout << "Код города: ";
		cin >> r[i].cod;
		cout << endl;

		cout	<< "_________________" << endl << endl;
		cout << "Название города: ";
		cin >> r[i].name;
		cout << endl;

		cout	<< "_________________" << endl << endl;
		cout << "Время разговора (сек) : ";
		cin >> r[i].time;
		cout << endl;

		cout	<< "_________________" << endl << endl;
		cout << "Тариф (коп/сек) : ";
		cin >> r[i].tar;
		cout << endl;

		cout	<< "_________________" << endl << endl;
		cout << "Номер телефона в городе : ";
		cin >> r[i].nom;
		cout << endl;

		cout	<< "_________________" << endl << endl;
		cout << "Номер абонента : ";
		cin >> r[i].ab;
		cout << endl;

	}

	cout	<< "_________________" << endl << endl;

	cout << "Введите код города, информация по которому интересует :";
	cin >> z;
	cout << endl;

	for (int i = 0; i < n; ++i)
	{
		if (r[i].cod == z)
		{
			S += r[i].time * r[i].tar;
			sT += r[i].time;
		}
	}

	cout << "_________________" << endl << endl;

	cout << "Время разговоров " << sT << " сек " << "сумма " << S << " коп." << endl;

	cout << "\033[34m _________________ \033[0m\n" << endl;
	printf("\033[32m   Всё (= \033[0m\n");
	cout << "\033[34m _________________ \033[0m\n" << endl << endl;


	return 0;
}