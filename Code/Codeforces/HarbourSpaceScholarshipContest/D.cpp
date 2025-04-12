#include <iostream>
#include <vector>
using namespace std;

string mat[3001];

int main() {
    int tt;
    cin>>tt;
    while (tt--) {
        int n = 0, ret = 0;
        cin>>n;
        vector<vector<int>> lf(n,vector<int>(n+1,0)), rt(n,vector<int>(n+1,0));
        for (int i = 0; i<n; i++) cin>>mat[i];
        for (int i = 0; i<n; i++) {
            int count = 0;
            for (int j = 0; j<n; j++) {
                if (i == 0);
                else if (j == 0) lf[i][j] = lf[i-1][j] + lf[i-1][j+1];
                else {
                    lf[i][j] = lf[i-1][j+1];
                    rt[i][j] += rt[i-1][j-1];
                }

                count += lf[i][j];
                if (i > 0 && j > 0) count -= rt[i-1][j-1];
                if ((count%2) ^ (mat[i][j]-'0')) {
                    lf[i][j]++;
                    rt[i][j+1]++;
                    ret++;
                }
            }
        }
        cout<<ret<<endl;
    }
}

/**
 * 首先，第一行包含一些为1的元素和一些为0的元素。
1的元素只能通过在相应的单元格上操作奇数次才能变成0，而0的元素只能通过在相应的单元格上操作偶数次才能变成0。
同一单元格上的两个操作等同于无操作，因此只对第一行中为1的元素的对应单元格执行一个操作。
因此，第一行上的操作是确定性的。
后续行会受到第一行中的操作的影响，因此继续以相同的方式考虑第2行到第n行就足够了。
现在考虑如何快速处理前一行对后一行的影响。
对位置(x，y)的操作将同时反转行x+1中从列y-1到列y+1的所有元素，以及行x+2中从列y-2到列y+2的所有元素，以此类推。
因此，被反转的元素正好是夹在通过斜率为1和-1的(x，y)的线之间的矩阵的一部分。
设b表示来自所有在前行的斜率为1的线的效果，而c表示来自所有在前行的斜率为-1的线的效果。
%为了优化复杂性，b、c都是使用与当前行的差数组获得的，使用前缀和来获得当时的b、c值。
在对(i，j)进行运算之后，b[i+1][j-1]被标记，c[i+1][j+2]被标记。
接下来，b[i][j]继承b[i-1][j+1]，c[i][j]继承c[i-1][j-1]。
对于当前行，通过维护b和c上的前缀和来获得前几行的效果。总的复杂性为O(n^2)。
*/