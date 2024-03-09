#include<bits/stdc++.h>
using namespace std;

int n, a[100], ok, k;

//Sinh hvi lap chap k cua n voi dk cai sau >= cai truoc
void kt(){
	for(int i=0;i<k;i++) a[i] = 1;
}

void sinh(){
	int i = k-1;
	while(i>=0&&a[i]==n) i--;
	if(i==-1){
		ok = 0;
	} else {
		a[i]++;
		for(int j=i+1;j<k;j++) a[j] = 1;
	}
}

int main(){
	char c;
	cin>>c;
	cin>>k;
	string s="";
	s = s + c;
	while(c>'A'){
		c--;
		s = c + s;
	}
	n = s.size();
	kt();
	ok=1;
	while(ok==1){
		string s1="";
		int check = 1;
		for(int i=0;i<k-1;i++){
			int val1 = a[i] - 1;
			int val2 = a[i+1]-1;
			if(s[val1]>s[val2]){
				check = 0;
				break;
			} else{
				s1 = s1 + s[val1];
			}
		}
		if(check) {
			s1 = s1 + s[a[k-1]-1];
			cout<<s1<<endl;
		}
		sinh();
	}
}