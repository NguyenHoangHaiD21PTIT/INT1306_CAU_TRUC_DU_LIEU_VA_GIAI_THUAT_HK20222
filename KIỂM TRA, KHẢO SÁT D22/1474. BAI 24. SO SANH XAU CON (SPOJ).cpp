#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    cout << s << endl;
    int q;
    cin >> q;
    int n = s.size();
    
    vector<vector<int>> a(26, vector<int>(n, 0)); // 26 là số lượng ký tự chữ cái trong tiếng Anh
    
    unordered_map<char, int> count;
    for (int j = 1; j <= n; j++) {
        count[s[j] - 'a']++;
        for (int i = 0; i < 26; i++) a[i][j] = count[i];
    }
    
    while(q--){
        int x, y, z, t;
        cin>>x>>y>>z>>t;
        int check = 1;
        for(int i = 0;i<26;i++){
            if(a[i][y] - a[i][x - 1] != a[i][t] - a[i][z - 1]){
                check = 0;
                break;
            }
        }
        if(check ==1) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}
