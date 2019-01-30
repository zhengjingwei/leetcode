#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ret = 0;
        if(nums.empty())
            return 0;
        for(int i=0, j =0 ;i < nums.size(); i++){
            while(nums[j] == val && j < nums.size()){
                j++;                // 找出不等于val的值
            }
            if(j < nums.size()) {
                nums[i] = nums[j];  // 原地修改
                j+=1;               // 更新j
                ret += 1;
            }
            else
                break;
        }
        return ret;
    }
};

int main() {
    vector<int> a = {3,2,2,3};
    int val =3;
    Solution sol;
    cout<<sol.removeElement(a,val)<<endl;
    return 0;
}