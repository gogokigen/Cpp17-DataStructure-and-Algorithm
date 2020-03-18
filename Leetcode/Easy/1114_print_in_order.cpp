/*******************************************************************
* https://leetcode.com/problems/print-in-order/
* Easy
* 
* Conception: 
*  1. Concurrency: https://en.wikipedia.org/wiki/Concurrent_computing
*                  https://www.geeksforgeeks.org/use-posix-semaphores-c/
*
* The same instance of Foo will be passed to three different threads.
* Thread A will call first(), thread B will call second(), and thread C will call third().
* Design a mechanism and modify the program to ensure that second() is executed after first(),
* and third() is executed after second().
*
*
* Example:
*
*
* Key:
*  1. 
*
* Advanced:
*  1. Using Queue to implement semaphore:
*     https://www.geeksforgeeks.org/semaphores-in-process-synchronization/
*
*******************************************************************/
#include <semaphore.h>
class Foo {
    
private:
    sem_t firstDone;
    sem_t secondDone;
    
public:
    Foo() {
        sem_init(&firstDone, 0, 0);
        sem_init(&secondDone, 0, 0);

    }

    void first(function<void()> printFirst) {
        
        // printFirst() outputs "first". Do not change or remove this line.
        printFirst();
        sem_post(&firstDone);
    }

    void second(function<void()> printSecond) {
        sem_wait(&firstDone);
        // printSecond() outputs "second". Do not change or remove this line.
        printSecond();
        sem_post(&secondDone);
    }

    void third(function<void()> printThird) {
        sem_wait(&secondDone);
        // printThird() outputs "third". Do not change or remove this line.
        printThird();
    }
};