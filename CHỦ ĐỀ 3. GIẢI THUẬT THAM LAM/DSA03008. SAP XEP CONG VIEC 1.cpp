#include<bits/stdc++.h>
using namespace std;

/* Viec nao ket thuc som thi sap xep truoc
Muon lam viec tiep theo, thi viec ay phai co tg bat dau > tg ket thuc viec truoc do */
struct task{
	int start, end;
};

bool cmp(task a, task b){
	return a.end<b.end;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		task a[n];
		for(int i=0;i<n;i++) cin>>a[i].start;
		for(int i=0;i<n;i++) cin>>a[i].end;
		sort(a,a+n,cmp);
		//Xong viec dau tien
		int cnt = 1, kt = a[0].end;
		for(int i=1;i<n;i++){
			if(a[i].start>=kt){
				cnt++;
				//Lam xong viec a[i] --> Cap nhat tg ket thuc
				kt = a[i].end;
			}
		}
		cout<<cnt<<endl;
	}
}