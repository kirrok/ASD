#include<iostream>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;
    bool Sovremennik;
    Date() : day(0) , month(0) , year(0) , Sovremennik(false) {}
    Date( int day , int month , int year , bool Sovremennik ) : day(day) , month(month),
        year(year) , Sovremennik(Sovremennik) {}
    bool operator <= (Date&);
    bool operator < (Date&);
};

bool Date::operator <= (Date& A)
{
    if ((this->year > A.year) ||
        (this->year == A.year && this->month > A.month) ||
        (this->year == A.year && this->month == A.month && this->day > A.day))
        return false;
    return true;
}

bool Date::operator < (Date& A)
{
    if ((this->year < A.year) ||
        (this->year == A.year && this->month < A.month ) ||
        (this->year == A.year && this->month == A.month && this->day < A.day))
        return true;
    return false;
}
/*
void heapify (Date *arr, int pos, int n) {
    while (2*pos+1 < n) {
        int t = 2*pos+1;
        if (2*pos+2 < n && arr[t] < arr[2*pos+2] )
        {
            t = 2*pos+2;
        }
        if (arr[pos] < arr[t]) {
            swap(arr[pos], arr[t]);
            pos = t;
        }
        else break;
    }
}

void heap_make(Date *arr , int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        heapify(arr, i, n);
    }
}

void heap_sort(Date *arr, int n)
{
    heap_make(arr, n);
    while( n > 0 )
    {
        swap(arr[0],arr[n-1]);
        n--;
        heapify(arr, 0, n);
    }
}
*/

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


Date& not_died_before_80 (Date born, Date &died) {

    if (Date(born.day, born.month, born.year + 62,true) < died)
        died =
}

int main()
{
    int n = 0;
    cin >> n;
    Date birth, death;
    int day, month, year;
    Date *mas = new Date[2*n];
    int count = 0;

        Date d = Date(4,5,100,false);
        not_died_before_80(Date(1,2,3,true), d);
        cout<<d.year;
    for ( int i = 0 ; i < n ; i++ ) {

        cin>> day >> month >> year;
        birth =  Date(day, month, year+18, true);

        cin>> day >> month >> year;
        death =  Date(day, month, year, false);
        if ( death <= birth)
            continue;


     //   if ( Date(birth.day, birth.month, birth.year+62, true) < death )
       //     death = Date(birth.day, birth.month, birth.year+62, false);

        mas[count] = birth;
        mas[count + 1] = death;
        count += 2;
    }

    heap_sort(mas, count);

    int meetings = 0;
    int max_meetings = 0;

    for ( int i = 0; i < count; i++)
    {
        if (mas[i].Sovremennik == true)
            ++meetings;
        if (mas[i].Sovremennik == false)
            --meetings;
          max_meetings = max(meetings, max_meetings);
    }

    cout << max_meetings <<endl;

    return 0;
}
