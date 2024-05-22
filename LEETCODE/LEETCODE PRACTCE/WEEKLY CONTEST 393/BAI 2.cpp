#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPrimeDifference(vector<int>& nums) {
        // Tạo mảng để lưu index đầu tiên của số nguyên tố thứ i
        vector<int> first_prime_index(101, -1); // Số lớn nhất trong mảng là 100
        // Tạo mảng để lưu index cuối cùng của số nguyên tố thứ i
        vector<int> last_prime_index(101, -1); // Số lớn nhất trong mảng là 100
        
        // Duyệt qua mảng nums để xác định các số nguyên tố và chỉ mục tương ứng
        for (int i = 0; i < nums.size(); ++i) {
            if (isPrime(nums[i])) {
                int num = nums[i];
                if (first_prime_index[num] == -1) {
                    // Nếu chưa có index đầu tiên của số nguyên tố này, lưu lại
                    first_prime_index[num] = i;
                }
                // Luôn cập nhật index cuối cùng của số nguyên tố này
                last_prime_index[num] = i;
            }
        }
        
        int a = 1e9, b = -1e9, c = 1e9, d = -1e9;//a, b là chỉ số min, max của mảng first; c, d là chỉ số min, max của mảng last 
        for(int i = 2;i<=100;i++){
        	if(isPrime(i)){
        		if(first_prime_index[i]!=-1){
	        		a = min(a, first_prime_index[i]);
	        		b = max(b, first_prime_index[i]);
	        	}
	        	if(last_prime_index[i]!=-1){
	        		c = min(c, last_prime_index[i]);
	        		d = max(d, last_prime_index[i]);
	        	}
			}
		}
		return abs(d - a);
    }
    
    // Hàm kiểm tra xem một số có phải là số nguyên tố hay không
    bool isPrime(int n) {
        if (n <= 1) return false;
        if (n <= 3) return true;
        if (n % 2 == 0 || n % 3 == 0) return false;
        int i = 5;
        while (i * i <= n) {
            if (n % i == 0 || n % (i + 2) == 0) return false;
            i += 6;
        }
        return true;
    }
};

int main() {
    Solution sol;
    vector<int> nums1 = {4, 2, 9, 5, 3};
    cout << sol.maximumPrimeDifference(nums1) << endl; // Output: 3
    
    vector<int> nums2 = {4, 8, 2, 8};
    cout << sol.maximumPrimeDifference(nums2) << endl; // Output: 0
    
    return 0;
}