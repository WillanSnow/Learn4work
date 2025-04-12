#include <bits/stdc++.h>
using namespace std;

int main() {
    int tt;
    string str;
    cin>>tt;
    while (tt--) {
        cin>>str;
        if (str == "abc") cout<<"YES"<<endl;
        else if (str == "acb") cout<<"YES"<<endl;
        else if (str == "bac") cout<<"YES"<<endl;
        else if (str == "bca") cout<<"NO"<<endl;
        else if (str == "cab") cout<<"NO"<<endl;
        else if (str == "cba") cout<<"YES"<<endl;
        else cout<<"error"<<endl;
    }
}