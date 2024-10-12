#ifndef RESTAURANT_H
#define RESTAURANT_H

#include <vector>
#include "Reservation.h"
#include "Table.h"
#include "Order.h"

class Restaurant {
private:
    std::vector<Reservation*> reservations;
    std::vector<Table> tables;
    std::vector<Order*> orders;

public:
    Restaurant();
    void addReservation(const std::string& name, int partySize, const std::string& time);
    void checkInReservation(const std::string& name);
    void enterOrder(const std::string& name, const std::vector<MenuItem>& items);
    void completeOrder(const std::string& name);
    void calculateAndPayBill(const std::string& name);
    void closeRestaurant();
    bool isReservationCheckedIn(const std::string& name) const;
};

#endif // RESTAURANT_H