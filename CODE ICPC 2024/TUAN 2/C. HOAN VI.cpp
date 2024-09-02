#include <bits/stdc++.h>
using namespace std;

struct TrangThai {
    vector<int> P;
    int buoc;
};

bool daSapXep(const vector<int>& P) {
    for (int i = 1; i < P.size(); ++i) {
        if (P[i-1] > P[i]) return false;
    }
    return true;
}

vector<int> TH1(const vector<int>& P, int N) {//Đổi chỗ kiểu 1
    vector<int> newP = P;
    for (int i = 0; i < N; ++i) swap(newP[2*i], newP[2*i+1]);
    return newP;
}

vector<int> TH2(const vector<int>& P, int N) { //Đổi chỗ kiểu 2
    vector<int> newP = P;
    for (int i = 0; i < N; ++i) swap(newP[i], newP[i+N]);
    return newP;
}

int BFS(int N, vector<int> P) {
    queue<TrangThai> q;
    set<vector<int>> daTham;
    q.push({P, 0});
    daTham.insert(P);
    
    while (!q.empty()) {
        TrangThai hienTai = q.front();
        q.pop();
        if (daSapXep(hienTai.P)) return hienTai.buoc;
        
        vector<int> P1 = TH1(hienTai.P, N);
        if (daTham.find(P1) == daTham.end()) {
            q.push({P1, hienTai.buoc + 1});
            daTham.insert(P1);
        }
        
        vector<int> P2 = TH2(hienTai.P, N);
        if (daTham.find(P2) == daTham.end()) {
            q.push({P2, hienTai.buoc + 1});
            daTham.insert(P2);
        }
    }
    return -1;
}

int main() {
    int N;
    cin >> N;
    vector<int> P(2*N);
    for (int i = 0; i < 2*N; ++i) cin >> P[i];
    int ketQua = BFS(N, P);
    cout << ketQua;
}