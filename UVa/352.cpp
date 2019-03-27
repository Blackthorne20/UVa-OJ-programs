/*
352 - The Seasonal War

https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=288
*/
#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define endl '\n'

vector<pair<int, int>> dir = { {0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1} };

int floodfill(vector<string> &images, int r, int c)
{
    if (images[r][c] != '1')
    {
        return 0;
    }
    else
    {
        int ans = 1;
        images[r][c] = '0'; // replace with 0 to avoid cycling
        for (auto i : dir)
        {
            ans += floodfill(images, r + i.first, c + i.second);
        }
        return ans;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, t = 1; // n = side length of image
    while (cin >> n)
    {
        // fill graph
        // ----------
        vector<string> image(n + 2);
        for (int i = 0; i < image.size(); i++)
        {
            if (i == 0 || i == image.size() - 1)
            {
                image[i] = string(n + 2, '0'); // add boundary layer of zeroes
            }
            else
            {
                string temp;
                cin >> temp;
                temp = '0' + temp + '0';
                image[i] = temp;
            }
        }

        // count number of war eagles
        // --------------------------
        int numWarEagles = 0;
        for (int r = 1; r < image.size() - 1; r++)
        {
            for (int c = 1; c < image.size() - 1; c++)
            {
                numWarEagles += floodfill(image, r, c) > 0 ? 1 : 0; // we care only if there is a war eagle, not its size
            }
        }

        cout << "Image number " << t << " contains " << numWarEagles << " war eagles." << endl;
        t++;
    }

    return 0;
}

