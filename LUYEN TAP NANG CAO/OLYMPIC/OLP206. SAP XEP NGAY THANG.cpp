#include <bits/stdc++.h>
using namespace std;
void chuanhoa(string &s){//chuan hoa ngay sinh
	if(s[1]=='/') s="0"+s;
	if(s[4]=='/') s.insert(3,"0");
}
bool cmp(const string &a, const string &b) {
    string year_a = a.substr(6, 4), year_b = b.substr(6, 4);
    string month_a = a.substr(3, 2), month_b = b.substr(3, 2);
    string day_a = a.substr(0, 2), day_b = b.substr(0, 2);
    if (year_a != year_b) return year_a < year_b;
    if (month_a != month_b) return month_a < month_b;
    return day_a < day_b;
}
int main(){
    int t; cin>>t;
    cin.ignore();
    vector<string> d(t);
    for (int i = 0; i < t; ++i) {
        cin>>d[i];
        chuanhoa(d[i]); 
    }
    sort(d.begin(), d.end(), cmp);
    for(string x: d) cout<<x<<endl;
}