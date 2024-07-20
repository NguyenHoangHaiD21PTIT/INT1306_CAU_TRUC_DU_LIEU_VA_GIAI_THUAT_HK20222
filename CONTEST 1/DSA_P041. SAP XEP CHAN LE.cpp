#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int a[n], d[n] = {0};
    vector<int> chan, le;
    
    for (int i = 0; i < n; ++i) cin >> a[i];
    
    // Phân loại số chẵn, lẻ và đánh dấu đâu là vị trí có số chẵn
    for (int i = 0; i < n; ++i) {
        if (a[i] % 2 == 1) {
            le.push_back(a[i]);
            d[i] = 1;
        } else {
            chan.push_back(a[i]);
            d[i] = 0;
        }
    }
    
    // Sắp xếp chẵn TĂNG lẻ giảm
    sort(chan.begin(), chan.end());
    sort(le.begin(), le.end(), greater<int>());
    
    // In theo đề
    int chan_index = 0, le_index = 0;
    for (int i = 0; i < n; ++i) {
        if (d[i] == 0) {
            cout << chan[chan_index++] << " ";
        } else {
            cout << le[le_index++] << " ";
        }
    }
    
    return 0;
}
