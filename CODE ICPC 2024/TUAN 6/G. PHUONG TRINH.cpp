#include <bits/stdc++.h>
using namespace std;
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
                    return 0; //Vô số nghiệm
                }
            } else  s.insert(-c / b); 
        } else {
            double delta = b * b - 4 * a * c;
            if (delta < 0) continue; 
            else if (delta == 0) s.insert(-b / (2 * a));  
            else {
                s.insert((-b + sqrt(delta)) / (2 * a)); 
                s.insert((-b - sqrt(delta)) / (2 * a)); 
            }
        }
    }
    cout << s.size(); 
}
