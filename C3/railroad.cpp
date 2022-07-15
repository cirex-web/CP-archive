#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FORE(i,a,b) for(int i = (a); i<=(b); i++)

#define FR(i,a) FOR(i,0,a)
#define FRE(i,a) FR(i,a+1)

#define vi vector<int>
#define vvi vector<vi>
#define vb vector<bool>
#define vvb vector<vb>
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    FR(t,T){
        int A,B; cin>>A>>B;
        vi a(A),b(B),ab(A+B); 
        FR(i,A)cin>>a[i];
        FR(i,B)cin>>b[i];
        FR(i,A+B)cin>>ab[i];
        vvb dp(A+1,vb(B+1,0));
        dp[0][0] = 1;
        FRE(i,A){
            FRE(j,B){
                int k = i+j-1;
                
                if(i&&ab[k]==a[i-1])dp[i][j]=dp[i][j]||dp[i-1][j]; //can use
                if(j&&ab[k]==b[j-1])dp[i][j]=dp[i][j]||dp[i][j-1];
                // cerr<<i<<" "<<j<<" "<<dp[i][j]<<endl;
            }
        }
        cout<<(dp[A][B]?"possible":"not possible")<<endl;
    }
    return 0;
}