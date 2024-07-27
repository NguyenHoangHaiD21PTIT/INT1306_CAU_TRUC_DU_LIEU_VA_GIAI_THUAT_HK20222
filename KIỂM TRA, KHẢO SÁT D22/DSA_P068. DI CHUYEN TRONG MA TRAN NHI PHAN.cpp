#include<bits/stdc++.h>
using namespace std;
string change(string x){
    string rs = "";
    while (x.size()%4 != 0) x = "0" + x;
    for (int i = 0; i < x.size(); i += 4){
        //Chia thành từng cụm 4 bit một
        string tmp = x.substr(i, 4);
        //Chuyển từng cụm 4 bit ở hệ 2 sang hệ 10
        int d = 0;
        for (int j=0; j<4; j++) d+= (tmp[j] - '0') * pow(2, (3 - j)) ;
        //Chuyển tương ứng sang các cụm hệ 16, <10 thì giữ nguyên, 10: A, 11:B, 12:C, 13:D
        char c;
        if (d >= 0 && d <= 9) c = d+'0';
        else c = d-10+'A';
        rs+=c;
    }
    
    //Xoá các số 0 ở đầu nếu có
    int i = 0;
    while(i<rs.size()&&rs[i]=='0') i++;
    if (i==rs.size()) return "0";
    else return rs.substr(i);
}

int main(){
    int n;
    cin>>n;
    int a[n][n];
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) cin>>a[i][j];
    }
    vector<vector<string>> b(n, vector<string>(n, ""));
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++) b[i][j] = to_string(a[i][j]);
    }
    for(int i = 0;i<n;i++){
        for(int j = 0;j<n;j++){
            if(!i&&j) b[i][j] = b[i][j - 1] + b[i][j];
            else if (i&&!j) b[i][j] = b[i - 1][j] + b[i][j];
            else if (i&&j) b[i][j] = max(b[i - 1][j], b[i][j - 1]) + b[i][j];
        }
    }
    cout<<change(b[n - 1][n - 1]);
}
