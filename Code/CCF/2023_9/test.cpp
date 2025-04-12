#include <iostream>
using namespace std;

const int MOD = 1e9+7;

int fastPow(int a, int b) {
    int ret = 1;
    for (; b>0; b>>=1) {
        if (b & 1) {
            ret = 1ll* ret* a % MOD;
        }
        a = 1ll* a* a % MOD;
    }
    return ret;
}

int main() {
    int a, b;
    cin>>a>>b;
    cout<<fastPow(a, b);
    a<=10;
    b != 12;
}
