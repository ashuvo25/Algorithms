#include <iostream>
#include <vector>

// Function to search for an element in a row-wise and column-wise sorted 2D array
bool searchElement(const std::vector<std::vector<int>>& matrix, int target, int rowStart, int rowEnd, int colStart, int colEnd)
{
    // Check if the range is valid
    if (rowStart > rowEnd || colStart > colEnd)
        return false;

    // Calculate the middle row and column indices
    int rowMid = (rowStart + rowEnd) / 2;
    int colMid = (colStart + colEnd) / 2;

    // Check if the middle element is the target element
    if (matrix[rowMid][colMid] == target)
        return true;

    // If the target element is less than the middle element,
    // search in the subarray formed by the rows above the middle row and columns to the left of the middle column
    if (matrix[rowMid][colMid] > target)
    {
        return searchElement(matrix, target, rowStart, rowMid - 1, colStart, colEnd) ||
               searchElement(matrix, target, rowMid, rowEnd, colStart, colMid - 1);
    }

    // If the target element is greater than the middle element,
    // search in the subarray formed by the rows below the middle row and columns to the right of the middle column
    return searchElement(matrix, target, rowMid + 1, rowEnd, colStart, colEnd) ||
           searchElement(matrix, target, rowStart, rowMid, colMid + 1, colEnd);
}

// Test the code
int main()
{
    std::vector<std::vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 50}
    };

    int target = 17;

    int rows = matrix.size();
    int cols = matrix[0].size();

    bool found = searchElement(matrix, target, 0, rows - 1, 0, cols - 1);

    if (found)
        std::cout << "Element " << target << " is found in the matrix." << std::endl;
    else
        std::cout << "Element " << target << " is not found in the matrix." << std::endl;

    return 0;
}
/*
#include <bits/stdc++.h>
#define ROW 4
#define COL 4
using namespace std;

bool binary_search(int mat[ROW][COL], int row, int start,
				int end, int key)
{
	while (start <= end) {
		int mid = start + (end - start) / 2;
		if (mat[row][mid] == key) {
			return true;
		}
		else if (mat[row][mid] < key) {
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}
	}
	return false;
}

void search(int mat[ROW][COL], int key)
{
	// search in each row
	for (int i = 0; i < ROW; i++) {
		// perform binary search in current row
		if (mat[i][0] <= key && mat[i][COL - 1] >= key) {
			if (binary_search(mat, i, 0, COL - 1, key)) {
				cout << "Found " << key << " at " << i
					<< " " << endl;
				return;
			}
		}
	}
	cout << key << " not found" << endl;
}

// Driver code
int main()
{
	int mat[ROW][COL] = { { 10, 20, 30, 40 },
						{ 15, 25, 35, 45 },
						{ 27, 29, 37, 48 },
						{ 32, 33, 39, 50 } };
	int key = 50;
	search(mat, key);
	return 0;
}

*/