#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, arr[100005], mid;
    cin>>n;
    for (int i = 0; i<n; i++) {
        cin>>arr[i];
    }
    sort(arr, arr+n);
    cout<<arr[n-1]<<' ';
    if (n & 1) {
        cout<<arr[n/2]<<' ';
    }
    else {
        mid = arr[n/2]+arr[n/2-1];
        if (mid & 1) {
            cout<<mid/2<<".5 ";
        }
        else cout<<mid/2<<" ";
    }
    cout<<arr[0]<<endl;
}