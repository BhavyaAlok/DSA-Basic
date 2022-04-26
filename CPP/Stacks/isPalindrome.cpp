class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for(auto x:s)
        {
            if((x<=90 && x>=65) || (x<=122 && x>=97) ||(x<=57 && x>=48)  )
            {
                if(x<=90 && x>=65)ss+= (x+32) ;
                else ss+=x;
            }
        }
        
        if(ss.size()==0) return true;
        else
        {
            string v=ss;
            std::reverse(v.begin(), v.end());
            cout<<v << " "<<ss;
            if(v==ss){return true;}
            else{return false;}
        }
    }
};
