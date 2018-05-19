// 118. Pascal's Triangle
class Solution {
public:
	// time: O(numRows^2), space: O(numRows^2)
	vector<vector<int>> generate(int numRows) {
		auto triangle = vector<vector<int>>();
		triangle.reserve(numRows);

		for (int iRow = 0; iRow < numRows; ++iRow) {
			// This can be swapped out with just initializing the first and last elements of the array for performance.
			auto row = vector<int>(iRow + 1, 1);
			auto lastRow = iRow - 1;

			// This gets skipped on the first row, no need to bounds check.
			for (int iCol = 1; iCol < iRow; ++iCol) {
				row[iCol] = triangle[lastRow][iCol - 1] + triangle[lastRow][iCol];
			}

			triangle.push_back(row);
		}

		return triangle;
	}
};
