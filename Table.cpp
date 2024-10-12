#include "Table.h"

Table::Table(int number, int size) : tableNumber(number), size(size), available(true) {}

int Table::getTableNumber() const { return tableNumber; }
int Table::getSize() const { return size; }

bool Table::isAvailable() const { return available; }
void Table::markOccupied() { available = false; }
void Table::markAvailable() { available = true; }