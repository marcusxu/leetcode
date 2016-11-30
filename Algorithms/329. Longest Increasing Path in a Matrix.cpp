class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if (matrix.size() == 0)
            return 0;
        int width = matrix[0].size();
        int height = matrix.size();
        int result = 0;
        vector<vector<int>> memo(height, vector<int>(width, 0));
        for (int i = 0; i < height; i++)
            for (int j = 0; j < width; j++)
            {
                int tmp = nprocess(matrix, i, j, height, width, memo);
                if (tmp > result)
                     result=tmp;
            }
        return result;
    }

    int nprocess(vector<vector<int>> &matrix, int i, int j, int m, int n, vector<vector<int>> &memo)
    {
        if (memo[i][j] != 0) return memo[i][j];
        memo[i][j] = 1;
        vector<vector<int>> shift{ { 0, -1 }, { 0, 1 }, { -1, 0 }, { 1, 0 } };
        int max = 1;
        for (int k = 0; k < 4; k++)
        {
            int x = i + shift[k][0];
            int y = j + shift[k][1];
            if ((x < m) && (x >= 0) && (y<n) && (y >= 0) && (matrix[x][y]>matrix[i][j]))
            {
                int tmp = nprocess(matrix, x, y, m, n, memo) + 1;
                if (tmp > max)
                    max = tmp;
            }
        }
        memo[i][j] = max;
        return max;
    }
};