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
        pair<int, int> front = q.front();
        int x = front.first;
        int y = front.second;
        q.pop();
        
        string scurPoint = makeKey(x, y); // Chuyển điểm thành string
        int currentDist = dis[scurPoint]; // Số lần đổi hướng để đến được điểm
        
        if (x == enX && y == enY) {
            check = 1;
            cout << currentDist << endl;
            break;
        }
        
        // Duyệt các điểm chung hoành độ
        for (pair<int, int>& p : mpX[x]) {
            int nx = p.first;
            int ny = p.second;
            string nextKey = makeKey(nx, ny); // Tạo string cho điểm
            if (nx == enX && ny == enY) {
                cout << currentDist << endl;
                return 0;
            } else if (!visited[nextKey]) {
                q.push({nx, ny});
                visited[nextKey] = true;
                dis[nextKey] = currentDist + 1;
            }
        }

        // Duyệt các điểm chung tung độ
        for (pair<int, int>& p : mpY[y]) {
            int nx = p.first;
            int ny = p.second;
            string nextKey = makeKey(nx, ny); // Tạo string cho điểm
            if (nx == enX && ny == enY) {
                cout << currentDist << endl;
                return 0;
            } else if (!visited[nextKey]) {
                q.push({nx, ny});
                visited[nextKey] = true;
                dis[nextKey] = currentDist + 1;
            }
        }
    }

    if (!check) {
        cout << -1 << endl;
    }

    return 0;
}
/*
4 0 0 9 3
1 7
0 3
3 0
3 3
*/
