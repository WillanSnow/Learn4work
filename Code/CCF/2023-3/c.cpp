#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

struct User
{
    unordered_map<int, int> element;
    int dn;

    User():element(), dn(0) {}
};

int n;
User *users;

void print(set<int> ans) {
    for (auto i = ans.begin(); i!= ans.end(); i++) {
        cout<<*(i)<<' ';
    }
    cout<<endl;
}

int getab(string &exp, string &expa, string &expb) {
    int count = 1, i = 2;
    for (i = 2; i<exp.size(); i++) {
        if (exp[i] == '(') {
            count++;
            expa += exp[i];
        }
        else if (exp[i] == ')') {
            count --;
            if (count == 0) break;
            else {
                expa += exp[i];
            }
        }
        else {
            expa += exp[i];
        }
    }
    for (i+=2; i<exp.size()-1; i++) {
        expb += exp[i];
    }
    return exp[0] == '&';
}

set<int> calculate(string exp) {
    set<int> ret;
    if (exp[0] != '|' && exp[0] != '&') {
        int flag = 0, ele, value;
        string temp = "";
        for (int i = 0; i<exp.size(); i++) {
            if (exp[i] == ':' || exp[i] == '~') {
                ele = stoi(temp);
                flag = exp[i] == ':';
                temp = "";
            }
            else {
                temp += exp[i];
            }
        }
        value = stoi(temp);
        
        for (int i = 0; i<n; i++) {
            if (users[i].element.count(ele) > 0 && !(flag ^ (users[i].element[ele] == value))) {
                ret.insert(users[i].dn);
            }
        }
    }
    else {
        string expa, expb;
        int flag = getab(exp, expa, expb);
        set<int> ansa = calculate(expa), ansb = calculate(expb);
        if (flag) {
            for (auto i = ansa.begin(); i!= ansa.end(); i++) {
                if (ansb.find(*(i)) != ansb.end()) {
                    ret.insert(*(i));
                }
            }
        }
        else {
            for (auto i = ansa.begin(); i!= ansa.end(); i++) {
                ret.insert(*(i));
            }
            for (auto i = ansb.begin(); i!= ansb.end(); i++) {
                ret.insert(*(i));
            }
        }
    }
    return ret;
}

int main() {
    cin>>n;
    users = new User[n];

    for (int i = 0; i<n; i++) {
        // 创建用户
        int dn, num, ele, value;
        cin>>dn>>num;
        users[i].dn = dn;
        for (int j = 0; j<num; j++) {
            cin>>ele>>value;
            users[i].element[ele] = value;
        }
    }
    // for (int i = 0; i<n; i++) {
    //     for (auto j = users[i].element.begin(); j != users->element.end(); j++) {
    //         cout<<j->first<<'-'<<j->second<<' ';
    //     }
    //         cout<<endl;
    // }

    int m;
    cin>>m;
    string exp;
    for (int i = 0; i<m; i++) {
        // 输入表达式
        cin>>exp;
        print(calculate(exp));
    }
    delete[] users;
}