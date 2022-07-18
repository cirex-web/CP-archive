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
#define all(a) a.begin(),a.end()
#define vl vector<ll>
#define vvl vector<vl>
using ll = long long;
struct branch{
    branch* left = NULL,*right = NULL;
    int val = -1;
};
struct BIT{
    map<int,int> ar;vi nums;int N;
    BIT(int NVal){
        N = NVal;
    }
    ll set(int i){
        ll res = get(i); //number of things >=i (eh)
        nums.push_back(i);
        for(i++;i<N+1;i+=i&-i)ar[i]++;
        return res;
    }
    int get(int i){
        int sum = sz(nums);
        //get i-1 basically (but all distinct so you can do i) TODO:
        for(i;i;i-=i&-i)sum-=ar[i];
        // cerr<<sum<<endl;
        return sum;

    }
};
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int N; cin>>N;
    branch root;
    function<void(branch&)> prop = [&](branch& cur){
        int val;cin>>val;
        if(!val){
            // cerr<<"making branch"<<endl;
            cur.left = new branch(); cur.right = new branch();
            // cerr<<"left"<<endl;
            prop(*cur.left);
            // cerr<<"right"<<endl;
            prop(*cur.right);
        }else{
            // cerr<<"value"<<endl;
            cur.val = val;
        }
    };
    prop(root);
    ll ans = 0;
    //maybe pass it in as & 
    function<BIT(branch&)> dfs = [&](branch& curBranch){
        if(curBranch.left!=NULL){
            BIT a = dfs(*curBranch.left), b = dfs(*curBranch.right);

            if(sz(a.nums)<sz(b.nums))swap(a,b);
            ll sa = sz(a.nums), sb = sz(b.nums),start = sa,end = sa+sb-1;
            ll newInversions = (start+end)*(end-start+1)/2;
            ll inversions = 0;
            for(int num:b.nums){
                inversions+=a.set(num);
            }
            // cerr<<inversions<<" "<<newInversions<<endl;
            assert(inversions<=newInversions);
            ans+=min(inversions,newInversions-inversions);
            return a;
        }else{
            BIT cur(N);
            cur.set(curBranch.val);
            return cur;
        }
    };
    // cerr<<NULL<<endl;
    // cerr<<root.left->left->left<<endl;
    dfs(root);
    cout<<ans<<endl;
    return 0;
}
/*
4
0
0
4
3
0
2
1

*/