#include<bits/stdc++.h>
using namespace std;

void selectSort(vector<int>& arr) {
    for(int i = 0; i < arr.size() - 1; i++) {
        int minIdx = i;

        for(int j = i + 1; j < arr.size(); j++) {
            if(arr[j] < arr[minIdx]) {
                minIdx = j;
            }
        }

        swap(arr[i], arr[minIdx]);
    }
}

int main() {
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    selectSort(arr);

    cout << "Sorted array:\n";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
