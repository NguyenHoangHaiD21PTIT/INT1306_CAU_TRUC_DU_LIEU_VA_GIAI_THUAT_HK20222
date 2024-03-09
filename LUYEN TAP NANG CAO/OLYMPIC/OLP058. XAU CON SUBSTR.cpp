#include <bits/stdc++.h> 
using namespace std; 
int main() { 
	string s, t; 
	cin>>s;
	cin.ignore();
	cin>>t; 
	int cnt = 0; //Vị trí đầu tiên xét đến của xâu thay vì là 0 đã bị tịnh tiến cnt đơn vị
	while (s.find(t) != string::npos) { 
		int idex = s.find(t); //Vị trí đầu tiên tìm ra xâu con
		cout << idex + cnt + 1 << ' '; //Vị trí đầu tiên xét lần tiếp bị đẩy cnt đơn vị nên vị trí thực tìm được phải cộng vào
		s = s.substr(idex + 1); //Tịnh tiến xâu lên 1 đơn vị so với vị trí đầu tiên tìm được
		cnt += idex + 1; 
	} 
}
		