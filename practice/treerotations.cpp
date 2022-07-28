#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int (i) = (a); i<(b); i++)
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
    branch* left = nullptr,*right = nullptr;
    int val = -1;
};
struct BIT{
    map<int,int> ar;vi nums;int N;

    BIT(int NVal){
        N = NVal;
    }//what why
    void set(int i){
        nums.push_back(i);
//        cerr<<i<<endl;
        assert(i>0&&i<=N);
        for(i;i<N+1;i+=i&-i)ar[i]++;
    }
    ll get(int i){
        ll sum = sz(nums);
        for(;i;i-=i&-i)sum-=ar[i]; //technically inclusive but i shouldn't even exist at this point
        // cerr<<sum<<endl;
        return sum;

    }
};
int main(){
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin>>N;
    branch root;
    function<void(branch&)> prop = [&](branch& cur){
        int val;cin>>val;
        if(!val){
//            cerr<<"make two branches"<<endl;
            cur.left = new branch(); cur.right = new branch();
            prop(*cur.left);
            prop(*cur.right);
        }else{
            cur.val = val;
//            cerr<<"set!"<<endl;
        }
    };
    prop(root);
    ll ans = 0;
    //maybe pass it in as & 
    function<BIT(branch&)> dfs = [&](branch& curBranch){
        if(curBranch.left!=nullptr){
            BIT a = dfs(*curBranch.left), b = dfs(*curBranch.right);
//            cerr<<&a<<" "<<&b<<endl;
            if(sz(a.nums)<sz(b.nums))swap(a,b);
            ll newInversions = sz(b.nums)*sz(a.nums);
            ll inversions = 0;
//            cerr<<a.nums[0]<<endl;
            for(int num:b.nums){
//                cerr<<num<<endl;
                inversions+=a.get(num); //add all of this;
            }
            cerr<<inversions<<" "<<newInversions<<endl;
            for(int num:b.nums)a.set(num); //add them in now
            ans+=min(inversions,newInversions-inversions);

//            cerr<<"return "<<&a<<endl;

            return a;
        }else{
            BIT* cur = new BIT(N);
            cur->set(curBranch.val);

//            cerr<<"return "<<&cur<<endl;
            return *cur;
        }
    };

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


5
0
0
0
1
2
0
3
4
5


 5
 0
 0
 0
 5
 3
 0
 4
 2
 1

*/