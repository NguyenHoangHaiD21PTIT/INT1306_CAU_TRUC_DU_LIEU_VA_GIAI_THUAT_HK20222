#include <bits/stdc++.h>
using namespace std;

const double EPS = 1e-9; // Sai số nhỏ để so sánh số thực

struct Point {
    double x, y;
};

double distance(Point a, Point b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

// Tìm tâm đường tròn ngoại tiếp 3 điểm A, B và C
Point circum3(Point a, Point b, Point c) {
    double D = 2 * (a.x * (b.y - c.y) + b.x * (c.y - a.y) + c.x * (a.y - b.y));
    if (abs(D) < EPS) return {0, 0}; // Nếu 3 điểm thẳng hàng, thì không có tâm luôn
    double x = ((a.x * a.x + a.y * a.y) * (b.y - c.y) + (b.x * b.x + b.y * b.y) * (c.y - a.y) + (c.x * c.x + c.y * c.y) * (a.y - b.y)) / D;
    double y = ((a.x * a.x + a.y * a.y) * (c.x - b.x) + (b.x * b.x + b.y * b.y) * (a.x - c.x) + (c.x * c.x + c.y * c.y) * (b.x - a.x)) / D;
    return {x, y};
}

// Tìm tâm đường tròn đi qua 2 điểm A và B
Point circum2(Point a, Point b) {
    double x = (a.x + b.x) / 2.0, y = (a.y + b.y) / 2.0;
    return {x, y};
}

// Kiểm tra xem có đường tròn nào đi qua 2 điểm mà chứa cả n điểm đã cho không
double check2(int n, vector<Point> &pts) {
    double ans = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            Point A = pts[i], B = pts[j];
            Point O = circum2(A, B); // Tâm đường tròn đi qua A và B
            double r = distance(O, A); // Bán kính đường tròn

            // Kiểm tra các điểm còn lại
            bool valid = true;
            for (int m = 0; m < n; m++) {
                if (distance(O, pts[m]) > r) { // Kiểm tra với sai số EPS
                    valid = false;
                    break;
                }
            }
            if (valid) ans = min(ans, r);
        }
    }
    return ans;
}

// Kiểm tra đường tròn qua 3 điểm
double check3(int n, vector<Point> &pts) {
    double ans = 1e18;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int l = j + 1; l < n; l++) {
                Point A = pts[i], B = pts[j], C = pts[l];
                Point O = circum3(A, B, C); // Tâm đường tròn ngoại tiếp 3 điểm
                double r = distance(O, A); // Bán kính

                // Kiểm tra các điểm còn lại
                bool valid = true;
                for (int m = 0; m < n; m++) {
                    if (distance(O, pts[m]) > r + EPS) { // Kiểm tra với sai số EPS
                        valid = false;
                        break;
                    }
                }
                if (valid) ans = min(ans, r);
            }
        }
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    vector<Point> pts(n);
    for (int i = 0; i < n; i++) cin >> pts[i].x >> pts[i].y;
    double ans = 1e18;
    ans = min(ans, check2(n, pts));
    ans = min(ans, check3(n, pts));
    cout << fixed << setprecision(6) << ans << endl;
}
