//-----------------------------------------------------------------------------------------

#include <iostream>
#include "my.h"
#include <time.h>
using namespace std;

//-----------------------------------------------------------------------------------------

// ТЗ:

//++ 1.Создать двунаправленный список с числами в диапазоне от –50 до +50.

//++ 2.Переместить во второй список все элементы, находящиеся после эле-
// мента с максимальным значением и вывести результат.

//++ 3.В конце работы все списки должны быть удалены.

//-----------------------------------------------------------------------------------------

struct Ochd {
  int info;
  Ochd *next, *prev;
} *t, *p;

//-----------------------------------------------------------------------------------------

Ochd *AddOchd (Ochd *, Ochd **, int);
Ochd *Addbegin (Ochd *, Ochd **, int);
void View (Ochd *);
void Dell_All (Ochd *);
Ochd *Select(Ochd *, Ochd **, Ochd *, Ochd **);
void View_back (Ochd *);

//-----------------------------------------------------------------------------------------

Ochd *Select(Ochd *begin1, Ochd **end, Ochd *begin2, Ochd **end2) {

  int max = -51; int p_max, k;
  Ochd *max_a, *p;
  k = 0;

  p = begin1;

  while ((p->next) != NULL) {
    k++;
    if (max < (p->info)) {
      max = p->info;
      max_a = p;
      p = p->next;
      p_max = k;
    } else p = p->next;
  }

  if (max < (p->info))
  {
    p_max = k + 1;
    max = p->info;
  }

  Line(20)
  ;  cout <<  "Макс эл-т: " << ColorRedB << max <<  ColorEnd << " порядковый номер: " << p_max << endl;
  Line(20);

  p = max_a;
  do {
    p = p->next;
    begin2 = AddOchd(begin2, end2, p->info);
  } while ((p->next) != NULL);
  return begin2;
}
Ochd *AddOchd (Ochd *begin1, Ochd **end, int in) {

  t = new Ochd;
  t->info = in;
  t->next = NULL;
  t->prev = (*end);
  if ((*end) == NULL) begin1 = t;
  else (*end)->next = t;
  (*end) = t;

  return begin1;
}

void View (Ochd *p) {
  while (p != NULL) {
    if ((p->info) < 0)
      cout << p->info << endl;
    else cout << " " << p->info << endl;
    p = p->next;

  }
}


void View_back (Ochd *p) {
  while (p != NULL) {
    if ((p->info) < 0)
      cout << p->info << endl;
    else cout << " " << p->info << endl;
    p = p->prev;
  }
}

void Dell_All (Ochd *begin1) {
  while (begin1 != NULL) {
    t = begin1;
    begin1 = begin1->next;
    delete t;
  }

}

Ochd *Addbegin (Ochd *begin1, Ochd **end, int in) {

  t = new Ochd;
  t->info = in;
  t->prev = NULL;
  t->next = begin1;
  if (begin1 == NULL) *end = t;
  else begin1->prev = t;
  begin1 = t;

  return begin1;
}

//-----------------------------------------------------------------------------------------

int main () {
  setlocale(LC_ALL, "Russian");
  srand(time(NULL));
  Clear();

  int n, t;
  Ochd *begin1, *end;
  begin1 = end = NULL;

  Ochd *begin2, *end2;
  begin2 = end2 = NULL;

  Line(20);
  cout << "Введите количество элементов: "; cin >> n; cout << endl;
  for (int i = 0; i < n; i++) {
    t = -50 + rand() % 100;
    begin1 = AddOchd(begin1, &end, t);
  }

  Line(20);

  cout << "Первый список:" << endl;
  View (begin1); cout << endl;

  begin2 = Select(begin1, &end, begin2, &end2);

  cout << "Второй список:" << endl;
  View (begin2); cout << endl;
  Line(20);

  // cout << "Наоборот:" << endl;
  // View_back (end); cout << endl;

  Dell_All (begin1);
  Dell_All (begin2);


}
//-----------------------------------------------------------------------------------------