#include "imageActions.hpp"
#include <opencv2/opencv.hpp>
#include <thread>

constexpr double R = 0.299;
constexpr double G = 0.587;
constexpr double B = 0.114;

imageActions::imageActions(const std::string& imgDirPath){
    mDirItr = std::filesystem::recursive_directory_iterator(imgDirPath);
}

bool imageActions::getImagePath(std::string& path){
    std::lock_guard<std::mutex> lock(mPathLock);
    if(mDirItr == std::filesystem::end(mDirItr)){
        std::cout << "No more images" << std::endl;
        return false;
    }
    path  = mDirItr->path();
    ++mDirItr;
    return true;
}

static double dot(double b, double r, double g) {
    return ((r * R) + (g * G) + (b * B));
}

cv::Mat imageActions::doSomething(const cv::Mat& imgIn){
    cv::Mat imgOut(imgIn.rows, imgIn.cols, CV_8UC1);

    for(int x = 0 ; x < imgIn.cols ; ++x){
        for(int y = 0 ; y < imgIn.rows ; ++y){
            cv::Vec3b brgPixel = imgIn.at<cv::Vec3b>(y, x);
            imgOut.col(x).row(y).setTo(dot(brgPixel[0], brgPixel[1], brgPixel[2]));
        }
    }
    return imgOut;
}

bool imageActions::saveImage(const cv::Mat& img){
    std::string outPath(IMAGE_PATH_OUT + std::string("/image_") + std::to_string(++mSaveCount) + ".jpg");
    return cv::imwrite(outPath, img);
}

bool imageActions::XAction(){
    std::string path;
    if(getImagePath(path)) {
        std::cout << "Start cv::imread" << std::endl;
        cv::Mat imgIn = cv::imread(path, 1);
        if (imgIn.empty()) {
            std::cout << "Failed imread(): image not found" << std::endl;
            return false;
        }

        std::cout << "Start doSomething" << std::endl;
        cv::Mat imgOut = doSomething(imgIn);
        if (imgOut.empty()) {
            std::cout << "Failed image not found" << std::endl;
            return false;
        }

        std::cout << "Start saveImage" << std::endl;
        if (!saveImage(imgOut)) {
            std::cout << "Fail to save " << path << std::endl;
            return false;
        }
    } else {
        return false;
    }
    return true;
}

void imageActions::XActionLoop(int numOfThreads) {
    auto XActionLoop = [this]() {
        while(XAction()){}
    };

    std::vector<std::thread> threadVec;

    for(int i = 0 ; i < numOfThreads ; ++i) {
        std::thread trd(XActionLoop);
        threadVec.push_back(std::move(trd));
    }

    for(int i = 0 ; i < threadVec.size() ; ++i) {
        threadVec[i].join();
    }
}