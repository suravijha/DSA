// For a given two-dimensional integer array/list ‘ARR’ of size (N x M), print the ‘ARR’ in a sine wave order, i.e., print the first column top to bottom, next column bottom to top, and so on.

#include <vector>
using namespace std;
vector<int> wavePrint(vector<vector<int>> arr, int nRows, int mCols)
{
	vector<int> ans;
	for (int i = 0; i < mCols; i++)
	{
		if (i % 2 == 0)
		{
			for (int j = 0; j < nRows; j++)
			{
				ans.push_back(arr[j][i]);
			}
		}
		else
		{
			for (int j = nRows - 1; j >= 0; j--)
			{
				ans.push_back(arr[j][i]);
			}
		}
	}
	return ans;
}