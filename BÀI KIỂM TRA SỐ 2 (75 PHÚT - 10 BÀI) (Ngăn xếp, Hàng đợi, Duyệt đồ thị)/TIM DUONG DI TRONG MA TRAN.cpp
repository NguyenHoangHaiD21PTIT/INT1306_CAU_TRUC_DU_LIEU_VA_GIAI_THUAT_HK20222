#include<bits/stdc++.h>
using namespace std;
string binaryToHex(string binary) {
    while (binary.length() % 4 != 0) binary = "0" + binary;
    
    vector<string> groups;
    for (int i = 0; i < binary.length(); i += 4) {
        groups.push_back(binary.substr(i, 4));
    }

    string res = "";
    for (string group : groups) {
        int decimal = stoi(group, nullptr, 2);//chuyển từng cụm hệ 2 sang hệ 10
        res += to_string(decimal);
    }
    
    return res;
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
    cout<<binaryToHex(b[n - 1][n - 1]);
}
