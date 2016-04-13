/*
СОБОЛЕВ КИРИЛЛ

6_3. Binary MSD для long long.
Дан массив неотрицательных целых 64­разрядных чисел. Количество чисел не больше 10 6​
​
.
Отсортировать массив методом MSD по битам (бинарный QuickSort).

*/

#include <iostream>
#include <vector>

const int BITSWORD = 64;
using namespace std;

void quicksortB(long long*, int, int, int);
int digit(long long, int);


int main() {

    int num;
    cin >> num;

    long long *data = new long long[num];

    for (int i = 0; i < num;i++) {
        cin >> data[i];
    }

    quicksortB(data, 0, num - 1, 0);

    for (int i = 0; i < num;i++) {
        cout << data[i] <<" ";
    }

    delete[] data;
    return 0;
}

void quicksortB(long long *data, int l, int r, int d) {
    int i = l, j = r;
    if (r <= l || d > BITSWORD) return;

    while (j != i) {

        while (digit(data[i], d) == 0 && (i < j)) i++;
        while (digit(data[j], d) == 1 && (j > i)) j--;
        swap(data[i],data[j]);
    }

    if (digit(data[r], d) == 0) j++;
        quicksortB(data, l, j-1, d+1);
        quicksortB(data, j, r, d+1);
}

int digit(long long value, int bits_number) {
    return ( value >> ( BITSWORD - bits_number - 1 ) & 1 );
}
