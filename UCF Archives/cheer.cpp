#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)

int main(){
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        long long prev = LLONG_MAX, sum = 0;
        vector<long long> ar(N);
        FR(i,N){
           cin>>ar[i];
            
        }
        sort(ar.rbegin(),ar.rend());
        FR(i,N){
            if(prev-ar[i]>=2){
                cerr<<ar[i]<<endl;
                prev = ar[i];
                sum+=ar[i];
            }
        }
        cout<<sum<<endl;
    }
}