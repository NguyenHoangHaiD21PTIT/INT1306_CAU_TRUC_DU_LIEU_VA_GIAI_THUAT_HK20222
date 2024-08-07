#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, x = 0, y = 0, dir = 0;
    string s;
    cin>>n>>s;
    string q = "GRBL";
    //Đánh số các hướng theo chiều kim đồng hồ
    int dx[4] = {0,1,0,-1};
    int dy[4] = {1,0,-1,0};
    for(char x1: s){
        dir = (dir+ q.find(x1))%4;
        x+=dx[dir]; y+=dy[dir];
    }
    cout<<x<<" "<<y;
}
