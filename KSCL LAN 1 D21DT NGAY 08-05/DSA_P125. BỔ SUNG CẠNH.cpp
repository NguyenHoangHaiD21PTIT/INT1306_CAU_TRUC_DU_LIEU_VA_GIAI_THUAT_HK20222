#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005];

int find(int x){
	if(x == par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y){
	x = find(x); y = find(y);
	if(x == y) return false;
	if(sze[x] < sze[y]) swap(x, y);
	par[y] = x;
	sze[x] += sze[y];
	return true;	
}

int main(){
	int V, E;
    cin >> V >> E;
    //Make_set
	for(int i = 1;i <= V;i++){
		par[i] = i;
		sze[i] = 1;
	}
    while(E--){
        int x, y; cin >> x >> y;
        Union(x, y);
    }
    int P1 = find(1), ans = 0;
    for(int i = 2; i <= V; i++){
        int PI = find(i);
        if(PI != P1) ans = max(ans, sze[PI]);
    }
    cout << ans + sze[P1];
}
/*Idea: Nếu đồ thị liên thông thì số đỉnh tối đa đánh được là toàn bộ số đỉnh
Ngược lại: Ta sẽ đánh dấu toàn bộ số đỉnh thuộc thành phần liên thông mà 1 thuộc về
Xét các thành phần liên thông khác không chứa 1, ta chọn TPLT mà nhiều phần tử nhất
Ghép nó với TPLT chứa 1 thì sẽ ra TPLT chứa 1 nhiều ptu nhất
(2 thành phần liên thông muốn ghép với nhau thì chỉ cần 1 đoạn thẳng nối là đủ)
*/
