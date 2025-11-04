#include<bits/stdc++.h>
using namespace std;

bool valid(char a, char b){ //Cap dong mo tuong ung
	if((a == '(' && b == ')') || (a == '[' && b == ']') || (a == '{' && b == '}')) return true;
	return false;
}

bool check(string s){
	stack<char>st;
	for(char i: s){
		if(i == '(' || i == '[' || i == '{'){ //Gặp dấu mở ngoặc thì cho vào stack
			st.push(i);
		} else { //Gặp dấu đóng ngoặc
			if(st.empty()) return false;//Không có dấu mở ngoặc tương ứng
			if(valid(st.top(),i)) st.pop(); //Có dấu mở ngoặc cùng loại --> Cho cặp này ra ngoài
			else return false; //Có dấu đóng ngoặc nhưng khác loại
		}
	}
	return st.empty(); //Stack không rỗng chứng tỏ có dấu mở nhưng không có dấu dóng để ghép
}

int main(){
	int t; cin >> t;
	while(t--){
		string s; cin >> s;
		if(check(s)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}
}
/*
2
[()]{}{[()()]()}
[(]) */
