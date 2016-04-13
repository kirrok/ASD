#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstdio>
using namespace std;

bool is_left(char bracket);


class cstack {

    public:
        cstack();
        ~cstack();

        void push(char);
        void pop();
        char head();
        bool stack_is_empty() const;
        void resize_buffer(int);

        template <typename T>
        void elem_swap(T&,T&);

    private:
        char *data;
        int buffer_size;
        int buffer_capacity;
};

void sequence_is_right (char *bracket_line, int length) ;


int main() {



        int number_of_chars;
        char *bracket_line;

        scanf("%d",&number_of_chars);
        bracket_line = new char[number_of_chars];
        gets(bracket_line);

        for(int i = 0 ; i < number_of_chars; i++)
            printf("%c",bracket_line[i]);

            printf("\n");

        sequence_is_right(bracket_line,number_of_chars);
printf("1st while");



    return 0;
}

void sequence_is_right (char *bracket_line, int length) {

    cstack my_stack;
    bool seq_is_right = true;


    for (int i = 0 ; i < length && seq_is_right ; i++) {
                printf("\ni = %d\n", i);
        if(is_left(bracket_line[i])) {                               //скобка левая

            my_stack.push(bracket_line[i]);
            printf("pushed!\n");
        } else {                                                    //скобка правая
                printf("right bracket!\n");
            if( my_stack.stack_is_empty() || !is_left(my_stack.head()) ) { //стек пуст или скобка в нем правая.
                my_stack.push(bracket_line[i]);
                printf("pushed,right bracket and stack is empty!\n");
            }
            else {
                printf("stack is not empty and stack contains left bracket!\n");                //стек не пуст и скобка в нем левая
                if( (bracket_line[i] == ']' && my_stack.head() == '[') || (bracket_line[i] == ')' && my_stack.head() == '(') || (bracket_line[i] == '}' && my_stack.head() == '{') ) {
                    my_stack.pop();
                    printf("pop,brackets are equal!\n");
                } else
                {seq_is_right = false;
                printf("false!\n");}
            }
        }
        printf("1st while");
    }


    if(seq_is_right) {
            cstack tmp_stack;

            while(!my_stack.stack_is_empty() ) {
                tmp_stack.push(my_stack.head());
                my_stack.pop();

            }


            while(!tmp_stack.stack_is_empty() && !is_left(tmp_stack.head()) ) {
                my_stack.push(tmp_stack.head());
                tmp_stack.pop();
            }


            while(!my_stack.stack_is_empty()) {

                switch (my_stack.head()) {

                    case ']': {
                        cout << '[';
                        break;
                    }
                    case '}': {
                        cout << '{';
                        break;
                    }
                    case ')': {
                        cout << '(';
                        break;
                    }

                }

                my_stack.pop();
            }


        for(int i = 0 ; i < length ; ++i)
            cout << bracket_line[i];
            printf("for");


            while(!tmp_stack.stack_is_empty()) {
                my_stack.push(tmp_stack.head());
                my_stack.pop();
            }

        while(!my_stack.stack_is_empty()) {

            switch (my_stack.head()) {

                case '[': {
                    cout << ']';
                    break;
                }
                case '{': {
                    cout << '}';
                    break;
                }
                case '(': {
                    cout << ')  ';
                    break;
                }
            }
            my_stack.pop();
        }

    } else
    cout<<"IMPOSSIBLE";
}


bool is_left(char bracket) {

    return (bracket == '[' || bracket == '(' || bracket == '{');
}

cstack::cstack(): data(NULL), buffer_size(0),buffer_capacity() {}

cstack::~cstack() {
    delete[] data;
}

void cstack::push(char element) {

    if (buffer_size == buffer_capacity)
        resize_buffer(std::max(1,buffer_capacity*2));

    data[buffer_size] = element;
    buffer_size++;
}

bool cstack::stack_is_empty() const {
    return buffer_size == 0;
}
void cstack::resize_buffer(int new_capacity) {
    char* tmp = new char[new_capacity];

    for(int i = 0; i < new_capacity && i < buffer_size;i++)
        elem_swap(data[i],tmp[i]);

    elem_swap(data,tmp);
    delete [] tmp;

    buffer_capacity = new_capacity;

    if(new_capacity < buffer_size)
        buffer_size = new_capacity;

}
void cstack::pop () {
    --buffer_size;
}

char cstack::head () {
    return data[buffer_size-1];
}
template <typename T>
void cstack::elem_swap(T &one, T &two) {
    T tmp = one ;
    one = two;
    two = tmp;
}
//Разделить функцию stack_head() и stack_pop();
