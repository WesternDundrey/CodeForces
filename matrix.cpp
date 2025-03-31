#include <iostream>
#include <vector>
using namespace std;

int main(){
    int matrix[5][5];  
    int rowIndex = -1, colIndex = -1;  // Variables to store the position of '1'

    // Input the matrix
    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            std::cin >> matrix[row][col];

            // If we find '1', store its location
            if (matrix[row][col] == 1) {
                rowIndex = row;
                colIndex = col;
            }
        }
    }
    cout << abs(rowIndex - 2) + abs(colIndex - 2) << endl;

}