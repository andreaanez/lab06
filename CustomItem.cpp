#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>


#include "CustomItem.h"
using namespace std;

// how do I use inheritance in the constructor;
//constructor for base will use size; 
CustomItem::CustomItem(std::string size):IceCreamItem(size){
    if (size == "small" || size =="medium" || size == "large"){
        this -> size = size;
    }
    if (size == "small"){
        price = 3.00;
    }
    if (size == "medium" ){
        price = 5.00;
    }
    if (size == "large"){
        price = 6.50;
    }
 // set vector to null and erase contents***********************
}


// getting price from where it is stored in the base object "Ice Cream item "
// why do I only have a getter and not a setter 
double CustomItem::getPrice(){
    return price;
}

bool myfunc2(std::pair<string, int> a, std::pair<string, int> b){ // not a member function
	
	if ( a.first < b.first){
		return true;
	}
	if (a.first >= a.first){
		return false; // this make sense 
	}
	
	return false;
}


// add compose item ***
// i can set price directly in here becuase its  a member function?
std::string CustomItem::composeItem() {
 string order = "";
if (toppings.size()== 0){
    order += "Custom Size: ";
    order += size;
    order += "\n";
    order+= "Toppings: \n";
    order += "Price: ";
    order += "$";
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    order += stream.str();
    order += "\n";
}

else {
    sort (toppings.begin(), toppings.end(), &myfunc2);
    string order2 = "";
    order2 += "Custom Size: ";
    order2 += size;
    order2 += "\n";
    order2 += "Toppings: \n";
    vector<pair<string, int>>::iterator it; 
    cout << "in iterator"<<endl;
		for (it = toppings.begin(); it != toppings.end(); it++){
                order2 += it -> first;
                order2 += ": ";
                order2 += to_string(it -> second); 
                order2 += " oz \n";
        }
    order2 += "Price: ";
    order2 += "$";
    stringstream stream;
    stream << fixed << setprecision(2) << price;
    order2 += stream.str();
    order2 += "\n";
    return order2;
}

    return order;

}


CustomItem::~CustomItem(){ // what do I actually need to destruct ? // can be empty and do nothing 
//we want it to be vitual since it is a polymorphism // would want this specifc destructor called not the base class destructor 
return;
}

void CustomItem::addTopping(std::string topping){
     if (topping.length() ==0){
        return;
    }
    if (toppings.size()==0){
        toppings.push_back(pair<string, int>(topping, 1));
        price += .40;
    }


    else if (toppings.size()!=0){
		vector<pair<string, int>>::iterator it; 
		for (it = toppings.begin(); it != toppings.end(); it++){
			if ( it->first == topping) {
				int k = it->second;
				it->second = k+1;
                price += .40;
                return;
            }
        }
    toppings.push_back(pair<string, int>(topping, 1));
    price += .40;
    return;
    }

}