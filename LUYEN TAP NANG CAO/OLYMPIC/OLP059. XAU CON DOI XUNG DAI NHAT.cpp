#include<bits/stdc++.h>
using namespace std; 
#define int long long
const int N=5e5+5, p = 1e9 + 7;
int n, ans;
char s[N];
int Pow[N], hash_left[N], hash_right[N];//hash_left[i] là từ 1 đến i, right là từ N đổ về i

void pre(){
    Pow[0]=1;
    for(int i=1;i<=200000;i++) Pow[i] = (Pow[i-1] * 31) % p;
}

int get_left(int i,int j){ //Hash từ i cho đến j chiều từ trái sang
    return (hash_left[j] - hash_left[i-1] * Pow[j-i+1] + p*p)%p;
}

int get_right(int i,int j){ //Hash từ j về i chiều từ bên phải sang, 
    return (hash_right[i] - hash_right[j + 1] * Pow[j-i+1] + p*p)%p;
}

bool check(int x,int y, int u, int v){
    return (get_left(x,y)==get_right(u,v));
}

void solution(){
    for(int i=1;i<=n;i++) hash_left[i]=(hash_left[i-1]*31 + s[i]-'a' + 1)%p;
    for(int i=n;i>0;i--) hash_right[i]=(hash_right[i+1]*31 + s[i]-'a' + 1)%p;
    for(int i=1;i<=n;i++){
        //Xâu đối xứng độ dài chẵn. Độ dài sẽ là 2 mid. Nửa đầu là [i về đầu] dài mid, thêm [i + 1 về sau] dài mid
        //i - l + 1 = mid ->l = i + 1 - mid; r - (i + 1) + 1 = mid -->r = mid + i
        int left=1, right = min(i,n-i);
        while(left <= right){
            int mid=(left+right)/2;
            if(check(i-mid+1, i, i + 1, i+mid)){
                ans = max(ans,mid*2);
                left = mid+1;
            }
            else right = mid-1;
        }
        //Xâu đối xứng độ dài lẻ. Ở đây thì i là tâm của xâu đối xứng, i - 1 đổ về dài mid, i + 1 đổ về dài mid
        //i - 1 - x  + 1 = mid, y - (i + 1) + 1 = mid
        left=1,right=min(i-1,n-i);
        while(left<=right){
            int mid=(left+right)/2;
            if(check(i-mid, i - 1, i + 1, i+mid)){
                ans=max(ans,mid*2+1);
                left=mid+1;
            }
            else right=mid-1;
        }
    }
    cout<<ans<<endl;
}

signed main(){
    pre();
    int t;
    cin>>t;
    while(t--){
        ans=1;
        cin>>n;
        for (int i = 1; i <= n; ++i) cin >> s[i];
        for (int i = 0; i <= n + 5; ++i) hash_right[i] = hash_left[i] = 0;
        solution();
    }
    return 0;
}
