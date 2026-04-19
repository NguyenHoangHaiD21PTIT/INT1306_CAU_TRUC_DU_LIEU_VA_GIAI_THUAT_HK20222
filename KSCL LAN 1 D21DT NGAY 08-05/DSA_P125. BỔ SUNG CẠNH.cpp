#include <bits/stdc++.h>
using namespace std;

int par[100005], s[100005];

int find (int x){
    if (x == par[x]) return x;
    return par[x] = find(par[x]);
}

bool join (int x, int y){
    x = find(x); y = find(y);
    if (x == y) return false;
    if (s[x] < s[y]) swap(x, y);
    par[y] = x;
    s[x] += s[y];
    return true;
}

int main(){
    int n, m; 
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        par[i] = i;
        s[i] = 1;
    }
    while (m--){
        int x, y; cin >> x >> y;
        join(x, y);
    }
    int ans = 0, P1 = find(1);
    for (int i = 2; i <= n; i++){
        int PI = find(i);
        if (PI != P1) ans = max (ans, s[PI]);
    }
    cout << ans + s[P1];
}
/*Idea: Nếu đồ thị liên thông thì số đỉnh tối đa đánh được là toàn bộ số đỉnh
Ngược lại: Ta sẽ đánh dấu toàn bộ số đỉnh thuộc thành phần liên thông mà 1 thuộc về
Xét các thành phần liên thông khác không chứa 1, ta chọn TPLT mà nhiều phần tử nhất
Ghép nó với TPLT chứa 1 thì sẽ ra TPLT chứa 1 nhiều ptu nhất
(2 thành phần liên thông muốn ghép với nhau thì chỉ cần 1 đoạn thẳng nối là đủ)
*/
