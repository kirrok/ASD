#include <stdio.h>
#include <stdlib.h>

char *simple_readline(void);
int main()
{
printf("_%s_",simple_readline());
    return 0;
}


char *simple_readline(void)
{
    const size_t block_size = 5; /*определяем размер блока единовременно считываемых данных*/

    char *result, *block, *temp;  /* переменная-результат, переменная для очередного  считанного блока и вспомогательная переменная*/
    size_t size = block_size; /* присваиваем значение*/
    size_t n = 0; /* ещё одна вспомогательная переменная -  в дальнейшем послужит для
 определения значения последнего элемента строки (будем проверять - символ ли переноса это на новую строку)*/

    result = block = (char*)malloc(size); /* выделям область памяти размером с единовременно читаемый
блок данных и переводим два указателя на эту область - в том числе и указатель на строку-результат*/

int SIZE = sizeof(block);
printf("%d",sizeof(block));
printf("%d",size);

    if (!result)
        return NULL;

    *result = '\0';
    int i = 0;
    for (;;) {
    i++;
        if (fgets(block, block_size, stdin) == NULL)
            break;

        n += sizeof(block);

        if (result[n - 1] == '\n')
            break;

        size += block_size;
        temp = (char*)realloc(result, size);

        if (temp == NULL)
            break;

        result = temp;
        block = result + n;
    }

    if (result[0] == '\0') {
        free(result);
        result = NULL;
    }

    return result;
}
