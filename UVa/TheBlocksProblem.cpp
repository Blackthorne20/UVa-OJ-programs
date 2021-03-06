// TheBlocksProblem.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

#define endl '\n'

void findElement(vector<vector<int>> &i_A, int i_f, int &o_r, int &o_c);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    cin.ignore();

    vector<vector<int>> blocks(n, vector<int>(1));
    for (int i = 0; i < n; i++)
    {
        blocks[i][0] = i;
    }

    string line;
    getline(cin, line);

    while (line != "quit")
    {
        int a, b, a_r, a_c, b_r, b_c;
        string instruction1, instruction2;
        stringstream ss(line);

        ss >> instruction1 >> a >> instruction2 >> b;

        findElement(blocks, a, a_r, a_c);
        findElement(blocks, b, b_r, b_c);

        if (a != b && a_r != b_r)
        {
            int top;
            if (instruction1 == "move")
            {
                if (instruction2 == "onto")
                {
                    //get a, move everything on top of it back to original spot
                    while (blocks[a_r].back() != a)
                    {
                        top = blocks[a_r].back();
                        blocks[a_r].pop_back();
                        blocks[top].push_back(top);
                    }

                    //move everything on top of b back to original spot
                    while (blocks[b_r].back() != b)
                    {
                        top = blocks[b_r].back();
                        blocks[b_r].pop_back();
                        blocks[top].push_back(top);
                    }

                    //put a onto b
                    blocks[a_r].pop_back();
                    blocks[b_r].push_back(a);
                }
                else if (instruction2 == "over")
                {
                    //move everything on top of a back to original spot
                    while (blocks[a_r].back() != a)
                    {
                        top = blocks[a_r].back();
                        blocks[a_r].pop_back();
                        blocks[top].push_back(top);
                    }

                    // put a onto b
                    blocks[a_r].pop_back();
                    blocks[b_r].push_back(a);
                }
            }
            else if (instruction1 == "pile")
            {
                vector<int> temp;
                if (instruction2 == "onto")
                {
                    while (blocks[b_r].back() != b)
                    {
                        top = blocks[b_r].back();
                        blocks[b_r].pop_back();
                        blocks[top].push_back(top);
                    }

                    //put a and everything on top of it into temp stack
                    while (blocks[a_r].back() != a)
                    {
                        top = blocks[a_r].back();
                        blocks[a_r].pop_back();
                        temp.push_back(top);
                    }
                    top = blocks[a_r].back();
                    blocks[a_r].pop_back();
                    temp.push_back(top);

                    //empty contents of temp onto b
                    while (!temp.empty())
                    {
                        blocks[b_r].push_back(temp.back());
                        temp.pop_back();
                    }
                }
                else if (instruction2 == "over")
                {
                    while (blocks[a_r].back() != a)
                    {
                        top = blocks[a_r].back();
                        blocks[a_r].pop_back();
                        temp.push_back(top);
                    }
                    top = blocks[a_r].back();
                    blocks[a_r].pop_back();
                    temp.push_back(top);

                    while (!temp.empty())
                    {
                        blocks[b_r].push_back(temp.back());
                        temp.pop_back();
                    }
                }
            }
        }
        getline(cin, line);
    }

    for (int r = 0; r < blocks.size(); r++)
    {
        cout << r << ":";
        for (int c = 0; c < blocks[r].size(); c++)
        {
            cout << " " << blocks[r][c];
        }
        cout << endl;
    }

    return 0;
}

void findElement(vector<vector<int>> &i_A, int i_f, int &o_r, int &o_c)
{
    for (int r = 0; r < i_A.size(); r++)
    {
        for (int c = 0; c < i_A[r].size(); c++)
        {
            if (i_A[r][c] == i_f)
            {
                o_r = r;
                o_c = c;
                return;
            }
        }
    }
}
