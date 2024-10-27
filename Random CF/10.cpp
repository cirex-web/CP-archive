#include <bits/stdc++.h>
using namespace std;
#define MAXI 20

bool canmake(int n, int arr[], int target) {
    for (int i = 0; i < (1<<n); i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            if ((1<<j) & i) {
                sum += arr[j];
            }
        }
        if (sum==target) return 1;
    }
    return 0;
}

bool ZiwenZapper(int n, int m, int arr1[], int arr2[]) {
    sort(arr1, arr1+n);
    sort(arr2, arr2+m);
    int a = 0, b = 0;
    for (int i = 0; i < n; i++) a += arr1[i];
    for (int i = 0; i < m; i++) b += arr2[i];
    if (b > a) return 0;
    if (canmake(n, arr1, a-b)==0) return 0;
    for (int i = 0; i < m; i++) {
        if (canmake(n, arr1, arr2[i])==0) return 0;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, t;
    int arr1[MAXI], arr2[MAXI];
    cin >> t;
    for(int j = 0; j < t; j++) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> arr1[i];
        cin >> m;
        for (int j = 0; j < m; j++) cin >> arr2[j];
        bool val = ZiwenZapper(n, m, arr1, arr2);
        cout << val << endl;
    }
    return 0;

}