#include <iostream>
using namespace std;

struct matrix
{
    int n, m;
    long **arr;

    matrix(int a = 0, int b = 0, bool flag = false):n(a), m(b) {
        arr = new long*[n];
        for (int i = 0; i<n; i++) {
            arr[i] = new long[m];
            for (int j = 0; j<m; j++) {
                if (flag){
                    cin>>arr[i][j];
                }
                else {
                    arr[i][j] = 0;
                }
            }
        }
    }
    ~matrix() {
        for (int i = 0; i<n; i++) {
            delete[] arr[i];
        }
        delete arr;
    }
    void transform() {
        long **newarr = new long*[m];
        for (int i = 0; i<m; i++) {
            newarr[i] = new long[n];
            for (int j = 0; j<n; j++) {
                newarr[i][j] = this->arr[j][i];
            }
        }
        for (int i = 0; i<n; i++) delete[] arr[i];
        delete[] arr;
        arr = newarr;
        
        int temp = this->n;
        this->n = this->m;
        this->m = temp;
    }
    void print() {
        for (int i = 0; i<this->n; i++) {
            for (int j = 0; j<this->m; j++) {
                cout<<this->arr[i][j]<<' ';
            }
            cout<<endl;
        }
    }
};


int main() {
    int n, d;
    cin>>n>>d;

    matrix Q(n, d, true), K(n, d, true), V(n, d, true), W(1, n, true);

    K.transform();

    matrix ans(n, n), ret(n, d);
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<n; j++) {
            for (int k = 0; k<d; k++) {
                ans.arr[i][j] += Q.arr[i][k]*K.arr[k][j];
            }
            ans.arr[i][j] *= W.arr[0][i];
        }
    }
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<d; j++) {
            for (int k = 0; k<n; k++) {
                ret.arr[i][j] += ans.arr[i][k] *V.arr[k][j];
            }
        }
    }
    ret.print();
}