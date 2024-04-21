#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i<n;i++) cin>>arr[i];
        stack<int> st; // Sử dụng để tìm phần tử đầu tiên bên trái < phần tử hiện tại
        vector<int> left(n), right(n, n);

        // Phần tử bên trái đầu tiên lớn hơn
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        // Reset stack 
        while (!st.empty()) st.pop();

        // Phần tử bên phải đầu tiên nhỏ hơn
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();  
            if (st.empty()) right[i] = n;   
            else right[i] = st.top();
            st.push(i);
        }
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (arr[i]) * (i - left[i]) * (right[i] - i);
        }
        cout<<sum<<endl;
    }
}