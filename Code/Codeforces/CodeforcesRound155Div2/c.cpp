#include <bits/stdc++.h>
using namespace std;

const int Mod = 998244353;

int t, n, length, point;
string s;
long long ret;

int main() {
    cin>>t;
    while (t--) {
        cin>>s;
        n = s.size();
        ret = 1;
        length = 0;
        for (int i = 0; i<n; ) {
            point = 1;
            while (point < n-i && s[i+point] == s[i]) {
                point++;
            }
            length+=point-1;
            i += point;
        }
        point = length;
        while (point > 1) {
            ret = (ret*point)%Mod;
            point--;
        }
        cout<<length<<' '<<ret<<endl;
    }
}