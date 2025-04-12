#include <bits/stdc++.h>
using namespace std;

int t, n;
const int Mod = 1e9+7;
int a , b , ret, temp;

int main() {
    cin>>t;
    while (t--) {
        cin>>n;
        a = 0;
        b = 1;
        for (int i = 1; i<n; i++) {
            temp = b;
            b = (a + b + 1)%Mod;
            a = temp;
        }
        cout<<b<<endl;
    }
}