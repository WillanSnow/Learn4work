#include <iostream>
#include <algorithm>
using namespace std;

char odd[50001], even[50001];

int main() {
    int t;
    cin>>t;
    while (t--) {
        int n, k;
        cin>>n>>k;
        for (int i = 0; i<n; i++) {
            if (i % 2==0) {
                cin>>even[i/2];
            }
            else {
                cin>>odd[i/2];
            }
        }
        sort(odd, odd+n/2);
        sort(even, even+n/2+n%2);
        if (k%2) {
            for (int i = 0; i<n; i++) {
                if (i%2) {
                    cout<<odd[i/2];
                }
                else {
                    cout<<even[i/2];
                }
            }
        }
        else {
            int i = 0, j = 0;
            while (i<n/2 && j<(n/2+n%2)) {
                if (odd[i] < even[j]) {
                    cout<<odd[i];
                    i++;
                }
                else {
                    cout<<even[j];
                    j++;
                }
            }
            while(i<n/2) {
                cout<<odd[i++];
            }
            while (j<n/2+n%2)
            {
                cout<<even[j++];
            }
        }
        cout<<endl;
    }
}