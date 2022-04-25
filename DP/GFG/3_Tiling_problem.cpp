/* ***********************************************
* 
 * 
 * Link to question - https://practice.geeksforgeeks.org/problems/ways-to-tile-a-floor5836/1
 * 
 * Question :
 * ----------
 * 
 * Given a floor of dimensions 2 x W and tiles of dimensions 2 x 1, 
 * the task is to find the number of ways the floor can be tiled. 
 * A tile can either be placed horizontally i.e as a 1 x 2 tile or vertically i.e as 2 x 1 tile. 
 * Print the answer modulo 10^9+7.
 * 
 * Example 1:
 * 
 * Input: W = 3
 * Output: 3
 * 
 * Explanation:
 * 
 * We need 3 tiles to tile the board of size  2 x 3. 
 *
 * 1) Place all 3 tiles vertically. 
 * 2) Place first tile vertically and remaining 2 tiles horizontally.
 * 3) Place first 2 tiles horizontally and remaining tiles vertically.
 * 
 * Example 2:
 * 
 * Input:   W = 4
 * Output:  5
 * 
 * Explanation: 
 * For a 2 x 4 board, there are 5 ways
 * 1) All 4 vertical
 * 2) All 4 horizontal
 * 3) First 2 vertical, remaining 2 horizontal.
 * 4) First 2 horizontal, remaining 2 vertical.
 * 5) Corner 2 vertical, middle 2 horizontal.
 * 
 * Your Task:
 * ---------
 * 
 * Complete the function numberOfWays() which takes an integer N as input parameters and returns the answer % 10^9+7.
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

    int mem[100005];
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
            if(n<0) return 0;
            if(n==0) return 1;
            return (CountWays(n-1)%mod + CountWays(n-2)%mod)%mod;
        }

	
        // Recursion with Memoization
        // 0(n) TC O(n) SC
        int CountWays2 (int n){
            if(n==0) return 1;
            if(n<0) return 0;
            if(!mem[n]){
                mem[n] = (CountWays(n-1)%mod + CountWays(n-2)%mod)%mod;
            }
            return mem[n];
        }

	
        // Iteration with memoization
        // O(n) TC - O(n) SC 
        
        int CountWays3 (int n){
            reset_vector();
            mem[0] = 1; mem[1] = 1; 

            for(int i=2; i<=n; i++){
                mem[i] = (mem[i-1]%mod + mem[i-2]%mod)%mod;
            }
            return mem[n];
        }

        // Iteration with 
        // O(n) TC - O(1) SC 
        int CountWays4 (int n){
            
            int a = 1;
            int b = 1;
            int ans = 1;

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


