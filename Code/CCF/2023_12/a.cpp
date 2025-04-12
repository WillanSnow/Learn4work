#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<m; j++) {
            cin>>arr[i][j];
        }
    }

    int flag;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            flag = 1;
            for (int k = 0; k<m; k++) {
                if (arr[i][k] >= arr[j][k]) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                cout<<j+1<<endl;
                break;
            }
            else if (j == n-1) {
                cout<<0<<endl;
            }
        }
    }
}