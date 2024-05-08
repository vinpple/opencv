/*
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(void)
{
	Mat src = imread("milkdrop.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	Mat bin;
	threshold(src, bin, 0, 255, THRESH_BINARY | THRESH_OTSU);
	Mat dst1, dst2;
	erode(bin, dst1, Mat()); //3x3 구조요소 사용
	dilate(bin, dst2, Mat()); //3x3 구조요소 사용
	imshow("src", src);
	imshow("bin", bin);
	imshow("erode", dst1);
	imshow("dilate", dst2);
	waitKey();
	destroyAllWindows();
	return 0;
}
*/


#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(void)
{
	Mat src = imread("car.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return -1; }
	imshow("src", src);
	waitKey(2000);
	blur(src, src, Size(5, 5));
	Sobel(src, src, -1, 1, 0);
	imshow("x축 방향 소벨", src);
	waitKey(2000);
	threshold(src, src, 150, 255, CV_8U);
	imshow("이진화 영상", src);
	waitKey(2000);
	Mat M=getStructuringElement(MORPH_RECT, Size(50, 5));
	morphologyEx(src, src, MORPH_CLOSE, M);
	morphologyEx(src, src, MORPH_CLOSE, Mat(9, 5, CV_8U));
	imshow("닫힘 영상", src);
	waitKey();
	return 0;
}
	
