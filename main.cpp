#define ll long long
class Solution {
public:
string s;
int mod=1e9+7;
unordered_set<string> st;
int dp[100001];
    ll solve(int index){
        if(index==s.size()){
            return 1;
        }

        if(dp[index]!=-1)
        return dp[index];

        if(index==s.size()-1){
            if(s[index]=='0')
            return 0;

           else if(s[index]=='*'){
                return 9;
            }
           else return 1;

        }

        int ch1=s[index],ch2=s[index+1];
        ll ans=0;
        if(ch1==0)
        return 0;

       

        if(ch1=='*'){
            ans=(ans+(9*solve(index+1)))%mod;
        }
        else {
            if(ch1=='0')
            return 0;

            else ans=(ans+solve(index+1))%mod;
        }

        if(ch1=='*'&&ch2=='*'){
           ans=(ans+15*solve(index+2))%mod;
        }

        if(ch1!='*'&&ch2=='*'){
          if(ch1=='1')
          ans=(ans+9*solve(index+2))%mod;
          else if(ch1=='2')
          ans=(ans+6*solve(index+2))%mod;

        }

        if(ch1=='*'&&ch2!='*'){
           if(ch2<='6'){
            ans=(ans+2*solve(index+2))%mod;
           }
           else ans=(ans+1*solve(index+2))%mod;
        }

        if(ch1!='*'&&ch2!='*'){
            string s2="";
            s2.push_back(ch1);
            s2.push_back(ch2);
          if(st.find(s2)!=st.end())
          ans=(ans+solve(index+2))%mod;
        }



        

      return dp[index]=ans%mod;


    }
    int numDecodings(string s) {
        this->s=s;
        
        memset(dp,-1,sizeof(dp));
        for(int i=1;i<=26;i++){
           st.insert(to_string(i));
        }
        return solve(0);
    }
};
