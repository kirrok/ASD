/* СОБОЛЕВ КИРИЛЛ

3_2. Современники.
Группа людей называется современниками если был такой момент, когда они могли собраться
вместе. Для этого в этот момент каждому из них должно было  уже исполниться 18 лет, но ещё не
исполниться 80 лет.
Дан список Жизни Великих Людей. Необходимо получить максимальное количество современников.
В день 18летия человек уже может принимать участие в собраниях, а в день 80летия и в день смерти
уже не может.

*/

#include<iostream>

using namespace std;

class date {

public:

    int day,month,year;
    bool date_of_birth;

    date(): day(0), month(0), year(0), date_of_birth(false){}
    date(int d, int m, int y, bool flag): day(d), month(m), year(y), date_of_birth(flag){}
    //date1 <= _date
    bool operator <= (date &_date) {

    if ((this->year > _date.year ) ||
        (this->year == _date.year && this->month > _date.month) ||
        (this->year == _date.year && this->month == _date.month && this->day > _date.day))
        return false;
    return true;
    }

    bool operator < (date &A) {
    if ((this->year < A.year) ||
        (this->year == A.year && this->month < A.month ) ||
        (this->year == A.year && this->month == A.month && this->day < A.day))
        return true;
    return false;
}

};

template <class T>
void heap_make(T * data, int n) {
    for(int i = n/2; i >= 1; --i) {
        for (int j = i; j <= n/2;) {
            int k = j*2;
            if(k + 1 <= n && data[k] < data[k + 1]) {
                ++k;
            }
            if (data[j] < data[k]) {
                swap(data[k],data[j]);
                j=k;
            } else {
                break;
            }
        }
    }
}

template <class T>
void heap_pop (T *data, int n) {
    swap(data[n],data[1]);

    for(int i = 1; 2*i < n;) {
        i *= 2;
        if(i + 1 < n && data[i] < data[i + 1]) {
            i++;
        }
        if(data[i/2] < data[i]){
            swap(data[i/2],data[i]);
        }
    }
}

template <class T>
void heap_sort (T *data, int n) {

    heap_make(data - 1, n);
    for(int i = 0; i < n; ++i) {
        heap_pop(data - 1, n - i);
    }
}

void not_died_before_80 (date born, date &died) {

    if (date(born.day, born.month, born.year + 62,true) < died)
        died = date(born.day, born.month, born.year + 62, false);
}

int get_max (date *dates,int real_number) {

    int maximum = 0;
    int current = 0;

    for ( int i = 1; i <= real_number; i++) {

        if (dates[i].date_of_birth == true)
            ++current;
        else
            --current;
          maximum = max(current, maximum);
    }
    return maximum;
}
int main() {

    int number;
    int day, month, year;
    int real_number = 1;
    cin >> number;
    date *dates_array = new date[2 * number + 1];

    for (int i = 0; i < number; i++) {

        cin >> day >> month >> year;
        dates_array[real_number] = date(day, month, year + 18,true);

        cin >> day >> month >> year;
        dates_array[real_number + 1] = date(day, month, year,false);

        if ( dates_array[real_number + 1] <= dates_array[real_number]) {
            continue;
            real_number -= 2;
        }
        not_died_before_80(dates_array[real_number], dates_array[real_number + 1]);
        real_number += 2;
    }

    heap_sort(dates_array, real_number);

    cout << get_max(dates_array, real_number);
    delete[] dates_array;
    return 0;
}
