class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> s;
        for(int i = 1;i<=n;++i){
            string tmp;
            if(!(i%3) && !(i%5))
                tmp = "FizzBuzz";
            else if(!(i%3))
                tmp = "Fizz";
            else if(!(i%5))
                tmp = "Buzz";
            else
                tmp = to_string(i);
            s.push_back(tmp);
        }
        return s;
    }
};