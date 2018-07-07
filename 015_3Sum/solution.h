class Solution {
public:
    vector<vector<int> > threeSum(vector<int>& nums) {
        vector<vector<int> > ret;
        sort(nums.begin(),nums.end());
        for(int i = 0; i < nums.size() ;i++){ //固定第一个数 
            int front = i + 1;
            int back = nums.size() -1;
            int target = -nums[i]; //两个数的和 
            while(front < back){
                if(nums[front] + nums[back] < target)
                    front ++;
                else if(nums[front] + nums[back] > target)
                    back --;
                else {
                    vector<int> turple(3,0);
                    turple[0] = nums[i];
                    turple[1] = nums[front];
                    turple[2] = nums[back];
                    ret.push_back(turple);
                    while(front < back && nums[front] == turple[1]) 
                        front++; //删除重复的元素 
                    while(front < back && nums[back] == turple[2]) 
                        back--;
                }
            } 
            while(i + 1 < nums.size() && nums[i+1] == nums[i])
                i++; //删除重复的第一个元素 
        }
        return  ret;
    }
};