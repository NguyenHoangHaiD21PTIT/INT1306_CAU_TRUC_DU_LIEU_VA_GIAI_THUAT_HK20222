#include<bits/stdc++.h>
using namespace std;
int main(){
	int s, n;//s: tong chu so, n: so chu so
	cin>>n>>s;
	if(s>9*n||s==0&&n>=2){
		cout<<"-1 -1";
	} else {
		vector<int>max(n);
		vector<int>min(n);
		int tmp = s;
		tmp--;
		for(int i=0;i<n;i++){
			if(s>=9){
				max[i]=9;
				s-=9;
			} else if (s!=0) {
				max[i]=s;
				s=0;
			} else {
				max[i]=s;
			}
		}
		for(int i = n-1;i>0;i--){
			if(tmp>=9){
				min[i]=9;
				tmp-=9;
			} else if (tmp!=0) {
				min[i]=tmp;
				tmp = 0;
			} else {
				min[i]=tmp;
			}
		}
		min[0]=tmp+1;
		for(auto i: min){
			cout<<i;
		}
		cout<<" ";
		for(auto i: max){
			cout<<i;
		}
	}
}