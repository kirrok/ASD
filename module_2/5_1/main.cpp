/*
СОБОЛЕВ КИРИЛЛ

5_1. Первые k элементов длинной последовательности.
Дана очень длинная последовательность целых чисел длины n. Требуется вывести в
отсортированном виде её первые k элементов. Последовательность может не помещаться в память.
Время работы O(n * log(k)). Доп. память O(k). Использовать слияние.
*/

#include <iostream>
#include <cstring>
using namespace std;

void quick_sort(int*, int, int);
void merge(int*, int*, int, int);
void print_result(int*, int);

int main()
{
    int number, k;
    cin >> number >> k;

    if(k == 0)
        return 0;

    int *buffer = new int[k];
    int *result = new int[k];

    int already_read = 0;

    for (int i = 0; i < k && already_read < number; i++, already_read++)
        cin >> result[i];

    quick_sort(result, 0, k - 1);

    while(already_read < number) {

        int i;

        for (i = 0; i < k && already_read < number; i++, already_read++)
            cin >> buffer[i];
        quick_sort(buffer,0, i - 1 );

        merge(result, buffer, k , i);

    }
    print_result(result, k);

    delete[] result;
    delete[] buffer;
    return 0;
}

void quick_sort(int *data, int left, int right) {
    int i = left, j = right;
    int pivot = data[(left + right) / 2];

    while (i <= j) {
        while (data[i] < pivot)
            i++;
        while (data[j] > pivot)
            j--;
        if (i <= j) {
            swap(data[i],data[j]);
            i++;
            j--;
        }
    };

    if (left < j)
        quick_sort(data, left, j);
    if (i < right)
        quick_sort(data, i, right);
}

void merge(int *result, int *buffer, int k , int buffer_size) {

    int *tmp = new int[k];

    int result_pos = 0;
    int buffer_pos = 0;
    int tmp_pos = 0;

    while (result_pos < k && buffer_pos < buffer_size && tmp_pos < k)
    {
        if (result[result_pos] <= buffer[buffer_pos])
            tmp[tmp_pos++] = result[result_pos++];
        else
            tmp[tmp_pos++] = buffer[buffer_pos++];
    }

    while (result_pos < k && tmp_pos < k)
        tmp[tmp_pos++] = result[result_pos++];

    memcpy(result, tmp , k*sizeof(int));

}

void print_result(int *result, int result_size) {
    for (int i = 0; i < result_size;i ++)
    cout << result[i] << " ";
}
