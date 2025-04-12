#include <iostream>
#include <stack>
#include <vector>
#include <map>

using namespace std;

const int MOD = 1e9+7;

int fastPow(int a, int b) {
    int ret = 1;
    for (; b>0; b>>=1) {
        if (b & 1) {
            ret = 1ll* ret* a % MOD;
        }
        a = 1ll* a* a % MOD;
    }
    return ret;
}

struct POL {
    int bias;
    map<int, int> xn;

    POL():bias(1), xn() {}
    POL(string s) {
        if (s[0] == 'x') {
            s[0] = '0';
            bias = 1;
            xn[stoi(s)] = 1;
        }
        else {
            bias = stoi(s);
        }
    }
    int getValue(int beidx, vector<int> &vals) {
        if (xn.find(beidx) == xn.end()) {
            return 0;
        }
        else {
            int ret = bias;
            for (auto x: xn) {
                if (x.first == beidx) {
                    ret = 1ll* ret *x.second % MOD *fastPow(vals[x.first], x.second-1) % MOD; 
                }
                else {
                    ret = 1ll* ret* fastPow(vals[x.first], x.second) % MOD;
                }
            }
            if (ret < 0) ret += MOD;
            return ret;
        }
    }
    POL operator*(const POL other) {
        POL ret(*this);
        ret.bias = 1ll* ret.bias* other.bias % MOD;
        for (auto x: other.xn) {
            if (ret.xn.find(x.first) == ret.xn.end()) {
                ret.xn[x.first] = x.second;
            }
            else {
                ret.xn[x.first] = (ret.xn[x.first] + x.second) %MOD;
            }
        }
        return ret;
    }
};

struct POLS {
    vector<POL> pols;

    POLS():pols() {}
    POLS (string s) {
        pols.push_back(POL(s));
    }

    POLS operator*(const POLS other) {
        POLS ret;
        for (auto pol1: other.pols) {
            for (auto pol2: this->pols) {
                ret.pols.push_back(pol1*pol2);
            }
        }
        return ret;
    }
    POLS operator+(const POLS other) {
        POLS ret(*this);
        for (auto pol: other.pols) {
            ret.pols.push_back(pol);
        }
        return ret;
    }
    POLS operator-(const POLS other) {
        POL temp;
        POLS ret(*this);
        for (auto pol: other.pols) {
            temp = pol;
            temp.bias = -temp.bias;
            ret.pols.push_back(temp);
        }
        return ret;
    }
};

POLS get_exp(string s) {
    stack<POLS> sta;
    string temp = "";
    POLS op1, op2;
    s += ' ';
    for (auto c: s) {
        if (c == ' ') {
            if (temp == "+") {
                op2 = sta.top();
                sta.pop();
                op1 = sta.top();
                sta.pop();
                sta.push(op1+ op2);
            }
            else if (temp == "-") {
                op2 = sta.top();
                sta.pop();
                op1 = sta.top();
                sta.pop();
                sta.push(op1- op2);
            }
            else if (temp == "*") {
                op2 = sta.top();
                sta.pop();
                op1 = sta.top();
                sta.pop();
                sta.push(op1* op2);
            }
            else {
                sta.push(POLS(temp));
            }
            temp = "";
        }
        else {
            temp += c;
        }
    }

    return sta.top();
}

int main() {
    int n, m;
    cin>>n>>m;
    getchar();

    string experiment;
    getline(cin, experiment);

    POLS exp = get_exp(experiment);

    int beidx;
    long long ans;
    vector<int> vals(n+1);
    for (int i = 0; i<m; i++) {
        cin>>beidx;
        for (int i = 1; i<=n; i++) {
            cin>>vals[i];
        }

        ans = 0;
        for (auto pol: exp.pols) {
            ans = (ans + pol.getValue(beidx, vals)) % MOD;
        }
        cout<<ans<<endl;
    }

}