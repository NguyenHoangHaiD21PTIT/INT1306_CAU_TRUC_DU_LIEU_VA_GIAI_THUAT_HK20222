#include <algorithm>
using namespace std;

bool check(int p, const vector<int>& a) {
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] / p < a[i] / (p + 1) + 1)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i];

    int s = *min_element(a.begin(), a.end());
    int ans = 0;
    for (int i = s; i > 0; --i) {
        if (check(i, a)) {
            for (int j = 0; j < n; ++j)
                ans += a[j] / (i + 1) + 1;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}