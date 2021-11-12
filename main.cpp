#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
int main()
{
    std::string imagePath(IMAGE_PATH);
    imagePath.append("/image1.jpg");
    cv::Mat image = cv::imread(imagePath, 1);
    if ( !image.data )
    {
        std::cout << "No image data" << std::endl;
        return -1;
    }
    if (image.empty())
    {
        std::cout << "Failed imread(): image not found" << std::endl;
        return -1;
    }
    namedWindow("Display Image", cv::WINDOW_AUTOSIZE );
    imshow("Display Image", image);
    cv::waitKey(0);
    return 0;
}