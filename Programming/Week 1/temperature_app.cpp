#include <iostream> 
#include <vector>
#include <string>
#include <map>
using namespace std;

// MAP-BASED
void checkTemperatureWithMap() { // void returns no value
    map<string, double> dayAndTemperature =  { {"Monday", 2.32}, {"Tuesday", 21.85}, {"Wednesday", 35.58}, {"Thursday", 19.46}, {"Friday", 25.11}, {"Saturday", 10.06}, {"Sunday", 18.20} };
    char weatherClass;
    
    for (auto& element : dayAndTemperature) {
        string day = element.first;
        double temperature = element.second;

        if (temperature < 10) {
            weatherClass = 'R';
        } else if (10 <= temperature <= 20) {
            weatherClass = 'C';
        } else if (temperature > 20) {
            weatherClass = 'S';
        }

        cout << day << " : " << temperature << "°C" << " || Weather:  " << weatherClass << endl;
    }
}

// STRING-DOUBLE-BASED
void checkTemperatureWithStringDouble () {
vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
vector<double> temperature = {2.32, 21.85, 20.58, 19.46, 25.11, 30.06, 18.20}; /* the double is a data type for floats */
tuple<string, double> warmDay = {days[0], temperature[0]};
string temperatureClass;

for (int i=0; i < days.size(); i++) { //range-based for loop (for-each) -- i is an integer; days.size() returns the number of days, true as long as number of days it more than 0. increase i by 1.
    
    if (temperature[i] < 10) {
        temperatureClass = "cold";
    } else if (10 <= temperature[i] <= 20) {
        temperatureClass = "ok";
    } else if (temperature[i] > 20) {
        temperatureClass = "warm";
    }
    
    cout << days[i] << " : " << temperature[i] << "°C which is " << temperatureClass << endl;

    if (temperature[i] > get<1>(warmDay)) {
        warmDay = {days[i], temperature[i]};
    }
}

cout << "\nThe warmest day is " << get<0>(warmDay) << " at " << get<1>(warmDay) << "°C" << endl;
}

int main() {
    char x;
    while (true) {
        cout << "\nTo use string/double-based temperature check, press 1.\nTo use map-based temperature check, press 2." << endl;
        cout << "Choice: ";
        cin >> x;
        cout << "You chose  " << x << endl;

        if (x =='1') {
            checkTemperatureWithStringDouble();
        } else if (x == '2') {
            checkTemperatureWithMap();
        } else if (x == 'q') {
            break;
        } else {
            cout << "Enter either 1, 2 or q." << endl;
        }
    }
    return 0;
}
