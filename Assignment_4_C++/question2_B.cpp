#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    Vehicle(const string& reg, const string& owner, int year, double km){
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;

        cout << "[Vehicle Constructor] "
             << registrationNo << " : "
             << ownerName << endl;
    }

    virtual string vehicleType() const = 0;

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] " << registrationNo << endl;
    }
};

class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg,  const string& owner,  int year,  double km,  double payload,  double efficiency) : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;

        cout << "[Truck Constructor] "
             << registrationNo << endl;
    }

    string vehicleType() const override
    {
        return "Truck";
    }

    double fuelCost(double kmToTravel) const override
    {
        double effectiveEfficiency =
            fuelEfficiencyKmpl *
            (1 - 0.05 * payloadCapacityTons);

        double litresNeeded =
            kmToTravel / effectiveEfficiency;

        return litresNeeded * 93.00;
    }

    ~Truck()
    {
        cout << "[Truck Destructor] "
             << registrationNo << endl;
    }
};

class ElectricTruck : public Truck
{
private:
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(const string& reg,  const string& owner, int year,  double km,  double payload,  double efficiency,  double battery,  double range) : Truck(reg, owner, year, km, payload, efficiency)
    {
        batteryCapacityKWh = battery;
        rangePerChargeKm = range;

        cout << "[ElectricTruck Constructor] "
             << registrationNo << endl;
    }

    string vehicleType() const override
    {
        return "Electric Truck";
    }

    double fuelCost(double kmToTravel) const override
    {
        double energyUsed =
            (kmToTravel / rangePerChargeKm)
            * batteryCapacityKWh;

        return energyUsed * 9.50;
    }

    ~ElectricTruck()
    {
        cout << "[ElectricTruck Destructor] "
             << registrationNo << endl;
    }
};

int main()
{

    cout << "Creating ElectricTruck..." << endl;

    {
        ElectricTruck et(
            "V-ET001",
            "Green Logistics",
            2024,
            25000,
            10,
            8,
            200,
            400
        );

        cout << "ElectricTruck object is inside scope."
             << endl;
    }

    cout << "Scope ended." << endl;

    return 0;
}

