// CSCE 306 | Week 6 • Example 05: Sequence diagram -> code (interaction modeling)
// Build: g++ -std=c++17 -Wall -Wextra 05_sequence_diagram_to_code.cpp -o seq
//
//  :Customer        :Cart                 :Inventory            :PaymentGateway
//      |  checkout()  |                        |                        |
//      |------------->|                        |                        |
//      |              | loop [each item]       |                        |
//      |              |  reserve(sku, qty)     |                        |
//      |              |----------------------->|                        |
//      |              |<- - - - - - ok:bool - -|                        |
//      |              | alt [all reserved]     |                        |
//      |              |  charge(total)         |                        |
//      |              |------------------------------------------------>|
//      |              |<- - - - - - - - - - - - - - - - - - receipt:int |
//      |              | [else] release reserved items                    |
//      |<- - result - |                        |                        |
//
// Each solid arrow is a MEMBER FUNCTION CALL on the receiving object.
// Each dashed arrow is a RETURN VALUE. "loop" -> for, "alt" -> if/else.

#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

class Inventory {
    map<string, int> stock{{"PEN", 10}, {"PAD", 1}};
public:
    bool reserve(const string& sku, int qty)
    {
        auto it = stock.find(sku);
        if (it == stock.end() || it->second < qty) return false;
        it->second -= qty;
        return true;
    }
    void release(const string& sku, int qty) { stock[sku] += qty; }
};

class PaymentGateway {
    int nextReceipt = 9001;
public:
    int charge(double amount) { cout << "    charged $" << amount << '\n'; return nextReceipt++; }
};

struct LineItem { string sku; int qty; double price; };

class Cart {
    vector<LineItem> items;
    Inventory&       inventory;   // collaborators received by reference (association)
    PaymentGateway&  gateway;
public:
    Cart(Inventory& inv, PaymentGateway& gw) : inventory(inv), gateway(gw) {}
    void add(const LineItem& li) { items.push_back(li); }

    string checkout()
    {
        vector<LineItem> reserved;
        bool allOk = true;
        for (const LineItem& li : items) {                  // loop fragment
            if (inventory.reserve(li.sku, li.qty)) reserved.push_back(li);
            else { allOk = false; break; }
        }
        if (allOk) {                                        // alt fragment
            double total = 0;
            for (const LineItem& li : items) total += li.qty * li.price;
            return "receipt #" + to_string(gateway.charge(total));
        }
        for (const LineItem& li : reserved) inventory.release(li.sku, li.qty);
        return "failed: out of stock";
    }
};

int main()
{
    Inventory inv;
    PaymentGateway gw;

    Cart c1(inv, gw);
    c1.add({"PEN", 3, 1.25});
    c1.add({"PAD", 1, 4.00});
    cout << "cart 1: " << c1.checkout() << '\n';

    Cart c2(inv, gw);
    c2.add({"PEN", 2, 1.25});
    c2.add({"PAD", 1, 4.00});          // none left
    cout << "cart 2: " << c2.checkout() << '\n';
    return 0;
}
