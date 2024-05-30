#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin>>n>>q;
    int a[n];
    for(int i = 0;i<n;i++) cin>>a[i];
    stack<int>st;
    int r[n];
    for(int i = n - 1;i>=0;i--){
        while(!st.empty()&&a[i]>=a[st.top()]) st.pop();
        if(st.empty()) r[i] = -1;
        else r[i] = st.top();
        st.push(i);
    }
    while(q--){
        int index, buoc = 0;
        cin>>index;
        index--;
        while(r[index]!=-1){
            buoc++;
            index = r[index];
        }
        cout<<buoc<<endl;
    }
}
/*
5 5
1 3 4 2 5
1
2
3
4
5
*/
