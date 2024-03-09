#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		queue<int>qe;
		int q;//so truy van
		cin>>q;
		int n; 
		while(q--){
			int x; //loai truy van
			cin>>x;
			if(x==1){
				cout<<qe.size()<<endl;
			} else if (x==2){
				if(qe.size()==0){
					cout<<"YES"<<endl;
				} else {
					cout<<"NO"<<endl;
				}
			} else if (x==3) {
				cin>>n;
				qe.push(n);
			} else if (x==4){
				if(qe.size()!=0) qe.pop();
			} else if (x==5){
				if(qe.size()==0){
					cout<<-1<<endl;
				} else {
					int x = qe.front();
					cout<<x<<endl;
				}
			} else if (x==6){
				if(qe.size()==0){
					cout<<-1<<endl;
				} else {
					queue<int>copy=qe;
					vector<int>v;
					while(copy.size()!=0){
						int x = copy.front();
						copy.pop();
						v.push_back(x);
					}
					cout<<v[v.size()-1]<<endl;
				}
			}
		}
	}
}