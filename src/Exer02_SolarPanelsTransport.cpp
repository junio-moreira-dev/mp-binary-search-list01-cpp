//
// Created by Junio Moreira on 24/09/26.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

int main() {
    FAST_IO;

    int nc;
    cin >> nc;

    while (nc--) {
        int nPanels, trucks, freightRate;
        cin >> nPanels >> trucks >> freightRate;

        vector<int> weights(nPanels);
        int max_single_weight = 0;
        long long total_sum_weights = 0;

        for (int i = 0; i < nPanels; ++i) {
            cin >> weights[i];
            max_single_weight = max(max_single_weight, weights[i]);
            total_sum_weights += weights[i];
        }

        // ==========================================================
        // TODO 1: Define the binary search boundaries (low and high).
        // Hint: 'low' should be the maximum individual panel weight,
        // and 'high' should be the sum of all panel weights.
        // ==========================================================
        int low = max_single_weight; // Initial guess (change if needed)
        int high = total_sum_weights; // Initial guess (change if needed)

        int bestWeight = high;
        int finalTrucks = trucks;

        // ==========================================================
        // TODO 2: Implement the Binary Search loop on the answer
        // (while low <= high) to find the minimum maximum weight per truck.
        // ==========================================================
        while (low <= high) {
            int mid = low + (high - low) / 2;

            // ==========================================================
            // TODO 3: Implement the greedy logic to test if 'mid' is valid.
            // Count how many trucks are needed. If trucksNeeded <= trucks,
            // save 'mid' as bestWeight and search on the left (high = mid - 1).
            // Otherwise, search on the right (low = mid + 1).
            // ==========================================================

        }

        // Calculate total freight cost and print the result
        ll totalCost = (ll)bestWeight * finalTrucks * freightRate;
        cout << bestWeight << " $" << totalCost << "\n";
    }

    return 0;
}