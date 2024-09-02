#include <bits/stdc++.h>
using namespace std;
const int dX[4] = {0, 0, -1, 1}; 
const int dY[4] = {-1, 1, 0, 0}; 
char raw_maze[105][105]; 
int allowed[105][105][4]; 
int visited[105][105][4]; 
int n, m; //Size maze n x m


/*1. Xem những ô nào sẽ bị laze bắn. 
Quy ước: 0 là đi thẳng, 1: sang phải, 2: xuống dưới, 3: sang trái. THEO CÁI HƯỚNG ĐÓ
Ví dụ: Đang chọc sang phải thì 0: là tiếp tục sang phải, 1: sang phải bây giờ tương đương xuống dưới theo hệ trục gốc
Vì laze ưu tiên bắn ô theo hướng nó đang đi trước, rồi nó quay vòng. 
allowed[i][j][k] = 1: ô thứ i, j đang bị bắn theo hướng thứ k DỰA TRÊN HƯỚNG LAZE CHIẾU BAN ĐẦU*/
void preprocess(){
    memset(allowed, 0, sizeof(allowed)); 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(raw_maze[i][j] == '^'){//Lên - Phải - Xuống - Trái
                for(int k = i - 1; k >= 0 && raw_maze[k][j] == '.'; k--) allowed[k][j][0] = 1;
                for(int k = j + 1; k < m && raw_maze[i][k] == '.'; k++) allowed[i][k][1] = 1;
                for(int k = i + 1; k < n && raw_maze[k][j] == '.'; k++) allowed[k][j][2] = 1;
                for(int k = j - 1; k >= 0 && raw_maze[i][k] == '.'; k--) allowed[i][k][3] = 1;
            } else if(raw_maze[i][j] == '>'){
                for(int k = i - 1; k >= 0 && raw_maze[k][j] == '.'; k--) allowed[k][j][3] = 1;
                for(int k = j + 1; k < m && raw_maze[i][k] == '.'; k++) allowed[i][k][0] = 1;
                for(int k = i + 1; k < n && raw_maze[k][j] == '.'; k++) allowed[k][j][1] = 1;
                for(int k = j - 1; k >= 0 && raw_maze[i][k] == '.'; k--) allowed[i][k][2] = 1;
            } else if(raw_maze[i][j] == 'v'){
                for(int k = i - 1; k >= 0 && raw_maze[k][j] == '.'; k--) allowed[k][j][2] = 1;
                for(int k = j + 1; k < m && raw_maze[i][k] == '.'; k++) allowed[i][k][3] = 1;
                for(int k = i + 1; k < n && raw_maze[k][j] == '.'; k++) allowed[k][j][0] = 1;
                for(int k = j - 1; k >= 0 && raw_maze[i][k] == '.'; k--) allowed[i][k][1] = 1;
            } else if(raw_maze[i][j] == '<'){
                for(int k = i - 1; k >= 0 && raw_maze[k][j] == '.'; k--) allowed[k][j][1] = 1;
                for(int k = j + 1; k < m && raw_maze[i][k] == '.'; k++) allowed[i][k][2] = 1;
                for(int k = i + 1; k < n && raw_maze[k][j] == '.'; k++) allowed[k][j][3] = 1;
                for(int k = j - 1; k >= 0 && raw_maze[i][k] == '.'; k--) allowed[i][k][0] = 1;
            }
        }
    }
}

// Hàm kiểm tra ô (y, x) có hợp lệ và có thể đi qua không
bool is_valid(int y, int x){
    if(y >= 0 && y < n && x >= 0 && x < m) return raw_maze[y][x] == '.'; 
    return false;
}

int startX, startY, goalX, goalY; // Tọa độ điểm bắt đầu và điểm đích

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for(int i = 0; i < n; i++){
            cin >> raw_maze[i];
            for(int j = 0; j < m; j++){
                if(raw_maze[i][j] == 'S'){
                    startY = i;
                    startX = j;
                    raw_maze[i][j] = '.'; 
                } else if(raw_maze[i][j] == 'G'){
                    goalY = i;
                    goalX = j;
                    raw_maze[i][j] = '.'; 
                }
            }
        }
        preprocess(); //Xem những ô nào bị bắn trước
        memset(visited, 0, sizeof(visited)); 


        //2. Thực hiện thuật toán BFS
        queue<pair<int, int>> bfs_q; 
        queue<int> dis_q; // Hàng đợi để lưu trữ khoảng cách
        visited[startY][startX][0] = 1; // Đánh dấu vị trí bắt đầu đã thăm với thời gian 0
        bfs_q.push({startY, startX});
        dis_q.push(0);
        bool found = false;
        
        // Bắt đầu thuật toán BFS
        while(!bfs_q.empty()){
            int curY = bfs_q.front().first;
            int curX = bfs_q.front().second;
            int curDis = dis_q.front();
            if(curY == goalY && curX == goalX){
                cout << curDis << endl; 
                found = true;
                break;
            }
            bfs_q.pop();
            dis_q.pop();
            //Quét qua 4 khả năng di chuyển
            for(int i = 0; i < 4; i++){
                int nextY = curY + dY[i];
                int nextX = curX + dX[i];
                if(!is_valid(nextY, nextX)) continue;//ô không đi được thì bỏ luôn
                if(allowed[nextY][nextX][(curDis + 1) % 4]) continue;//ô đấy bị laze bắn thì cũng bỏ
                if(visited[nextY][nextX][(curDis + 1) % 4]) continue;//ô đấy đã xét thì cũng bỏ
                visited[nextY][nextX][(curDis + 1) % 4] = 1;
                bfs_q.push({nextY, nextX});
                dis_q.push(curDis + 1);
            }
        }
        if(!found) cout << "impossible" << endl; 
    }
}
