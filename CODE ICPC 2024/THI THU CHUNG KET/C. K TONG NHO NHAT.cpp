#include <bits/stdc++.h>
using namespace std;

struct Element {
    int sum;          // Tổng của các phần tử đã chọn
    vector<int> idxs; // Vị trí các phần tử đã chọn trong từng dãy
    Element(int s, vector<int> idx) : sum(s), idxs(idx) {}
    bool operator>(const Element& other) const {
        return sum > other.sum; 
    }
};

int main() {
    int K;
    cin >> K;
    vector<vector<int>> a(K, vector<int>(K)); 
    vector<Element> ele;         
    for (int i = 0; i < K; i++) {
        for (int j = 0; j < K; j++) cin >> a[i][j];
        sort(a[i].begin(), a[i].end()); 
    }
    priority_queue<Element, vector<Element>, greater<Element>> pq;  // Priority queue để lưu phần tử theo tổng tăng dần
    vector<int> idxs(K, 0);  // idxs[i] = j: trong hàng thứ i thì phần tử thứ j được chọn
    // Tổng ban đầu là tất cả các phần tử đầu tiên của K dãy
    int sum = 0;
    for (int i = 0; i < K; i++) sum += a[i][0];
    pq.push(Element(sum, idxs)); 
    set<int> res;  
    while (res.size() < K) {
        Element cur = pq.top();  
        pq.pop();
        res.insert(cur.sum);  
        for (int i = 0; i < K; i++) {//Xét K dãy
            if (cur.idxs[i] + 1 < K) {//Nếu vị trí được chọn trong hàng thứ i chưa phải vị trí cuối
                vector<int> new_idxs = cur.idxs;
                new_idxs[i]++; //Trong hàng thứ i, dịch vị trí phần tử được chọn lên
                int new_sum = cur.sum - a[i][cur.idxs[i]] + a[i][new_idxs[i]];
                cout<<new_sum<<endl;
                pq.push(Element(new_sum, new_idxs));
            
            }
        }
    }
    for (auto it = res.begin(); it != res.end(); it++) cout << *it << " ";
}
