#include <iostream>
using namespace std;

int maxCrossingSum(int arr[], int left, int mid, int right) {
    int sum = 0;
    int leftMax = arr[mid];
    sum = 0;
    for (int i = mid; i >= left; i--) {
        sum += arr[i];
        if (sum > leftMax) leftMax = sum;
    }

    int rightMax = arr[mid + 1];
    sum = 0;
    for (int i = mid + 1; i <= right; i++) {
        sum += arr[i];
        if (sum > rightMax) rightMax = sum;
    }

    return leftMax + rightMax;
}

int maxSubarraySum(int arr[], int left, int right) {
    if (left == right) return arr[left];

    int mid = left + (right - left) / 2;

    int leftSum = maxSubarraySum(arr, left, mid);
    int rightSum = maxSubarraySum(arr, mid + 1, right);
    int crossSum = maxCrossingSum(arr, left, mid, right);

    return max(leftSum, max(rightSum, crossSum));
}

int main() {
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Maximum subarray sum is: " << maxSubarraySum(arr, 0, n - 1) << endl;
    return 0;
}
