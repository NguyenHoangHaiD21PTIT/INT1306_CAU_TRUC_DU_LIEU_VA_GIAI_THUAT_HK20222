#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n1, n2, n3;
		cin>>n1>>n2>>n3;
		int a[n1], b[n2], c[n3];
		for(int i=0;i<n1;i++){
			cin>>a[i];
		}
		for(int i=0;i<n2;i++){
			cin>>b[i];
		}
		for(int i=0;i<n3;i++){
			cin>>c[i];
		}
		vector<int>giao(n1+n2);
		auto g=set_intersection(a, a+n1, b, b+n2, giao.begin());
		giao.resize(g-giao.begin());
		vector<int>giao2(giao.size()+n3);
		auto g2=set_intersection(giao.begin(), giao.end(), c, c+n3, giao2.begin());
		giao2.resize(g2-giao2.begin());
		if(giao2.size()==0){
			cout<<"NO";
		} else {
			for(auto x: giao2){
				cout<<x<<" ";
			}
		}
		cout<<endl;
	}
}