//Evan Wood : Flip Flop the Squarelotron : 10016 : Blackthorne20
//
//data structure required: 2D vector
//
//tricks of the trade: index arithmetic, lots of swapping, and plenty of patience

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define endl '\n'

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n_numMatrices;
    cin >> n_numMatrices;

    for (int i = 0; i < n_numMatrices; i++)
    {
        int n_matrixSideLength;
        cin >> n_matrixSideLength;

        //fill matrix
        vector<vector<int>> mat(n_matrixSideLength, vector<int>(n_matrixSideLength));
        for (int r = 0; r < n_matrixSideLength; r++)
        {
            for (int c = 0; c < n_matrixSideLength; c++)
            {
                cin >> mat[r][c];
            }
        }

        int n_numRings = n_matrixSideLength / 2 + n_matrixSideLength % 2;
        for (int j = 0; j < n_numRings; j++)
        {
            int n_numMoves;
            cin >> n_numMoves;

            for (int k = 0; k < n_numMoves; k++)
            {
                int s = n_matrixSideLength - j - 1;
                int n_moveType;
                cin >> n_moveType;

                switch (n_moveType)
                {
                case 1: //up-down flip

                    for (int r = j; r <= s; r++)
                    {
                        //swap top and bottom rows
                        swap(mat[j][r], mat[s][r]);
                    }
                    for (int c = 1; c < (n_matrixSideLength - 2 * j) / 2; c++)
                    {
                        //reverse side columns
                        swap(mat[j + c][j], mat[s - c][j]);
                        swap(mat[j + c][s], mat[s - c][s]);
                    }
                    break;
                case 2: //left-right flip

                    for (int c = j; c <= s; c++)
                    {
                        //swap side columns
                        swap(mat[c][j], mat[c][s]);
                    }
                    for (int r = 1; r < (n_matrixSideLength - 2 * j) / 2; r++)
                    {
                        //reverse top and bottom rows
                        swap(mat[j][j + r], mat[j][s - r]);
                        swap(mat[s][j + r], mat[s][s - r]);
                    }
                    break;
                case 3: //main diagonal flip

                    for (int r = j + 1; r <= s; r++)
                    {
                        // swaps left col and top row of selected ring
                        swap(mat[r][j], mat[j][r]);
                    }
                    for (int c = j + 1; c < s; c++)
                    {
                        //swaps bottom row and right col of select ring
                        swap(mat[s][c], mat[c][s]);
                    }
                    break;
                case 4: //inverse diagonal flip

                    for (int r = 0; r <= s - (j + 1); r++)
                    {
                        // swaps top col and right col of selected ring
                        swap(mat[j][j + r], mat[s - r][s]);
                    }
                    for (int c = 1; c < s - j; c++)
                    {
                        //swaps top row and right col of select ring
                        swap(mat[j + c][j], mat[s][s - c]);
                    }
                    break;
                }
            }
        }

        //print resulting matrix
        for (int r = 0; r < n_matrixSideLength; r++)
        {
            for (int c = 0; c < n_matrixSideLength; c++)
            {
                cout << mat[r][c];
                if (c != n_matrixSideLength - 1)
                {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }
    return 0;
}

