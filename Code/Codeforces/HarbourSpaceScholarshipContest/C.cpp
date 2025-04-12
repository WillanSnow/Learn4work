#include <iostream>
using namespace std;

int main() {
    int tt;
    cin>>tt;
    while (tt--) {
        int x, base = 1, ret = 0, ans[64];
        cin>>x;
        ans[ret] = x;
        while (x != base) {
            if ((x&base) != 0) {
                x -= base;
                ans[++ret] = x;
            }
            base<<=1;
        }
        while (x != 1) {
            x>>=1;
            ans[++ret] = x;
        }
        cout<<ret+1<<endl;
        for (int i = 0; i<=ret; i++) {
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
}

// #include <bits/stdc++.h>

// #define all(a) (a).begin(), (a).end()
// #define sz(a) (int)(a).size()
// #define pb push_back
// #define mp make_pair

// using namespace std;

// typedef long long ll;
// typedef long double ld;
// typedef pair<int, int> pii;

// bool bit(int mask, int pos) {
//     return (mask >> pos) & 1;
// }

// int main() {

//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
    
//     int tt;
//     cin >> tt;
//     while (tt--) {
//         int x;
//         cin >> x;
//         int p;
//         vector<int> ans;
//         ans.pb(x);
//         for (int i = 0; ; ++i) {
//             if (bit(x, i)) {
//                 if (x == (1 << i)) {
//                     p = i;
//                     break;
//                 }
//                 x -= (1 << i);
//                 ans.pb(x);
//             }
//         }
//         while (p > 0) {
//             x -= (1 << (p - 1));
//             ans.pb(x);
//             --p;
//         }
//         cout << sz(ans) << "\n";
//         for (int y : ans) {
//             cout << y << " ";
//         }
//         cout << "\n";
//     }

// }