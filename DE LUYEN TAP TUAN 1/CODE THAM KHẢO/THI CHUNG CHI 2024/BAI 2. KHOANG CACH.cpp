#include<bits/stdc++.h>
using namespace std;
int main(){
    int x = 0, y = 0;
    string s;
    cin>>s;
    for(char x1: s){
        if(x1=='E') x++;
        else if(x1=='N') y++;
        else if(x1=='W') x--;
        else y--;
    }
    cout<<fixed<<setprecision(2)<<sqrt(pow(x, 2) + pow(y, 2));
}