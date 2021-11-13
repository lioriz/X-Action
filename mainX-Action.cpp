#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <chrono>
#include "imageActions.hpp"

int main(int argc, char** argv)
{
    try {
        imageActions actions(IMAGE_PATH_IN);

        int numOfThreads = 1;

        if(argc > 1) {
            int argNum = atoi(argv[1]);
            if(argNum > 0 && argNum < 11) { // restraint for max 10 threads.
                numOfThreads = argNum;
            }
        }

        std::chrono::steady_clock::time_point start = std::chrono::steady_clock::now();

        actions.XActionLoop(numOfThreads);

        std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
        std::chrono::milliseconds time_span = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
        std::cout << "Operation took: " << time_span.count() << " milliseconds" << std::endl;

    } catch(std::filesystem::filesystem_error& err) {
        std::cout << "caught " << err.what() << std::endl;
        return -1;
    } catch(...) {
        std::cout << "caught ellipsis exception" << std::endl;
        return -1;
    }
    return 0;
}