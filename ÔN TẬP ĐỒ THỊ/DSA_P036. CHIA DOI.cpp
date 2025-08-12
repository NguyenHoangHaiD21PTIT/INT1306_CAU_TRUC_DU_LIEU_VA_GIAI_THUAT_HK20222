#include<bits/stdc++.h>
using namespace std;
long long f[35][35];
//f[i][j]: Số cách ăn hết i thanh nguyên và j nửa thanh
void prepare(){
    for(int i = 0; i <= 30; i++){
        for(int j = 0; j <= 30; j++){
            if(i == 0)f[i][j] = 1; //Không có thanh nguyên nào --> Cách duy nhất là ăn lần lượt từng j nửa thanh 
            if(j == 0)f[i][j] = f[i - 1][1]; //Không có nửa thanh nào --> Cách duy nhất là lấy 1 thanh nguyên, bẻ đôi, ăn 1 nửa để 1 nửa --> Bớt đi 1 thanh nguyên và thêm nửa thanh
            if(i && j)f[i][j] = f[i - 1][j + 1] + f[i][j - 1];
            //Cách 1: Lấy 1 thanh nguyên, bẻ đôi, ăn 1 nửa để 1 nửa --> Bớt đi 1 thanh nguyên và thêm nửa thanh
            //Cách 2: Ăn luôn 1 nửa thanh sẵn có
        }
    }
}
int main(){
    prepare();
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        cout << f[n][0] << endl;
    }
}
