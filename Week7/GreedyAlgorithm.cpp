#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Item {
    int value;
    int weight;
};

bool compareItems(const Item& item1, const Item& item2) {
    double ratio1 = static_cast<double> (item1.value / item1.weight);
    double ratio2 = static_cast<double> (item2.value / item2.weight);
    return ratio1 > ratio2;
}

double knapsackGreedy(int W, vector<Item> &items) {
    sort(items.begin(), items.end(), compareItems);
    double totalValue = 0.0;
    int currentWeight = 0;

    for(const Item& item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            int remainingCapacity = W - currentWeight;
            totalValue += (double)remainingCapacity * item.value / item.weight;
            break;
        }
    }
    return totalValue;
}

int main() {
    int W, N;
    cin >> W >> N;
    vector<Item> items(N);
    for(int i = 0; i < N; i++) {
        cin >> items[i].weight >> items[i].value;
    }
    double maxValue = knapsackGreedy(W, items);
    cout << maxValue << endl;
    return 0;
}



