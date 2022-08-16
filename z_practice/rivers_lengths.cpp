/*
-------------- River Sizes --------------------------

--> Input: Matrix[n][m]
n can be different than m
Elements of the matrix are 0 or 1
0 represent land
1 represent a part of a river
A river consists of connected 1 horizotally or vertically
The sum number of adjacent 1 of a river is its size value

--> Return an array of the sizes of all rivers ( no order is
needed)

    Sample Input           sample Output

[1 , 0 , 0 , 1 , 0],    [1 , 2 , 2 , 2 , 5]
[1 , 0 , 1 , 0 , 0],
[0 , 0 , 1 , 0 , 1],
[1 , 0 , 1 , 0 , 0],
[1 , 0 , 1 , 1 , 0],

--------------------------------------------------------
*/
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<int> river_size(vector<vector<int>> grid)
{
    int height = grid.size();
    int width = grid.at(0).size();
    vector<int> result;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int part = 0;
            while (grid[i][j] != 0)
            {
                part = 1;
                grid[i][j] = 0;
                if (grid[i][j + 1] == 1)
                {
                    j = j + 1;
                    grid[i][j + 1] = 0;
                    part++;
                }
                if ((grid[i][j - 1] == 1) && (j > 1))
                {
                    j = j - 1;
                    grid[i][j - 1] = 0;
                    part++;
                }
                if (grid[i + 1][j] == 1)
                {
                    i = i + 1;
                    grid[i + 1][j] = 0;
                    part++;
                }
                if ((grid[i - 1][j] == 1) && (i > 1))
                {
                    i = i - 1;
                    grid[i - 1][j] = 0;
                    part++;
                }
            }
            result.push_back(part);
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> grid;
    grid = {{1, 0, 0, 1, 0}, {1, 0, 1, 0, 0}};
    // for (int i = 0; i < river_size(grid).size(); i++)
    // {
    //     cout << river_size(grid)[i] << " " << endl;
    // }
    cout << river_size(grid)[0];
    return 0;
}