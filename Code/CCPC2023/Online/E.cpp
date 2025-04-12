#include <bits/stdc++.h>
using namespace std;

int t, a, b, nm;
const int mod = 1e9+7;

int an(int n) {
    if (n == 0) return 1;
    else if (n == 1) return a%mod;
    else {
        return (1ll*an(n/2)*an(n/2))%mod*an(n%2)%mod;
    }
}

int xnyn(int n) {
    if (n == 0) return 2;
    else if (n == 1) return a;
    else if (b == 0) {
        return an(n);
    }
    else {
        int xy1 = xnyn(0), xy2 = xnyn(1), temp;
        for (int i = 2; i<=n; i++) {
            temp = xy2;
            xy2 = ((1ll*a*xy2)%mod- (1ll*b*xy1)%mod)%mod;
        }
        return xy2;
    }
}

/**
 * (xn+yn) = (x+y)(xn1+yn1)-xy(xn2+yn2)
 * n = 0-->1
 * n = 1-->x+y
 * n = 2-->(x+y)2-2xy
 * **/

int main() {
    cin>>t;
    while (t--) {
        cin>>a>>b>>nm;
        cout<<xnyn(nm)<<endl;
    }
}