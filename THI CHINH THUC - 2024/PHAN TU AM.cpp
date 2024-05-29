#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        deque<int> dq;

        //xử lý cửa sổ đầu tiên
        for(int i = 0; i < k; i++){
            if(a[i] < 0) dq.push_back(i);
        }

        if(!dq.empty()) cout << a[dq.front()] << " ";
        else cout << "0 ";

        //Xử lý các cửa sổ kết thúc tại vị trí i
        for(int i = k; i < n; i++){
            //Loại phần tử âm đầu tiên ở đầu hàng đợi nếu nó k thuộc cửa sổ
            if(!dq.empty() && dq.front() <= i - k) dq.pop_front();
            if(a[i] < 0) dq.push_back(i);
            if(!dq.empty()) cout << a[dq.front()] << " ";
            else cout << "0 ";
        }
        cout << endl;
    }
    return 0;
}