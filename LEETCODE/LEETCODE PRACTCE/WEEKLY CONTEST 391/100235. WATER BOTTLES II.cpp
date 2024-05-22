#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
    	//Ban đầu
    	int fullBottles = numBottles;
	    int emptyBottles = 0;
	    int exchange = numExchange;
	    int drunk = 0;    
	    while (fullBottles > 0 || (emptyBottles >= exchange && fullBottles <= 0)) {
        	// Uống hết số chai hiện có nếu còn chai nhưng số chai trống không đủ trao đổi
	        if (fullBottles > 0 && emptyBottles < exchange) {
	            drunk += fullBottles;
	            emptyBottles += fullBottles;
	            fullBottles = 0;
	        } else {
	            // Đổi tối đa số chai trống có thể
	            fullBottles += 1;//đổi exc chai trống lấy 1 chai đầy
	            emptyBottles -= exchange;//giảm số chai trống đi
	            // Tăng số lượng cho phép trao đổi
	            exchange++;
	        }
    	}
    	return drunk;  
    }
};
int main(){
	Solution sol;
	int t = 2;
	while(t--){
		int m, n;
		cin>>m>>n;
		cout<<sol.maxBottlesDrunk(m, n)<<endl;
	}
}
/*
Ví dụ 1: Có 13 chai đầy, số cho phép trao đổi exc = 6
Lần 1: Uống hết 13 chai, còn 0 chai đầy, 13 chai trống, exc = 6, đã uống = 13
Lần 2: Đổi 6 chai trống lấy 1 chai đầy thì còn 1 chai đầy, 7 chai trống, exc = 7, đã uống = 13
Lần 3: Đổi 7 chai trống lấy 1 chai đầy thì còn 2 chai đầy, 0 chai trống, exc = 8, đã uống = 13
Lần 4: Uống hết 2 chai, còn 0 chai đầy, 2 chai trống, exc = 8, đã uống = 15
Do số lượng chai trống < exc nên không thể đổi tiếp. Đáp số là 15
*/

/*
Ví dụ 2: Có 10 chai đầy, số cho phép trao đổi exc = 3
Lần 1: Uống hết 10 chai, còn 0 chai đầy, 10 chai trống, exc = 3, đã uống = 10
Lần 2: Đổi 3 chai trống lấy 1 chai đầy thì còn 1 chai đầy, 7 chai trống, exc = 4, đã uống = 10
Lần 3: Đổi 4 chai trống lấy 1 chai đầy thì còn 2 chai đầy, 3 chai trống, exc = 5, đã uống = 10
Lần 3: Uống hết 2 chai, còn 0 chai đầy, 5 chai trống, exc = 5, đã uống = 12
Lần 4: Đổi 5 chai trống lấy 1 chai đầy thì còn 1 chai đầy, 0 chai trống, exc = 6, đã uống = 12
Lần 5: Uống hết 1 chai, còn 0 chai đầy, 1 chai trống, exc = 6, đã uống  = 13
Do số lượng chai trống < exc nên không thể đổi tiếp. Đáp số là 13
*/