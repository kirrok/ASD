#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
#define CONTROL_POINT 20
using namespace std;

void init_array(int*, int);
void search_index (int, int*, int, FILE*);
size_t get_interval (int* array_n, int elem, int length_n);

size_t length_n;
size_t length_m;
int *array_n = nullptr:
int *array_m = nullptr:

int main() {
/*FILE *data;
FILE *ans;
FILE *right_ans;

char path[40];

for(int m = 1; m < 4; m++) {*/
/*char path_to_data[] = "/home/kirrok/Документы/Projects/For_some_tests/tests/data/";
char path_to_ans[] = "/home/kirrok/Документы/Projects/For_some_tests/tests/ans/";
char path_to_right_ans[] = "/home/kirrok/Документы/Projects/For_some_tests/tests/rigth_ans/";

    sprintf(path,"%d",m);
    strcat(path_to_data,path);
    strcat(path_to_ans,path);
    strcat(path_to_right_ans,path);


data = fopen(path_to_data,"r");
ans = fopen(path_to_ans,"w");
right_ans = fopen(path_to_right_ans,"r");

size_t lenght_n,lenght_m;
fscanf(data ,"%zd%zd",&lenght_n,&lenght_m);*/

array_n[lenght_n];
array_m[lenght_m];

for(int i = 0; i < lenght_n; i ++)
    scanf("%d",&array_n[i]);
for(int i = 0; i < lenght_m; i ++)
    scanf("%d",&array_m[i]);
for(int i = 0; i < lenght_m; i ++)
    {
        printf("%zd ",get_interval(array_n, array_m[i], lenght_n));
    }

//for(int i = 0; i < lenght_m; i ++)
//search_index(array_m[i],array_n,lenght_n,ans);

/*char ans_line[100];
char right_ans_line[100];
fclose(ans);
ans = fopen(path_to_ans,"r");
fgets (ans_line,100, ans);
fgets (right_ans_line,100, right_ans);*/


        /*printf(" OTVET:%s\n",ans_line);
        printf("ROTVET:%s\n",right_ans_line);*/

/*fclose(data);
fclose(ans);
fclose(right_ans);*/

//init_array(array_n,lenght_n);
//init_array(array_m,lenght_m);


//}
return 0;
}

size_t get_index (const int elem) {

  if(elem <= array_n[0
    return -1;

  size_t _index = 1;

  while (elem > array_n[_index*2] && _index*2 < length_n)
    _index*=2;

  return _index;
}

int bin_search (const int elem,const size_t _index) {

  if (_index == -1)
    return 0;

  size_t start_index = _index;
  size_t finish_index;
  size_t average_index;

  if (_index*2 < length_n)
    fihish_index = _index*2;
  else
    finish_index = length_n-1;
/*----------------------------------------------------------------------------*/
  while (start_index < finish_index) {
    average_index = (start_index+finish_index)/2;
    elem <= array_n[average_index] ? finish_index = average_index : start_index = ++average_index;
  }
  if(elem <= array_n[finish_index])
    return finish_index
  else
    return length_n;
}


void init_array(int* arr,  int length) {

for(int i = 0; i < length; i++)
    scanf("%d",&arr[i]);
}

void search_index (int elem, int* arr, int length, FILE *f) {

bool index_not_found = true;

        for (int i = 0; i < length; i++)
        {

            if(elem <= arr[i]) {
                //printf("%d ",i);
                fprintf(f,"%d ",i);
                index_not_found = false;
                break;
            }
        }
if(index_not_found) {
    fprintf(f,"%d ",length);
   // printf("%d ",length);

}

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
