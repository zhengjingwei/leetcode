class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    	int n = nums1.size();
		int m = nums2.size();
		if(n > m) 
			return findMedianSortedArrays(nums2,nums1); 
		int c1,c2,l1,l2,r1,r2,low =0,high = 2*n; 
		while(low <= high){
			c1 = (low + high)/2;
			c2 = m + n - c1;
			l1 = (c1==0)?INT_MIN:nums1[(c1-1)/2];  
			r1 = (c1==2*n)?INT_MAX:nums1[c1/2];
			l2 = (c2==0)?INT_MIN:nums2[(c2-1)/2];
			r2 = (c2==2*m)?INT_MAX:nums2[c2/2];
			if(l1 > r2){
				high = c1 - 1;
			}
			else if (l2 > r1){
				low = c1 + 1;
			}
			else break ;
		}
		return (max(l1,l2) + min(r1,r2))/2.0;
    }
};