#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		queue<pair<int,int>>q; //luu trang thai cua so n va so buoc bien doi da thuc hien
		q.push({n,0});
		set<int>s;//danh dau xem so bien doi ay da tung co hay chua
		s.insert(n);
		while(1){
			pair<int,int>p = q.front();
			q.pop();
			if(p.first==1){
				cout<<p.second<<endl;
				break;
			}
			if(p.first > 1 && !s.count(p.first - 1)){
				q.push({p.first - 1, p.second + 1});//tru n di 1 va cong them 1 buoc
				s.insert(p.first - 1); //danh dau so nay da xuat hien
			}
			//Duyet tat ca cac uoc nguyen to > can(so dinh bien doi)
			for(int i = sqrt(p.first);i>=2;i--){
				if(p.first%i==0){ //uoc be la i, uoc to la n/i
					if(!s.count(p.first/i)){
						q.push({p.first/i, p.second + 1});
						s.insert(p.first/i);
					}
				}
			}
		}
	}
}