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
    return left.weight < right.weight ;
}

int floor_number (vector<man> &_man) {

    int counter = 0;

    return 0;

}

int build_a_tower (vector<man> &vman) {

    int counter = 1; //
    int weight = 0;
    int position = 0;
    int current_index = NULL;
    bool flag;

printf("BEFORE INT: \n -------------------------------------------------------\n");
printf("counter = %d, weight = %d, position = %d, current_index = %d \n",counter,weight,position,current_index);
    if(vman.size() > 1 ) {
printf("AFTER IF:\n");
        man current_man = vman[vman.size() - 1];
        current_index = vman.size()-1;
printf("counter = %d, weight = %d, position = %d, current_index = %d , current_man = %d\n",counter,weight,position,current_index,current_man.strength);
        do{
            weight = 0;

            if(counter != 1)
                current_index = position - 1;
printf("AFTER counter != 1\n");

            position = 0;
printf("counter = %d, weight = %d, position = %d, current_index = %d , current_man = %d\n",counter,weight,position,current_index,current_man.strength);
printf("weight + vman[%d].weight = %d    <= curren_man.strength = %d",position,weight + vman[position].weight,current_man.strength);
            if(weight+vman[position].weight <= current_man.strength && position < current_index)
                flag = true;

printf("BEFORE WHILE:\n");
printf("counter = %d, weight = %d, position = %d, current_index = %d , current_man = %d\n",counter,weight,position,current_index,current_man.strength);
printf("weight + vman[%d].weight = %d    <= curren_man.strength = %d",position,weight + vman[position].weight,current_man.strength);
            while( weight+vman[position].weight <= current_man.strength && position < current_index) {
                printf("for\n");
                position++;
                weight+=vman[position].weight;
                printf("weight + vman[%d].weight = %d    <= curren_man.strength = %d",position,weight + vman[position].weight,current_man.strength);

            }


printf("counter = %d, weight = %d, position = %d, current_index = %d , current_man = %d\n",counter,weight,position,current_index,current_man.strength);
            if(flag)
                counter++;
printf("counter = %d, weight = %d, position = %d, current_index = %d , current_man = %d\n",counter,weight,position,current_index,current_man.strength);
            current_man = vman[position - 1];
            printf("after current_man = vman[position - 1]\n");
printf("counter = %d, weight = %d, position = %d, current_index = %d , current_man = %d\n",counter,weight,position,current_index,current_man.strength);
printf("go back to loop!\n---------------------------------------------------------------------------------------------------\n");
        } while(current_index > position);

        printf("\n1COUNTER: %d\n",counter);
    }
}
int main(){

    vector<man> vman;
    man _man;
    while (scanf("%d%d",&_man.weight,&_man.strength) != 'NULL' && (_man.strength  !=  0))
    {
        vman.insert(vman.end(),_man);
    }

    sort (vman.begin(), vman.end(), ptr_fun(special_sort_function));

    for(int i = 0; i< vman.size();i ++)
        cout << vman[i].weight<<'-'<<vman[i].strength<<endl;


    printf("\n\n");


printf("\nBEFORE");
    build_a_tower(vman);
printf("\nAFTER");


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
