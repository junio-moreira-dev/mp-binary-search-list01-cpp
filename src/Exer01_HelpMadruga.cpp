//
// Created by Junio Moreira on 24/09/26.
//

#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

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
        // TODO 1: Initialize the binary search boundaries (low and high)
        // and the precision margin (eps).
        // ==========================================================
        double low = 0.0;
        double high = maxHeight;
        double eps = 1e-6;

        double answer = 0.0;

        // ==========================================================
        // TODO 2: Implement the Binary Search loop (while high - low > eps).
        // Inside the loop, calculate 'mid', compute the total upper area
        // obtained by cutting at height 'mid', and adjust low or high.
        // ==========================================================


        // ==========================================================
        // TODO 3: Assign the final height to the 'answer' variable.
        // ==========================================================

        // Print the answer with exactly 4 decimal places
        cout << fixed << setprecision(4) << answer << "\n";
    }

    return 0;
}