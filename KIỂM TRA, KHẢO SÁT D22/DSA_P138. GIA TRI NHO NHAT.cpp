#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin>>n>>k;
    int a[n + 1];
    for(int i = 1;i<=n;i++) cin>>a[i];
    sort(a + 1, a + n + 1);
    int ans = 0, pos = n/k + 1;
    a[0] = a[1];
    for(int i = 1;i<=n;i++){
        if(i==pos){
            pos+=n/k;
            continue;
        }
        ans+=a[i] - a[i - 1];
    }
    cout<<ans<<endl;
}
/*
Giả sử A = 1 2 3 4 5 6 7 8 9 10 11 12
n = 12, k = 3
Để tổng đề cho có GTNN thì ta xếp như sau
index  1   2    3    4    5    6    7    8    9    10    11    12
G.trị  1   5    9    2    6    10   3    7    11   4     8     12

12/3 thì ra 4 cụm
gán: a1 = 1, a4 = 2, a7 = 3, a10 = 4. pos đây chinh là điểm cuối của mỗi cụm
a2 = 5, a5 = 6, a8 = 7, a11 = 8. Hết nhóm 2
a3 = 9, a6 = 10, a9 = 11, a12 = 12
*/
