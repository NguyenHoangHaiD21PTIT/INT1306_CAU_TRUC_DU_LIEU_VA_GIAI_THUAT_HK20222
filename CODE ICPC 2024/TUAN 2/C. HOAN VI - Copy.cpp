#include <bits/stdc++.h>
using namespace std;

bool daSapXep(const vector<int>& P) {
    for (int i = 1; i < P.size(); ++i) {
        if (P[i-1] > P[i]) return false;
    }
    return true;
}

vector<int> TH1(const vector<int>& P, int N) { // Đổi chỗ kiểu 1
    vector<int> newP = P;
    for (int i = 0; i < N; ++i) swap(newP[2*i], newP[2*i+1]);
    return newP;
}

vector<int> TH2(const vector<int>& P, int N) { // Đổi chỗ kiểu 2
    vector<int> newP = P;
    for (int i = 0; i < N; ++i) swap(newP[i], newP[i+N]);
    return newP;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(2*N);
    for (int i = 0; i < 2*N; ++i) cin >> P[i];
    // Trường hợp 1: Bắt đầu với thao tác 1 trước
    vector<int> P1 = P;
    int buoc1 = 0;
    while (buoc1 <= 2*N && !daSapXep(P1)) {
        if (buoc1 % 2 == 0) P1 = TH1(P1, N);
        else P1 = TH2(P1, N);
        buoc1++;
    }
    if (!daSapXep(P1)) buoc1 = INT_MAX; 

    // Trường hợp 2: Bắt đầu với thao tác 2 trước
    vector<int> P2 = P;
    int buoc2 = 0;
    while (buoc2 <= 2*N && !daSapXep(P2)) {
        if (buoc2 % 2 == 0) P2 = TH2(P2, N);
        else P2 = TH1(P2, N);
        buoc2++;
    }
    if (!daSapXep(P2)) buoc2 = INT_MAX; 

    int ketQua = min(buoc1, buoc2);
    if (ketQua == INT_MAX) ketQua = -1;
    cout << ketQua;
}
