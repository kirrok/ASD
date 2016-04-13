#include <iostream>
#include <limits.h>
#include <ctime>
using namespace std;

int main()
{   unsigned int t1 = clock();
    int n;
    int k;
    int *mass;

    cin >> n;

    mass = new int[n];

    for (int i = 0; i < n ; i++)
        cin >> mass[i];

    cin >> k;

    for (int i = 0; i <= n - k; i ++) {
        int maximum = INT_MIN;
        for (int j = i; j < i + k; j ++) {
            if (mass[j] > maximum)
                maximum = mass[j];

        }
        cout << maximum << " ";
    }

    unsigned int t2 = clock();
    cout <<endl<<"SIMPLE TIME: ";
    cout << t2-t1;
    return 0;
}
