#include "cstdio"

int revers(const int number, int *mass) {
int temp_value;

for(size_t index = 0; index < number/2; index++) {
    temp_value = mass[index];
    mass[index] = mass[number-index-1];
    mass[number-index-1] = temp_value;
}
return 0;
}

int main() {
size_t number;
scanf("%zd", &number);
int mass[number];
for(size_t i = 0; i < number; i++)
scanf("%d", &mass[i]);
revers(number, mass);
for(size_t i = 0; i < number; i++)
printf("%d ", mass[i]);
return 0;
}


