#include <iostream>
#include <stack>
#include <stdio.h>
#include <cstdio>

using namespace std;

bool is_left(char bracket);
void test_sequence ();

class cstack {

    public:
        cstack();
        ~cstack();

        void push(char);
        void pop();
        char head();
        bool is_empty() const;
        void resize_buffer(int);

        template <typename T>
        void elem_swap(T&,T&);

    private:
        char *data;
        int buffer_size;
        int buffer_capacity;
};

int main() {

    test_sequence ();
    return 0;
}

void test_sequence () {

    cstack sequence;
    cstack sub_sequence;

    char bracket;
    bool correct = true;

    while ( ((bracket = getchar()) != '\n') && (bracket != '\0') && correct) {

        sequence.push(bracket);

        if(is_left(bracket)) {

            sub_sequence.push(bracket);

        } else {

            if( sub_sequence.is_empty() || !is_left(sub_sequence.head()) ) {

                sub_sequence.push(bracket);

            } else {

                if( (bracket == ']' && sub_sequence.head() == '[') || (bracket == ')' && sub_sequence.head() == '(') || (bracket == '}' && sub_sequence.head() == '{') ) {

                    sub_sequence.pop();

                } else correct = false;
            }
        }
    }

    if(correct) {

        cstack tmp;
        cstack _reverse;

        while(!sub_sequence.is_empty()) {
            tmp.push(sub_sequence.head());
            sub_sequence.pop();
        }

        while(!tmp.is_empty() && !is_left(tmp.head())) {
            sub_sequence.push(tmp.head());
            tmp.pop();
        }

        while (!sub_sequence.is_empty()) {

            switch(sub_sequence.head()) {

                case ']': cout << '['; break;
                case '}': cout << '{'; break;
                case ')': cout << '('; break;
            }
            sub_sequence.pop();
        }

        while(!sequence.is_empty()) {

            _reverse.push(sequence.head());
            sequence.pop();

        }

        while(!_reverse.is_empty()) {

            cout << _reverse.head();
            _reverse.pop();

        }

        while(!tmp.is_empty()) {
            sub_sequence.push(tmp.head());
            tmp.pop();

        }

        while(!sub_sequence.is_empty()) {

            switch(sub_sequence.head()) {

                case '[': cout << ']'; break;
                case '{': cout << '}'; break;
                case '(': cout << ')'; break;

            }
            sub_sequence.pop();
        }


   } else cout<<"IMPOSSIBLE";
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

bool cstack::is_empty() const {
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
