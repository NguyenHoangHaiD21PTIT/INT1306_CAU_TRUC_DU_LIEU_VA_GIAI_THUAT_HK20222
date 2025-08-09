#include <bits/stdc++.h>
using namespace std;
int main(){
    int s1, s2, f1, f2;
    cin >> s1 >> s2 >> f1 >> f2;
    cout<<max(abs(s1 - f1), abs(s2 - f2));
}
