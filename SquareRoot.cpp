
// Square root of a number in O(log n) time

int Solution::sqrt(int n) {
    if (n <= 1) return n;
    
    long left = 1, right = n-1;
    long mid; 
    
    while (left <= right){
        mid = left + (right - left) / 2;
        
        if (1l*mid*mid == n)
            return mid;
        
        if (1l*mid*mid > n)
            right = mid - 1;
        else
            left = mid + 1;
    }
    
    return right;
}

