#include<bits/stdc++.h>
using namespace std;

int par[100005], sze[100005];

int find(int x){
	if(x==par[x]) return x;
	return par[x] = find(par[x]);
}

bool Union(int x, int y){
	x = find(x);
	y = find(y);
	if(x==y) return false;
	if(sze[x]<sze[y]) swap(x,y);
	par[y] = x;
	sze[x]+=sze[y];
	return true;	
}

int main(){
	int dinh, canh;
    cin>>dinh>>canh;
    //Make_set
	for(int i=1;i<=dinh;i++){
		par[i] = i;
		sze[i] = 1;
	}
    while(canh--){
        int dau, cuoi;
        cin>>dau>>cuoi;
        Union(dau, cuoi);
    }
    /*Idea: Nếu đồ thị liên thông thì số đỉnh tối đa đánh được là toàn bộ số đỉnh
    Ngược lại: Ta sẽ đánh dấu toàn bộ số đỉnh thuộc thành phần liên thông mà 1 thuộc về
    Xét các thành phần liên thông khác không chứa 1, ta chọn TPLT mà nhiều phần tử nhất
    Ghép nó với TPLT chứa 1 thì sẽ ra TPLT chứa 1 nhiều ptu nhất
    (2 thành phần liên thông muốn ghép với nhau thì chỉ cần 1 đoạn thẳng nối là đủ)
    */
    int daiDien1 = find(1);//Tìm đại diện TPLT 1 thuộc về
    int ans = 0;//biến lưu số phần tử TPLT nhiều phần tử nhất
    for(int i = 2;i<=dinh;i++){
        int represent = find(i);//Tìm đại diện TPLT
        //Nếu 1 không trong tập đấy
        if(represent!=daiDien1) ans = max(ans, sze[represent]);
    }
    cout<<ans+sze[daiDien1];
}
