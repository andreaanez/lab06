#ifndef PREMADEITEM_H
#define PREMADEITEM_H
#include "IceCreamItem.h"
#include <string>

//https://www.programiz.com/cpp-programming/public-protected-private-inheritance
class PreMadeItem:public IceCreamItem {
public:
	
	PreMadeItem(std::string name, std::string size);
    
	virtual ~PreMadeItem();

	
    virtual std::string composeItem();
    virtual double getPrice();
    
private:
	std::string name;    

};

#endif