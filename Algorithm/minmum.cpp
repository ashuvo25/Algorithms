#include <iostream>
#include <vector>

// Function to find the minimum number in an array using divide and conquer
int findMinimum(const std::vector<int>& array, int start, int end)
{
    // Base case: Only one element
    if (start == end)
        return array[start];

    // Calculate the middle index
    int mid = (start + end) / 2;

    // Recursively find the minimum in the left and right subarrays
    int leftMin = findMinimum(array, start, mid);
    int rightMin = findMinimum(array, mid + 1, end);

    // Return the smaller of the two minimums
    return std::min(leftMin, rightMin);
}

// Test the code
int main()
{
    std::vector<int> array = {4, 2, 9, 1, 7, 5, 3, 8};

    int minNum = findMinimum(array, 0, array.size() - 1);

    std::cout << "The minimum number in the array is: " << minNum << std::endl;

    return 0;
}
