#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
    	int n = x, tong = 0;
		while(n){
			tong+=n%10;
			n/=10;
		}  
		if(x%tong==0) return tong;
		else return -1;
    }
};
int main(){
	Solution sol;
	int t = 2;
	while(t--){
		int x;
		cin>>x;
		cout<<sol.sumOfTheDigitsOfHarshadNumber(x)<<endl;
	}
}
