#include <iostream>
#include <algorithm>
using namespace std;

struct field
{
    int t;
    int c;
    field (int a = 0, int b = 0):t(a), c(b) {

    }
    bool operator< (const field &b) {
        return this->t > b.t;
    }
};


int main() {
    int n, m, k;
    cin>>n>>m>>k;
    field f[n];
    for (int i = 0; i<n; i++) {
        cin>>f[i].t>>f[i].c;
    }
    sort(f, f+n);
    int count = 0, idx = 0, nowadays = f[0].t;
    for (int i = 0; i<n; i++) {
        while (nowadays > f[i].t && m > count) {
            m -= count;
            nowadays --;
        }
        if (m < count) break;
        while (i+1 < n && f[i].t == f[i+1].t) {
            count += f[i].c;
            i++;
        }
        count += f[i].c;
    }
    while (nowadays > k && m > count) {
        m -= count;
        nowadays --;
    }
    cout<<nowadays<<endl;
}