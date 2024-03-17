#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int a[n];
		for(int i = 0;i<n;i++) cin>>a[i];
		int Max[n], Min[n];//Max[i] là phần tử lớn nhất trong dãy con từ [0; i]
		//Min[y] là phần tử nhỏ nhất trong dãy con từ [i; n - 1]
		/*Một vị trí i thỏa mãn nếu sắp xếp [0; i] tăng dần và [i + 1; n - 1] tăng dần thì dãy tăng dần
		Khi: Max trong đoạn [0;i] không vượt quá min phần còn lại của dãy số. Tức là Max[i]<=Min[i + 1] */
		Max[0] = a[0];
		for(int i = 1;i<n;i++) Max[i] = max(a[i], Max[i - 1]);
		Min[n - 1] = a[n - 1];
		for(int i = n - 2;i>=0;i--) Min[i] = min(a[i], Min[i + 1]);
		vector<int>ans;
		for(int i = 0;i<n -1;i++){
			if(Max[i]<=Min[i + 1]) ans.push_back(i + 1);
		}
		cout<<ans.size()<<endl;
		for(int x: ans) cout<<x<<" ";
		cout<<endl;
	}
}