#include<bits/stdc++.h>
using namespace std;

string res(string s){ //Ham pha dau ngoac tuong ung
	stack<int>st;//luu vi tri cac dau mo ngoac
	for(int i = 0;i<s.size();i++){
		if(s[i]=='('){
			st.push(i);
		} else if (s[i] ==')') {
			if(!st.empty()){
				int idx = st.top(); st.pop();//Vi tri dau mo ngoac tuong ung
				if(idx == 0 ) continue; //Dau mo ngoac dau tien --> khong can lam gi
				if(s[idx - 1] == '+') continue;//Toan tu truoc dau ngoac la + --> Khong can doi dau
				if(s[idx - 1] == '-'){ //Toan tu truoc dau ngoac la tru -> Doi het dau tu sau mo ngoac --> Truoc dong ngoac
					for(int j = idx + 1;j<=i-1;j++){
						if(s[j]=='+') s[j] = '-';
						else if (s[j]=='-') s[j] = '+';
					}
				}
			}
		}
	}
	string tmp = "";
	for(char i: s){
		if(i!='('&&i!=')') tmp+=i;
	}
	return tmp;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string a, b;
		cin>>a>>b;
		string x1 = res(a);
		string x2 = res(b);
		if(x1==x2) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}
