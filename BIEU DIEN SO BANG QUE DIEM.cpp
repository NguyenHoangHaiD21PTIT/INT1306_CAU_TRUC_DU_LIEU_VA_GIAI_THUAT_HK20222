#include <bits/stdc++.h>
using namespace std;

//Lưu số que diêm cần thiết để tạo ra từng số
vector<int> queDiems = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};

string soLonNhat(int N, const vector<int>& M) {
    vector<string> dp(N + 1, "");//dp[i]: Số lớn nhất có thể tạo từ i que diêm

    // 1. Sắp xếp các chữ số trong M theo thứ tự giảm dần
    vector<int> sortedM = M;
    sort(sortedM.begin(), sortedM.end(), greater<int>());

    for (int i = 1; i <= N; ++i) { //Xét từng số que diêm
        for (int so : sortedM) { 
            int queDiem = queDiems[so];
            if (i >= queDiem) {// Nếu có đủ que diêm để tạo ra chữ số này
                if (i == queDiem || !dp[i - queDiem].empty()) {// Kiểm tra nếu có thể tạo ra số với số lượng que diêm hiện tại
                    string newNumber = to_string(so) + dp[i - queDiem];
                    // Cập nhật số lớn nhất cho dp[i]
                    if (dp[i].empty()) dp[i] = newNumber;
                    else {
                        if (newNumber.size() > dp[i].size()) dp[i] = newNumber;
                        else if (newNumber.size() == dp[i].size()) {
                            if (newNumber > dp[i]) dp[i] = newNumber;
                        }
                    }
                }
            }
        }
    }
    return dp[N];
}

int main() {
    int N, M_size;
    cin >> N >> M_size;
    vector<int> M(M_size);
    for (int i = 0; i < M_size; ++i) cin >> M[i];
    cout << soLonNhat(N, M) << endl;
    return 0;
}
