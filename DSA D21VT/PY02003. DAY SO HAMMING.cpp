#include <bits/stdc++.h>
using namespace std;

vector<long long> v;
unordered_map<long long, long long> hammingMap;
int stt = 1;

void gen() {
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    unordered_map<long long, bool> m;
    pq.push(1);
    while (1) {
        long long tmp = pq.top();
        pq.pop();
        hammingMap[tmp] = stt;
        stt++;
        if(tmp>=pow(10, 18)) break;
        v.push_back(tmp);
        if (!m[tmp * 2]) {
            pq.push(tmp * 2);
            m[tmp * 2] = true;
        }
        if (!m[tmp * 3]) {
            pq.push(tmp * 3);
            m[tmp * 3] = true;
        }
        if (!m[tmp * 5]) {
            pq.push(tmp * 5);
            m[tmp * 5] = true;
        }
    }
}

int main() {
    gen();
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        if (hammingMap.find(n) != hammingMap.end()) cout << hammingMap[n] << endl;
        else cout << "Not in sequence" << endl;
    }
    return 0;
}