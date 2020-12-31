/*

769. MAX CHUNKS TO MAKE SORTED

Given an array arr that is a permutation of [0, 1, ..., arr.length - 1], 
we split the array into some number of "chunks" (partitions), and individually sort each chunk.  
After concatenating them, the result equals the sorted array.

What is the most number of chunks we could have made?

Example 1:

Input: arr = [4,3,2,1,0]
Output: 1
Explanation: Splitting into two or more chunks will not return the required result.
             For example, splitting into [4, 3], [2, 1, 0] will result in [3, 4, 0, 1, 2], which isn't sorted.
Example 2:

Input: arr = [1,0,2,3,4]
Output: 4
Explanation: We can split into two chunks, such as [1, 0], [2, 3, 4].
             However, splitting into [1, 0], [2], [3], [4] is the highest number of chunks possible.

*/
/*/////////////////////////////////////////////////////
Approach - O(n)

If a number is not max in it's chunk, then we need to break the chunk.
1. Iterate over the array.
2. Keep updating the maximum.
3. If maximum is equal to prev element, count++.

///////////////////////////////////////////////////*/
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {      
        int n = arr.size();
        int count = 0;       
        if(n==1)    count=1;

        else if(n>1){
            int temp = arr[0];
            for(int i=0; i<n; i++){
                temp = max(temp,arr[i]);
                if(temp== i) count++;
            }          
        }
        return count;
    }
};