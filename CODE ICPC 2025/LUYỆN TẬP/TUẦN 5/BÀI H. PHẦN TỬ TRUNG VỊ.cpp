#include <bits/stdc++.h>
using namespace std;

const int MAX = 1005;
int M, N, r, c;
int a[MAX][MAX], b[MAX][MAX], ps[MAX][MAX];

// Trung vị của ma trận r*c lẻ = phần tử thứ (r * c)/2 + 1
// Kiểm tra xem có tồn tại ma trận con nào có số phần tử <= x mà lớn hơn bằng STT trung vị
// --> Trung vị sẽ <= x
bool check(int x) {
    // Chuyển bảng a thành 0/1
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++){
            if(a[i][j] <= x) b[i][j] = 1;
            else b[i][j] = 0;
        }
    }
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++) ps[i][j] = b[i][j] + ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j -1 ];
    }
    int need = (r * c)/2 + 1;
    // Duyệt tất cả submatrix r*c
    // i - st + 1 = r --> st = i + 1 - r, j - st + 1 = c --> st = j + 1 - c
    for(int i = r; i <= M; i++){
        for(int j = c; j <= N; j++){
            int sum = ps[i][j] - ps[i - r][j] - ps[i][j - c] + ps[i - r][j - c];
            if(sum >= need) return true;
        }
    }
    return false;
}

int main() {
    cin >> M >> N >> r >> c;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= N; j++) cin >> a[i][j];
    }
    int l = 0, h = 1e9;
    int ans = h;
    while(l <= h){
        int mid = (l + h)/2;
        if(check(mid)){
            ans = mid;
            h = mid - 1;
        } else {
            l = mid + 1;
        }
    }
    cout << ans;
}
