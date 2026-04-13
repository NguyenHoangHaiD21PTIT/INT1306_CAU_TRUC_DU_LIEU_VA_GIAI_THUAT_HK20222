#include <bits/stdc++.h>
using namespace std;

int n, m, a[100007];
bool check(int x){ //Kiểm tra có thể xếp m tay đua mà kcach min >= x hay không
    int cnt = 1, last = a[1];
    for (int i = 2; i <= n; i++){
        if (a[i] - last >= x){
            cnt++;
            last = a[i];
        }
    }
    return cnt >= m;
}

int main(){
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 0, r = a[n] - a[1], res = 0;
    while (l <= r){
        int mid = (l + r) / 2;
        if (check(mid)){
            res = mid;
            l = mid + 1;
        } else r = mid - 1;
    }
    cout << res << endl;
}
