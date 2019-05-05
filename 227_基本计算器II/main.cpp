#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        int num = 0;
        char sign = '+';
        stack<int> nums;

        for (int i = 0; i < s.size(); ++i) {
            // 数字位；加减乘除和空格ASCII码都小于'0'
            if(s[i] >= '0'){
                num = num * 10   -'0' + s[i]; // 先做减法防止溢出
            }
            // 符号位或最后一字符（已得到最后的数字）
            if((s[i] < '0' && s[i] != ' ') || i == s.size() -1){
                if(sign == '+')
                    nums.push(num);
                else if(sign == '-')
                    nums.push(-num);
                else if(sign == '*'||sign == '/'){
                    int tmp = sign == '*'? nums.top()*num : nums.top()/num;
                    nums.pop();
                    nums.push(tmp);
                }
                sign = s[i];    //保存当前符号
                num = 0;
            }
        }

        int ret=0;  // 求和计算最终结果
        while (!nums.empty()){
            ret += nums.top();
            nums.pop();
        }
        return ret;
    }
};

int main(){
    Solution sol;
    string s = "3+2* 42";
//    string s = "3+2*2";
//    string s = " 3/2 ";
    cout<<sol.calculate(s)<<endl;
    return 0;
}