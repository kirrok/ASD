/* СОБОЛЕВ КИРИЛЛ

2_4. Скользящий максимум.
Дан массив натуральных чисел A[0..n), n не превосходит 10^8. Так же задан размер некотрого окна
(последовательно расположенных элементов массива) в этом массиве k, k<=n. Требуется для
каждого положения окна (от 0 и до n­k) вывести значение максимума в окне. Скорость работы O(n log
n)
Формат входных данных. ​
 Вначале вводится n ­ количество элементов массива. Затем вводится n
строк со значением каждого элемента. Затем вводится k  ­ размер окна.
Формат выходных данных. ​
 Разделенные пробелом значения максимумов для каждого положения
*/

#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;

int* build_tree (const int n,const size_t _size) {

    int *tree = new int[_size];

    for (int i = _size/2; i < _size/2 + n; i++ )
        cin >> tree[i];

    for (int i = _size/2 - 1; i > 0 ; i-- )
        tree[i] = max(tree[2 * i],tree[2 * i + 1]);

    return tree;
}

int get_maximum(int *tree, int k, int position) {

    int left = position;
    int right = position + k - 1;
    int maximum = 0;
    while (left <= right) {
        if(left % 2 != 0)
            maximum = max(maximum, tree[left]);
        if(right % 2 == 0)
            maximum = max(maximum, tree[right]);

        left = (left + 1)/2;
        right = (right - 1)/2;

    }
    return maximum;
}

int main()
{
    int n;
    int k;
    int *tree;

    cin >> n;

    if (n == 1){
        cout << n;
        return 0;
    }

    size_t _size = 2 * pow( 2 , static_cast<int>( log2( n - 1 ) + 1 ) );

    tree = build_tree(n, _size);

    cin >> k;

    if (k == 0)
        return 0;

    for (int i = _size / 2 ;i < _size/2 + n - k + 1; i++ )
        cout << get_maximum(tree, k , i) << " ";

    delete[] tree;

    return 0;
}
