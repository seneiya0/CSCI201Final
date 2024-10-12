#ifndef RESERVATION_H
#define RESERVATION_H

#include <string>
#include "Table.h"

class Reservation {
private:
    std::string customerName;
    int partySize;
    Table* table;  // Pointer to the assigned table (null if no table assigned)
    std::string time;

public:
    Reservation(const std::string& name, int size, const std::string& reservationTime);
    
    // Getters
    std::string getCustomerName() const;
    int getPartySize() const;
    std::string getTime() const;
    Table* getTable() const;
    
    // Setter
    void assignTable(Table* assignedTable);

    // Check-in functionality
    void checkIn();
};

#endif // RESERVATION_H