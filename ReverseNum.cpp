/*

Reverse a number with overflow detection

You are gien an integer N and the task is to reverse the digits of the given integer. Return 0 if the result overflows and does not fit in a 32 bit signed integer. 

Constraints:
N belongs to the integer limits.

Input-1: x = 123
Input-2: x = -123

Output-1: x = 321
Output-2: x = -321

Concepts Used:
==============
Overflow in case of addition: https://www.geeksforgeeks.org/check-for-integer-overflow/
Overflow in case of multiplication: https://www.geeksforgeeks.org/check-integer-overflow-multiplication/

*/

int reverse(int a) {
    if (a == 0) return 0;
    
    bool isNegative = false;
    
    if (a < 0)
    {
        isNegative = true;
        a = abs(a);
    }
    
    int rev = 0;
    
    while (a != 0){
        int digit = a % 10;
        
        long long result = rev * 10;
        
        if (rev != result / 10) 
            return 0;
        
        rev = result + digit;

        if (rev < 0) 
            return 0;
        
        a /= 10;
    }
    
    if (!isNegative)
        return rev;
    else
        return -rev;
}


