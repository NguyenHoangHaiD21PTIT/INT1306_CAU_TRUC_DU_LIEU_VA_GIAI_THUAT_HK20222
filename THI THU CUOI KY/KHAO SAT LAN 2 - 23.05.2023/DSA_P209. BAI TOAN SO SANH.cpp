#include <bits/stdc++.h>
using namespace std;
int main() {
    int N;
    cin >> N;
    vector<int>ke[100005];
    int vao[100005] = {0}; // Bậc vào của mỗi đỉnh
    int dinh = 0; // Số đỉnh đồ thị - số tên phân biệt
    unordered_map<string, int> id;//id[x] = a: Thằng tên là x sẽ có mã là a
    for (int i = 0; i < N; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (!id.count(s1)) {
            dinh++;
            id[s1] = dinh;
        }
        if (!id.count(s3)) {
            dinh++;
            id[s3] = dinh;
        }
        if (s2 == ">") {
            ke[id[s1]].push_back(id[s3]);
            vao[id[s3]]++;
        } else {
            ke[id[s3]].push_back(id[s1]);
            vao[id[s1]]++;
        }
    }
    // Thực hiện thuật toán Kahn
    queue<int> q;
    for (int i = 1; i <= dinh; i++) {
        if (vao[i] == 0) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;
        for (int i : ke[x]) {
            vao[i]--;
            if (vao[i] == 0) q.push(i);
        }
    }
    if (cnt == dinh) cout << "possible";
    else cout << "impossible" << endl;
}
