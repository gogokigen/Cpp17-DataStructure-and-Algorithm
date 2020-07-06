//https://stackoverflow.com/questions/50216413/thread-sync-using-mutex-and-condition-variable
//https://shengyu7697.github.io/blog/2020/02/20/std-condition-variable/
//gcc -g mutex_condition_test.cpp -lstdc++ -pthread -o mutex_condition_test

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <string>
#include <vector>

using namespace std;

mutex mu;
condition_variable cv;

vector<int> data;

bool flag = false;

bool dumpsd(){
    unique_lock<mutex> lock(mu);
    cv.wait(lock, []{return (flag == true);});
    for (const auto v : data) {  cout << "aa: " << v << '\n';}
}

int main(){
    auto result = async(launch::async, dumpsd);
    for(int i = 0; i < 10; ++i) {
         cout << "emplace_back" << endl;
         data.emplace_back(i);
    }
    flag = true;
    cv.notify_one();
    // do something
    result.wait();
    return 0;
}
