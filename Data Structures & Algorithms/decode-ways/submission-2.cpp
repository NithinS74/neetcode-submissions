class Solution {
public:
    int numDecodings(string s) {
        unordered_map<int,int> memo;
        return decode(s,0,memo);
    }
    int decode(string &s, int i,unordered_map<int,int>&memo){
        if(memo.count(i)) return memo[i];
        int n = s.size();
        if(s[i]=='0'){
            return 0;
        }if(i>=n) return 1;
        int ways = decode(s,i+1,memo);    
         if((i<n-1) && ((s[i]=='2' && s[i+1]<'7')|| (s[i]=='1') )){
            ways+= decode(s,i+2,memo);
        }
        memo[i] = ways;
        return ways;
    }
};
