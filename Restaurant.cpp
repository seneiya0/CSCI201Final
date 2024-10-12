#include "Restaurant.h"
#include <iostream>

// constructor (initializes tables with it's number (i) and different sizes)
Restaurant::Restaurant() {
    // initialize tables (8 two-person tables, 2 ten-person tables, etc.)
    for (int i = 1; i <= 8; ++i) {
        tables.push_back(Table(i, 2));  // 2-person tables
    }
    for (int i = 9; i <= 10; ++i) {
        tables.push_back(Table(i, 10));  // 10-person tables
    }
    for (int i = 11; i <= 14; ++i) {
        tables.push_back(Table(i, 6));  // 6-person tables
    }
    for (int i = 15; i <= 20; ++i) {
        tables.push_back(Table(i, 4));  // 4-person tables
    }
}

// method to add a reservation
void Restaurant::addReservation(const std::string& name, int partySize, const std::string& time) {
    if (partySize > 10) {
        std::cout << "We cannot handle reservations larger than 10 people." << std::endl;
        return;
    }
    reservations.push_back(new Reservation(name, partySize, time));
    std::cout << "Reservation made for " << name << " at " << time << " for " << partySize << " people." << std::endl;
}

// method to check-in a reservation
void Restaurant::checkInReservation(const std::string& name) {
    for (auto& reservation : reservations) {
        if (reservation->getCustomerName() == name && reservation->getTable() == nullptr) {
            for (auto& table : tables) {
                if (table.isAvailable() && table.getSize() >= reservation->getPartySize()) {
                    reservation->assignTable(&table);
                    table.markOccupied();
                    reservation->checkIn();
                    return;
                }
            }
            std::cout << "No available table for the party size." << std::endl;
            return;
        }
    }
    std::cout << "No reservation found for " << name << std::endl;
}

// method to enter an order for a table
void Restaurant::enterOrder(const std::string& name, const std::vector<MenuItem>& items) {
    for (auto& reservation : reservations) {
        if (reservation->getCustomerName() == name && reservation->getTable() != nullptr) {
            Order* order = new Order(reservation);
            for (const auto& item : items) {
                order->addItem(item);
            }
            orders.push_back(order);
            std::cout << "Order placed for " << name << std::endl;
            return;
        }
    }
    std::cout << "No checked-in reservation found for " << name << std::endl;
}

// method to complete an order
void Restaurant::completeOrder(const std::string& name) {
    for (auto& order : orders) {
        if (order->getReservation()->getCustomerName() == name && !order->isComplete()) {
            order->markComplete();
            std::cout << "Order completed for " << name << std::endl;
            return;
        }
    }
    std::cout << "No incomplete order found for " << name << std::endl;
}

// method to calculate and pay the bill
void Restaurant::calculateAndPayBill(const std::string& name) {
    for (auto& order : orders) {
        if (order->getReservation()->getCustomerName() == name && order->isComplete() && !order->isPaid()) {
            double total = order->calculateTotal();
            std::cout << "Total bill for " << name << ": $" << total << std::endl;
            order->markPaid();
            std::cout << "Payment successful for " << name << std::endl;
            return;
        }
    }
    std::cout << "No completed and unpaid order found for " << name << std::endl;
}

// method to close the restaurant (if no pending reservations/orders)
void Restaurant::closeRestaurant() {
    bool canClose = true;
    for (const auto& order : orders) {
        if (!order->isComplete() || !order->isPaid()) {
            canClose = false;
            break;
        }
    }

    if (canClose) {
        std::cout << "All orders completed and paid. Closing the restaurant." << std::endl;
    } else {
        std::cout << "Pending orders exist. Cannot close the restaurant until all bills are paid." << std::endl;
    }
}

bool Restaurant::isReservationCheckedIn(const std::string& name) const {
    for (const auto& reservation : reservations) {
        if (reservation->getCustomerName() == name && reservation->getTable() != nullptr) {
            return true; // Reservation exists and is checked in
        }
    }
    return false; // reservation does not exist or is not checked in
}