#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;

    int rely[m], time[m];
    int first[m], last[m];
    for (int i = 0; i<m; i++) {
        cin>>rely[i];
    }
    for (int i = 0; i<m; i++) {
        cin>>time[i];
    }
    // for (int i = 0; i<m; i++) {
    //     cout<<rely[i]<<' '<<time[i]<<endl;
    // }
    // calculate first time
    // first[j] = first[i] + time[j]
    for (int i = 0; i<m; i++) {
        if (rely[i]) {
            first[i] = first[rely[i]-1]+time[rely[i]-1];
        }
        else {
            first[i] = 1;
        }
        last[i] = n;
        cout<<first[i]<<' ';
    }
    cout<<endl;
    // calculate ddl
    // ddl[i] = ddl[j] - time[j]
    bool flag = true;
    for (int i = m-1; i>=0; i--) {
        if (first[i] + time[i] - 1 > n) {
            flag = false;
            break;
        }
        else {
            last[i] = min(last[i], n-time[i]+1);
            if (rely[i]) {
                last[rely[i]-1] = min(last[rely[i]-1], last[i]-time[rely[i]-1]);
            }
        }
    }
    if (flag) {
        for (int i = 0; i<m; i++) {
            cout<<last[i]<<' ';
        }
        cout<<endl;
    }
}