/* 
42. TRAPPING RAIN WATER

Given n non-negative integers representing an elevation map where the width of each bar is 1.
Compute how much water it can trap after raining.

|
|                            ___ 
|            ___            |   |___     ___
|    ___    |   |___     ___|   |   |___|   |___
|___|___|___|___|___|___|___|___|___|___|___|___|__

I : height = [0,1,0,2,1,0,1,3,2,1,2,1]    O : 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) are being trapped.

I : height = [4,2,0,3,2,5]
O : 9
*/

// Prefix MAX and Suffix MAX - O(n)

class Solution {
public:
    int trap(vector<int>& bars) {
        
        int answer = 0;
        int n= bars.size();
        if(n>0){
            int PMAX[n],SMAX[n];

            PMAX[0] = bars[0];
            SMAX[n-1] = bars[n-1];

            for(int i=1; i<n; i++){
                PMAX[i]= max(PMAX[i-1],bars[i]);
            }
            for(int i=n-2; i>=0; i--){
                SMAX[i]= max(SMAX[i+1],bars[i]);
            }             
            for(int i = 0; i<n; i++){
                if(bars[i]<PMAX[i] && bars[i]<SMAX[i])
                    answer += min (PMAX[i],SMAX[i]) - bars[i];
            }       
        }
        return answer;  
    } 
};