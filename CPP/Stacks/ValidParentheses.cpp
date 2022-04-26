#include<stack>
class Solution {
public:
    bool isValid(string s) {
        std::stack<char>left;
        std::stack<char>right;
        
        bool flag = true;
        
        // if(s[0] == ']' || s[0] == '}' || s[0]==')')return false;
        for(auto x:s)
        {
            if(x == '(' || x == '[' || x == '{')
            {
                left.push(x);
            }
            else    
            {

                
                if(left.size() == 0 ) { return false;}
                else{
                   char temp = left.top();
                if( (temp == '(' && x==')') || (temp == '[' && x==']') || (temp == '{' && x=='}') ){left.pop(); continue;}
                else {flag=false; break;}
                }
               }
                
            }
        
        
        if(flag == true && left.size() == 0 ){return true;}
            else{
                return false;
            }
    }
};
