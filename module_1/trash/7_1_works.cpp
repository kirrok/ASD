#include <iostream>
#include <stdio.h>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

struct man
{
    int weight;
    int strength;
};

bool special_sort_function(const man &left, const man &right) {
    if (left.weight == right.weight)
        return left.strength > right.strength;

    else
        return left.weight < right.weight;
}

int build_a_tower (vector<man> &vman) {

    int counter = 1;
    int weight = 0;
    int position = 0;
    int current_index = 0;
    bool flag = false;

    if(vman.size() > 1 ) {

        man current_man = vman[vman.size() - 1];
        current_index = vman.size()-1;

        do{
            weight = 0;
            flag = false;

            if(counter != 1) {
                current_index = position -1;
                current_man = vman[position -1];

            }
            position = 0;

            if(weight+vman[position].weight <= current_man.strength && position < current_index)
                flag = true;
            while( weight+vman[position].weight <= current_man.strength && position < current_index) {

                weight+=vman[position].weight;
                position++;
            }

            if(flag)
                counter++;

        } while(current_index > position - 1 &&  flag);

    }

    return counter;
}
int main(){

    vector<man> vman;
    man _man;
    while (!cin.eof())
    {
        scanf("%d%d",&_man.weight,&_man.strength);
        vman.insert(vman.end(),_man);
    }

    sort (vman.begin(), vman.end(), ptr_fun(special_sort_function));

    for (int i = 0 ; i < vman.size();i ++ ) {

        cout << vman[i].weight << " - " << vman[i].strength<<endl;

    }
    cout << build_a_tower(vman);

    return 0;
}



/* 1. Получаем массив структур.
    2. Сортируем его по Массе.
    3. Первый элемент - самый тяжелый в массиве.
    4. Для текущего элемента i находим количество элементов которое он может выдержать :
    заведем перменную и счетчик и будем увеличивать ее на значения веса элемента массива проходя
    массив с конца ( от меньших весов к большим),
    до тех пор, пока значение переменной <= значения силы предыдущего элемента. подсчитываем итерации. (n).
    5. Когда нашли n. будем рабоать только с первыми n элементами массива (цикл от j до n), первый элемент
    из n т.е j возьмем за i. Повторяем все до тех пор пока не сможем выбрать хотя бы 1 элемент.
*/
