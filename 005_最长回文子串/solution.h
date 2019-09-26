// 1 中心扩展法
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return s;
        int maxlen = 0, left = 0,right = 0,substr_left,substr_right,substr_len;
        string max_sub_string = "";
        for(int i = 1;i<len;++i){
            left = i -1 ;
            right = i;
            // even Palindrome  eg. "abba"
            while(left >=0 && right < len && s[left]==s[right]){
                --left;
                ++right;
            }
            substr_left = left +1;
            substr_right = right -1;
            substr_len = substr_right -substr_left +1 ;
            if(substr_len > maxlen){
                max_sub_string = s.substr(substr_left,substr_len);
                maxlen = substr_len;
            }
            
            // odd Palindrome eg. "abcba"
            left = i-1;
            right = i+1;
            while(left >=0 && right < len && s[left]==s[right]){
                --left;
                ++right;
            }
            substr_left = left +1;
            substr_right = right -1;
            substr_len = substr_right -substr_left +1 ;
            if(substr_len > maxlen){
                max_sub_string = s.substr(substr_left,substr_len);
                maxlen = substr_len;
            }   
        }
        return max_sub_string;
    }
};

// 2 动态规划
class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size();
        if(len <= 1) return s;
        int maxlen = 1 ,begin;
        bool dp[len][len]; // dp[i][j] == true -> s[i..j] is palindrome
        memset(dp,0,sizeof(dp));
        for(int i = 0; i<len ;i++){
            dp[i][i] = true; 
        }
        for(int i =0 ; i< len -1;i++){
            if(s[i]==s[i+1]){
                dp[i][i+1] = true;
                maxlen = 2;
                begin = i;
            }
        }
        for(int substr_len = 3; substr_len <= len ;substr_len ++){
            for(int i =0; i <= len -substr_len; i++){
                int j = i + substr_len -1 ;
                if(s[i] == s[j] && dp[i+1][j-1] == true){ 
                    dp[i][j] = true ;
                    begin = i;
                    maxlen = substr_len;
                }
            }
        }
        return s.substr(begin,maxlen);
    }
};
// 3 Manacher
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() <= 1) return s;
        int id=0,mx=0;
        // Manacher Algorithm
        string str = preProcess(s);
        int len = str.size();
        vector<int> p(len,0);
        for(int i =1; i< len-1;i++){
        	p[i] = mx > i ? min(p[2*id -i],mx-i):1; //mx为当前最长回文子串的右边界
        	while(str[i+p[i]] == str[i-p[i]]) // 计算P[i] 
        		p[i]++;
        	if( i + p[i] > mx){
        		mx = i+ p[i];
        		id = i;
			}
		}
		// 遍历p，寻找最大回文长度 
		int maxlen =0,index =0;
		for(int i =1;i<len-1;i++){
			if(p[i] > maxlen){
				maxlen = p[i];
				index = i;
			}
		}
		return s.substr((index - maxlen)/2,maxlen-1);	//p[i]-1为原字符串中的回文子串长度 
	}
	string preProcess(string &s){
		int n = s.size();
		string res;
		res.push_back('$');
		res.push_back('#');
		for(int i = 0; i<n ;i++){
			res.push_back(s[i]);
			res.push_back('#');
		}
		res.push_back('^');
		return res;
	}
};