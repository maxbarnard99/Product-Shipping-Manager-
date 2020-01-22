
#ifndef TUBE_H
#define TUBE_H

#include "shipping_item.h"

class Tube: public ShippingItem{
    private:
        double circumference_;
    public:
        static const double kPi;
        Tube();
        Tube(Address address, double weight, double length,
             double circumference);
        ~Tube(){}
        //getters
        double circumference()const{return circumference_;}
        //setters
        void set_circumference(double circumference);
        //other methods
        double Volume() const;
        double Girth() const;
        void Display(std::ostream &out) const;
};


#endif 