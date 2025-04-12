#include <bits/stdc++.h>
using namespace std;

int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, ans[365];

int main() {
    int delay = 5;
    for (int i = 0; i<365; i++) {
        ans[i] = delay--;
        if (delay == 0) delay = 7;
    }

    int m, d, countday = 0;
    while (true) {
        cin>>m>>d;
        if (m == 0 && d == 0) break;
        else if (m > 12 || d > month[m-1]) cout<<-1<<endl;
        else if (m == 12 && d >= 29) {
            cout<<-1<<endl;
        }
        else {
            countday = d;
            for (int i = 0; i<m-1; i++) {
                countday += month[i];
            }
            cout<<ans[countday-1]<<endl;
        }
    }
}