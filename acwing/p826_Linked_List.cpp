//使用两个数组模拟静态链表，时间会快一些吧
#include<bits/stdc++.h>
using namespace std;
const int MAXN=100010;
int head,ne[MAXN],e[MAXN],idx; //e存储链表数值，ne存下标指向，idx下标，head存头结点下标

void init(){
    idx=0;
    head=-1; //一开始指向空链表
    memset(ne,0,sizeof ne);
    memset(e,0,sizeof e);
}
void add_head(int x){ //头插
    e[idx]=x;
    ne[idx]=head;
    head=idx++;
}
void add(int k,int x){ //下标k后面插入
    e[idx]=x;
    ne[idx]=ne[k];
    ne[k]=idx++;
}
void remove(int k){
    ne[k]=ne[ne[k]];
}

int main()
{
    freopen("in.txt","r",stdin);
    int m;cin>>m;
    init();
    while(m--){
        char c;cin>>c;
        int k,x;
        if(c=='H'){
            cin>>x;
            add_head(x);
        }else if(c=='D'){
            cin>>k;
            if(k==0) head=ne[head];
            else remove(k-1);
        }else{
            cin>>k>>x;
            add(k-1,x);
        }
    }
    for(int i=head;i!=-1;i=ne[i]){
        cout<<e[i]<<" ";
    }
    return 0;
}