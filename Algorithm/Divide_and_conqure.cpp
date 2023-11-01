#include <iostream>
#include <climits>
using namespace std;
int maxCrossingSum(int arr[], int low, int mid, int high)
{
    int leftSum = INT_MIN;  // Initialize left sum to negative infinity
    int sum = 0;
    for (int i = mid; i >= low; i--)  {
        sum += arr[i];
        if (sum > leftSum)
            leftSum = sum;
    }
    int rightSum = INT_MIN;  // Initialize right sum to negative infinity
    sum = 0;
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > rightSum)
            rightSum = sum;
    }
    return leftSum + rightSum;
}

int maxSubarraySum(int arr[], int low, int high)
{
    if (low == high)  // Base case: Only one element
        return arr[low];
    int mid = (low + high) / 2;  // Calculate the middle index
                   // Find the maximum subarray sum in the left subarray
    int leftSum = maxSubarraySum(arr, low, mid);
                  // Find the maximum subarray sum in the right subarray
    int rightSum = maxSubarraySum(arr, mid + 1, high);
                  // Find the maximum subarray sum crossing the middle element
    int crossingSum = maxCrossingSum(arr, low, mid, high);
                    // Return the maximum of the three sums
    return std::max(std::max(leftSum, rightSum), crossingSum);
}

int main()
{
    int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    int maxSum = maxSubarraySum(arr, 0, n - 1);
    cout << "Maximum subarray sum is: " << maxSum << endl;
    return 0;
}
