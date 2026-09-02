#include <iostream>
using namespace std;


// 1. Integer quantity
double reorderCost(int qty, double unitPrice) {
    return qty * unitPrice;
}


// 2. Fractional quantity
double reorderCost(double qty, double unitPrice) {
    return qty * unitPrice;
}


// 3. Integer quantity + tax
double reorderCost(int qty, double unitPrice, double taxRate) {

    double cost = qty * unitPrice;

    double tax = cost * taxRate / 100;

    return cost + tax;
}


// 4. Default argument
double applyDiscount(double price, double discountPercent = 10.0) {

    double discount = price * discountPercent / 100;

    return price - discount;
}


int main() {

    // Calling integer quantity version
    cout << "Integer reorder cost : "
         << reorderCost(10, 50.0)
         << endl;


    // Calling fractional quantity version
    cout << "Fractional reorder cost : "
         << reorderCost(2.5, 50.0)
         << endl;


    // Calling version with tax
    cout << "Reorder cost with tax : "
         << reorderCost(10, 50.0, 18.0)
         << endl;


    // Calling default argument
    cout << "Price after default discount : "
         << applyDiscount(1000)
         << endl;


    // Calling with custom discount
    cout << "Price after 20% discount : "
         << applyDiscount(1000, 20.0)
         << endl;


    return 0;
}