#include<stdio.h>
#include<math.h>
int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		double xa, ya, xb, yb, xc, yc;
		scanf("%lf%lf%lf%lf%lf%lf", &xa, &ya, &xb, &yb, &xc, &yc);
		double ab=sqrt((xa-xb)*(xa-xb)+(ya-yb)*(ya-yb));
		double bc=sqrt((xb-xc)*(xb-xc)+(yb-yc)*(yb-yc));
		double ca=sqrt((xc-xa)*(xc-xa)+(yc-ya)*(yc-ya));
		if(ab+bc>ca&&bc+ca>ab&&ca+ab>bc){
			double p=(double) (ab+bc+ca)/2;
			double s=sqrt(p*(p-ab)*(p-bc)*(p-ca));
			printf("%.2lf\n", s);
		} else {
			printf("INVALID\n");
		}
	}
}


