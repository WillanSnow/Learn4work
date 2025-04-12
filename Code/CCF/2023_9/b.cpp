#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int n, m, lf, rt;
    cin>>n>>m;
    double *valk = new double[n+2], *valth = new double[n+2], x, y, temp;
    valk[0] = 1;
    valk[1] = 0;
    for (int i = 1; i<=n; i++) {
        cin>>lf>>temp;
        if (lf == 1) {
            valk[i] = temp* valk[i-1];
            valth[i] = valth[i-1];
        }
        else {
            valk[i] = valk[i-1];
            valth[i] = temp + valth[i-1];
        }
    }
    for (int i = 0; i<m; i++) {
        cin>>lf>>rt>>x>>y;
        x = x * valk[rt] / valk[lf-1];
        y = y* valk[rt]/valk[lf-1];
        temp = x;
        x = x*cos(valth[rt]-valth[lf-1]) - y* sin(valth[rt]- valth[lf-1]);
        y = temp*sin(valth[rt]-valth[lf-1]) + y* cos(valth[rt]- valth[lf-1]);
        cout<<fixed<<x<<' '<<y<<endl;
    }
}