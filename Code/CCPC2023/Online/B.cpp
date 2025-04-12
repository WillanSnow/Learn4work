#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int> hat;
int t, x;

int min(int a, int b) {
    if (a < b) return a;
    else return b;
}

int getans(int y) {
    if (hat.find(y) != hat.end()) return hat[y];
    else {
        int ret = min(getans(y/4)+y%4, getans(y/3)+y%3)+1;
        hat[y] = ret;
        return ret;
    }
}

int main() {
    hat[1] = 1;
    hat[0] = 0;
    hat[2] = 2;
    cin>>t;
    while (t--) {
        cin>>x;
        cout<<getans(x)<<endl;
    }
    // for (int i = 0; i<10; i++) {
    //     if (hat.find(i) != hat.end()) {
    //         cout<<hat[i]<<' ';
    //     }
    //     else cout<<-1<<' ';
    // }
}