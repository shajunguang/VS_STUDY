/*
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;
const int MAXN=105;
int N,K,M,S,T,dist[MAXN],culture[MAXN],dislike[MAXN][MAXN];
int h[MAXN],e[MAXN*MAXN],ne[MAXN*MAXN],w[MAXN*MAXN],idx;
bool st[MAXN],vis[MAXN];

void init(){
    idx=0;
    memset(h,-1,sizeof h);
}
void add(int a,int b,int W){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=W;
    h[a]=idx++;
}
//求1号点到n号点的最短距离，如果不存在，则返回-1
int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[S]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,S});  //first存储距离，second存储节点编号

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance=t.first;

        if(st[ver] || vis[culture[ver]]) continue;
        st[ver]=true;
        vis[culture[ver]]=true;

        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(dislike[j][ver]) continue;
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[T]==0x3f3f3f3f) return -1;
    return dist[T];
}

int main()
{
    freopen("in.txt","r",stdin);
    cin>>N>>K>>M>>S>>T;
    for(int i=1;i<=N;i++) cin>>culture[i];

    for(int i=1;i<=K;i++)
        for(int j=1;j<=K;j++)
            cin>>dislike[i][j];
    
    init();
    for(int i=0;i<M;i++){
        int a,b,w;cin>>a>>b>>w;
        if(dislike[b][a]) continue;
        add(a,b,w);
        if(!dislike[a][b]) add(b,a,w);
    }
    if(dislike[T][S] || culture[S]==culture[T]){
        cout<<-1;
        return 0;
    }
    cout<<dijkstra()<<endl;
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
int n,k,m,s,t,c[120],g[120][120],f[120][120],aa,bb,cc;
int main(){
    freopen("in.txt","r",stdin);
    cin>>n>>k>>m>>s>>t;
    for(register int i=1;i<=n;i++)
        for(register int j=1;j<=n;j++)
        	f[i][j]=21743822;
    for(register int i=1;i<=n;i++){
        cin>>c[i];
    }
    for(register int i=1;i<=k;i++){
        for(register int j=1;j<=k;j++){
            cin>>g[i][j];
        }
    }
    for(register int i=1;i<=m;i++){
        cin>>aa>>bb>>cc;
        if(!g[c[bb]][c[aa]]&&c[bb]!=c[aa])f[aa][bb]=min(f[aa][bb],cc);
        if(!g[c[aa]][c[bb]]&&c[bb]!=c[aa])f[bb][aa]=min(f[bb][aa],cc);
    }
    if(c[s]==c[t]){
        cout<<-1;
        return 0;
    }
    for(register int i=1;i<=n;i++){
        for(register int j=1;j<=n;j++){
            if(i!=j)
                for(register int k=1;k<=n;k++){
                    if(j!=k&&i!=k){
                        if(f[i][k]+f[k][j]<f[i][j]){
                            f[i][j]=f[i][k]+f[k][j];
                        }
                    }
                }
        }
    }
    if(f[s][t]==21743822)cout<<-1;
    else cout<<f[s][t];
}