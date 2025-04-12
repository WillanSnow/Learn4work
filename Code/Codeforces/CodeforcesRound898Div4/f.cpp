#include <bits/stdc++.h>
using namespace std;

int t, n, k, height[200005], fruit[200005];
int sum, lf, rt, ret;

int main() {
    cin>>t;
    while (t--) {
        cin>>n>>k;
        for (int i = 0; i<n; i++) cin>>fruit[i];
        for (int i = 0; i<n; i++) cin>>height[i];
        lf = 0;
        rt = 0;
        sum = fruit[0];
        ret = 0;
        while (lf <n && rt < n) {
            // cout<<lf<<' '<<rt<<' '<<sum<<endl;
            if (sum > k) {
                sum-=fruit[lf++];
            }
            else if (rt < lf) {
                sum+=fruit[++rt];
            }
            else {
                ret = ret > rt-lf+1? ret: rt-lf+1;
                if (rt < n-1 && height[rt]%height[rt+1] == 0) {
                    sum+=fruit[++rt];
                }
                else {
                    lf = rt+1;
                    sum = 0;
                }
            }
        }
        cout<<ret<<endl;
    }
}