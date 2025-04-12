#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int n;
    double rate;
    cin>>n>>rate;
    rate += 1;

    int income;
    double profit = 0;
    for (int i = 0; i<=n; i++) {
        cin>>income;
        profit += income*pow(rate, -i);
        // cout<<profit;
    }
    cout<<profit<<endl;
}