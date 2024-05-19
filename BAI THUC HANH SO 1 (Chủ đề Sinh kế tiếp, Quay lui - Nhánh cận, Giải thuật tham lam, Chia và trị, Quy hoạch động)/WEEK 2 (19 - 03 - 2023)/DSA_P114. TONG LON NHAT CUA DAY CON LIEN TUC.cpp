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

        // Phần tử bên phải đầu tiên lớn hơn bằng
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
/*Nếu xong bài này thì có thể luyện tập tiếp 2 bài sau trên Leetcode:
Bài 1: 907. SUM OF SUB ARRAY MINUMUMS https://leetcode.com/problems/sum-of-subarray-minimums/description/?envType=daily-question&envId=2024-01-20
Bài 2: 2104. SUM OF SUBARRAY RANGES https://leetcode.com/problems/sum-of-subarray-ranges/ */
