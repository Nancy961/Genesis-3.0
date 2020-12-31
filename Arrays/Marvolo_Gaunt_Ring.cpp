/*
855B - 42 MARVOLO GAUNT RING - CODEFORCES

Professor Dumbledore is helping Harry destroy the Horcruxes. He went to Gaunt Shack as he suspected a Horcrux to be present there. He saw Marvolo Gaunt's Ring and identified it as a Horcrux. Although he destroyed it, he is still affected by its curse. Professor Snape is helping Dumbledore remove the curse. For this, he wants to give Dumbledore exactly x drops of the potion he made.
Value of x is calculated as maximum of p·ai + q·aj + r·ak for given p, q, r and array a1, a2, ... an such that 1 ≤ i ≤ j ≤ k ≤ n. Help Snape find the value of x. Do note that the value of x may be negative.

Input
First line of input contains 4 integers n, p, q, r ( - 109 ≤ p, q, r ≤ 109, 1 ≤ n ≤ 105).
Next line of input contains n space separated integers a1, a2, ... an ( - 109 ≤ ai ≤ 109).

Output
Output a single integer the maximum value of p·ai + q·aj + r·ak that can be obtained provided 1 ≤ i ≤ j ≤ k ≤ n.

Example 1:
 I : 5 1 2 3
     1 2 3 4 5
 O : 30

Example 2:
 I : 5 1 2 -3
     -1 -2 -3 -4 -5
 O : 12

*/

// Prefix Sum && Suffix Sum - O(n)
#include<bits/stdc++.h>
#define ll long long int
using namespace std;
 
int main(){
    ll n, p,q,r;
    cin>> n>> p>> q >> r;
    ll arr[n];
    for(ll i =0; i<n; i++){
        cin>>arr[i];
    }
    ll PMAX[n], SMAX[n];
    ll maxm = LLONG_MIN;
    for(ll i =0; i<n; i++){
        maxm = max(maxm,arr[i]*p);
        PMAX[i]= maxm;
    }
    maxm = LLONG_MIN;
    for(ll i =n-1; i>=0; i--){
        maxm = max(maxm,arr[i]*r);
        SMAX[i]= maxm;
    }
    ll answer = LLONG_MIN;
    for(ll i =0; i<n; i++){
        ll pi = PMAX[i];
        ll rk = SMAX[i];
        answer = max (answer, (pi + rk + arr[i]*q));
    }
    cout<< answer <<"\n";
    return 0;
}