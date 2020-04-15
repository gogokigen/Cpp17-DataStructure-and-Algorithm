/*******************************************************************
* Observer Pattern
* 
* Reference: 
*  1. Very clearly explanation https://www.geeksforgeeks.org/observer-pattern-set-1-introduction/
*  2. https://medium.com/@gayashanbc/explore-the-observer-design-pattern-with-c-8592459b0486
*  3. https://leetcode.com/discuss/interview-question/object-oriented-design/488544/OOD-Notification-System
*  4. https://riptutorial.com/cplusplus/example/24695/observer-pattern
*
*
* Key:
*  1. All observers register to Subject
*  2. Subject has a method to update observers' states
*
* Pros:
*  1. Notification system
*
* Advanced:
*  1. 
*
*******************************************************************/
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std; 

class Observer {
public:

    /**
     * Update the state of this observer
     */
    virtual void update(int prices, float discountm, float total) = 0;

};


class Subject {
public:

    /**
     * Register an observer
     * @param the observer object to be registered
     */
    virtual void registerObserver(Observer *observer) = 0;

    /**
     * Unregister an observer
     */
    virtual void removeObserver(Observer *observer) = 0;

    /**
     * Notify to all the registered observers when the Subject's state changed
     */
    virtual void notifyObservers() = 0;

};

class ShoppingMallNews : public Subject {
    vector<Observer *> observers; // observers

    int price = 0;
    float discount = 0.0f;

public:

    void registerObserver(Observer *observer) override;
    void removeObserver(Observer *observer) override;
    void notifyObservers() override;

    /**
     * Set the new state of the ShoppingMallNews
     */
    void setState(int price, float discount);

};

void ShoppingMallNews::registerObserver(Observer *observer) {
    observers.push_back(observer);
}

void ShoppingMallNews::removeObserver(Observer *observer) {
    // find the observer
    auto iterator = find(observers.begin(), observers.end(), observer);

    if (iterator != observers.end()) { // observer found
        observers.erase(iterator); // remove the observer
    }
}

void ShoppingMallNews::notifyObservers() {
    for (Observer *observer : observers) { // notify all observers
        observer->update(price, discount, price*discount);
    }
}

void ShoppingMallNews::setState(int price, float discount) {
    this->price = price;
    this->discount = discount;
    cout << endl;
    notifyObservers();
}

class Client : public Observer {

private:
    int id;

public:
    Client(int id);
    virtual void update(int price, float discount, float total) override;

};

void Client::update(int price, float discount, float total) {
    // print the changed values
    cout << "Client (" << id << ") Data >\tPrice: " << price
              << "\tDiscount: " << discount
              << "\tTotal: " << total
              << endl;
}

Client::Client(int id) {
    this->id = id;
}

int main() {
    ShoppingMallNews newsStation;
    Client one(1), two(2), three(3);

    float discount, total;
    int price;

    newsStation.registerObserver(&one);
    newsStation.registerObserver(&two);
    newsStation.registerObserver(&three);

    cout << "Enter Price, Discount (seperated by spaces) << ";
    cin >> price >> discount;

    newsStation.setState(price,discount);

    cout << "Remove Client 2" << endl;
    newsStation.removeObserver(&two);

    cout << "Enter Price, Discount (seperated by spaces) << ";
    cin >> price >> discount;

    newsStation.setState(price,discount);

    return 0;
}
/*
Enter Price, Discount (seperated by spaces) << 100 0.3                                                              
                                                                                                                    
Client (1) Data >   Price: 100      Discount: 0.3   Total: 30                                                   
Client (2) Data >   Price: 100      Discount: 0.3   Total: 30                                                   
Client (3) Data >   Price: 100      Discount: 0.3   Total: 30  
                                                 
Remove Client 2  
                                                                                                   
Enter Price, Discount (seperated by spaces) << 1000 0.4                                                             
                                                                                                                    
Client (1) Data >   Price: 1000     Discount: 0.4   Total: 400                                                  
Client (3) Data >   Price: 1000     Discount: 0.4   Total: 400 
*/