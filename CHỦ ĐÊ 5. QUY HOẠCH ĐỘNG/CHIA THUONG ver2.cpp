#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e9 + 7;

int f[1005]= {};//số cách chia i phần thưởng cho học sinh

int solve(int n){
	//Có phần thưởng nhưng có 1 học sinh:
	for(int i = 0;i<=n+1;i++) f[i] = 1;//Có 1 cách là chia cho chính em đó
	for(int j = 2;j<=n;j++){//Số học sinh
		for(int i = j;i<=n;i++){
			f[i]+=f[i - j];
			f[i]%=MOD;
		}
	}
	return f[n];
}

int main() {
    ifstream cin("input.txt");
    ofstream cout("output.txt");
    int n;
    cin >> n;
    cout<<solve(n);
} 
