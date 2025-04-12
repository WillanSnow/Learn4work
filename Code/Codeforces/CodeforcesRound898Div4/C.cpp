#include <bits/stdc++.h>
using namespace std;

int sorce[10][10] = {{1,1,1,1,1,1,1,1,1,1},{1,2,2,2,2,2,2,2,2,1},{1,2,3,3,3,3,3,3,2,1},{1,2,3,4,4,4,4,3,2,1},{1,2,3,4,5,5,4,3,2,1},{1,2,3,4,5,5,4,3,2,1},{1,2,3,4,4,4,4,3,2,1},{1,2,3,3,3,3,3,3,2,1},{1,2,2,2,2,2,2,2,2,1},{1,1,1,1,1,1,1,1,1,1}};

int main() {
    int tt, ret, n = 10;
    string str;
    cin>>tt;
    while (tt--) {
        ret = 0;
        for (int i = 0; i<n; i++) {
            cin>>str;
            for (int j = 0; j<n; j++) {
                if (str[j] == 'X') ret += sorce[i][j];
            }
        }
        cout<<ret<<endl;
    }
}