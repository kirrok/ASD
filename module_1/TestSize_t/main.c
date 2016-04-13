#include <stdio.h>
#include <stdlib.h>

int main()
{
char mass[] = "Helo";
    const size_t size = 5;

    char *result = (char*)malloc(size);


*(resul
printf("%s",*(result+500));
    printf("%d\n",size); //выводим сколько содержит в себе size
    printf("%d\n",sizeof(size));    //сколько занимает переменная size
    printf("%d\n",sizeof(char));
    printf("%d\n",sizeof(result));
    printf("%d\n",result); //размер char
    printf("%d\n",&result[4]-&result[0]);
    printf("%s","END");
    return 0;
}
