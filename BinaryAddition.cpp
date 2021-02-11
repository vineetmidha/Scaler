/*
Add two binary strings:
a = "100"
b = "11"
a+b = "111"

a = "1010110111001101101000"
b = "1000011011000000111100110"
a+b = "1001110001111010101001110"
*/

string addBinary(string a, string b) {
    if (a.size()==0 && b.size()==0) return "";
    
    if (a.size()==0) return b;
    
    if (b.size()==0) return a;

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    
    string ans = "";
    string carry = "0";
    
    for (int i=0; i<min(a.size(), b.size()); i++)    {
        if (a[i]=='0' && b[i]=='0'){
            ans += ((carry=="0") ? "0" : "1");
            carry = "0";
        } else if (a[i]=='0' && b[i]=='1' || a[i]=='1' && b[i]=='0'){
            ans += ((carry=="0") ? "1" : "0");
            carry = carry;
        } else if (a[i]=='1' && b[i]=='1') {
            ans += ((carry=="0") ? "0" : "1");
            carry = "1";
        } 
    }

    // Handle remaining digits of the larger number
    
    if (carry=="0"){
        ans += (a.size() > b.size() ? a.substr(b.size()) : b.substr(a.size()));
    } else {
        string s = (a.size() > b.size() ? a.substr(b.size()) : b.substr(a.size()));
        
        for (int i=0; i<s.size(); i++){
            if (carry=="0"){
                ans += s[i];
            } else {
                if (s[i]=='0'){
                    ans += "1";
                    carry = "0";
                } else {
                    ans += "0";
                    carry = carry;
                }
            }
        }
    }
    
    // Handle last carry
    
    if (carry=="1") ans+="1";
    
    reverse(ans.begin(), ans.end());

    return ans;
}
