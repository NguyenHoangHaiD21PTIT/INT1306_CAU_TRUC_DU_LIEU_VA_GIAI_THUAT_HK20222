#include<bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
using namespace std;
int n,x[51][4],a[300][300];
int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
map<int,int>z[2];
void asu(int p){
  int cnt=1;
  vector<int>v;
  r(i,n)r(j,4)if(j%2==p)v.push_back(x[i][j]);
  sort(v.begin(),v.end());
  v.erase(unique(v.begin(),v.end()),v.end());
  r(i,v.size())z[p][v[i]]=cnt,cnt+=2;
}
void make_G(){
  r(i,n){
    for(int j=z[0][x[i][0]];j<=z[0][x[i][2]];j++)
      a[z[1][x[i][1]]][j]=1,a[z[1][x[i][3]]][j]=1;
    for(int j=z[1][x[i][1]];j<=z[1][x[i][3]];j++)
      a[j][z[0][x[i][0]]]=1,a[j][z[0][x[i][2]]]=1;
  }
}
void bfs(int y,int x){
  a[y][x]=1;
  queue<pair<int,int> >q;
  q.push(make_pair(y,x));
  while(!q.empty()){
    pair<int,int>p=q.front();q.pop();
    y=p.first,x=p.second;
    r(i,4){
      int yy=y+dy[i],xx=x+dx[i];
      if(yy<0||xx<0||yy>=300||xx>=300)continue;
      if(!a[yy][xx]){
        a[yy][xx]=1;
        q.push(make_pair(yy,xx));
      }
    }
  }
}
int main(){
    int t;
    cin >>t;
  while(t--){
      cin >>n;
    int ans=0;
    memset(a,0,sizeof(a));
    r(i,2)z[i].clear();
    r(i,n){
      r(j,4)cin>>x[i][j];
      if(x[i][0]>x[i][2])swap(x[i][0],x[i][2]);
      if(x[i][1]>x[i][3])swap(x[i][1],x[i][3]);
    }
    r(i,2)asu(i);
    make_G();
    r(i,300)r(j,300)if(!a[i][j])ans++,bfs(i,j);
    cout<<ans<<endl;
  }
}
