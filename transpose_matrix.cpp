//
//  transpose_matrix.cpp
//  
//
//  Created by Brad Duvall on 11/29/18.
//


#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<int>> transpose (vector<vector<int>> &A);
vector<vector<int>> twoDimVector (int rows, int cols, int defaultValue=0);
void printVector(vector<vector<int>> &inputVector);

int main(int argc, char * const argv[])
{
    vector<vector<int>> inputVector = { {1, 2},
                                        {3, 4},
                                        {5, 6}};

    //printVector(inputVector);

    //cout << endl;

    vector<vector<int>> outputVector = transpose (inputVector);

    //vector<vector<int>> outputVector = twoDimVector(2,3,0);

    printVector(outputVector);

    return 0;
};

vector<vector<int>> transpose (vector<vector<int>> &A)
{
    //creates new 2d vector and returns it leaving A unchanged

    int rows = A.size();
    int cols = A[0].size();

    vector<vector<int>> transposed  = twoDimVector(cols,rows,0); //cols and rows are switched for transposing

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            transposed[j][i] = A[i][j];
        }
    }

    return transposed;

};

vector<vector<int>> twoDimVector (int rows, int cols, int defaultValue)
{
    vector<vector<int>> returnVector(rows);

    for(int i = 0; i < rows; i++)
    {
        returnVector[i] = vector<int>(cols);

        for(int j = 0; j < cols; j++)
        {
            returnVector[i][j] = defaultValue;
        }
    }

    return returnVector;
};

void printVector(vector<vector<int>> &inputVector)
{
    for (int i = 0; i < inputVector.size(); i++) { 
        for (int j = 0; j < inputVector[0].size(); j++) 
            cout << inputVector[i][j] << " "; 
        cout << endl; 
    }
}