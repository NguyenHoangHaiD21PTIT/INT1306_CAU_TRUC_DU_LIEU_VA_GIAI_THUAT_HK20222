#include<bits/stdc++.h>
using namespace std;
string trai(string s){//413526
	string tmp = "";
    tmp += s[3];tmp += s[0];tmp += s[2];tmp += s[4];tmp += s[1];tmp += s[5];
    return tmp;
}
string phai(string s){//152463
	string tmp = "";
	tmp += s[0];tmp += s[4];tmp += s[1];tmp += s[3];tmp += s[5];tmp += s[2];
    return tmp;
}
int main(){
	int a[6], b[6];
	string st = "", en = "";
	for(int i = 0; i < 6; i++){
		cin >> a[i];
		st += (a[i] + '0');
	}
	for(int i = 0; i < 6;i++){
		cin >> b[i];
		en += (b[i] + '0');
	}
	if(st == en){
		cout << 0 << endl;
		return 0;	
	}
	queue<string>q;
	unordered_map<string, bool>visited;
	unordered_map<string, int>f;
	q.push(st);
	visited[st] = true;
	f[st] = 0;
	while(!q.empty()){
		string tmp = q.front();
		q.pop();
		if(tmp == en){
			cout<<f[en]<<endl;
			break;
		}
		string l = trai(tmp);
		if(!visited[l]){
			q.push(l);
			visited[l] = true;
			f[l] = f[tmp] + 1;
		}
		string r = phai(tmp);
		if(!visited[r]){
			q.push(r);
			visited[r] = true;
			f[r] = f[tmp] + 1;
		}
	}
}
