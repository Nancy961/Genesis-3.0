/* ***********************************************
* 
 * 
 * Link to question - https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1
 * 
 * Question :
 * ----------
 * 
 * There are n stairs, a person standing at the bottom wants to reach the top. 
 * The person can climb either 1 stair or 2 stairs at a time. 
 * Count the number of ways, the person can reach the top (order does matter).
 * 
 * Example 1:
 * 
 * Input: n = 4
 * Output: 5
 * 
 * Explanation:
 * 
 * You can reach 4th stair in 5 ways. 
 * Way 1: Climb 2 stairs at a time. 
 * Way 2: Climb 1 stair at a time.
 * Way 3: Climb 2 stairs, then 1 stair and then 1 stair.
 * Way 4: Climb 1 stair, then 2 stairs then 1 stair.
 * Way 5: Climb 1 stair, then 1 stair and then 2 stairs.
 * 
 * Example 2:
 * 
 * Input:   n = 10
 * Output:  89 
 * 
 * Explanation: 
 * There are 89 ways to reach the 10th stair.
 * 
 * Your Task:
 * ---------
 * 
 * Complete the function countWays() which takes the top stair number m as input parameters and returns the answer % 10^9+7.
 * 
 * Expected Time Complexity : O(n)
 * Expected Auxiliary Space: O(1)
 * 
 * Constraints:
 * 1 ≤ n ≤ 104
 * 
 * 
*/
 
//  SOLUTION

#include <iostream>

using namespace std;

class Solution{

    private:

        int mem[10005];
	    int mod = 1000000007;

    public :
        Solution(){
            reset_vector();
        }

        void reset_vector() {
            for(int i=0; i<10005; i++)
                mem[i] = 0;
        }

        // Recursion - Top-down 
	    // O(2^n) TC - O(n) SC
        int CountWays (int n){
            if(n==0) return 1;
            if(n<2) return n;
            return (CountWays(n-1)%mod + CountWays(n-2)%mod)%mod;
        }

	
        // Recursion with Memoization
	    // 0(n) TC O(n) SC
        int CountWays2 (int n){
            if(n==0) return 1;
            if(n<2) return n;
            if(!mem[n]){
                mem[n] = (CountWays(n-1)%mod + CountWays(n-2)%mod)%mod;
            }
            return mem[n];
        }

	
        // Bottom up with memoization
        // O(n) TC - O(n) SC 
	
        int CountWays3 (int n){
            reset_vector();
	        mem[0] = 1; mem[1] = 1;

            for(int i=2; i<=n; i++){
               mem[i] = (mem[i-1]%mod + mem[i-2]%mod)%mod;
            }
            return mem[n];
        }

        // Bottom up with no extra space
	    // O(n) TC - O(1) SC 
        int CountWays4 (int n){
            
            int a = 1;
            int b = 1;
            int ans = 0;

            for(int i=2; i<=n; i++){
               	ans = (a%mod + b%mod)%mod;
		        a = b;
		        b = ans;
            }
            return ans;
        }

};

int main(){

    int test_cases;
    cin >> test_cases;
    int number_of_stairs = 0;

    while(test_cases--){
        cin >> number_of_stairs;
        Solution ob;
        cout<< ob.CountWays4(number_of_stairs);
    }
    return 0;
}


