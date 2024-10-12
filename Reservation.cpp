#include <iostream>
#include "Reservation.h"

// constructor
Reservation::Reservation(const std::string& name, int size, const std::string& reservationTime)
    : customerName(name), partySize(size), table(nullptr), time(reservationTime) {}

// getters
std::string Reservation::getCustomerName() const { return customerName; }
int Reservation::getPartySize() const { return partySize; }
std::string Reservation::getTime() const { return time; }
Table* Reservation::getTable() const { return table; }

// setter
void Reservation::assignTable(Table* assignedTable) {
    table = assignedTable;
}

// check-in functionality
void Reservation::checkIn() {
    if (table) {
        std::cout << customerName << " has been checked in and seated at table " << table->getTableNumber() << std::endl;
    } else {
        std::cout << "No table assigned yet for " << customerName << std::endl;
    }
}