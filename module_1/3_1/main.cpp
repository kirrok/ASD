#include <iostream>
#include <stdio.h>
#include <cstdlib>


size_t gallop_search (const int);
size_t bin_search (const int, const size_t);
int* init_array (size_t);

size_t length_n;
size_t length_m;
int *array_n = NULL;
int *array_m = NULL;


int main() {

  scanf("%zd%zd",&length_n,&length_m);

  array_n = init_array(length_n);
  array_m = init_array(length_m);

  for(size_t i = 0; i < length_m; i++) {

    size_t start_index = gallop_search(array_m[i]);
    printf(" elem: %d. start_index: %zd. ",array_m[i],start_index);
    size_t desired_index = bin_search(array_m[i],start_index);
    printf("index: %zd.\n",desired_index);

  }

return 0;
}

size_t gallop_search (const int elem) {

  if (elem <= array_n[0])
    return 0;
  if(elem > array_n[length_n-1])
    return length_n;

  size_t _index = 1;

  while (_index*2 < length_n && elem > array_n[_index*2])
    _index*=2;

    return _index;
}

size_t bin_search (const int elem, const size_t _index) {

  if(_index == length_n || _index == 0)
    return _index;

  size_t start_index = _index;
  size_t finish_index;
  size_t average_index;

  if (_index*2 < length_n)
    finish_index = _index*2;
  else
    finish_index = length_n-1;

  while (start_index < finish_index) {
    average_index = (start_index+finish_index)/2;
    elem <= array_n[average_index] ? finish_index = average_index : start_index = ++average_index;
  }

  if(elem <= array_n[finish_index])
    return finish_index;
  else
    return length_n;
}

int* init_array(const size_t length) {

  int * arr = (int*)malloc(length*sizeof(int));
  for(size_t i = 0; i < length; i++)
    scanf("%d",&arr[i]);

  return arr;
}

/* ​
Дан отсортированный массив целых чисел A[0..n­1] и массив целых чисел B[0..m­1]. Для каждого
элемента массива B[i] найдите минимальный индекс k минимального элемента массива A, равного или
превосходящего B[i]: A[k] >= B[i]. Если такого элемента нет, выведите n. Время работы поиска k для каждого
элемента B[i]: O(log(k)).
n, m ≤ 10000.

Формат входных данных.
В первой строчке записаны числа n и m. Во второй и третьей массивы A и B соответственно.

Идея в следующем:
1. Создаем два массива, первый упорядочен, второй
2.

in
4 3
2 4 5 7
4 6 1
-------
out
1 3 0

*/
