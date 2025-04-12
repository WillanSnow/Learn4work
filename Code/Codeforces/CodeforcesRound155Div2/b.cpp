#include <bits/stdc++.h>
using namespace std;

int t, n, a;
long long suma, sumb, mina, minb;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        mina = INT32_MAX;
        minb = mina;
        suma = 0;
        sumb = 0;
        for (int i = 0; i<n; i++) {
            cin>>a;
            if (a < mina) mina = a;
            suma+=a;
        }
        for (int i = 0; i<n; i++) {
            cin>>a;
            if (a < minb) minb = a;
            sumb+=a;
        }
        suma += minb*n;
        sumb += mina*n;
        if (suma > sumb) cout<<sumb<<endl;
        else cout<<suma<<endl;
    }
}