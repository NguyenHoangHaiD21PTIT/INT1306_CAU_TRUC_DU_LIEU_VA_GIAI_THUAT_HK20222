#include <bits/stdc++.h>
using namespace std;

int p[200005], sz[200005];

int f(int x){
    if(x == p[x]) return x;
    return p[x] = f(p[x]);
}

bool u(int x, int y){
    x = f(x); y = f(y);
    if(x == y) return false;
    if(sz[x] < sz[y]) swap(x, y);
    p[y] = x;
    sz[x] += sz[y];
    return true;    
}

struct E { 
    int a, b; 
    long long w; 
};

bool cmp(const E &x, const E &y){ 
    return x.w < y.w;
}

int main() {
    int n, m; cin >> n >> m;
    for(int i = 1; i <= n; i++){ 
        p[i] = i; 
        sz[i] = 1; 
    }
    vector<E> pos;
    long long sum = 0;
    for(int i = 0; i < m; i++){
        int x, y; long long w;
        cin >> x >> y >> w;
        if(w <= 0) u(x, y);
        else { 
            sum += w; 
            pos.push_back({x, y, w}); 
        }
    }
    sort(pos.begin(), pos.end(), cmp);
    long long keep = 0;
    for(auto &e : pos) if(u(e.a, e.b)) keep += e.w;
    cout << sum - keep;
}
/* Tư duy giải bài:
- Xóa cạnh âm sẽ bị phạt, và nếu xóa còn làm giảm khả năng liên thông, nên tốt nhất giữ nguyên.
- Lý tưởng nhất là xóa hết các cạnh dương nếu vẫn giữ được liên thông, để nhận được điểm thưởng tối đa.
- Vì vậy, ta sẽ tìm những cạnh dương có trọng số lớn có thể xóa mà đồ thị vẫn liên thông.

Cách tiếp cận ngược:
- Ban đầu coi mỗi đỉnh là một thành phần rời rạc.
- Gặp cạnh âm: nối luôn 2 đầu mút (tương đương giữ lại cạnh âm).
- Với các cạnh dương: xác định các cạnh "bắt buộc phải giữ" để đảm bảo liên thông, ưu tiên giữ những cạnh có trọng số nhỏ.
- Sắp xếp các cạnh dương theo trọng số tăng dần.
- Duyệt từng cạnh dương, nếu hai đầu nếu chưa cùng thành phần liên thông, tức là bắt buộc phải giữ cạnh đó.
- Khi biết được các cạnh dương bắt buộc giữ, đáp số là tổng trọng số tất cả các cạnh dương ban đầu trừ đi tổng trọng số các cạnh buộc phải giữ.
*/

