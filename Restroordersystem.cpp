#include <iostream>
#include <string>

using namespace std;

class MenuItem
{
    public:
        string name;
        float price;
        static string restaurantName;

        virtual void display()
        {
            cout << name << " - Rupees " << price << endl;
        }
};

string MenuItem::restaurantName = "THE A4 RESTRO";

class FoodItem : public MenuItem
{
    public:
        FoodItem(string n, float p)
        {
            name = n;
            price = p;
        }
};

class Bill
{
    public:
        float total;
        string customerName;

        Bill()
        {
            total = 0.0;
        }

        void add(float price)
        {
            total = total + price;
            cout << "\n--- Added to cart! Current Total: Rupees " << total << endl;
        }

        void printFinal()
        {
            cout << "\n===============================\n" << endl;
            cout << " RESTAURANT: " << MenuItem::restaurantName << endl;
            cout << " CUSTOMER: " << customerName << endl;
            cout << " FINAL BILL TOTAL: " << total << endl;
            cout << " Thank you for your order !!! " << endl;
            cout << "\n===============================\n" << endl;
        }
};

int main()
{
    Bill myBill;
    int category = 0;
    int item = 0;

    cout << "Enter Customer Name: ";
    getline(cin, myBill.customerName);

    FoodItem p1("Veg Pizza :", 85), p2("Cheese Pizza :", 100);
    FoodItem b1("Coke :", 150), b2("Juice :", 200);
    FoodItem s1("Veg Sandwich :", 400), s2("Classic Sandwich :", 50);
    FoodItem r1("Classic Burger :", 650), r2("Veggie Burger :", 500);

    cout << "\n--- WELCOME TO " << MenuItem::restaurantName << " ---" << endl;

    while (category != 5)
    {
        cout << "\nSELECT A CATEGORY:" << endl;
        cout << "1. Pizza\n2. Beverages\n3. Sandwich\n4. Burger\n5. Checkout & Exit\n" << endl;
        cout << "Choice: ";
        cin >> category;

        if (category == 1)
        {
            cout << "\n-- PIZZA MENU --\n" << endl;
            cout << "1. "; p1.display();
            cout << "2. "; p2.display();
            cin >> item;
            if (item == 1) myBill.add(p1.price);
            else if (item == 2) myBill.add(p2.price);
        }
        else if (category == 2)
        {
            cout << "\n-- BEVERAGES --\n" << endl;
            cout << "1. "; b1.display();
            cout << "2. "; b2.display();
            cin >> item;
            if (item == 1) myBill.add(b1.price);
            else if (item == 2) myBill.add(b2.price);
        }
        else if (category == 3)
        {
            cout << "\n-- SANDWICHES --\n" << endl;
            cout << "1. "; s1.display();
            cout << "2. "; s2.display();
            cin >> item;
            if (item == 1) myBill.add(s1.price);
            else if (item == 2) myBill.add(s2.price);
        }
        else if (category == 4)
        {
            cout << "\n-- BURGERS --\n" << endl;
            cout << "1. "; r1.display();
            cout << "2. "; r2.display();
            cin >> item;
            if (item == 1) myBill.add(r1.price);
            else if (item == 2) myBill.add(r2.price);
        }
    }

    myBill.printFinal();
    return 0;
}