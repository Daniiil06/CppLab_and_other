#include <stdio.h>
#include <iostream>
#include "my.h"
#include <time.h>
//#include <unistd.h>

using namespace std;

struct Stack {
	int inf;
	Stack *next;
};
Stack *he, *t;
he = NULL;

Stack InStack(Stack *p, int in){
	Stack *t = new Stack;
	t -> inf = in;
	t -> next = he;
	return t;
}



int main()
{

	for (int i = 1; i <= 10; i++) {
                int in = rand() % 101 - 50;
                he = InStack (he, in);
        }
	return 0;
}