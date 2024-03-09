#include<iostream>
#include<set>
#include<vector>
#include<stack>

using namespace std;

int n, v; //n la so dinh, v la dinh bat dua tim chu trinh/ duong di
int a[30][30];

void EULER(int a[][30], int v){
	//Buoc 1: Khoi tao
    stack<int>st;
    vector<int>CE;
    st.push(v);
    //Buoc 2: Lap
    while(st.size()!=0){
        int x = st.top();
        int cnt = 0;//dem so dinh ke voi dinh x
        for(int i = 1;i<=n;i++){
        	if(a[x][i]) cnt++;
		}
        if(cnt){ //con dinh ke
        	//Lay dinh ke dau tien cua dinh x ra
        	int p;
            for(int i = 1;i<=n;i++){
            	if(a[x][i]){
            		p = i;
            		break;
				}
			}
			//Dua dinh do vao trong ngan xep
            st.push(p);
            //Xoa canh (x,p)
            a[x][p] = a[p][x] = 0;
        } else {
            st.pop();
            CE.push_back(x);
        }
    }
    //Buoc 3: Lat nguoc CE;
    for(int i = CE.size()-1;i>=0;i--) cout<<CE[i]<<" ";	
}

int main(){
    cin>>n>>v;
    for(int i = 1;i<=n;i++){
    	for(int j = 1;j<=n;j++) cin>>a[i][j];
	}
    EULER(a, v);
}
/*
13 1
0 1 0 0 0 0 0 1 1 0
0 0 1 1 0 0 0 0 0 0
0 0 0 1 1 0 0 0 0 0
1 0 0 0 0 1 0 0 0 0
1 0 0 0 0 0 1 0 0 0
0 0 1 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1 1 0
0 0 0 0 0 0 0 0 1 1
0 0 0 0 1 1 0 0 0 1
0 1 0 0 0 0 0 0 0 0 */
