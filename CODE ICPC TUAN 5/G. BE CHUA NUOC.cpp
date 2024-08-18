#include <bits/stdc++.h>
using namespace std;

int calculateWater(vector<int>& heights) {
    int n = heights.size();
    if (n <= 2) return 0;
    vector<int> leftMax(n), rightMax(n);
    leftMax[0] = heights[0];
    for (int i = 1; i < n; ++i) leftMax[i] = max(leftMax[i-1], heights[i]);
    rightMax[n-1] = heights[n-1];
    for (int i = n-2; i >= 0; --i) rightMax[i] = max(rightMax[i+1], heights[i]);
    int water = 0;
    for (int i = 0; i < n; ++i) water += min(leftMax[i], rightMax[i]) - heights[i];
    return water;
}

void backtrack(vector<int>& heights, int K, int index, int& maxWater) {
    if (index == heights.size() || K == 0) {
        maxWater = max(maxWater, calculateWater(heights));
        return;
    }
    backtrack(heights, K, index + 1, maxWater);
    heights[index]++;
    backtrack(heights, K - 1, index, maxWater);
    heights[index]--;
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> heights(N);
    for (int i = 0; i < N; ++i) cin >> heights[i];
    int maxWater = 0;
    backtrack(heights, K, 0, maxWater);
    cout << maxWater << endl;
}
