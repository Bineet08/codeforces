#include <iostream>
#include <vector>
#include <cmath>

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

    int count = 0;
    for (int i = 0; i < n - 2; i++) {
        for (int j = i + 1; j < n - 1; j++) {
            for (int k = j + 1; k < n; k++) {
                // Calculate the lengths of the sides using the Euclidean distance formula
                double side1 = sqrt(pow(points[i].x - points[j].x, 2) + pow(points[i].y - points[j].y, 2));
                double side2 = sqrt(pow(points[j].x - points[k].x, 2) + pow(points[j].y - points[k].y, 2));
                double side3 = sqrt(pow(points[k].x - points[i].x, 2) + pow(points[k].y - points[i].y, 2));

                // Check if the three sides satisfy the Pythagorean theorem
                if (side1 * side1 == side2 * side2 + side3 * side3 ||
                    side2 * side2 == side1 * side1 + side3 * side3 ||
                    side3 * side3 == side1 * side1 + side2 * side2) {
                    count++;
                }
            }
        }
    }

    cout << "Number of right triangles: " << count << endl;

    return 0;
}
