#include <iostream>
#include <cstdlib> // For rand() and srand()
#include <ctime>   // For time()
using namespace std;

class die {
public:
    // Default constructor: sets the number rolled by the die to 1
    die() {
        num = 1;
    }

    // Function to roll a die using a random number generator
    void roll() {
        num = rand() % 6 + 1;  // Random number between 1 and 6
    }

    // Function to return the number on the top face of the die
    int getNum() const {
        return num;
    }

private:
    int num;  // The number on the top face of the die
};
int main() {
    srand(static_cast<unsigned int>(time(0)));  // Seed the random number generator with current time

    const int NUM_DICE = 10;
    die dice[NUM_DICE];  // Array of 10 dice
    int desiredSum, rolls, count = 0;

    // Prompt the user for input
    cout << "Enter the desired sum (between 10 and 60): ";
    cin >> desiredSum;

    cout << "Enter the number of times to roll the dice: ";
    cin >> rolls;

    // Rolling the dice 'rolls' times
    for (int i = 0; i < rolls; i++) {
        int sum = 0;

        // Roll each die and calculate the sum
        for (int j = 0; j < NUM_DICE; j++) {
            dice[j].roll();
            sum += dice[j].getNum();
        }

        // Check if the sum matches the desired sum
        if (sum == desiredSum) {
            count++;
        }
    }

    // Output the result
    cout << "The desired sum of " << desiredSum << " was rolled " << count << " times out of " << rolls << " rolls." << endl;

    return 0;
}