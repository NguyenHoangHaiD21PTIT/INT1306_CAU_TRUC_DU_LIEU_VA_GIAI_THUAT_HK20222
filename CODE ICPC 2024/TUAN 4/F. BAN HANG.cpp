#include <bits/stdc++.h>
using namespace std;

int main(){
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3; // Nhập giá trị cho n1, n2, n3
    unordered_map<string, int> mp1, mp2, mp3;
    unordered_set<string> vList;
    vector<string> List;
    for(int i = 0; i < n1; i++){
        string x; 
        int y;
        cin >> x >> y;
        if(vList.find(x) == vList.end()){
            List.push_back(x);
            vList.insert(x);
        }
        mp1[x] += y;
    }
    for(int i = 0; i < n2; i++){
        string x; 
        int y;
        cin >> x >> y;
        if(vList.find(x) == vList.end()){
            List.push_back(x);
            vList.insert(x);
        }
        mp2[x] += y;
    }
    for(int i = 0; i < n3; i++){
        string x; 
        int y;
        cin >> x >> y;
        if(vList.find(x) == vList.end()){
            List.push_back(x);
            vList.insert(x);
        }
        mp3[x] += y;
    }
    vector<string> res;
    for(string x : List){
        if(mp1[x] >= 20 && mp2[x] >= 20 && mp3[x] >= 20) res.push_back(x);
    }
    cout << res.size() << " ";
    for(string x : res) cout << x << " ";
}
