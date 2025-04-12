#include <bits/stdc++.h>
using namespace std;

int t, n, s, e, s1, e1, flag;

int main() {
    cin>>t;
    while(t--) {
        cin>>n;
        cin>>s1>>e1;
        flag = true;
        for (int i = 1; i<n; i++) {
            cin>>s>>e;
            if (s>=s1 && e>=e1) flag = false;
        }
        if (flag) cout<<s1<<endl;
        else cout<<-1<<endl;
    }
}