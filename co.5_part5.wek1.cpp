#include <iostream>
#include <map>
#include <string>

using namespace std;

class Wallet {
public:
  Wallet() {}
  void insertCurrency(string type, double amount) {
    currencies[type] += amount;
  }
  bool removeCurrency(string type, double amount) {
    if (currencies.find(type) == currencies.end()) {
      return false;
    }
    double balance = currencies[type];
    if (balance < amount) {
      return false;
    }
    currencies[type] -= amount;
    return true;
  }
  bool containsCurrency(string type, double amount) {
    if (currencies.find(type) == currencies.end()) {
      return false;
    }
    double balance = currencies[type];
    return balance >= amount;
  }
  string toString() {
   ostringstream oss;
   for (auto it = currencies.begin(); it != currencies.end(); it++) {
     oss << it->first << ": " << it->second << endl;
   }
   return oss.str();
  }
private:
  map<string, double> currencies;
};

int main() {
  Wallet wallet;
  wallet.insertCurrency("BTC", 1.5);
  cout << "Wallet should contain 1.5 BTC now" << endl;
  cout << wallet << endl;
  bool result = wallet.containsCurrency("BTC", 1.5);
  cout << "Result should be true " << result << endl;
  result = wallet.removeCurrency("BTC", 2.0);
  cout << "Result should be false " << result << endl;
  result = wallet.removeCurrency("BTC", 1.0);
  cout << "Result should be true " << result << endl;
  return 0;
}
