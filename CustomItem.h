#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H
#include "IceCreamItem.h"
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
//https://www.programiz.com/cpp-programming/public-protected-private-inheritance
class CustomItem:public IceCreamItem {
public:
	
	CustomItem(std::string size);
    //Constructs a custom ice cream order with a si
    //The only sizes an IceCreamItem may have are: small, medium, and large.
	//Each size will have a base price for the order (without the addition of toppings).
    // A small size is $3.00, a medium size is $5.00, and a large size is $6.50.
	virtual ~CustomItem();

	// Returns the dollar amount of an ice cream item.
    virtual std::string composeItem();
    virtual double getPrice();
	void addTopping(std::string topping);
    //has a weight of 1 oz. Each oz. increases 
    //the price of the CustomItem by $0.40 cents.
private:
	std::vector<std::pair<std::string, int> > toppings;    

};

#endif


