#include <iostream>
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string addBinary(string a, string b) {
        int i = a.size()-1;
        int j = b.size()-1;
        bool carry = false;
        string ret;
        while (i>=0 && j>=0){
            bool m = (a[i] == '1');
            bool n = (b[j] == '1');
            a[i] = m^n^carry + '0';
            carry = int(m + n + carry) > 1;
            --i,--j;
        }
        while (i>=0){
            bool m = (a[i] == '1');
            a[i] = m^carry + '0';
            carry = m && carry;
            --i;
        }
        while (j>=0){
            bool n = (b[j] == '1');
            if(n^carry)
                a.insert(a.begin(),'1');
            else
                a.insert(a.begin(),'0');
            carry = n && carry;
            --j;
        }
        if(carry)
            a.insert(a.begin(),'1');
        return a;
    }
};

int main(){
    Solution sol;
    string a = "11", b = "1";
    string s = sol.addBinary(a,b);
    cout<<s<<endl;
    return 0;
}