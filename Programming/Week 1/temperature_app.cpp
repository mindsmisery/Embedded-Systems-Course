#include <iostream> 
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
std::vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
std::vector<double> temperature = {22.32, 21.85, 20.58, 19.46, 25.11, 20.06, 18.20}; /* the double is a data type for floats */

for (string d: days)
    std::cout << d << std::endl;

// for (int i = 0; i < days.size(); i++) // i is an integer; days.size() returns the number of days, true as long as number of days it more than 0. increase i by 1.
//     std::cout << "Temperature on: ";
//     std::cout << string[days];
    return 0;
}


// int main() {
//     map<string, double> day_temperature =  { {"Monday", 22.32}, {"Tuesday", 21.85}, {"Wednesday", 20.58}, {"Thursday", 19.46}, {"Friday", 25.11}, {"Saturday", 20.06}, {"Sunday", 18.20} };
    
// }