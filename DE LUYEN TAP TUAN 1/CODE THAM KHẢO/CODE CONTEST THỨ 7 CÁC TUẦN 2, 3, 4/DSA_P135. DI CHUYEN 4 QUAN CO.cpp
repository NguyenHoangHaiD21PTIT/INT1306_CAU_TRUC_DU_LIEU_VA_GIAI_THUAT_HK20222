#include <bits/stdc++.h>

using namespace std;

const int dx[] = {0, 0, 1, -1}; // phải, trái, dưới, trên
const int dy[] = {1, -1, 0, 0};

// Kiểm tra xem một ô có nằm trong bàn cờ hay không
bool isValid(int x, int y) {
    return x >= 1 && x <= 8 && y >= 1 && y <= 8;
}

// Hàm tạo trạng thái từ vị trí mới
vector<pair<int, int>> movePiece(const vector<pair<int, int>>& pieces, int pieceIndex, int nx, int ny) {
    vector<pair<int, int>> newPieces = pieces;
    newPieces[pieceIndex] = {nx, ny};
    return newPieces;
}

// Hàm tạo trạng thái từ vị trí nhảy
vector<pair<int, int>> jumpPiece(const vector<pair<int, int>>& pieces, int pieceIndex, int nx, int ny) {
    vector<pair<int, int>> newPieces = pieces;
    newPieces[pieceIndex] = {nx, ny};
    return newPieces;
}

// Hàm kiểm tra khả năng chuyển từ trạng thái này sang trạng thái khác
bool canReach(vector<pair<int, int>> start, vector<pair<int, int>> end) {
    // Sắp xếp các quân cờ để chuẩn hóa trạng thái
    sort(start.begin(), start.end());
    sort(end.begin(), end.end());

    // Sử dụng BFS để tìm kiếm trạng thái
    queue<vector<pair<int, int>>> q;
    set<vector<pair<int, int>>> visited;

    q.push(start);
    visited.insert(start);

    while (!q.empty()) {
        vector<pair<int, int>> current = q.front();
        q.pop();

        if (current == end) {
            return true;
        }

        // Di chuyển các quân cờ
        for (int i = 0; i < 4; ++i) {
            int x = current[i].first;
            int y = current[i].second;

            for (int j = 0; j < 4; ++j) {
                int nx = x + dx[j];
                int ny = y + dy[j];

                if (isValid(nx, ny) && find(current.begin(), current.end(), make_pair(nx, ny)) == current.end()) {
                    vector<pair<int, int>> newState = movePiece(current, i, nx, ny);
                    sort(newState.begin(), newState.end()); // Sắp xếp để chuẩn hóa
                    if (visited.find(newState) == visited.end()) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
        }

        // Nhảy qua các quân cờ
        for (int i = 0; i < 4; ++i) {
            int x = current[i].first;
            int y = current[i].second;

            for (int j = 0; j < 4; ++j) {
                int nx = x + 2 * dx[j];
                int ny = y + 2 * dy[j];
                int mx = x + dx[j];
                int my = y + dy[j];

                if (isValid(nx, ny) && find(current.begin(), current.end(), make_pair(mx, my)) != current.end() &&
                    find(current.begin(), current.end(), make_pair(nx, ny)) == current.end()) {
                    vector<pair<int, int>> newState = jumpPiece(current, i, nx, ny);
                    sort(newState.begin(), newState.end()); // Sắp xếp để chuẩn hóa
                    if (visited.find(newState) == visited.end()) {
                        q.push(newState);
                        visited.insert(newState);
                    }
                }
            }
        }
    }

    return false;
}

int main() {
    vector<int> start(8), end(8);

    // Đọc dữ liệu đầu vào
    for (int i = 0; i < 8; ++i) {
        cin >> start[i];
    }
    for (int i = 0; i < 8; ++i) {
        cin >> end[i];
    }

    vector<pair<int, int>> startState(4), endState(4);

    // Tạo trạng thái xuất phát
    for (int i = 0; i < 4; ++i) {
        startState[i] = {start[i * 2], start[i * 2 + 1]};
    }

    // Tạo trạng thái đích
    for (int i = 0; i < 4; ++i) {
        endState[i] = {end[i * 2], end[i * 2 + 1]};
    }

    if (canReach(startState, endState)) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}
