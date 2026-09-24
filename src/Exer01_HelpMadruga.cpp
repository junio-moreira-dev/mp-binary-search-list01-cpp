//
// Created by Junio Moreira on 24/09/26.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <cmath>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

// ==========================================================
// TODO 1: Implement the function that calculates the total upper
// remaining area when cutting the strips at a height 'mid'.
// ==========================================================
double calculateCurrentArea(const vector<int>& strips, double mid) {
    double currentArea = 0;

    // Hint: Loop through the strips and check if strips[i] > mid.
    // If it is, add (strips[i] - mid) to currentArea.

    return currentArea;
}

// ==========================================================
// TODO 2: Implement the Binary Search function.
// It should return the exact cutting height 'mid'.
// ==========================================================
double binarySearchHeight(double targetArea, const vector<int>& strips, int maxHeight) {
    double low = 0.0, high = maxHeight;
    double mid = 0.0;
    double eps = 1e-6; // Precision margin

    // Hint: Use the loop while (high - low > eps)
    // Call calculateCurrentArea inside the search to test 'mid'.

    return mid;
}

int main() {
    FAST_IO;

    int n;
    double targetArea;

    // Read test cases until n = 0 and targetArea = 0
    while (cin >> n >> targetArea && (n != 0 || targetArea != 0)) {
        vector<int> strips(n);
        double totalArea = 0;
        int maxHeight = -1;

        // Read strip lengths
        for (int i = 0; i < n; ++i) {
            cin >> strips[i];
            if (strips[i] > maxHeight) {
                maxHeight = strips[i];
            }
            totalArea += strips[i];
        }

        // Special cases verification
        if (abs(totalArea - targetArea) < 1e-9) {
            cout << ":D\n";
            continue;
        }

        if (totalArea < targetArea) {
            cout << "-.-\n";
            continue;
        }

        // ==========================================================
        // TODO 3: Call the binary search function and store the result.
        // ==========================================================
        double answer = 0.0; // Replace with the function call

        // Print the answer with exactly 4 decimal places
        cout << fixed << setprecision(4) << answer << "\n";
    }

    return 0;
}
