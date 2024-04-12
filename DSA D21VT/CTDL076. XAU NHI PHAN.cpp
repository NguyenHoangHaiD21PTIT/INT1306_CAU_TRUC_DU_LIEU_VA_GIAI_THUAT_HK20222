#include <bits/stdc++.h>
using namespace std;

long long trans(string s){
    long long tong = 0;
    reverse(s.begin(),s.end());
    for(int i=0;i<s.size();i++){
        if(s[i]=='1') tong+=pow(2,i);
    }
    return tong;
}

void decToBin(long long x, int n){
    stack<int>st;
    while(x){
        st.push(x%2);
        x/=2;
    }
    while(st.size() < n){
        st.push(0); // Thêm số 0 ở đầu để đảm bảo đủ n bits
    }
    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        long long k;
        cin>>n>>k;
        string s;
        cin>>s;
        long long soCu = trans(s);
        long long soMoi = (soCu + k + 1) % (1LL << n); // Sử dụng toán tử dịch bit thay vì pow(2, n)
        decToBin(soMoi, n); // Chuyển về nhị phân và in ra, đảm bảo in đủ n bits
        cout<<endl;
    }
    return 0;
}
/*
2
3 5
010
10 1000
1010101010 */