#include<bits/stdc++.h>
using namespace std;
long long trailZero(long long n){
	long long count = 0;
	while (n > 0) {
        n /= 5;
        count += n;
    }
    return count;
}
long long findSmallestM(long long n) {
    long long low = 0, high = 1e18;
    while (low < high) {
        long long mid = low + (high - low) / 2;
        long long zeros = trailZero(mid);
        if (zeros < n) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		long long n;
        cin >> n;
        long long result = findSmallestM(n);
        cout << result << endl;	
	}
}