#include <iostream>
#include <stdio.h>
#define CONTROL_POINT 20

void init_array(int* arr,int length);
void search_index (int elem, int* arr, int length);

int main()
{
size_t lenght_n,lenght_m;
scanf("%zd%zd", &lenght_n, &lenght_m);
int array_n[lenght_n];
int array_m[lenght_m];

init_array(array_n, lenght_n);
init_array(array_m, lenght_m);

for(int i = 0; i < lenght_m; i ++)
search_index(array_m[i], array_n, lenght_n);


return 0;
}

void init_array(int* arr, int length) {

for(int i = 0; i < length; i++)
    scanf("%d", &arr[i]);
}

void search_index (int elem, int* arr, int length) {
bool index_not_found = true;

        for (int i = 0; i < length; i++)
            if(elem <= arr[i]) {
                printf("%d ", i);
                index_not_found = false;
                break;
            }
if(index_not_found) printf("%d", length);

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
1. Создаем два массива.
2.

in
4 3
2 4 5 7
4 6 1
-------
out
1 3 0

2 1
1 2
2
 out 1

*/
