#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    	sort(nums.begin(), nums.end());
    	int cnt = 0;
    	for(int x: nums){
    		if(x<k) cnt++;
		}
		return cnt;
    }
};
int main(){
	Solution sol;
	vector<int>a = {2,11,10,1,3};
	int k = 10;
	cout<<sol.minOperations(a, k);
}