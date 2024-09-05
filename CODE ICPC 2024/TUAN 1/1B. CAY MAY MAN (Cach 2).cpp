#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 10;
bool checkLucky(string x) {
    for (char ch : x) {
        if (ch != '4' && ch != '7') return false;
    }
    return true;
}
int par[100005], sze[100005];
int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return false;
	if(sze[x]<sze[y]) swap(x,y);
	par[y] = x;
	sze[x]+=sze[y];
	return true;	
}

int main() {    
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        par[i] = i;
        sze[i] = 1;  
    }
    for (int i = 1; i < n; i++) {
        int a, b;
        string w;
        cin >> a >> b >> w;
        if(!checkLucky(w)) Union(a, b);
    }
    long long ans = 0;
    for (int i = 1; i <= n; ++i) {
        long long f = n - sze[find(i)];  // Số đỉnh không thuộc thành phần liên thông xấu này
        ans += f * (f - 1);  // Tính số cách chọn cặp (j, k) với j, k thuộc các thành phần khác nhau
    }
    cout << ans;
}
