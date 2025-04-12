#include <iostream>
#include <stack>
using namespace std;

bool test(string &inp) {
    stack<int> sta;
    for (int i = 0; i<inp.size(); i++) {
        if (inp[i] == '+') {
            sta.push(-1);
        }
        else if (inp[i] == '-') {
            sta.push(-2);
        }
        else if (inp[i] == 'x') {
            int num1 = sta.top(), num2 = inp[i+1]-'0';
            sta.pop();
            sta.push(num1*num2);
            i++;
        }
        else if (inp[i] == '/') {
            int num1 = sta.top(), num2 = inp[i+1]-'0';
            sta.pop();
            sta.push(num1/num2);
            i++;
        }
        else {
            sta.push(inp[i]-'0');
        }
    }
    while (sta.size() > 1) {
        int num2 = sta.top();
        sta.pop();
        int op = sta.top();
        sta.pop();
        int num1 = sta.top();
        sta.pop();
        if (op == -1) {
            sta.push(num1+num2);
        }
        else if (op == -2) {
            sta.push(num1-num2);
        }
    }
    return (sta.top() == 24);
}

int main() {
    int n;
    string inp;
    cin>>n;
    while (n--) {
        cin>>inp;
        if (test(inp)) {
            cout<<"Yes"<<endl;
        }
        else cout<<"No"<<endl;
    }
}