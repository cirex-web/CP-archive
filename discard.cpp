#include <bits/stdc++.h>

#define FOR(i,a,b) for(int i = (a); i<(b); i++)
#define FR(i,a) FOR(i,0,a)
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0)
#define ll long long
#define vl vector<ll>
#define vi vector<int>
#define vvi vector<vi>

#define sz(a) ((int)a.size())
#define all(a) a.begin(), a.end()
#define pb(a) push_back(a)

vi prefix;
vvi sparse;
//how do you even reset??
struct node{
    node *a = NULL,*b = NULL;
    ll lazy = 0,sum = 0;
    int l,r;
    bool reset_flag = 0;
    node(int nl,int nr){
        l = nl, r = nr;
    }
    void increment(int nl, int nr, ll amt){
        if(nl>r||nr<l)return;
        if(nl<=l&&nr>=r){
            sum+=amt*(r-l+1);
            lazy+=amt;
            return;
        }
        push();
        a->increment(nl,nr,amt); b->increment(nl,nr,amt);
        sum=a->sum+b->sum;
    }
    void push(){
        if(!a){
            int mid = (l+r)/2;
            a = new node(l,mid);
            b = new node(mid+1,r);
        }
        if(reset_flag){
            a->reset(l,r);
            b->reset(l,r);
            reset_flag = 0;
        }
        if(lazy){
            a->increment(l,r,lazy);
            b->increment(l,r,lazy);
            lazy = 0;
        }
    }
    void reset(int nl, int nr){
        
        if(nl>r||nr<l)return;
        if(nl<=l&&nr>=r){
            reset_flag = 1;
            lazy = 0;
            sum = 0;
            // sum = prefix[r+1]-prefix[l]; 
//             cerr<<l<<" "<<r<<" "<<sum<<endl;
            return;
        }
        push();
        a->reset(nl,nr); b->reset(nl,nr);
        sum = a->sum+b->sum;
    }
    ll get(int nl, int nr){
        if(nl>r||nr<l)return 0;
        if(nl<=l&&nr>=r){
            return sum;
        }
        push();
        return a->get(nl,nr)+b->get(nl,nr);
    }
};
struct no_reset_min_node{
no_reset_min_node *a = NULL,*b = NULL;
    ll lazy = 0,minimum = 0;
    int l,r;
    ll original_minimum; //after setup
    no_reset_min_node(int nl,int nr){
        l = nl, r = nr;
    }
    void increment(int nl, int nr, ll amt){
        if(nl>r||nr<l)return;
        if(nl<=l&&nr>=r){
            minimum+=amt;
            lazy+=amt;
            return;
        }
        push();
        a->increment(nl,nr,amt); b->increment(nl,nr,amt);
        minimum = min(a->minimum,b->minimum);
    }
    void push(){
        if(!a){
            int mid = (l+r)/2;
            a = new no_reset_min_node(l,mid);
            b = new no_reset_min_node(mid+1,r);
        }

        if(lazy){
            a->increment(l,r,lazy);
            b->increment(l,r,lazy);
            lazy = 0;
        }
    }

    ll get(int nl, int nr){
        if(nl>r||nr<l)return LLONG_MAX;
        if(nl<=l&&nr>=r){
            return minimum;
        }
        push();
        return min(a->get(nl,nr),b->get(nl,nr));
    }
};
no_reset_min_node* og_min_root;
struct min_node{
    min_node *a = NULL,*b = NULL;
    ll lazy = 0,minimum = 0;
    int l,r;
    bool reset_flag = 0;
    ll original_minimum; //after setup
    min_node(int nl,int nr){
        l = nl, r = nr;
    }
    void increment(int nl, int nr, ll amt){
        if(nl>r||nr<l)return;
        if(nl<=l&&nr>=r){
            minimum+=amt;
            lazy+=amt;
            return;
        }
        push();
        a->increment(nl,nr,amt); b->increment(nl,nr,amt);
        minimum = min(a->minimum,b->minimum);
    }
    void push(){
        if(!a){
            int mid = (l+r)/2;
            a = new min_node(l,mid);
            b = new min_node(mid+1,r);
        }
        if(reset_flag){
            a->reset(l,r);
            b->reset(l,r);
            reset_flag = 0;
        }
        if(lazy){
            a->increment(l,r,lazy);
            b->increment(l,r,lazy);
            lazy = 0;
        }
    }
    void reset(int nl, int nr){
        
        if(nl>r||nr<l)return;
        if(nl<=l&&nr>=r){
            reset_flag = 1;
            lazy = 0;
            minimum = og_min_root->get(l,r);  
            // cerr<<l<<" "<<r<<" "<<sum<<endl;
            return;
        }
        push();
        a->reset(nl,nr); b->reset(nl,nr);
        minimum = min(a->minimum,b->minimum);
    }
    ll get(int nl, int nr){
        if(nl>r||nr<l)return LLONG_MAX;
        if(nl<=l&&nr>=r){
            return minimum;
        }
        push();
        return min(a->get(nl,nr),b->get(nl,nr));
    }
};
int main(){
    fast;
    int T; cin>>T;
    FR(t,T){
        
        int N,Q; cin>>N>>Q;
        min_node min_root(0,N-1);
        node filled_root(0,N-1);
        og_min_root = new no_reset_min_node(0,N-1); //for restoration
        prefix.clear();prefix.resize(N+1,0); //for restoration
        
        ll ans = 0;

        FR(i,N){
            ll cur; cin>>cur;
            prefix[i+1]=prefix[i]+cur;
            og_min_root->increment(i,i,cur);
            min_root.increment(i,i,cur);
        }
        cout<<prefix[999];
        // FR(i,N)cout<<min_root.get(i,i+1)<<endl;
        FR(q,Q){
            char t; int l,r;cin>>t>>l>>r;l--;r--;
            if(t=='+'){
                ll inc = min_root.get(l,r);
                // cerr<<inc<<endl;
                filled_root.increment(l,r,inc);
                min_root.increment(l,r,-inc); //remove 
            }else{
                ans+=filled_root.get(l,r);
                // cerr<<filled_root.get(l,r)<<endl;
                filled_root.reset(l,r);
                assert(filled_root.get(l,r)==0);
                min_root.reset(l,r);
            }
        }
        cout<<ans<<endl;
    }
    // min_node min_root()
    // node test(0,5);
    // // test.reset(0,2);
    // while(1){
    //     int t,l,r;cin>>t>>l>>r;
    //     if(t==1){

    //         cout<<test.get(l,r)<<endl;
    //     }else if(t==2){
    //         test.reset(l,r);
    //     }else{
    //         int amt; cin>>amt;
    //         test.increment(l,r,amt);
    //     }
    // }
    // int T; cin>>T;
    // FR(t,T){
       
    // }
}