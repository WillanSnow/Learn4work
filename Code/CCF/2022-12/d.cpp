#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<vector<int>> element(n);
    vector<int> parent(n, -1);
    for (int i = 1; i<n; i++) {
        cin>>parent[i];
        // parent[i] = i;
        parent[i]--;
    }

    int node, t;
    for (int i = 0; i<n; i++) {
        cin>>t;
        node = i;
        while (node != -1) {
            // cout<<node<<' ';
            element[node].push_back(t);
            node = parent[node];
        }
        // cout<<endl;
    }

    // int count, pingf;
    long long count, pingf;
    for (int i = 0; i<n; i++) {
        sort(element[i].begin(), element[i].end());
        count = 0;
        if (element[i].size() > 1) {
            pingf = element[i][1]- element[i][0];
            count += pingf* pingf;
            pingf = element[i][element[i].size()-1]- element[i][element[i].size()-2];
            count += pingf* pingf;
        }
        for (int j = 1; j<element[i].size()-1; j++) {
            // cout<<count<<' ';
            pingf = min(element[i][j]-element[i][j-1], element[i][j+1]-element[i][j]);
            count += pingf* pingf;
        }
        cout<<count<<endl;
    }
    set<int> a;
}