#include<bits/stdc++.h>
using namespace std;

//f[0][i]表示全红
//f[1][i]表示红黄
//f[2][i]表示红黄红
int minimumOprations(const string &s){
    int n = leaves.size();
        vector<vector<int>> f(n, vector<int>(3));
        f[0][0] = (leaves[0] == 'y');
        f[0][1] = f[0][2] = f[1][2] = INT_MAX;
        for (int i = 1; i < n; ++i) {
            int isRed = (leaves[i] == 'r');
            int isYellow = (leaves[i] == 'y');
            f[i][0] = f[i - 1][0] + isYellow;
            f[i][1] = min(f[i - 1][0], f[i - 1][1]) + isRed;
            if (i >= 2) {
                f[i][2] = min(f[i - 1][1], f[i - 1][2]) + isYellow;
            }
        }
        return f[n - 1][2];
}

int main()
{

}