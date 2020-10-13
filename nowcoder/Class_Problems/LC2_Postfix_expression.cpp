#include<bits/stdc++.h>
using namespace std;

int evalRPN(vector<string>& tokens){
    stack<int> st;
    for(int i=0;i<(int)tokens.size();i++){
        if(tokens[i]!="+" && tokens[i]!="-"&&tokens[i]!="*"&&tokens[i]!="/") st.push(stoi(tokens[i]));
        else{
            if(st.size()<2) return 0;
            int t1=st.top();st.pop();
            int t2=st.top();st.pop();
            //cout<<t1<<" "<<t2<<endl;
            switch(tokens[i][0]){
                case '+':
                    st.push(t1+t2);
                    break;
                case '-':
                    st.push(t2-t1);
                    break; 
                case '*':
                    st.push(t1*t2);
                    break;
                case '/':
                    if(t1==0) return 0;
                    st.push(t2/t1);
                    break;          
            }
        }
    }
    return st.top();
}
int main()
{
    vector<string>tokens={"20","10","+","30","*"};
    cout<<evalRPN(tokens)<<endl;
    return 0;
}