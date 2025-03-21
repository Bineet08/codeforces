#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int odd_max = 0, even_max = 0;

        int i=0;
        int arr=0;
        for(int i=0;i<n;i++){
            cin >> arr;
            if (i % 2 == 0) {
                even_max = max(even_max, arr);
            } else {
                odd_max = max(odd_max, arr);
            }
        }
        int res=max(even_max+ (n+1)/2,odd_max + n/2);
        cout << res << endl;
    }
    return 0;
}
