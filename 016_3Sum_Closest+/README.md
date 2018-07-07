# [18. 4Sum](https://leetcode.com/problems/4sum/description/)

Given an array `nums` of *n* integers and an integer `target`, are there elements *a*, *b*, *c*, and *d* in `nums` such that *a*+ *b* + *c* + *d* = `target`? Find all unique quadruplets in the array which gives the sum of `target`.

**Note:**

The solution set must not contain duplicate quadruplets.

**Example:**

```
Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.

A solution set is:
[
  [-1,  0, 0, 1],
  [-2, -1, 1, 2],
  [-2,  0, 0, 2]
]
```



# 思路

与3Sum题目类似，先进行排序。通过固定第一个数，和第二个数，通过设置一个头指针和一个尾指针，分别从首部和尾部向中间，判断四个数之和。



# 复杂度

$O(n^3)$

（排序$O(nlogn)$ + 三重循环$O(n^3)$）




# solution

```c++
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if(nums.size()<4) return ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size(); i++){
        	for(int j = i+1 ; j < nums.size() ; j++){
        		int front = j +1 ;
        		int back = nums.size() -1;
        		int tar = target - nums[i] - nums[j];
        		while(front < back){
        			if(nums[front] + nums[back] < tar)
        				front++;
        			else if(nums[front] + nums[back] > tar)
        				back--;
        			else {
        				vector<int> turple(4,0);
        				turple[0] = nums[i];
        				turple[1] = nums[j];
        				turple[2] = nums[front];
        				turple[3] = nums[back];
        				ret.push_back(turple);
        				
        				while(front < back && nums[front] == turple[2] )  //跳过重复元素 
        					front ++;
        				while(front < back && nums[back] == turple[3] )  //跳过重复元素 
        					back --;
					}
				}
				while(j+1<nums.size() && nums[j+1] == nums[j])
					j++;
			}
			while(i+1<nums.size() && nums[i+1] == nums[i])
					i++;
		}
		return ret;
    }
};
```

