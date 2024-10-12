#ifndef ORDER_H
#define ORDER_H

#include <vector>
#include <map>
#include "Reservation.h"

// Enum to represent menu items
enum MenuItem {
    VeggieBurger,
    Hamburger,
    FriedChickenSliders,
    HamburgerSliders,
    VeggieSliders,
    HaddockSandwich,
    BLT,
    FauxBLT,
    ChickenBurrito,
    FalafelWrap,
    CheesePizza,
    PepperoniPizza,
    FauxMeatAndChips,
    FishAndChips
};

class Order {
private:
    Reservation* reservation; // associated reservation
    std::vector<MenuItem> items; // items ordered by the customer
    bool completed;
    bool paid;
    std::map<MenuItem, double> menuPrices;

public:
    Order(Reservation* res);

    void addItem(MenuItem item);
    void markComplete();
    bool isComplete() const;
    void markPaid();
    bool isPaid() const;
    double calculateTotal() const;
    Reservation* getReservation() const;
};

#endif