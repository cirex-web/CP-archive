#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;

struct knight{
    int start,death,qual,years;
};
int main(){
    int T; cin>>T;
    FR(t,T){
        int N; cin>>N;
        vector<knight> knights;
        FR(i,N){
            int start,death,qual,years;
            cin>>start>>death>>qual>>years;
            knights.push_back({start,death,qual,years});
        }
        sort(all(knights),[&](knight& a, knight& b){
            return a.start<b.start;
        });
        int i = 0;
        auto cmp = [&](int a, int b){
            return knights[a].qual>knights[b].qual;
        };
        set<int,decltype(cmp)> q(cmp);
        int start_time = -1;
        while(true){
            while(i<sz(knights)&&knights[i].start<=start_time){
                q.insert(i++);
            }
            while(sz(q)){
                int top = *q.begin(); 
                if(knights[top].death>start_time){
                    start_time = min(start_time+knights[top].years,knights[top].death);
                    goto nxt;
                }
            }
            break;
            nxt:;
            //print info
            
        }

    }
    
    return 0;
}
 