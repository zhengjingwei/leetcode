#include <iostream>
#include <bits/stdc++.h>
using namespace std;

/*
 * 回溯+set去重
 */

class SolutionI {
private:
    set<vector<int>> s; // set去重
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());  // 排序使数组内部也是从小到大排序
        combinationSumCore(candidates, target, 0, curr);
        vector<vector<int>> ret(s.begin(),s.end());
        return ret;
    }

    void combinationSumCore(vector<int>& candidates, int target, int begin, vector<int>& curr){
        if(target == 0){
            s.insert(curr);
            return;
        }
        else if(target<0||begin>= candidates.size())           // curr和大于target
            return;
        for (int i = begin; i < candidates.size(); ++i) {   // 注意用变量begin控制curr数组内的数字都是从小到大
            curr.push_back(candidates[i]);
            combinationSumCore(candidates, target-candidates[i], i+1, curr); // target-candidates[i]表示选择i元素
            curr.pop_back();
        }
    }
};

/*
 * 回溯
 */
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> vec;
        sort(candidates.begin(),candidates.end());  //排序
        dpSum(candidates,target,vec,0);
        return ans;
    }

private:
    vector<vector<int>> ans;
    void dpSum(vector<int>& candidates, int target,vector<int> vec,int begin){
        if(target<0)
            return;
        else if(target==0){
            ans.push_back(vec);
        }else{
            for(int i=begin;i<candidates.size()&&candidates[i]<=target;++i){
                if(i>begin&&candidates[i-1]==candidates[i]) //目的是去重
                    continue;
                vec.push_back(candidates[i]);
                dpSum(candidates,target-candidates[i],vec,i+1);
                vec.pop_back();
            }
        }
    }
};

int main(){
    vector<int> nums = {10,1,2,7,6,1,5};
    int target = 8;
    Solution sol;
    vector<vector<int>> ret = sol.combinationSum2(nums,target);
    for (auto rows:ret){
        for (auto v:rows)
            cout << v <<" ";
        cout << endl;
    }
    return 0;
}