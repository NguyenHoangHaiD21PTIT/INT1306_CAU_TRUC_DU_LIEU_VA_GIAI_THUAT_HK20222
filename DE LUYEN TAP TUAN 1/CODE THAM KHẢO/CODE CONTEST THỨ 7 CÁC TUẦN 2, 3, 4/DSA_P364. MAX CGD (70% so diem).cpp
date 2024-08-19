#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    int a[n+5];
    for (int i = 1; i <= n; i++) cin >> a[i];
    int tong = 0; 
    for(int i = 1;i<=n;i++) tong+=a[i];
    vector<int> uoc;
    for (int i = 1; i * i <= tong; i++) {
        if (tong % i == 0) {
            uoc.push_back(i);
            if (i * i != tong) uoc.push_back(tong / i);
        }
    }
    sort(uoc.begin(), uoc.end(), greater<int>()); // Sắp xếp các ước số theo thứ tự giảm dần
    pair<int, int>v[n + 2];
    for (int x : uoc) {
        for(int i = 1;i<=n;i++) v[i] = {a[i]%x, x - (a[i]%x)};
        sort(v + 1,v + n + 1);
        int du[500] = {}, thieu[500] = {};
        for(int i = 1;i<=n;i++){
            du[i] = du[i - 1] + v[i].first;
            thieu[i] = thieu[i - 1] + v[i].second;
        }
        for(int i = 1;i<=n;i++){
            if(du[i]==thieu[n]-thieu[i]&&du[i]<=k){
                cout<<x;
                return 0;
            }
        }
    }
}
