
#include <iostream>
#include <vector>
#include <ctime>

int const Sudoku_size = 9; // 9x9 Sudoku

void PrintSudoku(std::vector<std::vector<int>> &arr)
{
    for (int i = 0; i < Sudoku_size; i++)
    {
        for (int j = 0; j < Sudoku_size; j++)
        {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool IsNumberSafe(int search_value, int row_num_to_check, int column_num_to_check, std::vector<std::vector<int>> &arr)
{
    for (int i = 0; i < Sudoku_size; i++)
    {
        if (arr[row_num_to_check][i] == search_value || arr[i][column_num_to_check] == search_value)
        {
            return false;
        }
    }
    row_num_to_check = row_num_to_check - row_num_to_check % 3;
    column_num_to_check = column_num_to_check - column_num_to_check % 3;

    for (int i = 0; i <= 2; i++)
    {
        for (int j = 0; j <= 2; j++)
        {
            if (arr[row_num_to_check + i][column_num_to_check + j] == search_value)
            {
                return false;
            }
        }
    }
    return true;
}

bool SolveSudoku(std::vector<std::vector<int>> &arr)
{
    for (int i = 0; i < Sudoku_size; i++)
    {
        for (int j = 0; j < Sudoku_size; j++)
        {
            if (arr[i][j] == 0)
            {
                for (int search_value = 1; search_value <= 9; search_value++)
                {
                    if (IsNumberSafe(search_value, i, j, arr))
                    {
                        arr[i][j] = search_value;
                        
                        if (SolveSudoku(arr))
                        {
                            return true;
                        }
                        arr[i][j] = 0;
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{

    std::vector<std::vector<int>> array;
    array = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 2},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
        };

    std::cout << "Sudoku Problem" << std::endl;
    PrintSudoku(array);

    SolveSudoku(array);

    std::cout << "-----Solved------" << std::endl;

    PrintSudoku(array);

    return 0;
}
