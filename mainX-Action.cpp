#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <filesystem>
#include "imageActions.hpp"

int main()
{
    try {
        imageActions actions(IMAGE_PATH_IN);

        std::string path;
        while(actions.getImagePath(path)) {
            std::cout << "Start cv::imread" << std::endl;
            cv::Mat imgIn = cv::imread(path, 1);
            if (imgIn.empty())
            {
                std::cout << "Failed imread(): image not found" << std::endl;
                return -1;
            }

            std::cout << "Start doSomething" << std::endl;
            cv::Mat imgOut = actions.doSomething(imgIn);
            if (imgOut.empty())
            {
                std::cout << "Failed image not found" << std::endl;
                return -1;
            }

            std::cout << "Start saveImage" << std::endl;
            if(!actions.saveImage(imgOut)) {
                std::cout << "Fail to save " << path << std::endl;
            }
        }

    } catch(std::filesystem::filesystem_error& err) {
        std::cout << "caught " << err.what() << std::endl;
        return -1;
    } catch(...) {
        std::cout << "caught ellipsis exception" << std::endl;
        return -1;
    }
    return 0;
}