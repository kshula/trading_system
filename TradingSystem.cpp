#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a simple struct for representing a trade order
struct Order {
    string symbol;
    int quantity;
    double price;
    string side; // "BUY" or "SELL"

    Order(string sym, int qty, double prc, string s) 
        : symbol(sym), quantity(qty), price(prc), side(s) {}
};

// Define a trading system class
class TradingSystem {
private:
    vector<Order> orders; // Store orders in a vector

public:
    // Function to place a new order
    void placeOrder(const Order& order) {
        orders.push_back(order);
        cout << "Order placed: " << order.side << " " << order.quantity << " shares of " 
             << order.symbol << " at $" << order.price << endl;
    }

    // Function to execute all pending orders
    void executeOrders() {
        for (const auto& order : orders) {
            if (order.side == "BUY") {
                cout << "Executing BUY order: " << order.quantity << " shares of " 
                     << order.symbol << " at $" << order.price << endl;
                // Implement logic to execute buy order (e.g., update portfolio)
            } else if (order.side == "SELL") {
                cout << "Executing SELL order: " << order.quantity << " shares of " 
                     << order.symbol << " at $" << order.price << endl;
                // Implement logic to execute sell order (e.g., update portfolio)
            }
        }
        orders.clear(); // Clear executed orders
    }
};

int main() {
    // Create a trading system instance
    TradingSystem tradingSystem;

    // Example: Place some buy and sell orders
    tradingSystem.placeOrder(Order("AAPL", 100, 150.50, "BUY"));
    tradingSystem.placeOrder(Order("GOOG", 50, 2800.75, "BUY"));
    tradingSystem.placeOrder(Order("AAPL", 50, 155.20, "SELL"));

    // Execute all pending orders
    tradingSystem.executeOrders();

    return 0;
}
