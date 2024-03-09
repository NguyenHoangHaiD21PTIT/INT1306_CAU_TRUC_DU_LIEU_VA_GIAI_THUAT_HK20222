#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
	ll n;
	cin>>n;
	ll a[n];
	for(ll i=0;i<n;i++) cin>>a[i];
	ll prefix[n];
	
	//Mảng cộng dồn
	for(ll i=0;i<n;i++){
		if(i==0) prefix[0] = a[0];
		else prefix[i] = prefix[i-1] + a[i];
	}
	
	ll f[n + 5]={};//f[i] là GTNN trong dãy con [i; n-1]
	f[n - 1] = a[n - 1];
	for(ll i = n-2;i>=1;i--) f[i] = min(a[i], f[i + 1]);
	
	vector<pair<ll, double>>v;//lưu số k (số bài bị xóa) và điểm trung bình ứng với nó
	double Max = -1.7e18; //giá trị trung bình lớn nhất
	
	for (ll k = 1;k<=n-2;k++){//Lần lượt xóa k bài -> tính điểm từ bài thứ k đến hết trừ đi bài thấp nhất (Chỉ số bài đi từ 0)
		ll res = prefix[n - 1] - prefix[k - 1] - f[k]; //Tổng điểm trừ đi bài thấp nhất
		double tmp = (double)res/(n - k -1); //Điểm trung bình
		Max = max(Max, tmp); //Cập nhật điểm TB lớn nhất
		v.push_back({k, tmp});
	}
	
	for (auto i: v){
		if(i.second == Max) cout<<i.first<<" ";
	}
}