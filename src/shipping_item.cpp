
#include "shipping_item.h"
#include <fstream>

const double ShippingItem::kMaxWeight = 70;
const double ShippingItem::kMaxSize = 108;
const double ShippingItem::kMinSize = .007;

//constructor && destructor
ShippingItem::ShippingItem(){
    address_.name = "unknown";
    weight_ = 2;
    length_ = 12;
    delivered_ = false;
}
ShippingItem::ShippingItem(Address address, double weight, double length){
    //try{
        set_address(address);
        set_weight(weight);
        set_length(length);
    //}catch(std::out_of_range e){
    //    e.what();
    //}
}

//setters
void ShippingItem::set_address(Address address){
    address_ = address;
}
void ShippingItem::set_weight(double weight){
    if (weight<0 || weight > kMaxWeight){
        throw std::out_of_range("Weight cannot be less than 0");
    }
    else{
        weight_ = weight;
    }
}
void ShippingItem::set_length(double length){
    if(length < kMinSize || length > kMaxSize){
        throw std::out_of_range("Length must be between .007 and 108");
    }
    else{
        length_ = length;
    }
}
void ShippingItem::set_delivered(bool delivered){
    delivered_ = delivered;
}

//other methods
void ShippingItem::MarkDelivered(){
    delivered_ = true;
}
