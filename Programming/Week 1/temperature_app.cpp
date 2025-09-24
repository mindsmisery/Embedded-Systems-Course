#include <iostream> 
#include <vector>
#include <string>
#include <unordered_map>
#include <limits.h>
using namespace std;

// MAP-BASED
void checkTemperatureWithMap() { // void returns no value
    // The map runs into a bizarre problem where it prints out days in an alphabetical order. 
    unordered_map<string, double> dayAndTemperature =  { {"Sunday", 18.20}, {"Saturday", 10.06}, {"Friday", 25.11}, {"Wednesday", 35.58},{"Thursday", 19.46}, {"Tuesday", 21.85}, {"Monday", 2.32}};
    string warmestDay;
    string temperatureClass;
    double maxTemperature = INT_MIN;
    double averageTemperature = 0.0;
    
    for (auto& element : dayAndTemperature) {
        int randomNumber;
        char weatherClass;
        string day = element.first;
        double temperature = element.second;
        
        if (temperature < 10) {
            temperatureClass = "cold";
        } else if (temperature >= 10 && temperature <= 20) {
            temperatureClass = "ok";
        } else if (temperature > 20) {
            temperatureClass = "warm";
        }

        randomNumber = rand() % 11;

        if (randomNumber < 3) {
            weatherClass = 'S';
        } else if (randomNumber >= 3 && randomNumber <= 5) {
            weatherClass = 'F';
        } else if (randomNumber >= 6 && randomNumber <= 8) {
            weatherClass = 'R';
        } else {
            weatherClass = 'T';
        }

        if (temperature > maxTemperature) {
            maxTemperature = temperature;
            warmestDay = day;
        }

        averageTemperature = averageTemperature + temperature;
        cout << "[" << weatherClass << "] " << day << " : " << temperature << "°C" << " - Temperature is " << temperatureClass << endl;
    }

    averageTemperature = averageTemperature / 7;

    cout << "\n| The warmest day of the week is " << warmestDay << " at " << maxTemperature << "°C" << endl;
    cout << "| Average temperature of the week is " << averageTemperature << "°C" << endl;
    cout << "\nReturning to menu selection. . ." << endl << endl;
}

// STRING-DOUBLE-BASED
void checkTemperatureWithStringDouble () {
    vector<string> days = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    vector<double> temperature = {2.32, 21.85, 20.58, 19.46, 25.11, 30.06, 18.20}; /* the double is a data type for floats */
    pair<string, double> warmestDay = {days[0], temperature[0]};
    string temperatureClass;

    for (int i=0; i < days.size(); i++) { //range-based for loop (for-each) -- i is an integer; days.size() returns the number of days, true as long as number of days it more than 0. increase i by 1.
    
    if (temperature[i] < 10) {
        temperatureClass = "cold";
    } else if (temperature[i] >= 10 && temperature[i] <= 20) {
        temperatureClass = "ok";
    } else if (temperature[i] > 20) {
        temperatureClass = "warm";
    }
    
    cout << days[i] << " : " << temperature[i] << "°C - Temperature is " << temperatureClass << endl;

    if (temperature[i] > get<1>(warmestDay)) {
        warmestDay = {days[i], temperature[i]};
    }
}

cout << "\n| The warmest day of the week is " << get<0>(warmestDay) << " at " << get<1>(warmestDay) << "°C" << endl;
}

// MAIN FUNCTION
int main() {
    srand(time(0));
    char x;
    while (true) {
        cout << "\nTo use string/double-based temperature check, enter 1.\nTo use map-based temperature check, enter 2.\nTo quit, enter q." << endl;
        cout << "Choice: ";
        cin >> x;

        if (x == 'q') {
            cout << "\nQuitting weather program. . ." << endl;
        } else {
            cout << "\nRunning weather program. . ." << endl << endl;
        }

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
