#include <iostream>
using namespace std;

int main() {
    int tt, n, a, q;
    string note;
    cin>>tt;
    while (tt--) {
        cin>>n>>a>>q;
        cin>>note;
        int maxOn = a, minOn = a, off = 0;
        for (auto c : note) {
            if (c == '+') {
                maxOn ++;
                if (off) off--;
                else minOn++;
            }
            else {
                off++;
            }
        }
        if (minOn >= n) cout<<"YES"<<endl;
        else if (maxOn < n) cout<<"NO"<<endl;
        else cout<<"MAYBE"<<endl;
    }
}