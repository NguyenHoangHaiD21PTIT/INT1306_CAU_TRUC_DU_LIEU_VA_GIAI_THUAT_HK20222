#include <bits/stdc++.h>
using namespace std;

int soLanBam(int N, int ST, int EN, int u, int d) {
    if (ST == EN) return 0;
    vector<bool> daTham(N + 1, false);
    queue<pair<int, int>> hangDoi; //Lưu tầng và số lần nhấn
    hangDoi.push({ST, 0});
    daTham[ST] = true;
    while (!hangDoi.empty()) {
        int tangHienTai = hangDoi.front().first;
        int soLan = hangDoi.front().second;
        hangDoi.pop();

        //Xét đích
        if(tangHienTai==EN) return soLan;

        // Lên
        int tangTiepTheo = tangHienTai + u;
        if (tangTiepTheo <= N && !daTham[tangTiepTheo]) {
            hangDoi.push({tangTiepTheo, soLan + 1});
            daTham[tangTiepTheo] = true;
        }

        // Xuống
        tangTiepTheo = tangHienTai - d;
        if (tangTiepTheo >= 1 && !daTham[tangTiepTheo]) {
            hangDoi.push({tangTiepTheo, soLan + 1});
            daTham[tangTiepTheo] = true;
        }
    }

    return -1;
}

int main() {
    int n, st, en, u, d;
    cin>>n>>st>>en>>u>>d;
    cout<<soLanBam(n, st, en, u, d);
}
