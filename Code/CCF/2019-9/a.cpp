#include <iostream>
using namespace std;

int main() {
    int n, m;
    cin>>n>>m;
    int init_num, change, now_sum, final_sum = 0, count = 0, max_change = 0, max_idx = 1;
    for (int i = 0; i<n; i++) {
        cin>>init_num;
        final_sum += init_num;
        now_sum = 0;
        for (int j = 0; j<m; j++) {
            cin>>change;
            now_sum -= change;
        }
        if (now_sum > max_change) {
            max_change = now_sum;
            max_idx = i+1;
        }
        count += now_sum;
    }
    cout<<final_sum-count<<' '<<max_idx<<' '<<max_change<<endl;
}