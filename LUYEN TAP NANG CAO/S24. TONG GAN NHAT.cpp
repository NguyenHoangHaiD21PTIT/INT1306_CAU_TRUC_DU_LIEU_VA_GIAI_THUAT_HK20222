#include <bits/stdc++.h>
using namespace std;
int main() {
    int T;
    cin >> T;
    for (int t = 0; t < T; ++t) {
        int N, M;
        cin >> N >> M;
        vector<int> A(N);
        for (int i = 0; i < N; ++i)  cin>>a[i];
        sort(A.begin(), A.end());
        int nearest_sum = INT_MIN;
        for (int i = 0; i < N - 2; ++i) {
            int left = i + 1;
            int right = N - 1;
            while (left < right) {
                int current_sum = A[i] + A[left] + A[right];
                if (current_sum <= M) {
                    nearest_sum = max(nearest_sum, current_sum);
                    left++;
                } else {
                    right--;
                }
            }
        }
        cout << nearest_sum << endl;
    }
}
