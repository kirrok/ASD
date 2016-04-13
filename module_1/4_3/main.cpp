#include <iostream>
#include <stdio.h>
using namespace std;

class cstack {

    public:
        cstack();
        ~cstack();

        void push(int);
        int pop();
        bool stack_is_empty() const;
        void resize_buffer(int);

        template <typename T>
        void elem_swap(T&,T&);

    private:
        int *data;
        int buffer_size;
        int buffer_capacity;
};


cstack::cstack(): data(NULL), buffer_size(0),buffer_capacity() {}

cstack::~cstack() {
    delete[] data;
}

void cstack::push(int element) {

    if (buffer_size == buffer_capacity)
        resize_buffer(std::max(1,buffer_capacity*2));

    data[buffer_size] = element;
    buffer_size++;
}

bool cstack::stack_is_empty() const {
    return buffer_size == 0;
}
void cstack::resize_buffer(int new_capacity) {
    int* tmp = new int[new_capacity];

    for(int i = 0; i < new_capacity && i < buffer_size;i++)
        elem_swap(data[i],tmp[i]);

    elem_swap(data,tmp);
    delete [] tmp;

    buffer_capacity = new_capacity;

    if(new_capacity < buffer_size)
        buffer_size = new_capacity;

}
int cstack::pop () {
    return data[--buffer_size];
}

template <typename T>
void cstack::elem_swap(T &one, T &two) {
    T tmp = one ;
    one = two;
    two = tmp;
}


class cqueue {


    public:
        cqueue(): queue_size(0) {}

        int pop() {

            if(tail.stack_is_empty())
                for (int i = 0 ; !head.stack_is_empty(); i++)
                    tail.push(head.pop());

            return tail.pop();

        }

        void push(int elem) {

            head.push(elem);
            queue_size++;

        }

        bool cqueue_is_empty () const{
            return head.stack_is_empty() && tail.stack_is_empty();
        }
    private:
        cstack head, tail;
        int queue_size;

};


void operability_test (cqueue &q) {

    int number_of_command;
    int command;
    int element;
    bool flag = true;

    scanf("%d", &number_of_command);

    for (int i = 0 ; i < number_of_command && flag; i++) {

        scanf("%d%d", &command,&element);

        switch(command) {
            case 2:
                if (q.cqueue_is_empty()) {

                    if(element != -1) {

                        flag = false;
                    }

                }
                else {
                        if(q.pop() != element)
                            flag = false;
                }
                break;
            case 3:
                q.push(element);
                break;
        }
    }

    if (flag)
        cout << "YES";
        else
            cout << "NO";

}




int main()
{
    cqueue q;
    operability_test(q);

    return 0;
}


