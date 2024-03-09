#include <bits/stdc++.h>
using namespace std;

int n; // so thanh pho

int c[1001][1001], x[1000001] = {0}, ans = INT_MAX, visited[1000001] = {0}, cmin;

// mang c la ma tran trong so
// mang x la luu lai duong di
// ans la luu lai gia tri duong di nho nhat
// visited check xem 1 thanh pho da duoc tham hay chua



void Try(int i, int sum){
    for (int j = 2; j <= n; j++){ // mac dinh la tham dinh 1 dau tien nen xet tu dinh 2{
        if (!visited[j]){ // check xem thanh pho j da duoc tham hay chua
            visited[j] = true;        // danh dau da duoc tham de ko duyet lai
            x[i] = j;                 // cho vao danh sach duong di
            sum += c[x[i - 1]][x[i]]; // tinh chi phi khi qua dinh nay
            if (i == n){              // neu di qua du n thanh pho roi thi xet xem gia tri duong di voi bien ans
                ans = min(ans, sum+c[x[i]][1]);
            } else if(sum + (n-i+1)*cmin<ans) {
            	Try(i+1,sum);
			}
            sum -= c[x[i - 1]][x[i]];
            visited[j] = false;
        }
    }
}

int main(){
    cin>>n;
    cmin = INT_MAX;
    for(int i=1;i<=n;i++){
    	for(int j=1;j<=n;j++){
    		cin>>c[i][j];
    		if(c[i][j]!=0) cmin=min(cmin,c[i][j]);
		}
	}
	x[1] = 1;
	visited[1] = 1;
	Try(2,0);
	cout<<ans<<endl;
}
