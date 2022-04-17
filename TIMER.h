#include <chrono>
#include <string>
#include <iostream>
#include <fstream>

class Timer {
public:
    Timer(const std::string &name) {};

    void start() {
        begin_ = std::chrono::high_resolution_clock::now();
    }
    void stop(const std::string &name, const std::string &arr_name) {
        end_ = std::chrono::high_resolution_clock::now();
        duration_ = end_ - begin_;
        std::cout << duration_.count() << std::endl;
        std::string filename = name + ".txt";
        std::ofstream fout;
        fout.open(filename ,std::ofstream::app);
        if (!fout.is_open()) {
            std::cout << "ERROR: WE HAVE SOME PROBLEMS!" << std::endl;
        } else {
            fout << arr_name << " : " << duration_.count() << " ms" << std::endl;
            fout.close();
        }
    }
    ~Timer() {};
private:
    std::string name_;
    std::chrono::time_point<std::chrono::high_resolution_clock> begin_;
    std::chrono::time_point<std::chrono::high_resolution_clock> end_;
    std::chrono::duration<double, std::milli> duration_;
};