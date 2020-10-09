#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > res;
        dfs(res, S, 0, vector<int>());
        return res;
    }

    void dfs(vector<vector<int> > &res, vector<int> &S, int idx, vector<int> tmp) {
        if (idx > S.size() - 1) { sort(tmp.begin(), tmp.end()); res.push_back(tmp); return; }
        dfs(res, S, idx+1, tmp);
        tmp.push_back(S[idx]);
        dfs(res, S, idx+1, tmp);
    }
};
int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> res;
    Solution r;
    res=r.subsets(nums);
    for(auto &i:res){
        for(auto j:i) cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}