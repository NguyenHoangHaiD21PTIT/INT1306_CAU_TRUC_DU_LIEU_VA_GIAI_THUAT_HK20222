#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
    	priority_queue<long long, vector<long long>, greater<long long>>pq;    
    	for(int x: nums) pq.push(x);
    	int cnt = 0;
    	while(pq.size()>=2){
    		int x1 = pq.top(); pq.pop();
    		int x2 = pq.top(); pq.pop();
    		if (x1>=k) return cnt;
    		pq.push(x1 * 2 + x2);
    		cnt++;
		}
		return cnt;
    }
};
int main(){
	Solution sol;
	vector<int>a = {1,1,2,4,9};
	int k = 20;
	cout<<sol.minOperations(a, k);
}