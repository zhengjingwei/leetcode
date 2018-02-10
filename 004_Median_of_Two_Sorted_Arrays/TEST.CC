#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        if(n > m)   //????1????
            return findMedianSortedArrays(nums2,nums1);
        int L1,L2,R1,R2,c1,c2,lo = 0, hi = 2*n;  //?????????'#'????1?2*n??
        while(lo <= hi)   //??
        {
            c1 = (lo+hi)/2;  //c1??????
            c2 = m+n- c1;
            L1 = (c1 == 0)?INT_MIN:nums1[(c1-1)/2];   //map to original element
            R1 = (c1 == 2*n)?INT_MAX:nums1[c1/2];
            L2 = (c2 == 0)?INT_MIN:nums2[(c2-1)/2];
            R2 = (c2 == 2*m)?INT_MAX:nums2[c2/2];

            if(L1 > R2)
                hi = c1-1;
            else if(L2 > R1)
                lo = c1+1;
            else
                break;
        }
        return (max(L1,L2)+ min(R1,R2))/2.0;
    }
};

int main(int argc, char** argv) {
	int a[7] = {1,2,3,4,5,6,7};  
	vector<int> v1(a,a+7);
	cout<<INT_MIN<<endl;
	cout<<INT_MAX<<endl;
	return 0;
}
