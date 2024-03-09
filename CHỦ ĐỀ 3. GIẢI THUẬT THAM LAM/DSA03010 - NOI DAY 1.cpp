#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		priority_queue<long long, vector<long long>, greater<long long>>q; //vector luu chieu dai nhung soi day sau khi noi
		long long ans = 0;
		while(n--){
			long long x;
			cin>>x;
			q.push(x);
		}
		while(q.size()>=2){
			long long x1 = q.top();
			q.pop();
			long long x2 = q.top();
			q.pop();
			//Tong chi phi da tang len x1+x2 & 2 day do dai x1 x2 thanh 1 day chieu dai moi = x1 + x2
			ans+=x1+x2;
			q.push(x1+x2);
		}
		cout<<ans<<endl;
	}
}