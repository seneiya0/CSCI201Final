#ifndef TABLE_H
#define TABLE_H

class Table {
private:
    int tableNumber;
    int size;
    bool available;

public:
    Table(int number, int size);
    int getTableNumber() const;
    int getSize() const;
    bool isAvailable() const;
    void markOccupied();
    void markAvailable();
};

#endif // TABLE_H