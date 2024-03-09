#include<bits/stdc++.h>
using namespace std;
double kc(int x1, int y1, int x2, int y2){
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int k;//ti le
		cin>>k;
		int check = 1;
		int xa,ya,xb,yb,xc,yc,xd,yd;
		cin>>xa>>ya>>xb>>yb>>xc>>yc>>xd>>yd;
		double ab = kc(xa,ya,xb,yb);
		double bc = kc(xb,yb,xc,yc);
		double ca = kc(xc,yc,xa,ya);
		double da = kc(xd,yd,xa,ya);
		if(ab+bc>ca&&bc+ca>ab&&ca+ab>bc){
			double ak=(double)ab*ca/(k*da);
			if(ak>ca){
				check = 0;
			} else {
				double xk, yk;
				double p = (double) ak/ca;
				xk = (p*(xc-xa)+xa);
				yk = (p*(yc-ya)+ya);
				cout<<fixed<<setprecision(2)<<xk<<" "<<yk;
			}
		} else {
			check = 0;
		}
		if(check==0){
			cout<<"No solution";
		}
		cout<<endl;
	}
}