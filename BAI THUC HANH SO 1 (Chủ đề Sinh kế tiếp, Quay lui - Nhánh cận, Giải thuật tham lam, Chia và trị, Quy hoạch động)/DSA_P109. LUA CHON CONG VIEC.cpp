#include<bits/stdc++.h>
using namespace std;

struct task{
	long long deadline, profit; 
};

bool cmp (task a, task b){
	if(a.profit!=b.profit) return a.profit>b.profit;
	return a.deadline > b.deadline;
}
task a[100007]; 

int main(){
	long long n;
	cin>>n;
	for(long long i=0;i<n;i++) cin>>a[i].deadline>>a[i].profit;
	sort(a,a+n,cmp);
	long long ans = 0;
	set<int>tGian;//Trong này chỉ chứa các đơn vị thời gian chưa sử dụng
	for(int i = 1;i<=n;i++) tGian.insert(i);
	for(int i = 0;i<n;i++){
	    auto x = tGian.upper_bound(a[i].deadline);
	    if(x==tGian.begin()) continue;
	    /*LÍ LUẬN: 
	    Ví dụ: dl là 3. Các đơn vị thời gian chưa dùng là 5 7 8 15 thì bỏ. Tức là min(tg chưa dùng) > dl --> Chả có chỗ xếp
	    Ta tìm được vị trí đầu tiên > dl --> Lùi để về vị trí sau cùng gần dl nhất 
	    Xếp sau để còn chỗ cho các việc có dl sớm*/
	    
	    //XẾP VIỆC
	    x--;//Xếp vào Vị trí sát dl nhất
	    ans+=a[i].profit;//Làm xong trước dl thì có lãi
	    tGian.erase(x); //thời gian x đã có việc xếp vào
	}
	cout<<ans;
}
