#include <bits/stdc++.h>
using namespace std;

int n, ok, a[100];
vector<pair<string, int>>v;//(Tập con, Tổng)

void kt(){
    for (int i = 0; i < n; i++) a[i] = 0;
}

void sinh(){
    int i = n - 1;
    while (i >= 0 && a[i] == 1){
        a[i] = 0;
        i--;
    }
    if (i >= 0) a[i] = 1;
    else ok = 0;
}

bool cmp(pair<string, int> a, pair<string, int> b){
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    int k; cin >> n >> k;
    int b[n];
    for (int i = 0; i < n; i++) cin >> b[i];
    kt(); ok = 1;
    while (ok){
        string s = "";
        int sum = 0;
        for (int i = 0; i < n; i++){
            if (a[i]){
                s += to_string(i + 1) + " ";
                sum += b[i];
            }
        }
        if (s != "" && sum <= k) v.push_back({s, sum});
        sinh();
    }
    sort(v.begin(), v.end(), cmp);
    if (v.size() == 0) cout << "-1";
    for (auto x: v) cout << x.first << "\n" << "Sum = " << x.second << "\n";
}
