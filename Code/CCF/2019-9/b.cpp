#include <iostream>
using namespace std;

int main() {
    int n, m ,a, apple_count = 0, apple_num;
    bool *drop;
    cin>>n;
    drop = new bool[n];
    // for (int i = 0; i<n; i++) cout<<drop[i]<<' ';
    for (int i = 0; i<n; i++) {
        drop[i] = 0;
        cin>>m>>apple_num;
        for (int j = 1; j<m; j++) {
            cin>>a;
            if (a > 0) {
                if (a < apple_num) {
                    drop[i] = 1;
                }
                apple_num = a;
            }
            else {
                apple_num += a;
            }
        }
        apple_count += apple_num;
    }
    cout<<apple_count<<' ';

    int drop_count = 0, three_drop = 0;
    for (int i = 1; i<n-1; i++) {
        if (drop[i]) {
            drop_count ++;
            if (drop[i-1] && drop[i+1]) {
                three_drop ++;
            }
        }
    }

    if (drop[0]) {
        drop_count ++;
        if (drop[n-1] && drop[1]) {
            three_drop ++;
        }
    }
    if (drop[n-1]) {
        drop_count ++;
        if (drop[n-2] && drop[0]) {
            three_drop ++;
        }
    }
    cout<<drop_count<<' '<<three_drop<<endl;
    delete[] drop;
}