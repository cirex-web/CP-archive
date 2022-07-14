#include <bits/stdc++.h>

using namespace std;
#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
#define sz(a) ((int)a.size())
#define ROF(i,a,b) for(int i = (a); i>=(b);i--)
#define all(a) a.begin(),a.end()
using vi = vector<int>;
using ll = long long;
using pii = pair<int,int>;
using pdd = pair<double,double>;


bool chk(string& a, string& b){
    int difs = 0;
    FR(i,sz(a)){
        difs+=a[i]!=b[i];
    }
    return difs==1;
}
int main(){
    int T;cin>>T;
    FR(t,T){
        int D,Q,N; cin>>D>>Q>>N;
        vector<string> words;
        map<string,int> index;
        FR(d,D){
            string word; cin>>word;
            words.push_back(word);
            index[word] = d;
        }
        vector<vector<int>> g(D);
        FR(i,D){
            FOR(j,i+1,D){
                FR(k,N){
                    if(chk(words[i],words[j])){
                        g[i].push_back(j);
                        g[j].push_back(i);
                    }
                }
            }
        }
        FR(_,Q){
            string As,Bs; cin>>As>>Bs;
            int A = index[As], B = index[Bs];
            vi dist(D,INT_MAX);
            dist[A] = 0;
            queue<int> q; q.push(A);
            while(sz(q)){
                int a = q.front(); q.pop();
                for(int b: g[a]){
                    if(dist[b]==INT_MAX){
                        dist[b] = dist[a]+1;
                        q.push(b);
                    }
                }
            }
            cout<<(dist[B]==INT_MAX?-1:dist[B])<<endl;
        }

    }
    
    return 0;
}