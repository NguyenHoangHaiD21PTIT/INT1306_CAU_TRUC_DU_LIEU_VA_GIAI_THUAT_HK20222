#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int R, C;
        cin >> R >> C;
        int a[R][C];
        int cnt = 0; // số hạt chưa nảy mầm
        queue<pair<int,int>> q;
        int d[R][C]; // số bước di chuyển ít nhất để sang ô (i, j)
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){ 
                cin >> a[i][j];
                if(a[i][j] == 1) cnt++;
                if(a[i][j] == 2){
                    q.push({i, j});
                    d[i][j] = 1;
                }
            }
        }
        int dx[4] = {-1, 0, 0, 1};
        int dy[4] = {0, -1, 1, 0}; // Tương ứng sang trái, lên trên, xuống dưới, sang phải
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int i = p.first, j = p.second;
            if(cnt == 0){
                cout << d[i][j]<< endl; // Trừ 1 vì ngày bắt đầu là ngày 0
                break;
            }
            for(int k = 0; k < 4; k++){
                int i1 = i + dx[k], j1 = j + dy[k];
                if(i1 >= 0 && i1 < R && j1 >= 0 && j1 < C && a[i1][j1] == 1){
                    a[i1][j1] = 2;
                    q.push({i1, j1});
                    d[i1][j1] = d[i][j] + 1;
                    cnt--; // Đánh dấu một hạt đã nảy mầm
                }
            }
        }
        if(cnt) cout << -1 << endl; // Nếu vẫn còn hạt chưa nảy mầm
    }
    return 0;
}