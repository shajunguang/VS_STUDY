#include<bits/stdc++.h>
#define N 100005
#define M 1000005
using namespace std;

int n,m,v[N],minv[N],maxv[N];
int sa[N],ans;
queue<int> q;

struct Graph{
    int head[N],e[M],ne[M],cnt=1; //邻接表
    bool st[N];

    void add(int u,int v){
        e[cnt]=v;
        ne[cnt]=head[u];
        head[u]=cnt++;
    }

    void bfs(int s){ //能被到达or能到达 判断
        st[s]=1;q.push(s);
        while(q.size()){
            int p=q.front();q.pop();
            for(int i=head[p];i;i=ne[i]){
                int j=e[i];
                if(!st[j])
                    st[j]=1,q.push(j);
            }
        }
    }
    void mark(int s,int* a,int v){ //标记其他点信息
        a[s]=v;q.push(s);
        while(q.size()){
            int p=q.front();q.pop();
            for(int i=head[p];i;i=ne[i]){
                int j=e[i];
                if(!a[j])
                    a[j]=v,q.push(j);
            }
        }
    }
} mp,fmp; //图和反图

struct OP{ //点排序规则
    bool operator() (int a,int b) const{
        return v[a] < v[b];
    }
};

int main()
{
    freopen("in.txt","r",stdin);
    cin>>n>>m;
    int a,b,op;
    for(int i=1;i<=n;i++) cin>>v[i];

    while(m--){
        cin>>a>>b>>op;
        mp.add(a,b);
        fmp.add(b,a);
        if(op==2){ //存图
            mp.add(b,a);
            fmp.add(a,b);
        }
    }

    mp.bfs(1);fmp.bfs(n); //能被到达or能到达 执行判断
    for(int i=1;i<=n;i++) sa[i]=i;

    sort(sa+1,sa+n+1,OP());
    for(int i=1;i<=n;i++) //标记minv
        if(!minv[sa[i]] && mp.st[sa[i]]) //能被起点到达 且 没被标记
            mp.mark(sa[i],minv,v[sa[i]]);
    
    for(int i=n;i;i--) //标记maxv
        if(!maxv[sa[i]] && fmp.st[sa[i]]) //能到达终点 且没被标记
            fmp.mark(sa[i],maxv,v[sa[i]]);
    
    for(int i=1;i<=n;i++)
        if(mp.st[i] && fmp.st[i]) //存在合法路径
            ans=max(ans,maxv[i]-minv[i]); //尝试更新答案
    
    cout<<ans;
    return 0;
}