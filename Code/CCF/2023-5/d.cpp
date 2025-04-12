#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int n, m, k;
vector<vector<int>> dis;
unordered_map<int, int> getDis;

struct Point
{   
    vector<int> cost, mincost, neibg; 

    Point():cost(k), mincost(k), neibg() {
    }
    ~Point() {
    }
    void addNeibg(int node) {
        neibg.push_back(node);
    }
};

istream& operator>>(istream &os, Point &node) {
    for (int i = 0; i<k; i++) {
        cin>>node.cost[i];
    }
    return os;
}
ostream& operator<<(ostream &os, const Point &node) {
    int minAns = node.mincost[0];
    for (int i = 0; i<k; i++) {
        if (node.mincost[i] < minAns) {
            minAns = node.mincost[i];
        }
    }
    os<<minAns;
    return os;
}

void findMin(Point* nodes, int now, int before) {
    for (auto i: nodes[now].neibg) {
        if (i != before) {
            findMin(nodes, i, now);
        }
    }
    int onecost, temp;
    for (int i = 0; i<k; i++) {
        nodes[now].mincost[i] = nodes[now].cost[i];
        for (auto j: nodes[now].neibg) {
            if (j != before) {
                onecost = INT_MAX;
                for (int ii = 0; ii<k; ii++) {
                    if (getDis.count((now<<16)|j) > 0) {
                        temp = dis[getDis[(now<<16)|j]][i*k+ii];
                    }
                    else {
                        temp = dis[getDis[(j<<16)|now]][ii*k+i];
                    }
                    temp += nodes[j].mincost[ii];
                    onecost = min(onecost, temp);
                }
                nodes[now].mincost[i] += onecost;
            }
        }
    }
}

int main() {
    cin>>n>>m>>k;
    Point *nodes = new Point[n];
    for (int i = 0; i<n; i++) {
        cin>>nodes[i];
    }

    int u, v;
    dis = vector<vector<int>>(m, vector<int>(k*k));
    for (int i = 0; i<m; i++) {
        cin>>u>>v;
        getDis[(u<<16)|v] = i;
        nodes[u].addNeibg(v);
        nodes[v].addNeibg(u);

        for (int j = 0; j<k*k; j++) {
            cin>>dis[i][j];
        }
    }

    findMin(nodes, 0, -1);
    cout<<nodes[0]<<endl;

    delete[] nodes;
}