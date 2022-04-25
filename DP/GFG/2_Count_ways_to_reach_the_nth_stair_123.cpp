/* ***********************************************
* 
 * 
 * Link to question - https://www.geeksforgeeks.org/count-ways-reach-nth-stair-using-step-1-2-3/
 * 
 * Question :
 * ----------
 * 
 * A child is running up a staircase with n steps and can hop either 1 step, 2 steps, or 3 steps at a time. 
 * Implement a method to count how many possible ways the child can run up the stairs.
 * 
 * Example 1:
 * 
 * Input: n = 4
 * Output: 7
 * 
 * Explanation:
 * 
 * Below are the seven ways
 * 1 step + 1 step + 1 step + 1 step
 * 1 step + 2 step + 1 step
 * 2 step + 1 step + 1 step 
 * 1 step + 1 step + 2 step
 * 2 step + 2 step
 * 3 step + 1 step
 * 1 step + 3 step
 * 
 * Example 2:
 * 
 * Input:   n = 3
 * Output:  4
 * 
 * Explanation: 
 * 1 step + 1 step + 1 step
 * 1 step + 2 step
 * 2 step + 1 step
 * 3 step
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
        // O(3^n) TC - O(n) SC
        int CountWays (int n){
            if(n==0) return 1;
            if(n<3) return n;
            return (CountWays(n-1)%mod + CountWays(n-2)%mod + CountWays(n-3)%mod)%mod;
        }

	
        // Recursion with Memoization
        // 0(n) TC O(n) SC
        int CountWays2 (int n){
            if(n==0) return 1;
            if(n<3) return n;
            if(!mem[n]){
                mem[n] = (CountWays(n-1)%mod + CountWays(n-2)%mod + CountWays(n-3)%mod)%mod;
            }
            return mem[n];
        }

	
        // Iteration with memoization
        // O(n) TC - O(n) SC 
        
        int CountWays3 (int n){
            reset_vector();
            mem[0] = 1; mem[1] = 1; mem[2] = 2;

            for(int i=3; i<=n; i++){
                mem[i] = (mem[i-1]%mod + mem[i-2]%mod + mem[i-3]%mod)%mod;
            }
            return mem[n];
        }

        // Iteration with 
        // O(n) TC - O(1) SC 
        int CountWays4 (int n){
            
            int a = 1;
            int b = 1;
            int c = 2;
            int ans = 0;

            for(int i=3; i<=n; i++){
                ans = (a%mod + b%mod + c%mod)%mod;
                a = b;
                b = c;
                c = ans;
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


