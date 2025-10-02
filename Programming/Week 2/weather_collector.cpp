#include <string>
#include <algorithm>
#include <fstream>
#include <format>
#include <iostream>
#include <stdexcept>
#include <numeric>
#include <iomanip>
using namespace std;

class WeatherStation {
    private:
    float* readings;
    float average_temperature;
    float reading_sum;
    int reading_count;
    int reading_capacity;

    public:
    string location;
    string file_name;

    WeatherStation(const string& location_input, int initial_capacity = 10) {
        location = location_input;
        file_name = location + "_readings.txt";
        reading_count = 0;
        reading_capacity = initial_capacity;
        readings = new float[reading_capacity];
        reading_sum = 0.0f;
        average_temperature =  0.0f;
    }

    ~WeatherStation() {
        delete[] readings;
    }

    template <typename T>
    int countReadingsAbove(T* array, int count, T threshold) {
        return std::count_if(array, array + count, [threshold](T value) { return value > threshold; });
    }

    void addReading(float temperature) {
    if (reading_count >= reading_capacity) {
        int new_reading_capacity = reading_capacity + 5;
        float * temporary_readings = new float[new_reading_capacity];

        for (int i = 0; i < reading_count; ++i)
            temporary_readings[i] = readings[i];

        delete[] readings;
        readings = temporary_readings;
        reading_capacity = new_reading_capacity;
        }

        readings[reading_count++] = temperature;
        reading_sum += temperature;
        average_temperature = reading_sum / reading_count;
    }

    void printReadings() {
        std::string readings_string;
        int count_above_25 = std::count_if(readings, readings + reading_count, [](float temperature){return temperature > 25.0f;});

        for (int i = 0; i < reading_count; ++i) {
            readings_string += std::to_string(readings[i]);
            if (i != reading_count - 1)
            readings_string += " ";
        }

        std::cout << "Location: " << location << endl;
        std::cout << "Readings: " << readings_string << endl;
        std::cout << "Average: " << std::fixed << std::setprecision(2) << average_temperature << std::endl;
        std::cout << "Readings above 25°C: " << count_above_25 << endl;
        std::cout << "Saved to file: " << file_name << std::endl;
    }

    void saveToFile() {
        ofstream StationFile(file_name);
        if (!StationFile.is_open())
            throw runtime_error("Unable to open file " + file_name + " for writing.");
        
        StationFile << location << "\n";
        StationFile << reading_count << "\n";
        
        for (int i = 0; i < reading_count; ++i) {
            StationFile << readings[i];
            if (i != reading_count - 1)
                StationFile << " ";
        }
        StationFile.close();
    }
};

int main() {
    try {
        WeatherStation lahtiStation("Lahti");
        lahtiStation.addReading(22.5f);
        lahtiStation.addReading(24.0f);
        lahtiStation.addReading(26.3f);
        lahtiStation.addReading(21.8f);
        lahtiStation.addReading(25.7f);

        lahtiStation.printReadings();
        lahtiStation.saveToFile();
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}