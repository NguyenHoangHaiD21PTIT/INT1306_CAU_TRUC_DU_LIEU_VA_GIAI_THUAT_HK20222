#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    vector <int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    a.push_back (-1);
    int res = 0, tmp = 0, Max = *max_element(a.begin(), a.end());
    for (int i = 0; i <= n; i++){
        if (a[i] == Max) tmp++;
        else {
            res = max (res, tmp);
            tmp = 0;
        }
    }
    cout << res;
}
/*TBC của 1 dãy không vượt quá phần tử lớn nhất trong dãy đó. Nếu 1 dãy đang có Max, nhét thêm bất kỳ phần tử nào < Max --> TBC < Max
YC1: Để dãy đạt TBC lớn nhất, dãy con đó chỉ được phép chứa Max
+) TBC của đoạn 1 Max, 2 thằng Max, ... đều là Max -->YC2: Tìm dãy con liên tiếp Max dài nhất
*/
