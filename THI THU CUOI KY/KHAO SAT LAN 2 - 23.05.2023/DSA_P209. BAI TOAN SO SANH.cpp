#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> ke(100005);
    int vao[100005] = {0}; // Bậc vào của mỗi đỉnh
    int dinh = 0; // Số đỉnh đồ thị - số tên phân biệt
    unordered_map<string, int> nameToNumber;
    for (int i = 0; i < N; i++) {
        string s1, s2, s3;
        cin >> s1 >> s2 >> s3;
        if (!nameToNumber.count(s1)) {
            dinh++;
            nameToNumber[s1] = dinh;
        }
        if (!nameToNumber.count(s3)) {
            dinh++;
            nameToNumber[s3] = dinh;
        }

        int numS1 = nameToNumber[s1];
        int numS3 = nameToNumber[s3];

        if (s2 == ">") {
            ke[numS1].push_back(numS3);
            vao[numS3]++;
        } else {
            ke[numS3].push_back(numS1);
            vao[numS1]++;
        }
    }

    // Thực hiện thuật toán Kahn
    queue<int> q;
    for (int i = 1; i <= dinh; i++) {
        if (vao[i] == 0) {
            q.push(i);
        }
    }

    int cnt = 0;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        cnt++;

        for (int i : ke[x]) {
            vao[i]--;
            if (vao[i] == 0) {
                q.push(i);
            }
        }
    }

    if (cnt == dinh) {
        cout << "possible" << endl;
    } else {
        cout << "impossible" << endl;
    }

    return 0;
}