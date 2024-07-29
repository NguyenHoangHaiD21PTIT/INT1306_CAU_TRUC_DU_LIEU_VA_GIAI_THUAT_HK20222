#include <bits/stdc++.h>
using namespace std;
int main(){
	long long n, k;
	cin >> n >> k;
	priority_queue<long long, vector<long long>, greater<long long>>pq;
	for (int i = 0; i < n; i++) {
		long long x;
		cin >> x;
		pq.push(x);
	}
	long long tmp, tien = 0;
	while (pq.size() > 1) {
		long long sum = 0, lon = 0, nho = 0, x = pq.size();
		tmp = min(k, x);
		for(int i = 1;i<=tmp;i++){
			sum+=pq.top();
			if(i==1) nho = pq.top();
			if(i==tmp) lon = pq.top();
			pq.pop();
		}
		tien += lon - nho;
		pq.push(sum);
	}
	cout << pq.top() << "\n" << tien;
	return 0;
}
