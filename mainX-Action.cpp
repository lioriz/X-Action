#include <iostream>
#include <opencv2/opencv.hpp>
#include <thread>
#include <vector>
#include "imageActions.hpp"

int main(int argc, char** argv)
{
    try {
        imageActions actions(IMAGE_PATH_IN);

        auto XActionLoop = [&actions]() {
            while(actions.XAction()){}
        };

        int numOfThreads = 1;

        if(argc > 1) {
            int argNum = atoi(argv[1]);
            if(argNum > 0 && argNum < 11) { // restraint for max 10 threads.
                numOfThreads = argNum;
            }
        }

        std::vector<std::thread> threadVec;
        for(int i = 0 ; i < numOfThreads ; ++i) {
            std::thread trd(XActionLoop);
            threadVec.push_back(std::move(trd));
        }

        for(int i = 0 ; i < threadVec.size() ; ++i) {
            threadVec[i].join();
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