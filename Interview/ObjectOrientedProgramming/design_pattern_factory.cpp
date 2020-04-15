/*******************************************************************
* Factory Pattern
* 
* Reference: 
*  1. Very clearly explanation https://www.geeksforgeeks.org/design-patterns-set-2-factory-method/
*  2. https://codereview.stackexchange.com/questions/240157/c-template-to-implement-the-factory-pattern
*
*
* Key:
*  1. Parent has a static method to create their children (return object)
*
* Pros:
*  1. If I want to create another thype of child, I wouldn't recompiler.
*
* Advanced:
*  1. 
*
*******************************************************************/
#include <iostream> 
using namespace std; 
  
enum PhoneType { 
    Gsm,    Cdma,    Ims 
}; 

// Library classes 
class Phone { 
public: 
    virtual void printType() = 0; 
    static Phone* Create(PhoneType type); 
}; 
class GsmPhone : public Phone { 
public: 
    void printType() { 
        cout << "I am GsmPhone" << endl; 
    } 
}; 
class CdmaPhone : public Phone { 
public: 
    void printType() { 
        cout << "I am CdmaPhone" << endl; 
    } 
}; 
class ImsPhone : public Phone { 
    public: 
    void printType() { 
        cout << "I am ImsPhone" << endl; 
    } 
}; 

// !!This is the key!!
// Factory method to create objects of different types. 
// Change is required only in this function to create a new object type 
Phone* Phone::Create(PhoneType type) { 
    if (type == Gsm) 
        return new GsmPhone(); 
    else if (type == Cdma) 
        return new CdmaPhone(); 
    else if (type == Ims) 
        return new ImsPhone(); 
    else return NULL; 
} 


// PhoneProxy class 
class PhoneProxy { 
public: 
    // PhoneProxy doesn't explicitly create objects 
    // but passes type to factory method "Create()" 
    PhoneProxy(PhoneType pType) { 
        PhoneType type = pType; 
        pPhone = Phone::Create(type); 
    } 
    ~PhoneProxy() { 
        if (pPhone) { 
            delete[] pPhone; 
            pPhone = NULL; 
        } 
    } 
    Phone* getPhone()  { 
        return pPhone; 
    } 
  
private: 
    Phone *pPhone; 
}; 

// Driver program 
int main() { 
    PhoneProxy *pPhoneProxy = new PhoneProxy(Ims); 
    Phone * pPhone = pPhoneProxy->getPhone(); 
    pPhone->printType(); //I am ImsPhone
    return 0; 
} 