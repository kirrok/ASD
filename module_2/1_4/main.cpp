/*  СОБОЛЕВ КИРИЛЛ.


1_4. Строки.

Напишите программу, печатающую набор строк в лексикографическом порядке.

Строки разделяются символом перевода строки '\n'. Если последний символ в потоке ввода '\n',

считать, что после него нет пустой строки. Максимальная длина строки 255 символов. Написать свою

функцию сравнения строк.


*/


#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

void print_lines (char **lines, int n) {

    for (int i = 0; i < n ; ++i)
        cout << lines[i] <<endl;
}

bool line_cmp(const char *str1,const char *str2) {

    while (*str1 == *str2 && *str1) {
        str1++;
        str2++;
    }

    return *str1 <= *str2;
}
void insertion_sort (char **lines, int number) {

    for (int i = 1; i < number ; ++i ) {

        char *tmp_line = lines[i];

        int j;

        for(j = i; j > 0 && line_cmp(tmp_line,lines[j-1]); --j ) {
            lines[j] = lines[j-1];
        }

        lines[j] = tmp_line;
    }
}
int main()
{
    int n;

    cin >> n;

    char **lines = new char*[n];

    for (int i = 0; i < n ; ++i) {
        lines[i] = new char[255];
        scanf("%s",lines[i]);
    }

    insertion_sort(lines, n);
    print_lines(lines, n);

    for (int i = 0; i < n ; ++i) {
        delete lines[i];
    }
    delete lines;


    return 0;
}
