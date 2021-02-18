
/*

Implement Power Function

Implement pow(x, n) % d.

In other words, given x, n and d:

find (x^n % d)

Note that remainders on division cannot be negative. In other words, make sure the answer you return is non-negative. 

Input: x = 2, y = 3, d = 3
Output: 2

Explanation: 2 ^ 3 % 3 => 8 % 3 => 2
*/

long fastPower(int a, int b, int m){
    if (a==0) return 0;
    
    if (b==0) return 1;

    long ans = fastPower(a, b/2, m);
    
    if (b%2==0)
        return (ans%m * ans%m) % m;
    else
        return (a%m * ans%m * ans%m) % m;
}

int pow(int a, int b, int m) {

    int ans = fastPower(a, b, m);
    
    if (ans < 0)
        return (ans + m) % m;
    else
        return ans;
}
