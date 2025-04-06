#include <iostream>
#include <string>
using namespace std;

int main()
{
    int arr[3][4] = {0};

    arr[0][3] = 1;
    arr[1][3] = 1;

    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 4; j++)
    //         cout << arr[i][j] << " ";
    //     cout << endl;
    // }

    for (int i = 2; i >= 1; i--)
    {
        arr[i][3] = arr[i - 1][3];
    }
    arr[0][3] = 34;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }

    return 0;
}