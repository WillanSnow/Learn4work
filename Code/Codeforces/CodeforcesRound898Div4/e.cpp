#include <bits/stdc++.h>
using namespace std;

int t, n, x, blocks[200005], lf, rt, mid;

int test(int &mid) {
    int ret = 0;
    for (int i = 0; i<n; i++) {
        ret += mid > blocks[i] ? mid-blocks[i]: 0;
    }
    return ret;
}

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>x;
        for (int i = 0; i<n; i++) cin>>blocks[i];
        sort(blocks, blocks+n, [](int &a, int &b) {
            return a<b;
        });
        lf = 0;
        rt = n-1;
        while(lf < rt) {
            mid = lf+rt+1 >>1;
            if (test(blocks[mid]) <= x) {
                lf = mid;
            }
            else rt = mid-1;
        }
        lf = blocks[lf] + (x - test(blocks[lf]))/(lf+1);
        cout<<lf<<endl;
        // cout<<endl;
    }
}