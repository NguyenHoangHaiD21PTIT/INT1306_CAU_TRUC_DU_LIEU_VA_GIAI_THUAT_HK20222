#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++) cin>>a[i];
		//Voi moi buoc, ta xet cac cap so ke nhau den vi tri so dau tien chua duoc sx.
		//Buoc thu i se co i so duoc day ve sau
		vector<string>v;
		for(int i=0;i<n;i++){ //Buoc thu i
			int check = 0; //check = 1 tuc la buoc nay can sx
			for(int j=0;j<n - i - 1;j++){
				if(a[j]>a[j+1]){
					check = 1;
					swap(a[j],a[j+1]);
				}
			}
			if(check==1){
				string s = "";
				for(int i=0;i<n;i++) s = s + to_string(a[i]) + " ";
				v.push_back(s);
			} else {
				break;
			}
		}
		for(int i=v.size()-1;i>=0;i--) cout<<"Buoc "<<i+1<<": "<<v[i]<<endl;
	}
}