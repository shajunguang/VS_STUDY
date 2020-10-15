//拓扑排序
#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int h[MAXN],ne[MAXN],e[MAXN],w[MAXN],idx;
int C[MAXN];
bool st[MAXN],vis[MAXN];
queue<int> q;

void init()
{
    idx=0;
    memset(h,-1,sizeof h);
}
void add(int a,int b,int W){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=W;
    h[a]=idx++;
}

int main()
{
    //cout<<"hello"<<endl;
    freopen("in.txt","r",stdin);
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++){
        int U;
        cin>>C[i]>>U;
        if(C[i]>0) {
            vis[i]=true;
            q.push(i);
        }else C[i]-=U;
    }
    init();
    vector<int> g[MAXN];
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a].emplace_back(b);
        st[a]=true;
        add(a,b,w);
    }
    while(q.size()){
        int t=q.front();q.pop();
        if(C[t]<=0) continue;
        for(int j=h[t];j!=-1;j=ne[j]){
            //cout<<w[j]<<" "<<C[e[j]]<<endl;
            C[e[j]]+=w[j]*C[t];
            if(!vis[e[j]]){
                q.push(e[j]);
                vis[e[j]]=true;
            }
        }
    }
    int flag=1;
    for(int i=1;i<=n;i++){
        if(!st[i] && C[i]>0) {
            flag=0;
            cout<<i<<" "<<C[i]<<endl;
        }
    }
    if(flag) cout<<"NULL"<<endl;
    return 0;
}