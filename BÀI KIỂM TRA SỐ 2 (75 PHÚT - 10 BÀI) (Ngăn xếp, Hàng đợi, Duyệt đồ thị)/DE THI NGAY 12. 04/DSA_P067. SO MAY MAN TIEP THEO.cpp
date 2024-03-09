#include <bits/stdc++.h>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	queue<long long> q;
	q.push(4);
	q.push(7);
	long long kq = 0;
	int i = a;
	while (1) {
		long long tmp = q.front();
		q.pop();
		while (i <= tmp && i <= b) {
			kq += tmp;
			i++;
		}
		if (i > b) break;
		q.push(tmp * 10 + 4);
		q.push(tmp * 10 + 7);
	}
	cout << kq;
}        
