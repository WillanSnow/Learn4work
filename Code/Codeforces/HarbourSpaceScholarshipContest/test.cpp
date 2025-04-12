#include <iostream>
#include <vector>
using namespace std;

int main() {
    int a = 1;
    while (a != 0) {
        cout<<(14&a)<<' '<<(14&(a!=0))<<' '<<(14&a != 0)<<' '<<((14&a)!=0)<<endl;
        a<<=1;
    }
}