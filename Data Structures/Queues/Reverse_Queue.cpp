/////////////////////////////////////////////////////////////////////////////////////////////////////////

// Queue Reversal - GFG

////////////////////////////////////////////////////////////////////////////////////////////////////////
/*
Given a Queue Q containing N elements. The task is to reverse the Queue. Your task is to complete the function rev(), that reverses the N elements of the queue.
Input:
6
4 3 1 10 2 6
Output: 
6 2 10 1 3 4

Input:
4
4 3 2 1 

Output: 
1 2 3 4
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////
/* Approach - O(n),  O(n)

    Using Stack.
    1. Pop elements from the front of queue and push into stack. 
    2. When Queue is empty, we have all elements Queue in Stack in reversed manner (bottom to top).
    3. Pop elements from Stack and push in Queue.
    4. Reversed
*/
//////////////////////////////////////////////////////////////////////////////////////////////////////////

queue<long long int> rev(queue<long long int> q)
{
    stack<long long int> S;
    while(!q.empty()){
        S.push(q.front());
        q.pop();
    }
    while(!S.empty()){
        q.push(S.top());
        S.pop();
    }
    return q;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////////