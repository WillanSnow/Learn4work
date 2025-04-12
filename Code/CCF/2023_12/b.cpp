#include <iostream>
#include <cmath>
using namespace std;

bool isLegal(long long a) {
    for (int i = 2; i <= sqrt(a); i++) {
        if (a % i == 0) return false;
    }
    return true;
}

long long simple(long long n, int k) {
    long long ret = 1, lf = 2, temp;
    int count;

    while (n > 1) {
        if (isLegal(n)) {
            ret = 1 >= k? ret*n: ret;
            break;
        }
        if (isLegal(lf)) {
            count = 0;
            temp = 1;
            while (n % (temp*lf) == 0) {
                count++;
                temp *= lf;
            }
            if (count >= k) {
                ret *= temp;
            }
            // cout<<lf<<','<<count<<" ";
            n /= temp;
        }
        lf++;
    }
    return ret;
}

int main() {
    int q, k;
    long long n;
    cin>>q;
    while (q--) {
        cin>>n>>k;
        cout<<simple(n, k)<<endl;
    }
}