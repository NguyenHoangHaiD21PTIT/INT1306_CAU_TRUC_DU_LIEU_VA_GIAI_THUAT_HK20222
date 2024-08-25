#include<bits/stdc++.h>
using namespace std;
int main(){
    double x, tong = 0, Max = double(LLONG_MIN), Min = double(LLONG_MAX);
    long long cnt = 0;
    while(cin>>x){
        tong+=x;
        Max = max(Max, x);
        Min = min(Min, x);
        cnt++;
    }
    cout<<fixed<<setprecision(3)<<Min<<" "<<Max<<" "<<tong/cnt<<endl;
}