#include <bits/stdc++.h>
using namespace std;
const int dX[4] = {0, 0, -1, 1}; 
const int dY[4] = {-1, 1, 0, 0}; 
char raw_maze[105][105]; 
int allowed[105][105][4]; 
int visited[105][105][4]; 
int n, m; //Size maze n x m
/*1. Xem những ô nào sẽ bị laze bắn. 
Vì laze ưu tiên bắn ô theo hướng nó đang đi trước, rồi nó quay vòng. 
allowed[i][j][k] = 1: ô thứ i, j sẽ bị bắn vào thời điểm k mod 4 (Lí do lấy mod4 là vì hướng bắn là tuần hoàn)
Ví dụ: Laze có hướng là > thì 0s: Bắn phải, 1s: Bắn dưới, 2s: Bắn trái, 3s: Bắn lên, 4s: Lại sang phải. Do đó, ta chỉ cần biết thời điểm ấy mod 4 ra bao nhiêu thì biết khi ấy ô đó có bị bắn không*/
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
        preprocess(); //Xem mỗi ô sẽ bị bắn vào những khi nào (Không cần biết bị bắn do thằng nào, chỉ cần biết khi ấy nó có bị bắn hay không)
        memset(visited, 0, sizeof(visited)); 
        //2. Thực hiện thuật toán BFS
        queue<tuple<int, int, int>> q; // (y, x, thời điểm)
        q.push({startY, startX, 0});
        visited[startY][startX][0] = 1;
        bool found = false;
        while(!q.empty()){
            int curY, curX, curDis;
            tie(curY, curX, curDis) = q.front();
            q.pop();
            if(curY == goalY && curX == goalX){
                cout << curDis << endl; 
                found = true;
                break;
            }
            //Ta dùng BFS, nên tất cả các ô đi tới sẽ trong thời gian ngắn nhất. Bây giờ, xem nếu đi time min thế, thì có bị bắn không
            for(int i = 0; i < 4; i++){
                int nextY = curY + dY[i];
                int nextX = curX + dX[i];
                if(!is_valid(nextY, nextX)) continue; // Ô không đi được thì bỏ qua
                if(allowed[nextY][nextX][(curDis + 1) % 4]) continue; // Ô đấy bị laser bắn thì bỏ qua
                if(visited[nextY][nextX][(curDis + 1) % 4]) continue; // Ô đấy đã xét thì bỏ qua
                visited[nextY][nextX][(curDis + 1) % 4] = 1;
                q.push({nextY, nextX, curDis + 1});
            }
        }
        if(!found) cout << "impossible" << endl; 
    }
}
