#include<bits/stdc++.h>
using namespace std ; 
int main(){
	int n , k ; cin >> n >> k ; 
	int a[n] ; 
	for(auto &x : a) cin >> x; 
	sort(a , a + n , greater<int>()) ;
	int sum = 0; 
	vector<int> v ; 
    for(int i = 0;i<k;i++) v.push_back(a[i*2]);
    for(int i = 0;i<k;i++) v.push_back(a[i*2 + 1]);
    for(int i = 2 * k;i<n;i++) v.push_back(a[i]);
    for(int i =0;i<n - k;i++) sum+=abs(v[i] - v[i + k]);
    cout<<sum<<endl;
}
