#include <iostream>
using namespace std;

int min(int &a, int &b) {
    return a < b ? a : b;
}
int max(int &a, int b) {
    return a > b ? a : b;
}

int countTog(int &b, int &c, int &d) {
    if (d <= 0 || c >= b) return 0;
    else {
        return min(b, d) - max(0, c);
    }
}

int main() {
    int n, a, b, x1, y1, x2, y2;
    cin>>n>>a>>b;
    int ret = 0;
    for (int i = 0; i<n; i++) {
        cin>>x1>>y1>>x2>>y2;
        ret += countTog(a, x1, x2) *countTog(b, y1, y2);
    }
    cout<<ret<<endl;
}