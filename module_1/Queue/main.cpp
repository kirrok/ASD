#include <iostream>

using namespace std;

void setx(int&,const int&);
int main()
{
    int alpha = 7;
    int betta = 8;
    return 0;
}
void setx(int &alp, const int &bet) {

alp = 80;
bet = 190;
}


/*​
Реализовать очередь с помощью двух стеков. Использовать стек, реализованный с помощью
динамического буфера.

-------------------------------------------------------------------------------------------------------------------------------------
Cледует написать структуру данных, обрабатывающую команды
push* и pop*.
----- Формат входных данных.
В первой строке количество команд n. n ≤ 1000000.
Каждая команда задаётся как 2 целых числа: a b.

a = 2 ­ pop front
a = 3 ­ push back

Если дана команда pop*, то число b ­ ожидаемое значение.Если команда pop вызвана для пустой структуры
данных, то ожидается “­-1”.
-----Формат выходных данных.
Требуется напечатать YES ­ если все ожидаемые значения совпали. Иначе, если хотя бы одно ожидание не
оправдалось, то напечатать NO.







*/
