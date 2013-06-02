/**
 *This code takes continuous images by the default camera.When someone press ESC key,
 *then the image is saved and re-displayed
 *@autho Ujjal Suttra Dhar <ujjalsuttradhar@gmail.com>
*/

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;

int main()
{

  int key;

  VideoCapture webcam;
  webcam.open(0);

  Mat img;


  while(webcam.read(img))
  {
      imshow("WEbcam",img);

      key=cvWaitKey(10);

      if(key==27)
         break;
  }

  /*saving image*/
  imwrite("image.jpg",img);
  webcam.release();


  /*Re-display image*/
  Mat img2=imread("image.jpg");
  imshow("Taken Image",img2);
  cvWaitKey(0);

  return 0;
}
