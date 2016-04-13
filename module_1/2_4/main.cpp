// 2_4.cpp: определяет точку входа для консольного приложения.
//


#include <cstdlib>
#include <stdio.h>

struct man {
  short int Num;
  man *next = NULL;
} ;

int del_k_elem(man *_man, int k, int number);
man* create_an_array(const int number);

int main() {

  int number = 0;
  int k = 0;;

  if(scanf("%d%d", &number, &k)==EOF)
    return -1;

  man *man = create_an_array(number);

  if(printf("%d",del_k_elem(man, k, number))<0)
    return -1;

  return 0;
}

man* create_an_array(const int number) {

  man *current = NULL;
  man *temp = NULL;
  man *head = (man*)malloc(sizeof(man));

  head->Num = 1;
  temp = head;

  for(int i = 2; i <=number; i++) {
    current = (man*)malloc(sizeof(man));
    current -> Num = i;
    temp->next = current;
    temp = current;
  }

  current->next = head;

  return current;
}

int del_k_elem(man *_man,int k,int number) {

  man *temp = NULL;
  int last_man = 0;

  for(int i = 0; i < number; i++) {
    for(int i = 0; i < k-1; i++) {
      _man = _man->next;
    }

    temp = _man->next;
    _man->next = _man->next->next;
    last_man = _man->Num;
    free(temp);
  }

  return last_man;
}
