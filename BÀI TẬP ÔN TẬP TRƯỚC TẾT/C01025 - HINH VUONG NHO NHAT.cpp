#include<bits/stdc++.h>
using namespace std;
int main(){
	int x1,y1,x2,y2,x3,y3,x4,y4;
	cin>>x1>>y1>>x2>>y2>>x3>>y3>>x4>>y4;
	int xmin=min(x1,min(x2,min(x3,x4)));
	int xmax=max(x1,max(x2,max(x3,x4)));
	int ymin=min(y1,min(y2,min(y3,y4)));
	int ymax=max(y1,max(y2,max(y3,y4)));
	int x = xmax-xmin;
	int y = ymax-ymin;
	if(x>=y){
		cout<<x*x;
	} else {
		cout<<y*y;
	}
}
		