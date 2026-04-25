#include <bits/stdc++.h>
using namespace std;

int p[100005], s[100005];

int find (int x){
    if (x == p[x]) return x;
    return p[x] = find(p[x]);
}

bool join (int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    if (s[x] < s[y]) swap(x, y);
    p[y] = x; s[x] += s[y];
    return true;
}

int main(){
    int t; cin >> t;
    while (t--){
        int n, m; 
        cin >> n >> m;
        for (int i = 1; i <= n; i++){
            p[i] = i;
            s[i] = 1;
        }
        vector <pair <int, int>>e;
        while (m--){
            int x, y;
            cin >> x >> y;
            e.push_back ({x, y});
        }
        string check = "NO";
        for(auto x: e){
            if (!join (x.first, x.second)){
                check = "YES";
                break;
            }
        }
        cout << check << endl;
    }
}
