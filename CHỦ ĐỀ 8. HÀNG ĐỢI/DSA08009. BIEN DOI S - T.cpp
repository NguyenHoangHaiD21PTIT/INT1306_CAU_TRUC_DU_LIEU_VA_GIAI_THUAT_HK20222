#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	cin>>T;
	while(T--){
		int s, t;
		cin>>s>>t;
		queue<pair<int,int>>q; //Hnag doi luu trang thai cua so s va so buoc bien doi da lam
		q.push({s, 0});
		set<int>si; //de xem la so s sau bien doi da co tu lan truoc hay chua
		si.insert(s);
		while(1){
			pair<int,int>p = q.front();
			q.pop();
			if(p.first==t){
				cout<<p.second<<endl;
				break;
			}
			if(p.first>1&&!si.count(p.first - 1)){
				q.push({p.first - 1, p.second + 1});
				si.insert(p.first - 1);
			}
			if(p.first < t &&!si.count(p.first * 2)){
				q.push({p.first * 2, p.second + 1});
				si.insert(p.first * 2);
			}
		}
	}
}