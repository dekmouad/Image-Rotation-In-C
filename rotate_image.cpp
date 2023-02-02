#include<iostream>
#include<opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <string>
#include <thread>
using namespace std;//routine code
using namespace cv;




//to rotate image before applying multithreads

float angleofrotation;//declared variables to hold input(angel) by user
Mat outputimage;
Mat inputimage;
String inputwindowname;//path of image as string


void get_angel(){ 
    cout << "Enter the angle of rotation of image: ";
    cin >> angleofrotation;
}

int get_image() {
    inputimage = imread("model.png", IMREAD_UNCHANGED);
    if (inputimage.empty())
    {
        cout << "Error!!";
        cin.get();
        return -1;
    }
     inputwindowname = "Input Image";
     namedWindow(inputwindowname, WINDOW_NORMAL);
}

int main()
{
    std::thread thread1(get_angel);
    thread1.join(); //this makes sure that the thread finishes executing before main function

    
    std::thread thread2(get_image);
    thread2.join(); //this makes sure that the thread finishes executing before main function

	imshow(inputwindowname, inputimage);

	outputimage = inputimage;

	String outputwindowname = "Output Image";
	Point2f pt(inputimage.cols / 2., inputimage.rows / 2.);
	Mat r = getRotationMatrix2D(pt, angleofrotation, 1.0);
	warpAffine(inputimage, outputimage, r, Size(inputimage.cols, inputimage.rows));
	namedWindow(outputwindowname, WINDOW_NORMAL);
	imshow(outputwindowname, outputimage);

	waitKey(0);
	return 0;
}




/* rotate matrix */
/*

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
*/