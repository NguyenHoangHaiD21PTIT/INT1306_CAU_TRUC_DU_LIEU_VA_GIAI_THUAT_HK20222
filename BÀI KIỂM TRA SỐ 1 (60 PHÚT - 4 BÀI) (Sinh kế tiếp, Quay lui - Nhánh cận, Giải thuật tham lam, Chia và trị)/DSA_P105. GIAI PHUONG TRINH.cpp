#include <bits/stdc++.h>
using namespace std;

double f(double A, double B, double C, double x) {
    return A * x * x * x + B * x - C;
}

double solve(double A, double B, double C) {
    double left = 0, right = 1e9;
    double mid;
    while (right - left > 1e-7) {
        mid = (left + right) / 2;
        if (f(A, B, C, mid) * f(A, B, C, left) <= 0) right = mid;
        else left = mid;
    }

    return (left + right) / 2;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        double A, B, C;
        cin >> A >> B >> C;
        cout << fixed << setprecision(4) << solve(A, B, C) << endl;
    }
}