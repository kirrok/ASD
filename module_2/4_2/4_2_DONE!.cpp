/*
СОБОЛЕВ КИРИЛЛ

Даны неотрицательные целые числа n,k и массив целых чисел из [0..10^9] размера n. Требуется
найти k­ю порядковую статистику. т.е. напечатать число, которое бы стояло на позиции с индексом k
(0..n­1) в отсортированном массиве. Напишите нерекурсивный алгоритм.
Требования к дополнительной памяти: O(n). Требуемое среднее время работы: O(n).
Функцию Partition следует реализовывать методом прохода двумя итераторами в одном
направлении. Описание для случая прохода от начала массива к концу:
● Выбирается опорный элемент. Опорный элемент меняется с последним элементом массива.
● Во время работы Partition в начале массива содержатся элементы, не бОльшие опорного.
Затем располагаются элементы, строго бОльшие опорного. В конце массива лежат
нерассмотренные элементы. Последним элементом лежит опорный.
● Итератор (индекс) i указывает на начало группы элементов, строго бОльших опорного.
● Итератор j больше i, итератор j указывает на первый нерассмотренный элемент.
● Шаг алгоритма. Рассматривается элемент, на который указывает j. Если он больше опорного,
то сдвигаем j.
Если он не больше опорного, то меняем a[i] и a[j] местами, сдвигаем i и сдвигаем j.
● В конце работы алгоритма меняем опорный и элемент, на который указывает итератор i.

4_2. ​
Реализуйте стратегию выбора опорного элемента “медиана трёх”. Функцию Partition реализуйте
методом прохода двумя итераторами от конца массива к началу.

*/

#include <iostream>
#include <cstdio>

using namespace std;


int mediana_3(int *data , int left, int right) {

    int center = (left + right)/2;

    int mediana = left;

    if(data[left] < data[center] && data[left] < data[right]) {
        mediana = data[center] >= data[right] ? right : center;
        return mediana;
    }

    if(data[left] >= data[center] && data[left] >= data[right]) {
        mediana = data[center] <= data[right] ? right : center;
        return mediana;
    }
    return mediana;
}

int partition(int *data, int start, int end, int pivot ) {

	if( start == end )
		return start;

    swap(data[pivot], data[end]);

	int i = start;
	int j = start;
	while( j < end ) {
            if(data[j] > data[end])
                j++;
            else {
                swap(data[i],data[j]);
                j++;
                i++;
            }
	}
	swap( data[i], data[end] );
	return i;
}

int get_statistics (int *data, int number, int k) {

    int left = 0;
    int right = number - 1;
    int pivot;
    int index;

        while (left <= right) {

            pivot = mediana_3(data,left,right);
            index = partition(data, left, right, pivot);

            if (index == k)
                return data[index];

            if(index < k)
                left = index + 1;
            else right = index - 1;
        }

    return data[index];
}

int main() {

    int number = 0;
    int k = 0;

    cin >> number >> k;

    int *data = new int[number];

    for (int i = 0; i < number; ++i)
        cin >> data[i];

    cout <<get_statistics(data, number, k)<<endl;

    delete[] data;

    return 0;
};
