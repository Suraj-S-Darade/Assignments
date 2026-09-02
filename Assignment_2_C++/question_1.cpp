#include <iostream>
using namespace std;

class Product {

    int productId;
    string name;
    double price;
    int quantity;

public:

    static int ID;

    Product() {
        productId = ID++;
    }

    void acceptDetails() {

        cout << "Enter product name: ";
        cin >> name;

        cout << "Enter price: ";
        cin >> price;

        cout << "Enter quantity: ";
        cin >> quantity;
    }

    double getTotalValue() const {
        return price * quantity;
    }

    int getQuantity() const {
        return quantity;
    }

    string getName() const {
        return name;
    }

    void displayDetails() const {

        cout << productId << "\t"
             << name << "\t"
             << price << "\t"
             << quantity << "\t"
             << getTotalValue();

        if(quantity < 10) {
            cout << "\t<- LOW STOCK";
        }

        cout << endl;
    }
};


// Static variable definition
int Product::ID = 1001;


int main() {

    int size;
    int threshold = 10;

    cout << "Enter number of PRODUCTS: ";
    cin >> size;

    Product* arr = new Product[size];


    // Accept product details
    for(int i = 0; i < size; i++) {

        cout << "\nProduct " << i + 1 << endl;

        arr[i].acceptDetails();
    }

    cout << endl;

    // Inventory Report
    cout << "===== INVENTORY REPORT =====" << endl;

    cout << "ID\tName\tPrice\tQty\tTotal Value" << endl;

    for(int i = 0; i < size; i++) {

        arr[i].displayDetails();
    }


    // Find Highest Value Product
    double highest = 0;
    int highestIndex = 0;

    for(int i = 0; i < size; i++) {

        if(arr[i].getTotalValue() > highest) {

            highest = arr[i].getTotalValue();

            highestIndex = i;
        }
    }

    cout << endl;

    cout << "Highest Value Product : " << arr[highestIndex].getName << " (Rs. " << highest << ")" << endl;


    // Find Low Stock Products
    cout << "Low Stock (threshold: " << threshold << ") : " << ;

    for(int i = 0; i < size; i++) {

        if(arr[i].getQuantity() < threshold) {

            cout << arr[i].getName() << ", ";
        }
    }


    // Free memory
    delete[] arr;

    return 0;
}