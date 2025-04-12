#include <iostream>
using namespace std;

struct check
{
    string status[8];
    int count;

    check():count(0){

    }
    void init() {
        for (int i = 0; i<8; i++) {
            cin>>status[i];
        }
        count = 1;
    }
    bool operator==(check other) {
        bool ret = true;
        for (int i = 0; i<8; i++) {
            if (this->status[i] != other.status[i]) {
                return false;
            }
        }
        return true;
    }
};


int main() {
    int n;
    cin>>n;

    check op[n];
    bool flag;

    for (int i = 0; i<n; i++) {
        op[i].init();

        flag = false;
        for (int j = 0; j<i; j++) {
            if (op[i] == op[j]) {
                op[j].count++;
                cout<<op[j].count<<endl;
                flag = true;
                break;
            }
        }
        if (!flag) {
            cout<<op[i].count<<endl;
        }
    }
}