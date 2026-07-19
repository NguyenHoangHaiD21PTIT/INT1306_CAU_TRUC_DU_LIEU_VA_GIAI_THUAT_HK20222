#include <bits/stdc++.h>
using namespace std;

int main(){
    int q; cin >> q;
    queue <int> qe;//Mới thêm
    priority_queue <int, vector<int>, greater<int>>pq;//Min heap
    while(q--){
        int t; cin >> t;
        if (t == 1){
            int x; cin >> x;
            qe.push(x);
        } else if (t == 2){
            //TH1: Phần sắp xếp còn phần tử
            if (!pq.empty()){
                cout << pq.top() << endl;
                pq.pop();
            } else {
                cout << qe.front() << endl;
                qe.pop();
            }
        } else {
            while (!qe.empty()){
                pq.push(qe.front());
                qe.pop();
            }
        }
    }
}