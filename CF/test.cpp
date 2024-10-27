#include<bits/stdc++.h>
using namespace std;

int main() {
    map<int, int> mp;
    // add 1 to 5 to the map
    for (int i = 1; i <= 5; i++) {
        mp[i]++;
    }
    int cnt = 0;
    // check how many numbers from 1 to 10 exist in the map
    for (int i = 1; i <= 10; i++) {
        if (mp[i]) {
            cout<<"breh"<<endl;

            ++cnt;
        }
    }
    // now print the size of the map
    cout << (int)mp.size() << '\n';
    return 0;
}