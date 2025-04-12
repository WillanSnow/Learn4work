#include <iostream>
#include <memory>
using namespace std;

int main() {
    int *p = new int(1);
    unique_ptr<int> auto_p(p);

    cout<< *auto_p << endl;
}