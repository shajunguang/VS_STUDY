#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int N=1e3+10;
int m,n,h[N],ne[2*N],e[2*N],w[2*N],idx;
int dist[N],g[N][N];  //存储所有点到1号点的距离
bool st[N];

void init(){
    idx=0;
    memset(h,-1,sizeof h);
    memset(ne,0,sizeof ne);
    memset(g,0x3f,sizeof g);
}
void add(int a,int b,int f){
    e[idx]=b;
    ne[idx]=h[a];
    w[idx]=f;
    h[a]=idx++;
}

int dijkstra()
{
    memset(dist,0x3f,sizeof dist);
    dist[1]=0;
    priority_queue<PII,vector<PII>,greater<PII>> heap;
    heap.push({0,1});  //first存储距离，second存储节点编号

    while(heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance=t.first;

        for(int i=1;i<=n;i++)
            printf("%d ",dist[i]);
        printf("\n");

        if(st[ver]) continue;
        st[ver]=true;

        for(int i=h[ver];i!=-1;i=ne[i]){
            int j=e[i];
            if(dist[j]>distance+w[i]){
                dist[j]=distance+w[i];
                heap.push({dist[j],j});
            }
        }
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

//朴素方法
int dijkstra1()
{
    memset(dist, 0x3f,sizeof dist);
    dist[1]=0;

    for(int i=0;i<n-1;i++)
    {
        int t=-1; //在还未确定最短路的点中，寻找距离最小的点

        for(int j=1;j<=n;j++)
            if(!st[j] && (t==-1 || dist[t]>dist[j]))
                t=j;

        //用t更新其他点的距离
        for(int j=1;j<=n;j++)
            dist[j]=min(dist[j],dist[t]+g[t][j]);
        
        st[t]=true;

        for(int i=1;i<=n;i++)
            printf("%d ",dist[i]);
        printf("\n");
    }
    if(dist[n]==0x3f3f3f3f) return -1;
    return dist[n];
}

int main()
{
    freopen("in.txt","r",stdin);
    cin>>m>>n;
    init();
    for(int i=0;i<m;i++){
        int a,b,w;
        cin>>a>>b>>w;
        g[a][b]=w;
        add(a,b,w);
    }
    int res=dijkstra1();
    if(res==-1) cout<<"No exsit shortest path!"<<endl;
    else cout<<res<<endl;
    return 0;
}