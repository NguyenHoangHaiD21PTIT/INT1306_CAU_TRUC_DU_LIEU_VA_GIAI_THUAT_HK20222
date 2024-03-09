#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	while(t--){
		int k;
		cin>>k;
		string s;
		cin>>s;
		//Buoc 1: dem tan suat xuat hien moi loai ki tu
		map<char, int>mp;
		for(char x: s) mp[x]++;
		//Buoc 2: Day tan suat vao hang doi uu tien
		priority_queue<long long>freq; 
		for(auto i: mp) freq.push(i.second);
		//Buoc 3: Tap trung xoa nhung phan tu co tan suat cao nhat. Sau moi mot lan xoa thi lai phai xem dau la cai lon nhat
		while(k--){
			long long x = freq.top();
			x--;
			freq.pop();
			if(x>=0) freq.push(x);
		}
		long long ans = 0;
		//Buoc 4: Trong qe con lai nhung gi loi het ra
		while(freq.size()>0){
			ans+=1ll*freq.top()*freq.top();
			freq.pop();
		}
		cout<<ans<<endl;
	}
}
/*
2
2
ABCCBC
2
AAAB */