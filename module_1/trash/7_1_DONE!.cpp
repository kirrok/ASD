#include <stdio.h>
#include <iostream>
#include <algorithm>

const int MAX_SIZE = 100000;

int build_a_tower (int*, int*,const int) ;

int main (){

    int *strength = new int [MAX_SIZE];
    int *weight = new int [MAX_SIZE];

    int i = 0;

    while (scanf("%d%d",&weight[i],&strength[i]) != EOF && ++i && weight[i-1]!=0);

    std::sort (weight, weight + i);
    std::sort (strength, strength + i);

    std::cout <<build_a_tower(weight,strength,i);

    return 0;

}

int build_a_tower (int *weight,int *strength,const int number) {

    int summary_weight = weight [0];
    int floor_number = 1;


    for ( int i = 1 ; i < number; i++) {

        if (summary_weight < strength[i]) {

            summary_weight += weight[i];
            floor_number++;

        }
    }

    return floor_number;
}


