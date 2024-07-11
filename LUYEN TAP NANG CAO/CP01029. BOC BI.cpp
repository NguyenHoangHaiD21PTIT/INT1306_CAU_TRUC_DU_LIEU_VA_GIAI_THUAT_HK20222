#include <bits/stdc++.h>
using namespace std;
int main() {
    int a, b, c, k;
    cin>>a>>b>>c>>k;
    int x = min(a, k - 1), y = min(b, k - 1), z = min(c, k - 1);
    int res = x + y + z;
    if(a + b + c> res) res++;
    cout<<res;
}
