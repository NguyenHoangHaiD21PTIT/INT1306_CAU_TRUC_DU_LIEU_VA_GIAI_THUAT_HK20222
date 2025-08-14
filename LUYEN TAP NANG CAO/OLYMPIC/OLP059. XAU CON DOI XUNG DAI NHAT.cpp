#include<bits/stdc++.h>
using namespace std; 
#define int long long
const int N = 5e5 + 5, p = 1e9 + 7;
int n, ans;
char s[N];
int Pow[N], hash_left[N], hash_right[N]; // hash_left[i] là từ 1 đến i, right là từ N đổ về i

//1. Tính trước 31^i % MOD
void pre(){
    Pow[0] = 1;
    for(int i = 1;i <= 200000; i++) Pow[i] = (Pow[i - 1] * 31) % p;
}

int get_left(int i, int j){ //Hash [i i + 1 ... j]
    return (hash_left[j] - hash_left[i - 1] * Pow[j - i + 1] + p) % p;
}

int get_right(int i, int j){ //Hash [i i + 1 ... j] nhưng đảo ngược
    return (hash_right[i] - hash_right[j + 1] * Pow[j - i + 1] + p) % p;
}
/* Ví dụ: 123456. Ta muốn trích xuất ra 543 chẳng hạn (0 - based)
hash_right [5] = 6
hash_right [4] = 65
hash_right [3] = 654 
...
hash_right [0] = 654321
HR [2 ... 4] (Ngược) 543 = 6543 - 6 * 10 ^ 3 = H[2] - H [5] * 10 ^ (Độ dài = 5 - 2 + 1)
*/

bool check(int x, int y, int u, int v){ //[s[x] s[x + 1] ... s[y]] = [s[v] s[v - 1] ... s[u]]
    return (get_left(x, y) == get_right(u, v));
}

void sol(){
    for (int i = 1; i <= n; i++) hash_left[i] = (hash_left[i - 1] * 31 + s[i] - 'a' + 1) % p;
    for (int i = n; i > 0; i--) hash_right[i] = (hash_right[i + 1] * 31 + s[i] - 'a' + 1) % p;
    // Với mỗi i, ta chặt nhị phân trên chiều dài. Và ta chẳng biết đó là xâu đối xứng len chẵn hay lẻ cả
    // TH1: [x ... i][i ... y] tạo thành 2 xâu ngược nhau, mỗi xâu dài len --> Đối xứng dài 2 * len
    // TH2: [x ... i - 1] i [i + 1 ... y], 2 xâu con kia ngược nhau, mỗi xâu dài len --> Đối xứng dài 2 * len + 1
    // Lí do chặt nhị phân theo chiều dài vì:
    // Xâu S đối xứng rồi, thì thử thêm các X chữ cái vào trước và X chữ cái sau xâu S xem còn đx nữa không --> Tăng độ dài
    // Xâu S không đối xứng, thì thêm 1 lượng chữ cái bằng nhau 2 bên cũng vậy --> Không được lợi gì --> Giảm độ dài đi
    for (int i = 1; i <= n; i++){ // O(n)
        //Xâu đối xứng độ dài chẵn. Độ dài sẽ là 2 mid. Nửa đầu là [i về đầu] dài mid, thêm [i + 1 về sau] dài mid
        //i - l + 1 = mid ->l = i + 1 - mid; r - (i + 1) + 1 = mid -->r = mid + i
        // Và để tránh bị out index: i + 1 - mid >= 1 --> mid <= i; mid + i <= n --> mid <= (n - i) --> mid <= min (i, n - i)
        int left = 1, right = min(i, n - i); //O(logN)
        while(left <= right){
            int mid = (left + right)/2;
            if(check(i - mid + 1, i, i + 1, i + mid)){
                ans = max(ans, mid * 2);
                left = mid + 1;
            }
            else right = mid - 1;
        }
        //Xâu đối xứng độ dài lẻ. Ở đây thì i là tâm của xâu đối xứng, i - 1 đổ về đầu dài mid, i + 1 đổ về sau dài mid
        //i - 1 - st + 1 = mid --> st = i - mid; en - (i + 1) + 1 = mid = en - i --> en = mid + i
        // Và để tránh bị out index: i - mid >= 1 --> mid <= i - 1; mid + i <= n --> mid <= (n - i) --> mid <= min (i, n - i)
        left = 1, right = min(i - 1, n - i); //O(logN)
        while(left <= right){
            int mid = (left + right)/2;
            if(check(i - mid, i - 1, i + 1, i + mid)){
                ans = max(ans, mid * 2 + 1);
                left = mid + 1;
            }
            else right = mid - 1;
        }
    }
    cout << ans << endl;
    // O(N) * (O(logN) + O(logN)) = O(NlogN)
}

signed main(){
    pre(); int t; cin >>t ;
    while(t--){
        ans = 1; cin >> n;
        for (int i = 1; i <= n; ++i) cin >> s[i];
        for (int i = 0; i <= n + 5; ++i) hash_right[i] = hash_left[i] = 0;
        sol();
    }
    // O(T * N * log(N)) = O(2 * 10 ^ 6 * log(1e6)) ~ O(2 *10 ^ 6 * 2 * 10) = O (4 * 10 ^ 7)
}
