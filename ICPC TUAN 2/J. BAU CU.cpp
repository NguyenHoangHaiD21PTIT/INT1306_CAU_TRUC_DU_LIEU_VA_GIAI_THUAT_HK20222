#include <bits/stdc++.h>
using namespace std;

bool compare(pair<int, int> a, pair<int, int> b){
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}

int main(){
    int n, m;
    cin >> n >> m;

    vector<int>a(n);
    int cnt[1000] = {};
    for (int i = 0; i < n; ++i){
        cin >> a[i];
        cnt[a[i]]++;
    }

    vector<pair<int, int>> count;
    for (int x : a){
        if (cnt[x]){
            count.push_back({x, cnt[x]});
            cnt[x] = 0;
        }
    }
    
    sort(count.begin(), count.end(), compare);
    int result = -1;
    for (int i = count.size() - 2; i >= 0; --i){
        if (count[i].second < count.back().second){
            result = count[i].first;
            break;
        }
    }

    if (result == -1) cout << "NONE" << endl;
    else cout << result << endl;
}
