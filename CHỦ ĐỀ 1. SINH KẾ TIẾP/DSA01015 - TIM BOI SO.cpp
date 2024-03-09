#include<bits/stdc++.h>
using namespace std;

string s;
int n, ok ;
vector<string>v;//luu toan bo cac so tu 1 den 19 chu so tao tu 0 va 9

void kt(){
	s = string(n,'0');
}

void sinh(){
	int i = n-1;
	while(i>=0&&s[i]=='9'){
		s[i] = '0';
		i--;
	}
	if(i==-1){
		ok = 0;
	} else {
		s[i] = '9';
	}
}

int main(){
	n = 13;
	kt();
	ok=1;
	while(ok==1){
		v.push_back(s);
		sinh();
	}
	v.erase(v.begin());
	long long boi[600]; //boi[i] la so nho nhat gom 0 vs 9 chia het cho i
	for(int i=1;i<=500;i++){
		//Tim boi nho nhat cua moi so i
		for(auto j: v){
			long long x =stoll(j);
			if(x%i==0){
				boi[i] = x;
				break;
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		long long n;
		cin>>n;
		cout<<boi[n]<<endl;
	}
}