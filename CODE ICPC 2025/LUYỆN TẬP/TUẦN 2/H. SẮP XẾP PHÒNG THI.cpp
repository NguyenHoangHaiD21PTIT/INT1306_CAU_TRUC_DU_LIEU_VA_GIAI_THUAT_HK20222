#include<bits/stdc++.h>
using namespace std;

int par[200005], sze[200005];

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y){
	x = find(x);
	y = find(y);
	if(x == y) return false;
	if(sze[x] < sze[y]) swap(x,y);
	par[y] = x;
	sze[x] += sze[y];
	return true;	
}

int main(){
	int dinh, canh;
    cin >> dinh >> canh;
    //Make_set
	for(int i = 1;i <= dinh;i++){
		par[i] = i;
		sze[i] = 1;
	}
    while(canh--){
        int dau, cuoi;
        cin >> dau >> cuoi;
        Union(dau, cuoi);
    }
    /*Idea: Giả sử ta có 3 TPLT: LT1: a1, a2, a3, a4; LT2: b1, b2, b3; LT3: c1, c2, c3, c4, c5
    Chiến lược tham lam: 
    - Tô màu 1 cho: a1, b1, c1
    - Tô màu 2 cho: a2, b2, c2
    - Tô màu 3 cho: a3, b3, c3
    - Tô màu 4 cho: a4, c4. Màu còn lại cho c5 --> Đáp án là TPLT to nhất
    */
    int ans = 0;
    for(int i = 1;i <= dinh;i++) ans = max(ans, sze[i]);
    cout << ans;
}