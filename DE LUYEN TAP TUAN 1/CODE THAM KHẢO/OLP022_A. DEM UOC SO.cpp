#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int minPrime[1000001];
map<int, int>mp;

void sieve() { //Sàng tìm ước SNT nhỏ nhất
	for (int i = 2; i * i < 1000001; ++i) {
		if (minPrime[i] == 0) { //if i is prime
			for (int j = i * i; j < 1000001; j += i) {
				if (minPrime[j] == 0) minPrime[j] = i;
			}
		}
	}
	for (int i = 2; i < 1000001; ++i) {
		if (minPrime[i] == 0) minPrime[i] = i;
	}
}

void divisors(ll n) {//Phân tích ra thừa số nguyên tố, đếm số lượng mỗi loại
	while (n != 1) {
		int tmp = minPrime[n];
		while (n % tmp == 0) {
			n /= tmp;
			mp[tmp]++;
		}
	}
}

int main(){
	int t;
	cin >> t;
	sieve();
	while (t--) {
		int m;
		cin >> m;
		divisors(m);
		divisors(m + 1);
		divisors(m + 2);
		int d = 1, dn = 1;//d: Số ước của n, dn: Số ước của n^2
		for (auto x : mp) {
			int cnt = x.second;
			d *= (cnt + 1);
			dn *= (cnt * 2 + 1);
		}
		dn = (dn - 1) / 2;//dn: Số ước nhỏ hơn n của n^2
		d -= 1;//Số ước của n, nhỏ hơn n --> Cũng là số ước của n^2, nhỏ hơn n 
        //Như vậy: d là số ước của n^2, nhỏ hơn n và là ước của n
		cout << dn - d << endl;
		mp.clear();
	}
	return 0;
}