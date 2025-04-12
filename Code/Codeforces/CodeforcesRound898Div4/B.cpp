#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt, n, nubs[10], minNub, ret;
    cin>>tt;
    while(tt--) {
        cin>>n;
        minNub = 9;
        ret = 1;
        for (int i = 0; i<n; i++) {
            cin>>nubs[i];
            if (nubs[i] < minNub) minNub = nubs[i];
        }
        for (int i = 0; i<n; i++) {
            if (minNub == nubs[i]) {
                ret*=(minNub+1);
                minNub = -1;
            }
            else ret*=nubs[i];
        }
        cout<<ret<<endl;
    }
}