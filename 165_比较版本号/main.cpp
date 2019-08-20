class Solution {
public:
    int compareVersion(string version1, string version2) {
        
        char c;         //提取'.'
        int num1,num2;  //提取数字
        istringstream ist1(version1);
        istringstream ist2(version2);
        
        while(bool(ist1>>num1)+bool(ist2>>num2))
        {
            if(num1>num2)   return 1;
            if(num1<num2)   return -1;
            
            num1=0;
            num2=0;
            ist1>>c;
            ist2>>c;
        }
        
        return 0;
    }
};