#include <bits/stdc++.h>
using namespace std;
double myRound(double a) {
    return round(a * 1e6) / 1e6;
}
int main() {
    int t;
    cin >> t;
    set<double> s; 
    while (t--) {
        double a, b, c;
        cin >> a >> b >> c;
        if (a == 0) { 
            if (b == 0) { 
                if (c != 0) continue; 
                else {
                    cout << -1;
                    return 0; // Vô số nghiệm
                }
            } else {
                s.insert(myRound(-c / b)); 
            }
        } else {
            double delta = b * b - 4 * a * c;
            if (delta < 0) continue; 
            else if (delta == 0) {
                s.insert(myRound(-b / (2 * a)));  
            } else {
                s.insert(myRound((-b + sqrt(delta)) / (2 * a))); 
                s.insert(myRound((-b - sqrt(delta)) / (2 * a))); 
            }
        }
    }
    cout << s.size(); 
}

