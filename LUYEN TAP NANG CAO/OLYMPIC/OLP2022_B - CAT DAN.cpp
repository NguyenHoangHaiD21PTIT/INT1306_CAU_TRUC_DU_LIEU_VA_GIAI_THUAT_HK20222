#include<bits/stdc++.h>
using namespace std;
using ll = long long;

double kc(ll x1, ll y1, ll x2, ll y2){
	return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main(){
	ll x1, y1, x2, y2, x3, y3, x4, y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	double AB = kc(x1, y1, x2, y2);       double BC = kc(x2, y2, x3, y3);
	double CD = kc(x3, y3, x4, y4);       double AD = kc(x1, y1, x4, y4);
	double AC = kc(x1, y1, x3, y3);       double BD = kc(x4, y4, x2, y2);
	//Vector luu canh bien
	vector<double>v;
	v.push_back(AB); v.push_back(BC); v.push_back(CD);  v.push_back(AD); 
	sort(v.begin(), v.end());
	//Duong cheo nho hon trong 2 duong cheo
	double cheo = min(AC, BD);
	
	//Duyet cac bai
	ll t;
	cin>>t;
	ll res = 0; //so bai dung
	while(t--){
		ll a1, b1, a2, b2, a3, b3, a4, b4;
		cin>>a1>>b1>>a2>>b2>>a3>>b3>>a4>>b4;
		//vector luu cac canh bien
		vector<double>tmp;
		double c1 = kc(a1, b1, a2, b2); tmp.push_back(c1);
		double c2 = kc(a2, b2, a3, b3); tmp.push_back(c2);
		double c3 = kc(a3, b3, a4, b4); tmp.push_back(c3);
		double c4 = kc(a1, b1, a4, b4); tmp.push_back(c4);
		sort(tmp.begin(), tmp.end());
		//Tim duong cheo be hon trong 2 duong
		double cheo1 = kc(a1, b1, a3, b3); 
		double cheo2 = kc(a2, b2, a4, b4); 
		double cheocheck = min(cheo1, cheo2);
		int check = 1;
		if(cheocheck != cheo){
			check = 0;
		} else {
			for (int i = 0;i<4;i++){
				if(v[i]!=tmp[i]){
					check = 0;
					break;
				}
			}
		}
		if (check) res++;
	}
	cout<<res;
}