#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int l[n], r[n], a[n];// Tìm Vị trí phần tử đầu tiên bên trái, bên phải a[i] bé hơn a[i]
        //l, r là cận trái, phải của HCN
        for(int i = 0;i<n;i++) cin>>a[i];
        stack<int>st1, st2;
        for(int i = n - 1;i>=0;i--){
            while(!st1.empty() && a[i] <= a[st1.top()]) st1.pop();
            if(st1.empty()) r[i] = n - 1;
            else r[i] = st1.top() - 1;
            st1.push(i);
        }
        for(int i = 0;i<n;i++){
            while(!st2.empty() && a[i] <= a[st2.top()]) st2.pop();
            if(st2.empty()) l[i] = 0;
            else l[i] = st2.top() + 1;
            st2.push(i);
        }
        int res = 0;
        for(int i = 0;i<n;i++){
            if(r[i] - l[i] + 1 >= a[i]) res=max(res, a[i]);
        }
        cout<<res<<endl;
    }
}