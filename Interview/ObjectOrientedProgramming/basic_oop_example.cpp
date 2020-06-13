/*******************************************************************
* 
* vitrual and override
* 
* References: 
*  1. C++ primer version 5, chp 15.2
*
* Key:
*  1. 
*
*******************************************************************/
#include <stdio.h>
#include <iostream>
#include <string.h>
using namespace std;

class Quote{
public:
   Quote() = default;
   Quote(const string &isbn, double salesPrice): bookIsbn(isbn), price(salesPrice){
       //contructor and do nothing
   }
   
   static void statement(){
       cout << "Quote" << endl;
   }
   string getIsbn() const {
       return bookIsbn; 
   }
   
   virtual double calculateNetPrice( int n) const {
       return n * price;
   }
   
   //basic class should write de-contructor
   virtual ~Quote() = default;

private:
   string bookIsbn;
   
protected:
   double price = 0.0;
};


class BulkQuote : public Quote{
public:
   BulkQuote() = default;
   BulkQuote(const string &isbn, double salesPrice, int qty, double disc): Quote(isbn, salesPrice),minQty(qty), discount(disc){};
   
   double calculateNetPrice( int n) const override;
   static void statement(){
       cout << "BulkQuote" << endl;
   }
private:
   int minQty = 0;
   double discount = 0.0;
};



double BulkQuote::calculateNetPrice( int n) const{
    if( n >= minQty){
        return n * (1 - discount) * price;
    }else{
        return n * price;
    }
}



int main(){

    BulkQuote *bulk = new BulkQuote("AAB", 100, 2, 0.4);
    cout << "Net price: " << bulk->calculateNetPrice(4) <<endl;
    //Net price: 240
    bulk->statement();
    //BulkQuote
    return 0;
}