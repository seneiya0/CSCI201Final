#include "Order.h"

// Constructor
Order::Order(Reservation* res) : reservation(res), completed(false), paid(false) {
    // initialize menu prices
    menuPrices = {
        {VeggieBurger, 35},
        {Hamburger, 45},
        {FriedChickenSliders, 38},
        {HamburgerSliders, 38},
        {VeggieSliders, 38},
        {HaddockSandwich, 38},
        {BLT, 42},
        {FauxBLT, 42},
        {ChickenBurrito, 42},
        {FalafelWrap, 42},
        {CheesePizza, 59},
        {PepperoniPizza, 59},
        {FauxMeatAndChips, 77},
        {FishAndChips, 77}
    };
}

// method to add an item to the order
void Order::addItem(MenuItem item) {
    items.push_back(item);
}

// method to mark the order as completed
void Order::markComplete() { 
    completed = true; 
}
bool Order::isComplete() const { 
    return completed; 
}

// method to mark the order as paid
void Order::markPaid() { 
    paid = true;
}
bool Order::isPaid() const {
     return paid; 
}

// method to calculate the total bill (with tax and tip)
double Order::calculateTotal() const {
    double subtotal = 0.0;
    for (const auto& item : items) {
        subtotal += menuPrices.at(item);
    }
    double tax = subtotal * 0.10;
    double tip = subtotal * 0.20;
    return subtotal + tax + tip;
}

// getter for reservation
Reservation* Order::getReservation() const {
    return reservation;
}