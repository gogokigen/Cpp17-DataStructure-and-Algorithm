#include <iostream>
#include <vector>

using namespace std;

class Stack {
private:
    int maxSize;
    vector<int> v;
    int top;
public:
    Stack(int size) {
        this->maxSize = size;
        this->v.reserve(this->maxSize);
        this->top = -1;
    }

    void push(int j) {
        if (!(this->isFull())) {
            this->top++;
            this->v[this->top] = j;
        } else {
            cout << "\nstack is full"<<endl;
        }

    }

    int pop() {
        if (this->isEmpty()) {
            cout<<  "StackOverflow "<<endl;
        }
        int t_pop = 0;
        if (!(this->isEmpty())) {

            t_pop = this->v[this->top];
            this->top--;
        }
        
        //if (this->isEmpty()) {
        //    cout << "stack will be empty"<<endl;
        //}
        cout<<  "pop: "<< t_pop << endl;
        return t_pop;
    }

    int peak() {
        return this->v[this->top];
    }
    bool isEmpty() {
        return (this->top == -1);
    }

    bool isFull() {
        return (this->top == this->maxSize - 1);
    }
};



int main() {

    Stack s(4);

    s.push(10);
    s.push(20);
    s.push(-1);
    cout<<s.pop();
    cout<<"\n"<<s.pop();
    s.push(40);
    cout<<"\n"<<s.pop();
    s.push(1);
    s.push(6);
    s.push(9);
    s.push(33);
    return 0;

}
