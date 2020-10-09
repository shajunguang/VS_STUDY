#include<bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x):val(x),next(NULL){}
};

bool hasCycle(ListNode *head){
    if(!head || !head->next) return false;
    auto slow=head;
    auto fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast) return true;
    }
    return false;
}

int main()
{
    ListNode* head=new ListNode(0);
    auto nxt=head;
    for(int i=1;i<=5;i++){
        auto tmp=new ListNode(i);
        nxt->next=tmp;nxt=tmp;
    }
    nxt->next=head;
    if(hasCycle(head)) cout<<"True"<<endl;
    else cout<<"False"<<endl;
    return 0;
}