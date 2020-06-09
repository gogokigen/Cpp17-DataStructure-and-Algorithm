/*******************************************************************
* 
* Implement hash table
* 
* Conception: 
*  1. 
*
* Reference:
*  1. vector version: https://www.sanfoundry.com/c-program-implement-hash-tables/
*  2. linklist: http://www.kaushikbaruah.com/posts/data-structure-in-c-hashmap/
*  2. https://www.geeksforgeeks.org/c-program-to-check-prime-number/
*
*******************************************************************/
#include <iostream>
#include <vector>
using namespace std;

struct ArrayData {
    int val;
    int key;

    ArrayData() : val(0), key(0) {}
 };
 
class Hash_map {
private:
    int arraySize = 0;
    int capacity = 0;
    ArrayData array[30];
public:

    void initialArray(int capacity){
        if(capacity >= 30){
            capacity = 30;
            cout << "max table is 30!" << endl;
        }
        
        this->capacity = getPrime(capacity);
        for(int i = 0; i < this->capacity; i++){
            array[i] = ArrayData();
        }
    }
    
    int getTableSize(){
        return arraySize;
    }

    int hashcode(int key){
    	return (key % capacity);
    }

    int getPrime(int n){
    
    	if (n % 2 == 0) {
    		n++;
    	}

        while(!ifPrime(n)){
            n += 2;
        }
    	//for (; !ifPrime(n); n += 2);
    	return n;
    }

    bool ifPrime(int n){
        if (n <= 1) return false; 
        if (n <= 3) return true; 

        if (n % 2 == 0 || n % 3 == 0) 
            return false; 
        for(int i = 5; i * i <= n; i = i + 6){
            if(n % i == 0 || n % (i + 2) == 0){
                return false;
            }
        }
        return true;
    }

    void insertData(int key, int value){
        int index = hashcode(key);

        if(array[index].val == 0){
            array[index].key = key;
            array[index].val = value;
            arraySize++;
        } else if(array[index].key == key){
            array[index].val = value; //update valse
        } else {
            cout << "Inseret fail!" << endl;
        }
    }

    void removeData(int key){

    	int index  = hashcode(key);
    	if(array[index].val == 0){
    		cout << "This key does not exist" << endl;
    	} else {
    		array[index].key = 0;
    		array[index].val = 0;
    		arraySize--;

    		cout << "Key ("<< key << ") has been removed"<< endl;
    	}
    }


    void display(){
        for(int i = 0; i < capacity; i++){
            cout << "array[" << i << "].key = " << array[i].key << ", val = " << array[i].val << endl;
        }
    }
};


int main(){
    int capacity = 10;
    Hash_map* table = new Hash_map();
    
    cout << "initialArray" << endl;
    table->initialArray(capacity);
    cout << "insertData(4, 999)" << endl;
    table->insertData(4, 999);
    cout << "insertData(66, 33)" << endl;
    table->insertData(66, 33);
    
    cout << "getTableSize: " << table->getTableSize() << endl;
    cout << "display" << endl;
    table->display();
    cout << "removeData(4)" << endl;
    table->removeData(4);
    cout << "display" << endl;
    table->display();
    return 0;
}

/**
initialArray                                                                         
insertData(4, 999)                                                                   
insertData(66, 33)                                                                   
getTableSize: 2                                                                      
display                                                                              
array[0].key = 66, val = 33                                                          
array[1].key = 0, val = 0                                                            
array[2].key = 0, val = 0                                                            
array[3].key = 0, val = 0                                                            
array[4].key = 4, val = 999                                                          
array[5].key = 0, val = 0                                                            
array[6].key = 0, val = 0                                                            
array[7].key = 0, val = 0                                                            
array[8].key = 0, val = 0                                                            
array[9].key = 0, val = 0                                                            
array[10].key = 0, val = 0                                                           
removeData(4)                                                                        
Key (4) has been removed                                                             
display                                                                              
array[0].key = 66, val = 33                                                          
array[1].key = 0, val = 0                                                            
array[2].key = 0, val = 0                                                            
array[3].key = 0, val = 0                                                            
array[4].key = 0, val = 0                                                            
array[5].key = 0, val = 0                                                            
array[6].key = 0, val = 0                                                            
array[7].key = 0, val = 0                                                            
array[8].key = 0, val = 0                                                            
array[9].key = 0, val = 0                                                            
array[10].key = 0, val = 0  
**/