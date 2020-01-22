#include "flat.h"
#include "shipping_item.h"
#include <fstream>
#include <iomanip>

Flat::Flat() {
    set_height(8);
    set_thickness(.4);
}
Flat::Flat(Address address, double weight, double length,
           double height, double thickness) : ShippingItem(address, weight, length){
    // try{
    set_length(length);
    set_height(height);
    set_thickness(thickness);
    // }catch(std::out_of_range e){
    //     e.what();
    // }
}
//setters
void Flat::set_length(double length){
    if (length < kMinSize || length > 15)
    {
        throw std::out_of_range("Length is out of range");
    }
    else{
        length_ = length;
    }
}
void Flat::set_height(double height){
    if (height < kMinSize || height > 12)
    {
        throw std::out_of_range("Height is out of range");
    }
    else{
        height_ = height;
    }
}
void Flat::set_thickness(double thickness){
    if (thickness < kMinSize || thickness > .75)
    {
        throw std::out_of_range("thickness is out of range");
    }
    else{
        thickness_ = thickness;
    }
    
}
//other methods
double Flat::Volume() const {
    return length_*height_*thickness_;
}
void Flat::Display(std::ostream &out) const{
    out << std::fixed << std::setprecision(1)
        << "Flat: " << weight_ << " lbs. " << length_ << " x "
        << height_ << " x " << thickness_;
}
