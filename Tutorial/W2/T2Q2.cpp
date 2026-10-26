#include <iostream>
#include <string>
using namespace std;

class dayType {
private:
    string days[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"}; // Array to hold the days of the week
    int currentDayIndex; // Index of the current day in the array

public:
    // Default constructor to initialize the day to Sunday
    dayType() {
        currentDayIndex = 0; // Default to Sunday (index 0)
    }

    // Constructor to initialize the day to a specific day
    dayType(const string& day) {
        setDay(day); // Use the setDay function to initialize the day
    }

    // a) Function to set the current day
    void setDay(const string& day) {
        for (int i = 0; i < 7; i++) {
            if (days[i] == day) {
                currentDayIndex = i;
                return;
            }
        }
        cout << "Invalid day entered!" << endl;
    }

    // b) Function to print the current day
    void printDay() const {
        cout << "Current day: " << days[currentDayIndex] << endl;
    }

    // c) Function to return the current day as a string
    string getDay() const {
        return days[currentDayIndex];
    }

    // d) Function to return the next day
    string getNextDay() const {
        return days[(currentDayIndex + 1) % 7]; // Next day is the next index, wrap around with modulus 7
    }

    // e) Function to return the previous day
    string getPreviousDay() const {
        return days[(currentDayIndex + 6) % 7]; // Previous day is one before, wrap around with modulus 7
    }

    // f) Function to calculate the day after adding certain number of days
    string addDays(int numDays) const {
        return days[(currentDayIndex + numDays) % 7]; // Add days and wrap around using modulus 7
    }
};

int main() {
    // Create a dayType object
    dayType today("Tue"); // Set the initial day to Tuesday

    // Display current day
    today.printDay();

    // Get the next day
    cout << "Next day: " << today.getNextDay() << endl;

    // Get the previous day
    cout << "Previous day: " << today.getPreviousDay() << endl;

    // Add 4 days and get the resulting day
    cout << "Day after adding 4 days: " << today.addDays(4) << endl;

    // Add 13 days and get the resulting day
    cout << "Day after adding 13 days: " << today.addDays(13) << endl;

    // Set a new day to Friday
    today.setDay("Fri");
    today.printDay();

    // Add 2 days to Friday
    cout << "Day after adding 2 days to Friday: " << today.addDays(2) << endl;

    return 0;
}