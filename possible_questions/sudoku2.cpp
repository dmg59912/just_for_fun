#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
#include<hash_set>

/*
Sudoku is a number-placement puzzle. The objective is to fill a 9 × 9 grid with numbers in such a way that each column, each row, 
and each of the nine 3 × 3 sub-grids that compose the grid all contain all of the numbers from 1 to 9 one time.

Implement an algorithm that will check whether the given grid of numbers represents a valid Sudoku puzzle according to the layout 
rules described above. Note that the puzzle represented by grid does not have to be solvable.

Example

For

grid = [['.', '.', '.', '1', '4', '.', '.', '2', '.'],
        ['.', '.', '6', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '1', '.', '.', '.', '.', '.', '.'],
        ['.', '6', '7', '.', '.', '.', '.', '.', '9'],
        ['.', '.', '.', '.', '.', '.', '8', '1', '.'],
        ['.', '3', '.', '.', '.', '.', '.', '.', '6'],
        ['.', '.', '.', '.', '.', '7', '.', '.', '.'],
        ['.', '.', '.', '5', '.', '.', '.', '7', '.']]
the output should be
sudoku2(grid) = true;

For

grid = [['.', '.', '.', '.', '2', '.', '.', '9', '.'],
        ['.', '.', '.', '.', '6', '.', '.', '.', '.'],
        ['7', '1', '.', '.', '7', '5', '.', '.', '.'],
        ['.', '7', '.', '.', '.', '.', '.', '.', '.'],
        ['.', '.', '.', '.', '8', '3', '.', '.', '.'],
        ['.', '.', '8', '.', '.', '7', '.', '6', '.'],
        ['.', '.', '.', '.', '.', '2', '.', '.', '.'],
        ['.', '1', '.', '2', '.', '.', '.', '.', '.'],
        ['.', '2', '.', '.', '3', '.', '.', '.', '.']]
the output should be
sudoku2(grid) = false.

The given grid is not correct because there are two 1s in the second column. Each column, each row, and each 3 × 3 subgrid can only contain the numbers 1 through 9 one time.

Input/Output

[execution time limit] 3 seconds (java)

[input] array.array.char grid

A 9 × 9 array of characters, in which each character is either a digit from '1' to '9' or a period '.'.


*/

///This works only on JAVA

/*
boolean sudoku2(char[][] grid) {
    HashSet<String> seen = new HashSet<>();
    
    for( int i = 0; i < grid.length; ++i)
    {
        for( int j = 0; j < grid.length; ++j)
        {
            char current_val = grid[i][j];
            if (current_val != '.')
                if(!seen.add(current_val + " found in row " + i) || !seen.add(current_val + " found in column " + j)
                            || !seen.add(current_val + " found in sub box " + i/3 + j/3))
                            return false;
        }
        
    }
    return true;

}

*/


bool sudoku2(std::vector<std::vector<char>> grid);
int main(void)
{


    return 0;
}

bool sudoku2(std::vector<std::vector<char>> grid)
{
   std::hash_set<std::string> seen;
    
    for(int i = 0 ; i < grid.size(); ++i)
    {
        for(int j = 0; j < grid.size(); ++j)
        {
         char current_val = grid[i][j];
         if( current_val != '.')
            seen.insert( current_val + " found in row " + i );
        }
        
    }

}
