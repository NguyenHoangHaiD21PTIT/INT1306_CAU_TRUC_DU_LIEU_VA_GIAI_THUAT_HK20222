#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<int>st;//luu vi tri cc dau mo ngoac
		for(int i = 0;i<s.size();i++){
			if(s[i]=='('){
				st.push(i);
			} else if (s[i]==')') {
				if(!st.empty()){
					int idx = st.top(); st.pop(); //vi tri dau mo ngoac tuong ung
					if(idx==0) continue; //Dau mo ngoac dau tien -->  khong can lam gi
					if(s[idx - 1]=='+') continue; //Toan tu truoc cap ngoac la + --> Khong can doi dau
					if(s[idx - 1]=='-'){ //Doi dau tu sau mo ngoac --> Truoc dong ngoac
						for(int j = idx + 1;j<=i - 1;j++){
							if(s[j]=='+') s[j] = '-';
							else if (s[j]=='-') s[j] = '+';
						}
					}
				}
			}
		}
		for(int i = 0;i<s.size();i++){
			if(s[i]!='('&&s[i]!=')') cout<<s[i];
		}
		cout<<endl;
	}
}
/*
2
a–(b+c)
a-(b-c-(d+e))-f */