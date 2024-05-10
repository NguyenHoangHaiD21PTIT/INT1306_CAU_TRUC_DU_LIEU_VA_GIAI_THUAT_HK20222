#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<string>v;

void gen() {
	queue<string>q;
	q.push("6");
	q.push("8");
	while (1) {
		//Lấy đỉnh qe
		string top = q.front();
		q.pop();
		//Tạo xâu đảo ngược
		string tmp = top;
		reverse(tmp.begin(), tmp.end());
		//Xâu mới được tạo thành từ xâu đầu và đảo xâu đó
		string x = "";
		x += top + tmp;
		if (x != "68" && x != "86") v.push_back(x);
		if (v.size() > 10000) break;
		q.push(top + "6");
		q.push(top + "8");
	}
}

int main(){
	gen();
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		for (int i = 0; i < n; i++) cout << v[i] << " ";
		cout << endl;
	}
}
