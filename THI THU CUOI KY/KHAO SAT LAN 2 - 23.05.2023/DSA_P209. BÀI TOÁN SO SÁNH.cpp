#include <bits/stdc++.h>
using namespace std;

vector <int> adj[200005];
int in[200005]; //Bán bậc vào

int main(){
    int n, V = 0; cin >> n; //V: Số đỉnh PHÂN BIỆT
    map <string, int>id; //Ví dụ: id[A] = 1 --> Bạn A có mã là 1
    while (n--){
        string u, op, v;
        cin >> u >> op >> v;
        //Chưa có ID thì gán, gặp đỉnh mới, tăng số đỉnh để ghi nhận STT mới, rồi gán cho đỉnh mới đó
        if (!id.count(u)) id[u] = ++V;
        if (!id.count(v)) id[v] = ++V;
        if (op == ">"){
            adj[id[u]].push_back(id[v]);
            in[id[v]]++;
        } else {
            adj[id[v]].push_back(id[u]);
            in[id[u]]++;
        }
    }
    //Thuật toán Kahn
    queue <int> q;
    for (int i = 1; i <= V; i++){
        if (!in [i]) q.push(i);
    }
    int cnt = 0;
    while (!q.empty()){
        int u = q.front();
        q.pop();
        cnt++;
        for (int v: adj[u]){
            if (!--in[v]) q.push(v); //Giảm bậc vào đỉnh kề, nếu là 0 thì cho vào hàng đợi
        }
    }  
    if (cnt == V) cout << "possible" << endl;
    else cout << "impossible" << endl;
}
