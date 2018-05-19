// 120. Triangle
class Solution {
public:
	// time: O(numRows^2), space: O(1)
	int minimumTotal(vector<vector<int>>& triangle) {
		// Start from end of the triangle, calculating min sum per branch in place.
		for (int iRow = triangle.size() - 2; iRow >= 0; --iRow) {
			int iNextRow = iRow + 1;

			for (int iColumn = 0, numColumns = triangle[iRow].size(); iColumn < numColumns; ++iColumn) {
				// Pick the minimum path from the next row down.
				triangle[iRow][iColumn] += std::min(triangle[iNextRow][iColumn], triangle[iNextRow][iColumn + 1]);
			}
		}

		return triangle[0][0];
	}
};
