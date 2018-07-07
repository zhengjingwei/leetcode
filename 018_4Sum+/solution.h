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