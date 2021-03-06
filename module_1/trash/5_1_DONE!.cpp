#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstdio>

using namespace std;

bool is_left(char bracket);
void sequence_is_right (char *bracket_line, int length);

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

int main() {

    int number_of_chars;
    char *bracket_line;

    scanf("%d",&number_of_chars);
    bracket_line = new char[number_of_chars];
    gets(bracket_line);

    sequence_is_right(bracket_line,number_of_chars);

    return 0;
}

void sequence_is_right (char *bracket_line, int length) {

    cstack my_stack;
    bool seq_is_right = true;

    for (int i = 0 ; i < length && seq_is_right ; ++i) {

        if(is_left(bracket_line[i])) {

            my_stack.push(bracket_line[i]);

        } else {

            if( my_stack.stack_is_empty() || !is_left(my_stack.head()) ) {

                my_stack.push(bracket_line[i]);

            } else {

                if( (bracket_line[i] == ']' && my_stack.head() == '[') || (bracket_line[i] == ')' && my_stack.head() == '(') || (bracket_line[i] == '}' && my_stack.head() == '{') ) {

                    my_stack.pop();

                } else seq_is_right = false;
            }
        }
    }

    if(seq_is_right) {

        cstack tmp;

        while(!my_stack.stack_is_empty()) {
            tmp.push(my_stack.head());
            my_stack.pop();
        }
        while(!tmp.stack_is_empty() && !is_left(tmp.head())) {
            my_stack.push(tmp.head());
            tmp.pop();
        }
        while (!my_stack.stack_is_empty()) {

            switch(my_stack.head()) {

                case ']': cout << '['; break;
                case '}': cout << '{'; break;
                case ')': cout << '('; break;
            }
            my_stack.pop();
        }
        for(int i = 0 ; i < length ; i++)
            cout << bracket_line[i];

        while(!tmp.stack_is_empty()) {
            my_stack.push(tmp.head());
            tmp.pop();

        }
        while(!my_stack.stack_is_empty()) {

            switch(my_stack.head()) {

                case '[': cout << ']'; break;
                case '{': cout << '}'; break;
                case '(': cout << ')'; break;

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
//Разбить функцию pop() на  head() и pop();




/*Решение всех задач данного раздела предполагает использование стека. Способ реализации стека может
быть любым (список/динамический массив).
5_1. Скобочная последовательность.
Дан фрагмент последовательности скобок, состоящей из символов (){}[].
Требуется определить, возможно ли продолжить фрагмент в обе стороны, получив корректную
последовательность.
Длина исходной последовательности ≤ 200000.
Формат входных данных. ​
 Строка, содержащая символы (){}[] и, возможно, перевод строки.
Формат выходных данных. ​
 Если возможно ­ вывести минимальную корректную последовательность, иначе ­
напечатать " ​
IMPOSSIBLE
*/
