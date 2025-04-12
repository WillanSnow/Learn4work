#include <iostream>
using namespace std;

int main() {
    int n, m, x, y;
    cin>>n>>m;
    int biasx = 0, biasy = 0;
    for (int i = 0; i<n; i++) {
        cin>>x>>y;
        biasx += x;
        biasy += y;
    }
    for (int i = 0; i<m; i++) {
        cin>>x>>y;
        cout<<x+biasx<<' '<<y+biasy<<endl;
    }
}