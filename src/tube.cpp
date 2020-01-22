#include "tube.h"
#include "shipping_item.h"
#include <fstream>
#include <iomanip>

const double Tube::kPi(3.14159);
Tube::Tube(){
    set_circumference(12); //we dont hard code this for ease of updating
}
Tube::Tube(Address address, double weight, double length,
        double circumference) : ShippingItem(address, weight, length) {
    //try{
    set_circumference(circumference);
    //}catch(std::out_of_range e){
    //    e.what();
    //}
}

//setters
void Tube::set_circumference(double circumference){
    if (circumference < kMinSize || circumference+length_ > kMaxSize)
    {
        throw std::out_of_range("circumference IS OUT OF RANGE!!!");
    }
    else{
        circumference_ = circumference;
    }
    
}
//other methods
double Tube::Volume() const{
    double radius = circumference_/(2*kPi);
    return kPi*radius*radius*length_;
}
double Tube::Girth() const{
    return circumference_;
}
void Tube::Display(std::ostream &out) const{
    out << std::fixed << std::setprecision(1)
        << "Tube: " << weight_ << " lbs. " 
        << length_ << " x " << circumference_;
}

