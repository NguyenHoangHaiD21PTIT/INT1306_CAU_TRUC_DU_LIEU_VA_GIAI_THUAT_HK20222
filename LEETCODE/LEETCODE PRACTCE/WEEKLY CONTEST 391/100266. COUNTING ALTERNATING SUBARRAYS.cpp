#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
     	int n = nums.size();
	    long long count = 0;
	    long long consecutive = 1; // Đếm số lượng phần tử trong dãy con liên tiếp alternating
	    
	    for (int i = 1; i < n; ++i) {
	        if (nums[i] != nums[i - 1]) consecutive++;
	        else{
	            count += consecutive * (consecutive + 1) / 2;
	            consecutive = 1;
	        }
	    }
	    // Cập nhật số dãy con liên tiếp cuối cùng nếu cần
	    count += consecutive * (consecutive + 1) / 2;
    	return count;
    }
};
int main(){
	Solution sol;
	vector<int>a = {0, 1, 1, 1};
	vector<int>b = {1, 0, 1, 0};
	cout<<sol.countAlternatingSubarrays(a)<<endl;
	cout<<sol.countAlternatingSubarrays(b)<<endl;
}