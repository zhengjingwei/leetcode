class Solution {
public:
    int romanToInt(string s) {
		unordered_map<char, int> T = { { 'I' , 1 },
	                                   { 'V' , 5 },
	                                   { 'X' , 10 },
	                                   { 'L' , 50 },
	                                   { 'C' , 100 },
	                                   { 'D' , 500 },
	                                   { 'M' , 1000 } };
	    int num = T[s[0]] ; 
    	for( int i=1 ;i<s.size();i++){
    		if(T[s[i]] > T[s[i-1]]) 
    			num += T[s[i]] - 2*T[s[i-1]] ;
    		else 
    			num += T[s[i]];
		}
		return num;
    }
};