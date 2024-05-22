#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    string maximumOddBinaryNumber(string s) {
    	int dem0 = 0, dem1 = 0;
		for(char x: s){
			if(x=='0') dem0++;
			else dem1++;
		}
		string ans = "";
		if(dem1>1) ans = string(dem1 - 1, '1') + string(dem0, '0') + "1";
		else ans = string(dem1, '1') + string(dem0, '0');
		return ans;
    }
};
int main(){
	Solution sol;
	string s = "0101";
	cout<<sol.maximumOddBinaryNumber(s);
}