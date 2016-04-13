/*  СОБОЛЕВ КИРИЛЛ.


1_4. Строки.

Напишите программу, печатающую набор строк в лексикографическом порядке.

Строки разделяются символом перевода строки '\n'. Если последний символ в потоке ввода '\n',

считать, что после него нет пустой строки. Максимальная длина строки 255 символов. Написать свою

функцию сравнения строк.


*/

#include <iostream>
#include <string>

using namespace std;


string* get_lines (int n) {

    string *lines = new string [n];
    for (int i = 0; i < n; i++)
        cin >> lines[i];
    return lines;
}

void print_lines (string *lines, int n) {

    for (int i = 0; i < n ; ++i)
        cout << lines[i] <<endl;
}

bool operator < (const string &str1,const string &str2) {
    int i = 0;
    while (str1[i] == str2[i] && str1[i] != '\0') {
        i++;
    }

    return str1[i] <= str2[i];
}

template <typename T>
void insertion_sort (T *lines, int number) {

    for (int i = 1; i < number ; ++i ) {

        T tmp = lines[i];

        int j;

        for(j = i; j > 0 && tmp < lines[j-1]; --j ) {
            lines[j] = lines[j-1];
        }

        lines[j] = tmp;
    }
}

int main()
{
    int n;
    cin >> n;

    string *lines = get_lines(n);

    insertion_sort(lines, n);

    print_lines(lines, n);

    delete[] lines;
    return 0;
}
