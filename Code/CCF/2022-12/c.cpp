#include <iostream>
#include <cmath>
using namespace std;

int Q[8][8], M[8][8];
double Pi = acos(-1) / 8;

void print() {
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            cout<<M[i][j]<<' ';
        }
        cout<<endl;
    }
}

double alpha(int a) {
    if (a) return 1;
    else return sqrt(0.5);
}
double beta(int i, int u) {
    return cos(Pi*u*(i+0.5));
}


int main() {
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            cin>>Q[i][j];
            M[i][j] = 0;
        }
    }
    int n ,t, count = 0, base = 0, step = 1;
    cin>>n>>t;
    for (int i = 0; i<n; i++) {
        cin>>M[count-base][base];
        // M[count-base][base] = i;
        base += step;
        if (base > count || base > 7) {
            count ++;
            step = -1;
            base = min(count, 7);
        }
        else if (base < 0 || (count > 7 && base < count-7)) {
            count ++;
            step = 1;
            base = max(0, count-7);
        }
    }
    // print();
    if (t == 0) {
        print();
        return 0;
    }
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            M[i][j]*=Q[i][j];
        }
    }
    // print();
    if (t == 1) {
        print();
        return 0;
    }
    int temp;
    double Mper[8][8];
    for (int i = 0; i<8; i++) {
        for (int j = 0; j<8; j++) {
            Mper[i][j] = 0;
            for (int u = 0; u<8; u++) {
                for (int v = 0; v < 8; v++) {
                    Mper[i][j] += alpha(u)*alpha(v)*double(M[u][v])*beta(i,u)*beta(j,v);
                }
            }
            Mper[i][j] /= 4;
            // cout<<Mper[i][j]<<' ';
            Mper[i][j] += 128.5;
            temp = Mper[i][j];
            if (temp < 0) cout<<0;
            else if (temp > 255) cout<<255;
            else cout<<temp;
            cout<<' ';
        }
        cout<<endl;
    }
}