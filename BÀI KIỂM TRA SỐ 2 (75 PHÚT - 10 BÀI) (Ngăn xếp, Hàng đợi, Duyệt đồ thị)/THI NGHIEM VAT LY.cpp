#include <bits/stdc++.h>
using namespace std;

string makeKey(int x, int y) {
    return to_string(x) + "," + to_string(y);
}

int main() {
    int n, stX, stY, enX, enY;
    cin >> n >> stX >> stY >> enX >> enY;

    unordered_map<int, vector<pair<int, int>>> mpX; // mpX[i] lưu những điểm có cùng hoành độ là i 
    unordered_map<int, vector<pair<int, int>>> mpY; // mpY[i] lưu những điểm có cùng tung độ là i 
    
    mpX[stX].push_back({stX, stY});
    mpY[stY].push_back({stX, stY});
    mpX[enX].push_back({enX, enY});
    mpY[enY].push_back({enX, enY});

    for (int i = 1; i <= n; ++i) {
        int x, y;
        cin >> x >> y;
        mpX[x].push_back({x, y});
        mpY[y].push_back({x, y});
    }

    int check = 0;
    queue<pair<int, int>> q;
    unordered_map<string, bool> visited;
    unordered_map<string, int> dis;

    string startKey = makeKey(stX, stY);
    string endKey = makeKey(enX, enY);

    q.push({stX, stY});
    visited[startKey] = true;
    dis[startKey] = 0;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        string scurPoint = makeKey(x, y);//Chuyển điểm thành string
        int currentDist = dis[scurPoint];//Số bước đến điểm
        if (x==enX&&y==enY){
            check = 1;
            cout<< currentDist -1;//cắt đi điểm cuối, chỉ giữ các điểm ở giữa 2 điểm đường đi
            break;
        }
        // Duyệt các điểm chung hoành độ
        for (auto [nx, ny] : mpX[x]) {
            string nextKey = makeKey(nx, ny);//Tạo string cho điểm
            if (!visited[nextKey]) {
                q.push({nx, ny});
                visited[nextKey] = true;
                dis[nextKey] = currentDist + 1;
            }
        }

        // Duyệt các điểm chung tung độ
        for (auto [nx, ny] : mpY[y]) {
            string nextKey = makeKey(nx, ny);//Tạo string cho điểm
            if (!visited[nextKey]) {
                q.push({nx, ny});
                visited[nextKey] = true;
                dis[nextKey] = currentDist + 1;
            }
        }
    }

    if(!check) cout<<-1<<endl;
}