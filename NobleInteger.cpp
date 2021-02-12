/*
Given an integer array, find if an integer p exists in the array such that the number of integers greater than p in the array equals to p. If such an integer is found, return 1 else return -1.

a=[2,6,5]
Output: 1

a=[5,6,3]
Output: -1

Hidden cases:

a=[0]
Output: 1

a=[]
Output: -1
*/

int solve(vector<int> &a) {
    if (a.size()==0) return -1;
    
    if (a.size()==1)
        if (a[0]==0) return 1;
        else return -1;
        
    sort(a.begin(), a.end());
    
    for (auto i : a){
        int index = upper_bound(a.begin(), a.end(), i) - a.begin();
        int count = a.size() - index;
        if (i == count)
            return 1;
    }
    
    return -1;
}
