//Evan Wood : Rotated Squares : 10855 : Blackthorne20
//
//data structure required: 2D vectors
//
//tricks of the trade: indexing, traversing, and rotating 2D vectors
//                     using nested for loops

#include <iostream>
#include <vector>
using namespace std;

#define endl '\n'

void Rotate(vector<vector<char>> &B, int n);
int getCount(vector<vector<char>> &A, vector<vector<char>> &B, int N, int n);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, n;
    cin >> N >> n;

    while (!(N == 0 && n == 0))
    {
        //fill large matrix
        vector<vector<char>> A(N, vector<char>(N));
        for (int r = 0; r < N; r++)
        {
            for (int c = 0; c < N; c++)
            {
                cin >> A[r][c];
            }
        }

        //fill small matrix
        vector<vector<char>> B(n, vector<char>(n));
        for (int r = 0; r < n; r++)
        {
            for (int c = 0; c < n; c++)
            {
                cin >> B[r][c];
            }
        }

        int i = 0;
        while (i < 4)
        {
            //count how many times small matrix appears in large
            cout << getCount(A, B, N, n);
            if (i != 3)
            {
                cout << " ";
            }
            Rotate(B, n);
            i++;
        }


        cin >> N >> n;
        cout << endl;
    }


    return 0;
}

void Rotate(vector<vector<char>> &B, int n)
{
    //c, N-r-1
    vector<vector<char>> C(n, vector<char>(n));

    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            C[c][n - r - 1] = B[r][c];
        }
    }

    B = C;
}

int getCount(vector<vector<char>> &A, vector<vector<char>> &B, int N, int n)
{
    //traverse large matrix until the first element in the
    //small matrix is found
    int count = 0;
    for (int r = 0; r < N - n + 1; r++)
    {
        for (int c = 0; c < N - n + 1; c++)
        {
            //first element is hit
            if (A[r][c] == B[0][0])
            {
                //compare submatrix with small matrix
                int check = 0;
                for (int i = 0; i < n; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (A[r + i][c + j] == B[i][j])
                        {
                            check++;
                        }
                    }
                }

                //if submatrix contains all elements in the small
                //matrix in the correct order, then a match is found
                if (check == n * n)
                {
                    count++;
                }
            }
        }
    }
    return count;
}