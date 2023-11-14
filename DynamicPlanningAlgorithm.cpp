#include <iostream>
#include <vector>

using namespace std;

// Function to solve the 0/1 knapsack problem
int knapsack(int W, const vector<int>& weights, const vector<int>& values, int N) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int w = 1; w <= W; ++w) {
            if (weights[i - 1] <= w) {
                dp[i][w] = max(values[i - 1] + dp[i - 1][w - weights[i - 1]], dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[N][W];
}

int main() {
    int N, W;

    cout << "Enter the number of artifacts: ";
    cin >> N;

    vector<int> weights(N);
    vector<int> values(N);

    cout << "Enter the weights of artifacts:\n";
    for (int i = 0; i < N; ++i) {
        cin >> weights[i];
    }

    cout << "Enter the values of artifacts:\n";
    for (int i = 0; i < N; ++i) {
        cin >> values[i];
    }

    cout << "Enter the knapsack capacity: ";
    cin >> W;

    int result = knapsack(W, weights, values, N);
    cout << "The maximum value that can be stolen is: " << result << endl;

    return 0;
}
