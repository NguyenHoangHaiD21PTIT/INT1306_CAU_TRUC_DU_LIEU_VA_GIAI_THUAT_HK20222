#include<bits/stdc++.h>
using namespace std;

int d[505][505]; // d[i][j] là khoảng cách từ nguồn O đến ô i,j
int dx[4] = {-1, 0, 0, 1};
int dy[4] = {0, -1, 1, 0}; // Tương ứng sang trái, lên trên, xuống dưới, sang phải

int main(){
    int t;
    cin >> t;
    while(t--){
        int N, M;
        cin >> N >> M;
        int A[N][M];
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin >> A[i][j];
                d[i][j] = INT_MAX;
            }
        }
        d[0][0] = A[0][0]; // Chi phí tại ô đầu tiên là giá trị của ô đó

        // Sử dụng priority queue để lưu các ô cần duyệt theo thứ tự tăng dần của chi phí
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({A[0][0], {0, 0}}); // Thêm ô đầu tiên vào priority queue

        // Duyệt
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            int i = p.second.first, j = p.second.second;
            pq.pop();
            for(int k = 0; k < 4; k++){
                int i1 = i + dx[k], j1 = j + dy[k];
                // Kiểm tra xem ô kế tiếp có hợp lệ không và có thể cải thiện chi phí không
                if(i1 >= 0 && i1 < N && j1 >= 0 && j1 < M && d[i1][j1] > d[i][j] + A[i1][j1]){
                    d[i1][j1] = d[i][j] + A[i1][j1]; // Cập nhật chi phí tại ô kế tiếp
                    pq.push({d[i1][j1], {i1, j1}}); // Thêm ô này vào hàng đợi để duyệt
                }
            }
        }
        cout << d[N - 1][M - 1] << endl; // In ra chi phí nhỏ nhất từ ô (0, 0) đến ô (N - 1, M - 1)
    }
    return 0;
}