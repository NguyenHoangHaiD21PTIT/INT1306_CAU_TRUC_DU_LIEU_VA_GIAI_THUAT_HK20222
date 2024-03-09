#include<bits/stdc++.h>
using namespace std;

int a[1005][1005], visited[1005][1005], n;

int dx[2] = {1,0};
int dy[2] = {0,1};
string s = "";

string change(string s){
	if(s=="000") return "0";
	if(s=="001") return "1";
	if(s=="010") return "2";
	if(s=="011") return "3";
	if(s=="100") return "4";
	if(s=="101") return "5";
	if(s=="110") return "6";
	return "7";
}

string change2(string s){ //bin to oct
	while(s.size()%3!=0) s = "0" + s;
	string res1 ="";
	for(int i = 0;i<s.size();i+=3){
		string tmp = "";
		tmp = tmp + s[i] + s[i + 1] + s[i + 2];
		res1 += change(tmp);
	}
	int i = 0;
	while(res1[i] == 0){
		res1.erase(res1[i]);
		i++;
	}
	return res1;
}

bool cmp(string a, string b){
	if(a.size()!=b.size()) return a.size()<b.size();
	return a<b;
}

vector<string>v;

void Try(int i, int j){
	if(i==n-1&&j==n-1){
		v.push_back(change2(s));
	}
	for(int k=0;k<2;k++){
		int i1 = i + dx[k];
		int j1 = j + dy[k];
		if(i1>=0&&i1<=n-1&&j1>=0&&j1<=n-1&&visited[i1][j1]==0){
			s+=to_string(a[i1][j1]);
			visited[i1][j1] = 1;
			Try(i1,j1);
			visited[i1][j1] =  0 ;
			s.pop_back();	
		}
	}
} 

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j = 0;j<n;j++) cin>>a[i][j];
	}
	s+=to_string(a[0][0]);
	visited[0][0] = 1;
	Try(0,0);
	sort(v.begin(), v.end(), cmp);
	cout<<v[0];
} 
