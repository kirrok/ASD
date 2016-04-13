#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define TRUE 1
//char* get_string (void);
int main()
{
size_t i = 0;
    char *buffer = NULL;
    while (i <90)
    { i++;
    buffer = (char*)realloc(buffer,i);
    }
return 0;

}

char* get_string () {


    const size_t BUFFER = 5;
    printf("%s\n","3");
    char *current_string = (char*)malloc(5*sizeof(char));
    char *result_string = NULL;
    char *temp_string = NULL;

printf(" *%d\n",sizeof(*current_string));
printf(" _%d\n",sizeof(current_string));

    while(TRUE) {
    	printf("%s\n","4");
    	printf("%s\n","5");

    	fgets(current_string,sizeof(char),stdin);
    //	{printf("НИЧЕГО НЕ СЧИТАНО");
    	//break; }

    printf("%s","6");
    strcpy(temp_string,result_string);
    free(result_string);
    printf("%s","7");
    result_string = (char*)malloc(sizeof(result_string)+BUFFER);

    result_string = strcpy(result_string,temp_string);
    result_string = strcat(result_string,current_string);
            if(current_string[sizeof(current_string)-1] == '\0' || current_string[sizeof(current_string)-1] == '\n')
            {
                free(current_string);
                free(result_string);
                break;
            }printf("%s","8");
    }printf("%d","9");
    printf("%s",result_string);
return result_string;

}
