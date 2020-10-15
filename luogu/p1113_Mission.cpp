//拓扑排序
/*
#include<bits/stdc++.h>
using namespace std;
int n,l,t,ans[10005],maxans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>i>>l;
        int tmp=0;
        while(cin>>t && t){
            tmp=max(ans[t],tmp);
        }
        ans[i]=tmp+l;
        maxans=max(ans[i],maxans);
    }
    cout<<maxans;
    return 0;
}
*/
