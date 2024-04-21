/* Gray dài 1
0
1
Gray dài 2:
0 0
0 1
1 1
1 0 Tức là: cóp nguyên dãy 0 1 làm nửa đầu, lật ngược dãy này thành 1 0.
Nửa đầu thêm 0 nửa sau thêm 1
Gray dài 3:
0 00 (00[1] == 00[8])
0 01
0 11
0 10
1 10
1 11
1 01
1 00
Lại copy nguyên dãy mã gray dài 2 xuống làm nửa đầu, lật ngược dãy này làm nửa sau. Nửa đầu gắn 0, nửa sau gắn 1
*/
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>v(pow(2, n) + 5);
        v[1] = "0"; v[2] = "1";//Khởi tạo mã Gray dài 1
        for(int i = 2;i<=n;i++){//Sinh các mã Gray dài i
            int pos = pow(2, i - 1);//Nhân bản toàn bộ mã gray thứ i - 1 rồi đảo ngược nó
            //2^(n-1) là số mã Gray dài (n - 1)
            //Lật ngược đối xứng nửa sau
            for(int j = pos + 1;j<=pow(2, i);j++) v[j] = v[pow(2, i) - j + 1];
            //Nửa đầu thêm 0
            for(int j = 1;j<=pos;j++) v[j] = "0" + v[j];
            //Nửa sau thêm 1
            for(int j = pos + 1;j<=pow(2, i);j++) v[j] = "1" + v[j];
        }
        for(int i = 1;i<=pow(2, n);i++) cout<<v[i]<<" ";
        cout<<endl;
    }
}