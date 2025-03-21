/*#include<iostream>
#include<vector>
#include<math>
using namespace std;

int main(){
int t;
cin>>t;
while(t--){
    int n;
    cin>>n;
    vector<pair<int,int>> point(n);
    for(int i=0;i<n;i++){
        cin>>point[i].first<<point[i].second;
    }

}
}*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int main() {
    int n;
    cout << "Enter the number of points: ";
    cin >> n;

    vector<Point> points(n);
    cout << "Enter the coordinates (x y):\n";
    for (int i = 0; i < n; i++) {
        cin >> points[i].x >> points[i].y;
    }

    // Sort the points based on x coordinates
    sort(points.begin(), points.end(), [](const Point& p1, const Point& p2) {
        return p1.x < p2.x;
    });

    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // Check if the three points form a right triangle
                if (points[i].y == points[j].y && points[k].y == 1 && points[k].x - points[j].x == points[j].x - points[i].x) {
                    count++;
                }
            }
        }
    }

    cout << "Number of right triangles: " << count << endl;

    return 0;
}
