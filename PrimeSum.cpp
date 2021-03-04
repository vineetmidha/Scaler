
/*
Prime Sum

Given an even number A (greater than 2), return two prime numbers whose sum will be equal to given number. If there are more than one solutions possible, return the lexicographically smaller solution. 
If [a,b] is one solution with a <= b, and [c,d] is another solution with c <= d, then [a, b] < [c, d], if a < c OR a == c AND b < d.

NOTE: A solution will always exist. Read Goldback's conjecture. 

Constraints:
4 <= A <= 2*10^7

Input: First and only argument of input is an even number A.
Output: Return an integer array of size 2 containing prime whose sum will be equal to given number. 

Example:
Input: 4
Output: [2, 2]

Input: 138
Output: [7, 131]
*/

#include<bits/stdc++.h>

using namespace std;

#define ll long long

vector<bool> sieve(ll SIZE)
{
    vector<bool> isPrime(SIZE, true);
    
    for (ll i = 2; i*i <= SIZE; i++){
        if (isPrime[i]){
            for (ll j = i*i; j<SIZE; j+=i){
                isPrime[j] = false;
            }
        }
    }        
    
    return isPrime;
}

vector<int> Solution::primesum(int a) {
    vector<bool> isPrime = sieve(a);
    vector<int> result; 
    for (int i = 2; i <= a/2; i++){
        int j = a - i;
        if (isPrime[i] && isPrime[j]){
            result.push_back(i);
            result.push_back(j);
            return result;
        }
    }
    return result;
}
