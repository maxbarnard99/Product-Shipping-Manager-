#ifndef SHIPPING_ITEM_H
#define SHIPPING_ITEM_H

#include <string>


struct Address{
    std::string name;
    std::string street_address;
    std::string city;
    std::string state;
    std::string zip;
};


class ShippingItem{
    protected:
        struct Address address_;
        double weight_;
        double length_;
        bool delivered_;
    public:
        static const double kMaxWeight;
        static const double kMaxSize;
        static const double kMinSize;
        //constructor && destructor
        ShippingItem();
        ShippingItem(struct Address address, double weight, double length);
        ~ShippingItem(){}
        //getters 
        struct Address address() const {return address_;}
        double weight() const {return weight_;}
        double length() const {return length_;}
        bool delivered() const {return delivered_;}
        //setters
        void set_address(struct Address address);
        void set_weight(double weight);
        virtual void set_length(double length);
        void set_delivered(bool delivered);
        //other methods
        void MarkDelivered();
        virtual double Volume() const = 0; //setting these to zero creates a pure virtual 
        virtual void Display(std::ostream &out) const = 0; //class.
};  

#endif 