#include <bits/stdc++.h>
using namespace std;

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

//Tìm tâm đường tròn ngoại tiếp 3 điểm A, B và C
Point circum(Point a, Point b, Point c) {
    double D = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    double x = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / D;
    double y = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / D;
    return {x, y};
}

bool check(int n, int k, vector<Point>pts) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                //Tìm tâm đường tròn ngoại tiếp 3 điểm (A, B, C)
                Point A = pts[i], B = pts[j], C = pts[l];
                Point O = circum(A, B, C); //o là tâm đường tròn ngoại tiếp 3 điểm (i, j, k)
                double r = distance(O, A); //OA là bán kính = r
                
                //Có đường tròn rồi thì xét n điểm, trừ 3 điểm được chọn. Kcach từ tâm đến điểm xét < bán kính --> Trong đường tròn
                int cnt = 0;
                for (int m = 0; m < n; m++) {
                    if (m == i || m == j || m == l) continue;
                    double d = distance(O, pts[m]);
                    if (d < r) cnt++;
                }
                if (cnt == k) return true;
            }
        }
    }
    return false;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<Point> pts(n);
        for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
        if (check(n, k, pts)) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}