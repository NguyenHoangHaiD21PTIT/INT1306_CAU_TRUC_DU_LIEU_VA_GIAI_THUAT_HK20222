#include<bits/stdc++.h>
using namespace std;

int calc(int x, int y, char z){//x, y: toan tu, z: toan hang
	if(z=='+') return x + y;
	else if (z=='-') return x - y;
	else if (z=='*') return x * y;
	else return x / y;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		stack<int>st;
		for(int i = s.size()-1;i>=0;i--){
			if(isdigit(s[i])){//Toan hang thi push
				int x = s[i] - '0';
				st.push(x);
			} else { //Toan tu thi loi 2 phan tu dinh stack ra tinh, tinh xong -> toan hang to hon --> push
				int x1 = st.top(); st.pop();
				int x2 = st.top(); st.pop();
				int x3 = calc(x1, x2, s[i]);
				st.push(x3);
			}
		}
		cout<<st.top()<<endl;
	}
}
/*
2
-+8/632
-+7*45+20 */