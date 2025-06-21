// You are given an integer ‘target’, and your task is to find if it exists in the given 'mat' or not.

#include <vector>
using namespace std;
bool searchMatrix(vector<vector<int>> &mat, int target)
{
	for (int i = 0; i < mat.size(); i++)
	{
		for (int j = 0; j < mat[i].size(); j++)
		{
			if (mat[i][j] == target)
				return true;
		}
	}
	return false;
}