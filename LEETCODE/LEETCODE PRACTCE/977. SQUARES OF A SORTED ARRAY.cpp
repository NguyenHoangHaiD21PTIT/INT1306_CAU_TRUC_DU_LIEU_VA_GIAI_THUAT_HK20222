#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
    	vector<int>res;
		for(int x: nums) res.push_back(x* x);
		sort(res.begin(), res.end());
		return res;	
    }
};
int main(){
	Solution sol;
	vector<int>a = {-7,-3,2,3,11};
	vector<int>b = sol.sortedSquares(a);
	for(int x: b) cout<<x<<" ";
}