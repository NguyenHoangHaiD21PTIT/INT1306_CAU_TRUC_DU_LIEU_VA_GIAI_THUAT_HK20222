#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>arr(n);
        for(int i = 0;i < n; i++) cin >> arr[i];
        stack<int> st; // Sử dụng để tìm phần tử đầu tiên bên trái < phần tử hiện tại
        vector<int> left(n), right(n, n);
        // Phần tử bên trái đầu tiên lớn hơn
        for (int i = 0; i < n; i++) {
            while (!st.empty() && arr[st.top()] < arr[i]) st.pop();
            if (st.empty()) left[i] = -1;
            else left[i] = st.top();
            st.push(i);
        }
        // Reset stack 
        while (!st.empty()) st.pop();
        // Phần tử bên phải đầu tiên lớn hơn bằng
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && arr[st.top()] <= arr[i]) st.pop();  
            if (st.empty()) right[i] = n;   
            else right[i] = st.top();
            st.push(i);
        }
        long sum = 0;
        for (int i = 0; i < n; i++) {
            sum += (long long) (arr[i]) * (i - left[i]) * (right[i] - i);
        }
        cout<<sum<<endl;
    }
}
/* Ví dụ: Dãy 2 1 2
- Nếu giữ dấu bằng cả 2 phía thì
i 0 1 2
left  -1 0 -1 
right 3 2 3 
Xét phần tử a[0]. Chọn điểm đầu từ 0 đến 0, 1 cách. Chọn điểm cuối từ 0 đến 2, 3 cách. Ta có 3 dãy: [0, 0], [0, 1], [0, 2]
Xét phần tử a[2]. Chọn điểm đầu từ 2 đến 0, 3 cách. Chọn điểm cuối từ 2 đến 2, 1 cách. Ta có 3 dãy: [0, 2], [1, 2], [2, 2]
Như vậy là trùng nhau do dãy [0, 2] bị tính 2 lần
- Nếu bỏ dấu bằng cả 2 phía thì
left -1 0 0 
right 2 2 3 
Xét phần tử a[0]. Chọn điểm đầu từ 0 đến 0, 1 cách. Chọn điểm cuối từ 0 đến 1, 2 cách. Ta có 2 dãy: [0, 0], [0, 1]
Xét phần tử a[2]. Chọn điểm đầu từ 2 đến 1, 2 cách. Chọn điểm cuối từ 2 đến 2, 1 cách. Ta có 2 dãy: [1, 2], [2, 2]
Hụt mất dãy [0, 2]
*/
