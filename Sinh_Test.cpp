// LonggVuz.
#include<bits/stdc++.h>
using namespace std;
// Noob C++
void End(){
    cerr << "=> Thời gian code chạy: ";
    cerr << (1.0 * clock() / CLOCKS_PER_SEC) << " giây" << string(27, '\t');
}
#define LonggVuz() ios_base::sync_with_stdio(false); cin.tie(NULL);
#define use(x) freopen(x".inp", "r", stdin); freopen(x".out", "w", stdout);
#define fix(x) fixed << setprecision(x)
#define all(x) x.begin(), x.end()
#define len(x) (int)x.size()
#define ms(a, x) memset(a, x, sizeof(a))
#define fo(x, n) for(int x=1; x<=n; x++)
#define tc() int TC; cin >> TC; while(TC--)
#define el '\n'
#define fi first
#define se second
#define pb push_back
#define str string
#define int intmax_t
#define db double

const int mod = 1e9 + 7;
const int oo = 1e18 + 7;
const int maxn = 1e6 + 7;

mt19937_64 rd(time(0));

int rand(int left, int right){
    return left + rd() % (right - left + 1);
}

str thg = "abcdefghijklmnopqrstuvwxyz";
str hoa = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

void sinh1(int test){
	ofstream cout((to_string(test) + ".inp").c_str());

	if(test <= 10){

	}else{

	}
}

void sinh2(int test){
	ofstream cout((to_string(test) + ".inp").c_str());

	if(test <= 30){
		
	}else if(test <= 40){
		
	}else{
		
	}
}

void data(){
	freopen("data.inp", "w", stdout);

	

	End();
}

signed main(){
    LonggVuz();

    //data(); return 0;

    fo(i, 50){
    	if(i <= 20) sinh1(i);
    	else sinh2(i);
    }

    End();
}