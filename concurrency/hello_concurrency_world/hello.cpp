#include <thread>
#include <iostream>
#include <vector>
#include <chrono>

class Helloer{
public:
    Helloer() = default;
    void operator()(){
    //std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 30));
        std::cout << hw << " ";
    }
private:
    std::string hw = (std::rand() % 2 == 0)? "Hello": "World";
};

int main(){
    std::vector<std::thread> threads;
    for (size_t i =0; i < 10; ++i){
        Helloer hello;
        threads.emplace_back(hello);
    }
    for (size_t i =0; i < threads.size(); ++i){
        threads[i].join();
    }
}
