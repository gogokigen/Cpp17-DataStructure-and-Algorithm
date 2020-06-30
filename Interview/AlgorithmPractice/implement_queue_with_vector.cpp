#include <vector>
#include <mutex>          // std::mutex
#include <unistd.h>
using namespace std;

mutex mtx;


// advanced: using list to replace vector
class Queue {
public:
    int capacity;
    int top;
    Queue(int size) : capacity(size){};

    vector<int> queue;

    bool enqueue(int val){
        while(1){
            mtx.lock();
            if(queue.size() > capacity){
                mtx.unlock();
                sleep(100);
            }else{
                queue.push_back(val);
                mtx.unlock();
                return true;
            }
        }
    }


    bool dequeue(int& ret){
        while(1){
            mtx.lock();
            if(this->queue.size() == 0){
                mtx.unlock();
                sleep(100);
            }else{
                ret = queue[0];
                queue.erase(queue.begin());
                mtx.unlock();
                return true;
            }
        }
    }
};
