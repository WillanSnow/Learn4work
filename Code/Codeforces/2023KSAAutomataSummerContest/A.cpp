#include <iostream>
using namespace std;

const long long base = 10000000;

int gcd(long long a, long long b) {
    if (a < b) return gcd(b, a);
    else {
        int temp;
        while (b != 0) {
            temp = a%b;
            a = b;
            b = temp;
        }
        return a;
    }
}

int main() {
    double k;
    cin>>k;
    long long p = (long long)(k*base);
    int q = gcd(p, base);
    if (p/q < 1000000000) {
        cout<<"Yes"<<endl<<p/q<<' '<<base/q<<endl;
    }
    else {
        cout<<"No"<<endl;
    }
}