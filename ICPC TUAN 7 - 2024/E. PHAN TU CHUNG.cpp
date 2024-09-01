#include <bits/stdc++.h>
using namespace std;

int main() {
    int K;
    cin >> K;
    vector<int> lengths(K);
    vector<set<int>> sets(K);
    for (int i = 0; i < K; ++i) cin >> lengths[i];
    for (int i = 0; i < K; ++i) {
        for (int j = 0; j < lengths[i]; ++j) {
            int num;
            cin >> num;
            sets[i].insert(num);
        }
    }
    set<int> result = sets[0]; 
    for (int i = 1; i < K; ++i) {
        set<int> temp;
        for (auto x: result) {
            if (sets[i].find(x) != sets[i].end()) temp.insert(x);
        }
        result = temp; 
    }
    if (result.empty()) cout << "NO" << endl;
    else cout << *result.begin() << endl;
}
