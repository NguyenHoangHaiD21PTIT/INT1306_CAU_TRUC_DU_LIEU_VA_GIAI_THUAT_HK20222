include<bits/stdc++.h>
using namespace std;
int n, a[100], ok;//ok: con sinh duoc hay khong, k: so bit 1, n: do dai

void kht(){
	for(int i=1;i<=n;i++) a[i]=0;
}

void sinh(){
	int i=n;
	while(i>=1&&a[i]==1){
		a[i]=0;
		i--;
	}
	if(i==0) ok=0;
	else a[i]=1;
}

int main(){
    cin>>n;
    int k;
    cin>>k;
    kht();
    ok = 1;
    int cnt = 0;
    while(ok==1){
        if(cnt%k==0){
            for(int i = 1;i<=n;i++) cout<<a[i];
            cout<<endl;
        }
        sinh();
        cnt++;
    }
}
