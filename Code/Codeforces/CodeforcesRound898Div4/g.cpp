#include <bits/stdc++.h>
using namespace std;

int t, num, lf, minLf;
string str;

int main() {
    cin>>t;
    while(t--) {
        cin>>str;
        num = 0;
        lf = 0;
        minLf = str.size();
        for (auto &c: str) {
            if (c == 'A') lf++;
            else {
                num += lf;
                if (minLf > lf) minLf = lf;
                lf = 0;
            }
        }
        num += lf;
        if (minLf > lf) minLf = lf;
        cout<<num-minLf<<endl;
    }
}