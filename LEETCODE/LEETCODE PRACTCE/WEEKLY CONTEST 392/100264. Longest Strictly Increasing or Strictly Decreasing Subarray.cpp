#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        int maxLength = 1;
        int currentLength = 1;
        bool increasing = true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
            	//Đang là dãy giảm --> set lại chiều dài là 1 bắt đầu từ nums[i - 1]
                if (!increasing) currentLength = 1;
                increasing = true;
                currentLength++;
            } else if (nums[i] < nums[i - 1]) {
            	//Đang là dãy tăng --> set lại chiều dài là 1, dãy giảm bắt đầu từ nums[i - 1]
                if (increasing) currentLength = 1;
                increasing = false;
                currentLength++;
            } else {
                currentLength = 1;
            }
            maxLength = max(maxLength, currentLength);
        }

        return maxLength;
    }
};
int main(){
	Solution sol;
	vector<int>a = {1, 4, 3, 3, 2};
	cout<<sol.longestMonotonicSubarray(a);
}