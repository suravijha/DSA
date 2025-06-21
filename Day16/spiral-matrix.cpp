// LeetCode 54
// Given an m x n matrix, return all elements of the matrix in spiral order.

class Solution
{
public:
	vector<int> spiralOrder(vector<vector<int>> &matrix)
	{
		vector<int> ans;
		int startRow = 0;
		int startCol = 0;
		int endRow = matrix.size() - 1;
		int endCol = matrix[0].size() - 1;
		int total = (endRow + 1) * (endCol + 1);
		int count = 0;
		while (count < total)
		{
			// Print starting row
			for (int index = startCol; index <= endCol && count < total; index++)
			{
				ans.push_back(matrix[startRow][index]);
				count++;
			}
			startRow++;
			// Print ending column
			for (int index = startRow; index <= endRow && count < total; index++)
			{
				ans.push_back(matrix[index][endCol]);
				count++;
			}
			endCol--;
			// Print ending row
			for (int index = endCol; index >= startCol && count < total; index--)
			{
				ans.push_back(matrix[endRow][index]);
				count++;
			}
			endRow--;
			// Print starting column
			for (int index = endRow; index >= startRow && count < total; index--)
			{
				ans.push_back(matrix[index][startCol]);
				count++;
			}
			startCol++;
		}
		return ans;
	}
};