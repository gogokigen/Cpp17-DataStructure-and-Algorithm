//https://medium.com/swlh/c-mutex-write-your-first-concurrent-code-69ac8b332288
//https://www.bogotobogo.com/cplusplus/C11/7_C11_Thread_Sharing_Memory.php
//gcc -g async_test.cpp -lstdc++ -pthread -o async_test
#include <iostream>
#include <thread>
#include <mutex>
#include <string>

using namespace std;

mutex mu;
condition_variable cv;

void shared_cout(string msg, int id){
	mu.lock();
	cout << msg << ":" << id << endl;
	mu.unlock();
}

void thread_function(){
    for (int i = -100; i < 0; i++){
        shared_cout("thread function", i);
        //cout << "thread function: " << i << "\n";
    }
}

int main(){
	thread t(&thread_function);
	for (int i = 0; i < 100; i++){
            shared_cout("main thread", i);
	    //cout << "main thread: " << i << "\n";
        }
	t.join();
	return 0;
}

