#include<bits/stdc++.h>
using namespace std;
string rotateLeft(string s){//413526
	string tmp = "";
    tmp += s[3];tmp += s[0];tmp += s[2];tmp += s[4];tmp += s[1];tmp += s[5];
    return tmp;
}
string rotateRight(string s){//152463
	string tmp = "";
	tmp += s[0];tmp += s[4];tmp += s[1];tmp += s[3];tmp += s[5];tmp += s[2];
    return tmp;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int a[6], b[6];
		string st = "", en = "";
		for(int i =0;i<6;i++){
			cin>>a[i];
			st+=(a[i] + '0');
		}
		for(int i =0;i<6;i++){
			cin>>b[i];
			en+=(b[i] + '0');
		}
		if(st==en){
			cout<<0<<endl;
			continue;	
		}
		//Bước 1: Khởi tạo
		queue<string>q;
		unordered_map<string, bool>visited;//visited[i] = 1 tức là trạng thái đó đã từng có
		unordered_map<string, int>f;//f[i] là số bước ít nhất để đến trạng thái i
		
		q.push(st);//Đưa cấu hình khởi tạo
		visited[st] = true;//Đánh dấu đã xét nó
		f[st] = 0;//Số bước ra cấu hình này là 0
		//Bước 2: Lặp
		while(!q.empty()){
			string tmp = q.front();
			q.pop();
			if(tmp==en){
				cout<<f[en]<<endl;
				break;
			}
			string l = rotateLeft(tmp);
			if(!visited[l]){
				q.push(l);
				visited[l] = true;
				f[l] = f[tmp] + 1;
			}
			string r = rotateRight(tmp);
			if(!visited[r]){
				q.push(r);
				visited[r] = true;
				f[r] = f[tmp] + 1;
			}
		}
	}
}