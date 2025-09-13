#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAX = 100005;
ll lp[MAX + 1] = {}, a[100005];
set<ll>A;

void sieve() {
    for (ll i = 2; i <= sqrt(MAX); i++) {
        if (!lp[i]) {
            for (ll j = i * i; j <= MAX; j += i) {
                if (!lp[j]) lp[j] = i;
            }
        }
    }
    for (ll i = 2; i <= MAX; i++) {
        if (!lp[i]) lp[i] = i;
    }
}
set<ll> fact (ll n) {
    set<ll> ans;
    while (lp[n]) {
        ll p = lp[n];
        while (n % p == 0){
            ans.insert(p);
            n/=p;
        }
    }
    if (n > 1) ans.insert(n);
    return ans;
}

int main(){
    sieve();
    ll n, k; cin >> n >> k;
    for(ll i = 1; i <= n; i++){
        cin >> a[i];
        set <ll> ai = fact(a[i]);
        for(ll x: ai) A.insert(x);
    }
    vector<ll>kqua;
    kqua.push_back(1);
    for(ll i = 2; i <= k; i++){
        set <ll> q = fact(i);
        //Co set q, set ai
        ll check = 1; //K co TSNT nao trong A
        for(ll x: q){
            if(A.find(x) != A.end()){
                check = 0;
                break;
            }
        }
        if(check) kqua.push_back(i);
    }
    cout << kqua.size() << endl;
    for(ll x: kqua) cout << x << " ";
}
/* 
Ngây thơ 1: Đề bảo gì thì ta làm thế
Duyệt mỗi số x từ 1 đến K, rồi duyệt tiếp mỗi số A[i] trong dãy. Ta xem GCD(x, A[i]) = 1 hay không
ĐPT: O(K * N * log(1e9)) = 10^5 * 10^5 * log2(10^9) > 10^11 --> TLE
- 
Ý tưởng:
- Ở lớp 6, ta đã biết để tìm UCLN của 2 số, ta phải phân tích 2 số đó ra thừa số nguyên tố (TSNT), rồi chọn ra các TSNT chung. 
- GCD(K, A[i]) = 1 khi K và A[i] không có thừa số nguyên tố chung.
- Gom tất cả thừa số nguyên tố của A1..AN vào set A.
- Với mỗi số từ 1..K, phân tích ra TSNT → set q.
- Nếu q ∩ A = ∅ thì số đó thỏa mãn.

Ngây thơ 2: Nếu phân tích ra TSNT thuần túy thì sao? Ta biết rằng, PTTSNT số N thuần túy thì ĐPT là O(sqrt(N))
N = 10^5, mỗi a[i] = 10^9, ĐPT = 10^5.sqrt(10^9) = 3.16 * 10^9. Chắc chắn bị TLE. Như vậy, phải cải tiến phần PTTSNT.

Tối ưu:
- Không phân tích trực tiếp O(√N), mà dùng sàng tìm ước nguyên tố nhỏ nhất (lp[]). Vì bản chất PTTSNT chính là, mối một lần thì chia cho USNT nhỏ nhất
- Độ phức tạp: O(N log log N) = 10^5. log2[log2(10^5)] = 405394, đảm bảo
*/
