#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to merge two frequency maps
unordered_map<int, int> mergeMaps(unordered_map<int, int>& leftMap, unordered_map<int, int>& rightMap)
{
    unordered_map<int, int> mergedMap = leftMap;

    for (const auto& val: rightMap)
    {
        if (mergedMap.find(val.first) != mergedMap.end())
            mergedMap[val.first] += val.second;
        else
            mergedMap[val.first] = val.second;
    }

    return mergedMap;
}

// Function to find the frequency of each element using divide and conquer
unordered_map<int, int> findElementFrequency(vector<int>& arr, int low, int high)
{
    unordered_map<int, int> frequencyMap;

    if (low == high)  // Base case: Only one element
    {
        frequencyMap[arr[low]] = 1;
        return frequencyMap;
    }

    int mid = (low + high) / 2;  // Calculate the middle index

    // Find the frequency of elements in the left subarray
    unordered_map<int, int> leftMap = findElementFrequency(arr, low, mid);

    // Find the frequency of elements in the right subarray
    unordered_map<int, int> rightMap = findElementFrequency(arr, mid + 1, high);

    // Merge the frequency maps of left and right subarrays
    frequencyMap = mergeMaps(leftMap, rightMap);

    return frequencyMap;
}

// Test the code
int main()
{
    vector<int> arr = {1, 2, 3, 2, 1, 3, 4, 4, 4, 5};
    
    unordered_map<int, int> frequencyMap = findElementFrequency(arr, 0, arr.size() - 1);
    
    // Display the frequencies
    for ( auto& val : frequencyMap)
    {
        cout << "Element: " << val.first << ", Frequency: " << val.second << endl;
    }
    
    return 0;
}
