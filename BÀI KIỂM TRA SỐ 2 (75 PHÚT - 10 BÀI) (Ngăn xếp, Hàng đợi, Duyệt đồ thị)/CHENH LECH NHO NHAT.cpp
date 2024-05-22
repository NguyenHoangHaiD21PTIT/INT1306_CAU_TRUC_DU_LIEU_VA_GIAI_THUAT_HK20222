#include<bits/stdc++.h>
using namespace std ; 
#define ll long long
int main(){
	int n , k ; cin >> n >> k ; 
	int a[n] ; 
	for(auto &x : a) cin >> x; 
	sort(a , a + n , greater<int>()) ;
    //10 7 5 3 2 1
	ll sum = 0 ; 
	vector<int> v ; 
	map<int,int> used ;
	int i = k ; 
	int j = 0 ; 
	while(i --){
		v.push_back(a[j]) ;
		used[ j ] = 1 ; 
		j += 2 ; 
	}
	for(i = k ; i < n ; i ++){
		if(used[i] == 0){
			v.push_back(a[i]) ;
			used[i] = 1 ; 
		}
	}
	for(int i = 0 ; i < n - k ; i ++){
		sum += abs(v[i] - v[i + k]); 
	}
	cout << sum << endl ;
	return 0 ; 
}/*
6 3
5 2 7 1 10 3
Đề KSCL D21DT ngày 22 tháng 5
*/