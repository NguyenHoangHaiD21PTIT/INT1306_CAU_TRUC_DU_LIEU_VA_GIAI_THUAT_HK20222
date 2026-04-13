#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k; cin >> n >> k;
    vector<int>a;
    for(int i = 1;i <= n;i++){
        if(i != k) a.push_back(i);
    }
    for(int x: a) cout << x << " ";
    cout << k << endl;
    while(next_permutation(a.begin(), a.end())){
        for(int x: a) cout << x << " ";
        cout << k << endl;
    }
}
