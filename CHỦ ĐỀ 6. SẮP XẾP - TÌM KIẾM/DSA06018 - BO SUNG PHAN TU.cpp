#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		set<int>s;
		for(int i=0;i<n;i++){
			cin>>a[i];
			s.insert(a[i]);
		}
		int l = *min_element(a,a+n);
		int r = *max_element(a,a+n);
		int s1 = r - l +1 ;//so so can co trong doan [l;r]
		int s2 = s.size();//so cac so da co trong [l;r]
		int ans = s1 - s2; //so so con thieu
		cout<<ans<<endl;
	}
}