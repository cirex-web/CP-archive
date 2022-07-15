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
#define vb vector<bool>
#define vvb vector<vb>
#define sz(a) (int(a.size()))

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int T; cin>>T;
    FR(t,T){
        set<string> names;
        int N; cin>>N;
        bool ok = 1;
        FR(i,N){
            string name; int tl, p1,p2; cin>>name>>tl>>p1>>p2;
            if(names.count(name))ok = 0;
            names.insert(name);
            if(!(tl>0&&tl<=30&&p1>0&&p2>0&&p1%10==0&&p2%10==0&&p1+p2==100))ok = 0;
            
        }
        cout<<(ok?"Correct!":"Internal Error (response 0)")<<endl;
        
    }

    return 0;
}