#include <iostream>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        int x, y, n, b;
        cin>>x>>y>>n;
        b = y - x;
        if (b < n*(n-1)/2) {
            cout<<-1<<endl;
            continue;
        }
        else {
            cout<<x;
            b = y - (n-2)*(n-1)/2;
            for (int i = n-2; i>=1; i--) {
                cout<<' '<<b;
                b += i;
            }
            cout<<' '<<y<<endl;
        }
    }
}