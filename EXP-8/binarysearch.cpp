#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int low = 0, high = arr.size()- 1;
    while (low <= high) {
        int mid= low + (high - low) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}
int main() {
    vector<int> arr = {1, 3, 5, 7, 9};
    int target = 7;
    int result = binarySearch(arr, target);
    if (result != -1)
        cout << "Found at index: " << result;
    else
        cout << "Not found";
    return 0;
}
