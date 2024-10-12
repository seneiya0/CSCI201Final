#include <iostream>
#include <vector>
#include <limits>
#include <algorithm>
#include <cctype>
#include <string>
#include "Restaurant.h"
#include "Order.h"

void displayMenu();
void clearInput();
void displayMenuItems();
std::string toLowerCase(const std::string& str);

int main() {
    Restaurant restaurant;
    int choice;

    do {
        displayMenu();
        std::cin >> choice;

        if (std::cin.fail()) {
            std::cout << "Invalid input. Please enter a number between 0 and 6." << std::endl;
            clearInput();
            continue;
        }

        switch (choice) {
            case 1: {
                std::string name, time;
                int partySize;
                std::cout << "Enter customer name: ";
                clearInput();
                std::getline(std::cin, name);
                name = toLowerCase(name);
                std::cout << "Enter party size: ";
                std::cin >> partySize;

                if (std::cin.fail() || partySize <= 0) {
                    std::cout << "Invalid party size. Please enter a positive integer." << std::endl;
                    clearInput();
                    break;
                }

                std::cout << "Enter reservation time (e.g., 7:00 PM): ";
                clearInput();
                std::getline(std::cin, time);

                restaurant.addReservation(name, partySize, time);
                break;
            }
            case 2: {
                std::string name;
                std::cout << "Enter customer name for check-in: ";
                clearInput();
                std::getline(std::cin, name);
                name = toLowerCase(name);
                restaurant.checkInReservation(name);
                break;
            }
            case 3: {
                std::string name;
                int numItems;
                std::vector<MenuItem> items;
                std::cout << "Enter customer name for order: ";
                clearInput();
                std::getline(std::cin, name);
                name = toLowerCase(name);

                if (!restaurant.isReservationCheckedIn(name)) {
                    std::cout << "Reservation for " << name << " does not exist or is not checked in. Please check in the reservation first." << std::endl;
                    break;
                }

                std::cout << "Enter number of items: ";
                std::cin >> numItems;

                if (std::cin.fail() || numItems <= 0) {
                    std::cout << "Invalid number of items. Please enter a positive integer." << std::endl;
                    clearInput();
                    break;
                }

                for (int i = 0; i < numItems; ++i) {
                    int itemChoice;
                    displayMenuItems();
                    std::cout << "Select item (0-13): ";
                    std::cin >> itemChoice;

                    if (std::cin.fail() || itemChoice < 0 || itemChoice > 13) {
                        std::cout << "Invalid menu item. Please enter a number between 0 and 13." << std::endl;
                        clearInput();
                        --i; // retry the current item
                        continue;
                    }

                    items.push_back(static_cast<MenuItem>(itemChoice));
                }
                restaurant.enterOrder(name, items);
                break;
            }
            case 4: {
                std::string name;
                std::cout << "Enter customer name to complete order: ";
                clearInput();
                std::getline(std::cin, name);
                name = toLowerCase(name);
                restaurant.completeOrder(name);
                break;
            }
            case 5: {
                std::string name;
                std::cout << "Enter customer name to calculate and pay bill: ";
                clearInput(); 
                std::getline(std::cin, name);
                name = toLowerCase(name);
                restaurant.calculateAndPayBill(name);
                break;
            }
            case 6:
                restaurant.closeRestaurant();
                break;
            case 0:
                std::cout << "Exiting program. Goodbye!" << std::endl;
                break;
            default:
                std::cout << "Invalid choice, please enter a number between 0 and 6." <<  std::endl;
        }
    } while (choice != 0);

    return 0;
}

void clearInput() {
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input
}

// function to display the main menu
void displayMenu() {
    std::cout << "\n--- Messi Joes Management System ---\n";
    std::cout << "1. Make Reservation" << std::endl;
    std::cout << "2. Check-in Reservation" << std::endl;
    std::cout << "3. Enter Order" << std::endl;
    std::cout << "4. Complete Order" << std::endl;
    std::cout << "5. Calculate and Pay Bill" << std::endl;
    std::cout << "6. Close Restaurant" << std::endl;
    std::cout << "0. Exit Program" << std::endl;
    std::cout << "Enter your choice: ";
}

// function to display food menu
void displayMenuItems() {
    std::cout << "\nAvailable Menu Items:" << std::endl;
    std::cout << "0: Veggie Burger ($35)" << std::endl;
    std::cout << "1: Hamburger ($45)" << std::endl;
    std::cout << "2: Fried Chicken Sliders ($38)" << std::endl;
    std::cout << "3: Hamburger Sliders ($38)" << std::endl;
    std::cout << "4: Veggie Sliders ($38)" << std::endl;
    std::cout << "5: Haddock Sandwich ($38)" << std::endl;
    std::cout << "6: BLT ($42)" << std::endl;
    std::cout << "7: Faux BLT ($42)" << std::endl;
    std::cout << "8: Chicken Burrito ($42)" << std::endl;
    std::cout << "9: Falafel Wrap ($42)" << std::endl;
    std::cout << "10: Cheese Pizza ($59)" << std::endl;
    std::cout << "11: Pepperoni Pizza ($59)" << std::endl;
    std::cout << "12: Faux Meat and Chips ($77)" << std::endl;
    std::cout << "13: Fish and Chips ($77)" << std::endl;
    std::cout << std::endl;
}

std::string toLowerCase(const std::string& str) {
    std::string lowerStr = str;
    std::transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), [](unsigned char c) {
        return std::tolower(c);
    });
    return lowerStr;
}