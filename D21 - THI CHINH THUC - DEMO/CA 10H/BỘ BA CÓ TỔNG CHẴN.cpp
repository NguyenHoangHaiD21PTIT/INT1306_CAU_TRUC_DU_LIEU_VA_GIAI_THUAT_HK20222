#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, q;
    cin>>n>>q;
    int a[n], chan[n], le[n];//chan[i], le[i] là số số chẵn, số số lẻ từ đầu dãy đến i
    for(int i = 0;i<n;i++) cin>>a[i];
    if(a[0]%2==0) chan[0]=1, le[0] = 0;
    else le[0] = 1, chan[0] = 0;
    for(int i = 1;i<n;i++){
        if(a[i]%2==0){
            chan[i] = chan[i - 1] + 1;
            le[i] = le[i - 1];
        } else {
            chan[i] = chan[i - 1];
            le[i] = le[i - 1] + 1;
        }
    }
 
    while(q--){
        int l, r;
        cin>>l>>r;
        l--;r--;
        int soSoChan, soSoLe;
        if(l==0){
            soSoChan = chan[r], soSoLe = le[r];
        } else {
            soSoChan = chan[r] - chan[l - 1];
            soSoLe = le[r] - le[l - 1];
        }
        long long ans = 0;
        //TH1: 3 số chẵn.
        ans+=soSoChan*(soSoChan - 1)*(soSoChan - 2)/6;
        //TH2: 1 chẵn 2 lẻ: số số chẵn là x, lẻ là y: xC1 * yC2 = x * y * (y - 1)/2
        ans+=soSoChan*soSoLe*(soSoLe - 1)/2;
        cout<<ans<<endl;
    }
}
//https://oj.vnoi.info/problem/fc147_eventuples
//Bài này test trường mình siết hơn bên VNOI
