#ifndef IMAGEACTIONS_HPP
#define IMAGEACTIONS_HPP

#include <string>
#include <mutex>
#include <atomic>
#include <filesystem>

namespace cv {
class Mat;
};

class imageActions
{
public:
    //NOTE: The Ctor throw std::filesystem::filesystem_error on undefined directory path
    imageActions(const std::string& imgDirPath);

    bool getImagePath(std::string& path);

    static cv::Mat doSomething(const cv::Mat& imgIn);

    bool saveImage(const cv::Mat& imgIn);

    bool XAction();

private:
    std::mutex                                    mPathLock;
    std::filesystem::recursive_directory_iterator mDirItr;
    std::atomic<int>                              mSaveCount{0};
};

#endif // IMAGEACTIONS_HPP
