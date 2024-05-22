#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isIsomorphic(string s, string t) {
    	if(s.size()!=t.size()) return false;
    	unordered_map<char, char>mp_s, mp_t;
		for(int i = 0;i<s.size();i++){
			if(!mp_s.count(s[i])&&!mp_t.count(t[i])){
				mp_s[s[i]] = t[i];
				mp_t[t[i]] = s[i];
			} else {
				if(mp_s[s[i]]!=t[i]||mp_t[t[i]]!=s[i]) return false;
			}
		}
		return true;
    }
};
int main(){
	Solution sol;
	int t = 3;
	while(t--){
		string s, t;
		cin>>s>>t;
		if(sol.isIsomorphic(s, t)) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
/*egg add
foo bar
paper title*/