#include<iostream>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
using namespace std;//routine code
using namespace cv;



/* rotate matrix */


void rotate_matrix(vector <vector <int>>& v)
{
    int n = v.size();
    // first reverse the vector row-wise
    // we can either use the pre-defined
    // stl reverse function or we can use
    // for loops
    for (int row = 0; row < n; row++)
    {
        int start_col = 0;
        int end_col = n - 1;

        while (start_col < end_col)
        {
            swap(v[row][start_col], v[row][end_col]);
            start_col++;
            end_col--;
        }
    }

    // now transpose the vector
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i < j)
                swap(v[i][j], v[j][i]);

    return;
}

void print_matrix(vector <vector <int>> v)
{
    cout << "The rotated matrix is:" << endl;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
            cout << v[i][j] << " ";
        cout << endl;
    }
    cout << endl;
}
int main()
{
    cout << "Enter the size of the vector" << endl;
    int n;
    cin >> n;

    vector <vector <int>> v(n, vector <int>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ele;
            cin >> ele;

            v[i][j] = ele;
        }
    }

    rotate_matrix(v);
    print_matrix(v);

    return 0;
}
