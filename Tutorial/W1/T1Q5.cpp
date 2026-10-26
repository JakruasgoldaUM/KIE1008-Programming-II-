#ifndef SWIMMINGPOOL_H
#define SWIMMINGPOOL_H

#include <iostream>
#include <iomanip>

using namespace std;

// ============================================================
// 1. CLASS DECLARATION
// ============================================================
class swimmingPool {
private:
    double length;      // Length of pool (in metres)
    double width;       // Width of pool (in metres)
    double depth;       // Depth of pool (in metres)
    double fillRate;    // Water filling rate (in cubic metres per minute)
    double drainRate;   // Water draining rate (in cubic metres per minute)
    double waterAmount; // Current volume of water in pool (in cubic metres)

public:
    // Constructor with default parameters
    swimmingPool(double l = 0, double w = 0, double d = 0, 
                 double fRate = 0, double dRate = 0, double currentWater = 0);

    // Mutator and Accessor Functions
    void setPoolDimensions(double l, double w, double d);
    void setFillRate(double fRate);
    void setDrainRate(double dRate);
    void setWaterAmount(double currentWater);

    double getLength() const;
    double getWidth() const;
    double getDepth() const;
    double getFillRate() const;
    double getDrainRate() const;
    double getWaterAmount() const;

    // Core Member Functions
    double poolCapacity() const;  // Calculates maximum pool capacity (m^3)
    double waterNeeded() const;   // a) Calculates water needed to completely fill pool
    double timeToFill() const;    // b) Calculates time needed to fill remaining capacity (minutes)
    double timeToDrain() const;   // b) Calculates time needed to empty current water (minutes)
    void addWater(double time);   // c) Adds water based on fill rate and duration (minutes)
    void drainWater(double time); // c) Drains water based on drain rate and duration (minutes)
};

#endif // SWIMMINGPOOL_H


// ============================================================
// 2. MEMBER FUNCTION DEFINITIONS
// ============================================================

// Constructor implementation
swimmingPool::swimmingPool(double l, double w, double d, 
                           double fRate, double dRate, double currentWater) {
    setPoolDimensions(l, w, d);
    setFillRate(fRate);
    setDrainRate(dRate);
    setWaterAmount(currentWater);
}

// Mutators with non-negative validation
void swimmingPool::setPoolDimensions(double l, double w, double d) {
    length = (l >= 0) ? l : 0;
    width  = (w >= 0) ? w : 0;
    depth  = (d >= 0) ? d : 0;
}

void swimmingPool::setFillRate(double fRate) {
    fillRate = (fRate >= 0) ? fRate : 0;
}

void swimmingPool::setDrainRate(double dRate) {
    drainRate = (dRate >= 0) ? dRate : 0;
}

void swimmingPool::setWaterAmount(double currentWater) {
    double cap = poolCapacity();
    if (currentWater < 0) {
        waterAmount = 0;
    } else if (currentWater > cap && cap > 0) {
        waterAmount = cap; // Cannot exceed pool capacity
    } else {
        waterAmount = currentWater;
    }
}

// Accessors
double swimmingPool::getLength() const { return length; }
double swimmingPool::getWidth() const { return width; }
double swimmingPool::getDepth() const { return depth; }
double swimmingPool::getFillRate() const { return fillRate; }
double swimmingPool::getDrainRate() const { return drainRate; }
double swimmingPool::getWaterAmount() const { return waterAmount; }

// Calculates total pool volume (Volume = length * width * depth)
double swimmingPool::poolCapacity() const {
    return length * width * depth;
}

// a) Amount of water needed to fill an empty or partially filled pool
double swimmingPool::waterNeeded() const {
    double needed = poolCapacity() - waterAmount;
    return (needed > 0) ? needed : 0;
}

// b) Time needed to completely or partially fill the pool
double swimmingPool::timeToFill() const {
    if (fillRate <= 0) return 0;
    return waterNeeded() / fillRate;
}

// b) Time needed to completely or partially empty the pool
double swimmingPool::timeToDrain() const {
    if (drainRate <= 0) return 0;
    return waterAmount / drainRate;
}

// c) Add water for a specific duration in minutes
void swimmingPool::addWater(double time) {
    if (time > 0) {
        waterAmount += fillRate * time;
        if (waterAmount > poolCapacity()) {
            waterAmount = poolCapacity(); // Prevent overflow
        }
    }
}

// c) Drain water for a specific duration in minutes
void swimmingPool::drainWater(double time) {
    if (time > 0) {
        waterAmount -= drainRate * time;
        if (waterAmount < 0) {
            waterAmount = 0; // Prevent negative volume
        }
    }
}


// ============================================================
// 3. MAIN DRIVER PROGRAM
// ============================================================
int main() {
    cout << fixed << setprecision(2);
    cout << "=== Testing swimmingPool Class ===" << endl << endl;

    // Instantiate pool: 10m x 5m x 2m (Capacity = 100 m^3)
    // Fill rate = 2.5 m^3/min, Drain rate = 1.5 m^3/min, Current water = 30 m^3
    swimmingPool pool(10.0, 5.0, 2.0, 2.5, 1.5, 30.0);

    cout << "Pool Dimensions: " << pool.getLength() << "m x " 
         << pool.getWidth() << "m x " << pool.getDepth() << "m" << endl;
    cout << "Total Capacity: " << pool.poolCapacity() << " m^3" << endl;           // OUTPUT: Total Capacity: 100.00 m^3
    cout << "Current Water: " << pool.getWaterAmount() << " m^3" << endl << endl;   // OUTPUT: Current Water: 30.00 m^3

    // a) Water needed
    cout << "a) Water needed to fill pool: " << pool.waterNeeded() << " m^3" << endl; // OUTPUT: a) Water needed to fill pool: 70.00 m^3

    // b) Time needed to fill / empty
    cout << "b) Time needed to fill pool: " << pool.timeToFill() << " minutes" << endl;   // OUTPUT: b) Time needed to fill pool: 28.00 minutes
    cout << "   Time needed to drain pool: " << pool.timeToDrain() << " minutes" << endl << endl; // OUTPUT:    Time needed to drain pool: 20.00 minutes

    // c) Add water for 10 minutes (adds 2.5 * 10 = 25 m^3; total = 55 m^3)
    pool.addWater(10.0);
    cout << "c) After adding water for 10 mins:" << endl;
    cout << "   New Water Amount: " << pool.getWaterAmount() << " m^3" << endl;       // OUTPUT:    New Water Amount: 55.00 m^3
    cout << "   New Time Needed to Fill: " << pool.timeToFill() << " minutes" << endl << endl; // OUTPUT:    New Time Needed to Fill: 18.00 minutes

    // c) Drain water for 20 minutes (drains 1.5 * 20 = 30 m^3; total = 25 m^3)
    pool.drainWater(20.0);
    cout << "c) After draining water for 20 mins:" << endl;
    cout << "   New Water Amount: " << pool.getWaterAmount() << " m^3" << endl;       // OUTPUT:    New Water Amount: 25.00 m^3

    return 0;
}