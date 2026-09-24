//
// Created by Junio Moreira on 24/09/26.
//
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0);

// ==========================================================
// TODO 1: Implement a greedy validation function.
// It checks if it's possible to transport all panels using
// at most 'maxTrucks', such that no truck carries a weight
// greater than 'maxWeight'. Also, store the actual number
// of trucks used in 'trucksUsed'.
// ==========================================================
bool isValid(const vector<int>& weights, int maxTrucks, int maxWeight, int& trucksUsed) {
    int count = 1;
    int currentWeight = 0;

    // Hint: Loop through each panel weight. If a single panel exceeds maxWeight, return false.
    // If adding the current panel exceeds maxWeight, allocate a new truck (count++).

    trucksUsed = count;
    return count <= maxTrucks;
}

// ==========================================================
// TODO 2: Implement the Binary Search function on the answer.
// It should find the minimum possible maximum weight per truck
// and the corresponding number of trucks used.
// ==========================================================
void binarySearchWeight(const vector<int>& weights, int trucks, int& bestWeight, int& finalTrucks) {
    int low = 0, high = 0;

    // Hint: 'low' should be the maximum individual panel weight.
    // 'high' should be the sum of all panel weights.

    while (low <= high) {
        int mid = low + (high - low) / 2;
        int trucksUsed = 0;

        // Hint: Call isValid(...) with 'mid'.
        // If valid, save 'mid' as bestWeight, update finalTrucks, and try a smaller weight (high = mid - 1).
        // If invalid, we need a larger weight limit (low = mid + 1).
    }
}

void solveSolarPanels() {
    int nPanels, trucks, freightRate;
    cin >> nPanels >> trucks >> freightRate;

    vector<int> weights(nPanels);
    for (int i = 0; i < nPanels; ++i) {
        cin >> weights[i];
    }

    int bestWeight = 0, finalTrucks = 0;

    // ==========================================================
    // TODO 3: Call the binary search function to determine
    // the best weight and final number of trucks.
    // ==========================================================

    // Total cost = (heaviest truck weight) * (trucks used) * (freight rate)
    ll totalCost = (ll)bestWeight * finalTrucks * freightRate;
    cout << bestWeight << " \$" << totalCost << "\n";
}

int main() {
    FAST_IO;
    int nc;
    cin >> nc;

    while (nc--) {
        solveSolarPanels();
    }

    return 0;
}
