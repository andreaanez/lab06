#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>


#include "PreMadeItem.h"
using namespace std;

// how do I use inheritance in the constructor;
//constructor for base will use size; 
PreMadeItem::PreMadeItem(std::string name,std::string size):IceCreamItem(size){
    if (size == "small" || size =="medium" || size == "large"){
        this -> size = size;
    }
    if (size == "small"){
        price = 4.00;
    }
    if (size == "medium" ){
        price = 6.00;
    }
    if (size == "large"){
        price = 7.50;
    }
    this -> name = name;
}
PreMadeItem::~PreMadeItem(){
    return;
}

	
std::string PreMadeItem::composeItem(){
    string order = "";
    order += "Pre-made Size: ";
    order += size;
    order += "\n";
    order += "Pre-made Item: ";
    order += name;
    order +="\n";
    order += "Price: ";
    order += "$";
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    order += stream.str();
    order +="\n";
    return order;
}


 double PreMadeItem::getPrice() {
     return price;
 }
    
