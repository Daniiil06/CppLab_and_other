//-----------------------------------------------------------------------------------------
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
//-----------------------------------------------------------------------------------------

void Line(int l) {
	for (int i = 0; i < l; ++i)
	{
		cout << "_";
	}
	cout << endl;
	cout << endl;
}

void Clear() {
	printf("\033c");
}

void Endl() {
	cout << endl;
}

//-----------------------------------------------------------------------------------------
const string ColorRedB ="\033[31m";
const string ColorGreenB ="\033[32m";
const string ColorBlueB ="\033[34m";
const string ColorEnd ="\033[0m";
//-----------------------------------------------------------------------------------------

//--------------------------------Управление положением курсора----------------------------

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

//-----------------------------------------------------------------------------------------