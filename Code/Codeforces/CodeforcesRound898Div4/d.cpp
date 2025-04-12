#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt, n, k, ret, lf;
    string inp;
    cin>>tt;
    while (tt--) {
        cin>>n>>k;
        cin>>inp;
        ret = 0;
        lf = -1;
        for (int i = 0; i<n; i++) {
            if (inp[i] == 'B') {
                if (lf == -1) lf = i;
                else if (i - lf >= k) {
                    ret++;
                    lf = i;
                }
            }
        }
        if (lf != -1) ret++;
        cout<<ret<<endl;
        // cout<<endl;
    }
}