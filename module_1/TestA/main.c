#include <stdio.h>
#include <stdlib.h>x
#include <string.h>
#define TRUE 1

int main()
{
    const size_t BUFFER = 5*sizeof(char);
    char *result_line = NULL;
    strlen(result_line);
    char *temp_line = NULL;
    char *received_line = (char*)malloc(BUFFER);
    char *temp_adress = NULL;
int i = 1;
while(1){

    fgets(received_line,BUFFER,stdin);
    temp_adress = result_line;
        printf("RECEIVED_LINE: %s\n",received_line);
        if(i==1)
        temp_line = (char*)malloc(0);
        else temp_line = (char*)malloc(strlen(result_line));
        printf("no1"); // dвыделение памяти для копирование
        temp_line = strcpy(temp_line,result_line);
        printf("no2");
        result_line = (char*)realloc(result_line,(BUFFER)*i); //перевыделение памяти под новую RESULT строку
        i++;


        printf("RESULT_LINE_AFTER_REALLOC:%s\n",result_line);


       // free(temp_adress);
        printf("TEMP_LINE:%s\n",temp_line);

    result_line = strcpy(result_line,temp_line);

        printf("RESULT_LINE_AFTER_STRCPY:%s\n",result_line);

    result_line = strcat(result_line,received_line);

        printf("RESULT_LINE_AFTER_STRCAT:%s\n",result_line);
        printf("last_simv_received_line:%s\n",received_line[strlen(received_line)]);

        printf("\n____________________________________________\n");

    if(received_line[strlen(received_line)-1] == '\n')
    break;


}
        printf("____________________________________________\n");
        printf("_result_line: %s_",result_line);
return 0;
}
//нужно ввести проверку на условие вхождения в цикл в первый раз чтобы включить free(temp_adress);
