#include <iostream>
#include <vector>
using namespace std;

int n, k, arr[100005];

int main() {
    int tt;
    cin>>tt;
    while (tt--) {
        cin>>n>>k;
        k%=(n+1);
        vector<bool> recode(n+1,false);
        for (int i = 1; i<=n; i++) {
            cin>>arr[i];
            recode[arr[i]] = true;
        }
        for (int i = 0; i<=n; i++) {
            if (!recode[i]) {
                arr[0] = i;
                break;
            }
        }
        // for (int i = 0; i<=n; i++) cout<<arr[i]<<' ';
        // cout<<endl;
        for (int i = 1; i<=n; i++) {
            cout<<arr[i < k ? n - k + i + 1 : i - k]<<' ';
        }
        cout<<endl;
    }
}