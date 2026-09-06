#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Vehicle
{
protected:
    string registrationNo;
    string ownerName;
    int yearOfManufacture;
    double kmDriven;

public:

    Vehicle(const string& reg, const string& owner, int year, double km)
    {
        registrationNo = reg;
        ownerName = owner;
        yearOfManufacture = year;
        kmDriven = km;
    }

    virtual string vehicleType() const = 0;

    virtual double fuelCost(double kmToTravel) const = 0;


    virtual void describe() const
    {
        cout << "Registration: " << registrationNo << endl;

        cout << "Owner: " << ownerName << endl;

        cout << "Year: " << yearOfManufacture << endl;

        cout << "Km Driven: " << kmDriven << endl;
    }

    virtual ~Vehicle()
    {
    }

    double getKmDriven() const
    {
        return kmDriven;
    }

    string getRegNo() const
    {
        return registrationNo;
    }

    string getOwnerName() const
    {
        return ownerName;
    }
};

class Car : public Vehicle
{
private:
    string fuelType;
    double mileageKmpl;

public:

    Car(const string& reg,  const string& owner, int year, double km, const string& fuel, double mileage) : Vehicle(reg, owner, year, km)
    {
        fuelType = fuel;
        mileageKmpl = mileage;
    }


    string vehicleType() const override
    {
        return "Car";
    }


    double fuelCost(double kmToTravel) const override
    {
        double fuelPrice;

        if (fuelType == "Petrol")
        {
            fuelPrice = 106.00;
        }
        else
        {
            fuelPrice = 93.00;
        }

        return (kmToTravel / mileageKmpl)
               * fuelPrice;
    }


    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type: " << fuelType << endl;

        cout << "Mileage: " << mileageKmpl << " kmpl" << endl;
    }
};

class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& reg, const string& owner,  int year,  double km,  double payload,  double efficiency) : Vehicle(reg, owner, year, km)
    {
        payloadCapacityTons = payload;
        fuelEfficiencyKmpl = efficiency;
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


    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload Capacity: " << payloadCapacityTons << " tons" << endl;

        cout << "Fuel Efficiency: " << fuelEfficiencyKmpl << " kmpl" << endl;
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
    }


    string vehicleType() const override
    {
        return "Electric Truck";
    }


    double fuelCost(double kmToTravel) const override
    {
        double energyUsed = (kmToTravel / rangePerChargeKm) * batteryCapacityKWh;

        return energyUsed * 9.50;
    }


    void describe() const override
    {
        Vehicle::describe();

        cout << "Battery Capacity: " << batteryCapacityKWh << " kWh" << endl;

        cout << "Range Per Charge: " << rangePerChargeKm << " km" << endl;
    }
};

class Van : public Vehicle
{
private:
    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& reg, const string& owner, int year, double km, int seating, double mileage) : Vehicle(reg, owner, year, km)
    {
        seatingCapacity = seating;
        mileageKmpl = mileage;
    }


    string vehicleType() const override
    {
        return "Van";
    }


    double fuelCost(double kmToTravel) const override
    {
        double litresNeeded =
            kmToTravel / mileageKmpl;

        return litresNeeded * 106.00;
    }


    void describe() const override
    {
        Vehicle::describe();

        cout << "Seating Capacity: " << seatingCapacity << endl;

        cout << "Mileage: " << mileageKmpl << " kmpl" << endl;
    }
};

void printFleetReport(

    const vector<Vehicle*>& fleet,
    double tripKm)
{
    cout << "===== FLEET REPORT =====" << endl;

    cout << "Trip Distance: " << tripKm << " km" << endl;

    cout << endl;

    cout << "Registration" << "\tType" << "\t\tOwner" << "\t\tKm Driven" << endl;

    for (Vehicle* vehicle : fleet)
    {
        cout << vehicle->getRegNo() << "\t" << vehicle->vehicleType() << "\t\t" << vehicle->getOwnerName() << "\t\t" << vehicle->getKmDriven() << endl;
    }


    cout << endl;

    cout << "===== FUEL / CHARGE COST ESTIMATE =====" << endl;

    double lowestCost = 1e9;

    Vehicle* mostEfficient = nullptr;

    for (Vehicle* vehicle : fleet)
    {
        double cost =
            vehicle->fuelCost(tripKm);

        cout << vehicle->getRegNo() << " (" << vehicle->vehicleType() << ") : Rs. " << cost << endl;

        if (cost < lowestCost)
        {
            lowestCost = cost;
            mostEfficient = vehicle;
        }
    }

    cout << endl;

    cout << "===== MOST EFFICIENT VEHICLE ====="
         << endl;

    if (mostEfficient != nullptr)
    {
        cout << "Registration: " << mostEfficient->getRegNo() << endl;

        cout << "Type: " << mostEfficient->vehicleType() << endl;

        cout << "Cost: Rs. " << lowestCost << endl;
    }

    cout << endl;

    cout << "===== ELECTRIC TRUCKS =====" << endl;

    for (Vehicle* vehicle : fleet)
    {
        ElectricTruck* electricTruck = dynamic_cast<ElectricTruck*>(vehicle);


        if (electricTruck != nullptr)
        {
            cout << "Electric Truck Found: " << electricTruck->getRegNo() << endl;

            electricTruck->describe();

            cout << endl;
        }
    }
}

int main()
{
    vector<Vehicle*> fleet;

    fleet.push_back( new Car( "MH12AB1234", "Suraj", 2022, 15000, "Petrol", 20 ) );

    fleet.push_back( new Truck( "MH14TR5678", "Rahul", 2021, 30000, 2, 10 ) );

    fleet.push_back( new ElectricTruck( "V-ET002", "Green Logistics", 2024, 25000, 10, 8, 200, 400 ) );

    fleet.push_back( new Van( "MH16VN9999", "Amit", 2023, 18000, 8, 15 ) );

    fleet.push_back( new Car( "MH20CAR5555", "Raj", 2023, 10000, "Diesel", 18 ) );

    printFleetReport(fleet, 200);

    for (Vehicle* vehicle : fleet)
    {
        delete vehicle;
    }


    return 0;
}

