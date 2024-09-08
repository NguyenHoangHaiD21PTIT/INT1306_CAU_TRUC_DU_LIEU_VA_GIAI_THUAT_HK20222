#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;
    int num_0 = 0, num_1 = 0;
    for(char x: s){
        if(x=='1') num_1++;
        else num_0++;
    }
    cout<<min(num_0, num_1) * 2;
}