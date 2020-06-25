#include<iostream>
#include<vector>
/*
Note: Try to solve this task in-place (with O(1) additional memory), since this is what you'll be asked to do during an interview.

You are given an n x n 2D matrix that represents an image. Rotate the image by 90 degrees (clockwise).

Example

For

a = [[1, 2, 3],
     [4, 5, 6],
     [7, 8, 9]]
the output should be

rotateImage(a) =
    [[7, 4, 1],
     [8, 5, 2],
     [9, 6, 3]]
Input/Output

[execution time limit] 0.5 seconds (cpp)

[input] array.array.integer a

Guaranteed constraints:
1 ≤ a.length ≤ 100,
a[i].length = a.length,
1 ≤ a[i][j] ≤ 104.
*/




std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> & a);
void print_matrix(std::vector<std::vector<int>>);


int main(void)
{
    std::vector<std::vector<int>> matrix = { {1,2,3 }, {4, 5, 6}, {7,8,9} };

    std::cout << "Your matrix is ..." << std::endl;

    print_matrix(matrix);

    std::cout << "Now rotating 90 degrees clockwise twice" << std::endl;

    std::cout << "First time" << std::endl;

    rotateImage(matrix);

    print_matrix(matrix);

    std::cout << "Second time " << std::endl;
    rotateImage(matrix);
    print_matrix(matrix);

	return 0;
}



std::vector<std::vector<int>> rotateImage(std::vector<std::vector<int>> & a)
{
    // step process if we want to achive o(1) space used otherwise we can use other techniques

    //step 1, we need to transpose the matrix ( turn rows to columns)

    /*

        ex. 
            a = [[1, 2, 3],
                 [4, 5, 6],
                 [7, 8, 9]]

                   transpose or swap(array[i][j], array[j][i];
    
                 [[1, 4, 7 ],
                  [2, 5, 8 ],
                  [3, 6, 9]]
    */

    int n = a.size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = i; j < n; ++j)
        {
            int temp = a[i][j];
            a[i][j] = a[j][i];
            a[j][i] = temp;
        }
    }

    // step 2. flip horizontaly 
      /*

        ex.
            a = [[1, 2, 3],
                 [4, 5, 6],
                 [7, 8, 9]]

                  flip horizontally or swap(array[i][j], array[i][n -1 -j];

                 [[7, 4, 1 ],
                  [8, 5, 2 ],
                  [9, 6, 3]]
    */

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < (n / 2); ++j)
        {
            int  temp = a[i][j];
            a[i][j] = a[i][n - 1 - j]; // since we are comparing the last value minus one, else we will be out of bound, damn array rules ex N =3 - 1 = 2
            a[i][n - 1 - j] = temp;
        }
    }


    return a;
}


void print_matrix(std::vector<std::vector<int>> matrix)
{
    for (int i = 0; i < matrix.size(); ++i)
    {
        for (int j = 0; j < matrix.size(); ++j)
            std::cout << matrix[i][j] << ' ';
        std::cout << std::endl;
    }
}