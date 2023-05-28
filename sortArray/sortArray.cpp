#include <iostream>
#include "sortArray.h"
using namespace std;
int main() {
    int n = 0;
    cin >> n;
    SET<int, char>* a = new SET<int, char>[n];
    for (int i = 0; i < n; ++i) {
        int k = 0;
        cin >> k;
        a[i].key = k;
        a[i].other = ('a' + k % 26);
    }
    sortArray<int, char> s(a, n);
    s.show();
    s.arrSort();
    s.show();
}