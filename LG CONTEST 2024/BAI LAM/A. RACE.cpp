#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, k;
    cin >> n >> k;
    priority_queue<long long> pos_pq, neg_pq;
    for (int i = 0; i < n; i++) {
        long long x;
        cin >> x;
        if (x < 0) neg_pq.push(-x);  
        else pos_pq.push(x);
    }
    long long dis = 0;
    while (!neg_pq.empty()) {
        long long x = neg_pq.size();
        long long tmp = min(x, k), tmp1; 
        for (int i = 0; i < tmp; i++) {
            if (i == 0) tmp1 = neg_pq.top(); 
            neg_pq.pop();
        }
        dis += 2 * tmp1; 
    }
    while (!pos_pq.empty()) {
        long long x = pos_pq.size();
        long long tmp = min(x, k), tmp1; 
        for (int i = 0; i < tmp; i++) {
            if (i == 0) tmp1 = pos_pq.top(); 
            pos_pq.pop();
        }
        dis += 2 * tmp1; 
    }
    cout << dis << endl; 
    return 0;
}