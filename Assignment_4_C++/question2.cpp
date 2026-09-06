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
    Vehicle(const string& rn, const string& ow, int ym, double kd)
    {
        registrationNo = rn;
        ownerName = ow;
        yearOfManufacture = ym;
        kmDriven = kd;
    }

    virtual string vehicleType() const = 0;

    virtual double fuelCost(double kmToTravel) const = 0;

    virtual void describe() const;

    virtual ~Vehicle()
    {
        cout << "[Vehicle Destructor] "
             << registrationNo << endl;
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


void Vehicle::describe() const
{
    cout << "Registration : " << registrationNo << endl;
    cout << "Owner : " << ownerName << endl;
    cout << "Year : " << yearOfManufacture << endl;
    cout << "Km Driven : " << kmDriven << endl;
}

class Car : public Vehicle
{
    string fuelType;
    double mileageKmpl;

public:

    Car(const string& rn, const string& ow, int ym, double kd, const string& ft, double mkm) : Vehicle(rn, ow, ym, kd)
    {
        fuelType = ft;
        mileageKmpl = mkm;
    }

    string vehicleType() const override
    {
        return "CAR";
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

        return (kmToTravel / mileageKmpl) * fuelPrice;
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Fuel Type : " << fuelType << endl;
        cout << "Mileage : " << mileageKmpl << " Kmpl" << endl;
    }
};

class Truck : public Vehicle
{
protected:
    double payloadCapacityTons;
    double fuelEfficiencyKmpl;

public:

    Truck(const string& rn, const string& ow, int ym, double kd, double ton, double efficiency) : Vehicle(rn, ow, ym, kd)
    {
        payloadCapacityTons = ton;
        fuelEfficiencyKmpl = efficiency;
    }

    string vehicleType() const override
    {
        return "TRUCK";
    }

    double fuelCost(double kmToTravel) const override
    {
        double effectiveEffi =  fuelEfficiencyKmpl * (1 - 0.05 * payloadCapacityTons);

        double litersNeed =  kmToTravel / effectiveEffi;

        return litersNeed * 93.00;
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Payload Capacity: "
             << payloadCapacityTons << " tons" << endl;

        cout << "Fuel Efficiency: "
             << fuelEfficiencyKmpl << " kmpl" << endl;
    }
};

class ElectricTruck : public Truck
{
    double batteryCapacityKWh;
    double rangePerChargeKm;

public:

    ElectricTruck(const string& rn, const string& ow, int ym, double kd, double ton, double efficiency,  double bcapacity, double rangekm) : Truck(rn, ow, ym, kd, ton, efficiency)
    {
        batteryCapacityKWh = bcapacity;
        rangePerChargeKm = rangekm;
    }

    string vehicleType() const override
    {
        return "ELECTRIC TRUCK";
    }

    double fuelCost(double kmToTravel) const override
    {
        double energyUse = (kmToTravel / rangePerChargeKm) * batteryCapacityKWh;

        return energyUse * 9.50;
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Battery Capacity: "
             << batteryCapacityKWh << " kWh" << endl;

        cout << "Range per Charge: "
             << rangePerChargeKm << " km" << endl;
    }
};


class Van : public Vehicle
{
    int seatingCapacity;
    double mileageKmpl;

public:

    Van(const string& rn, const string& ow, int ym, double kd, int seating, double mileage) : Vehicle(rn, ow, ym, kd)
    {
        seatingCapacity = seating;
        mileageKmpl = mileage;
    }

    string vehicleType() const override
    {
        return "VAN";
    }

    double fuelCost(double kmToTravel) const override
    {
        double litersNeed =  kmToTravel / mileageKmpl;

        return litersNeed * 106.00;
    }

    void describe() const override
    {
        Vehicle::describe();

        cout << "Seating Capacity: "
             << seatingCapacity << endl;

        cout << "Mileage: "
             << mileageKmpl << " kmpl" << endl;
    }
};


int main()
{
    Car car( "MH12AB1234", "Suraj", 2022, 15000, "Petrol", 20 );

    Truck truck( "MH14TR5678", "Rahul", 2021, 30000, 2, 10 );

    ElectricTruck electricTruck( "V-ET001", "Green Logistics", 2024, 25000, 10, 8, 200, 400 );

    Van van( "MH16VN9999", "Amit", 2023, 18000, 8, 15 );


    cout << "\n===== CAR =====\n";
    car.describe();
    cout << "Cost for 200 km: " << car.fuelCost(200) << endl;


    cout << "\n===== TRUCK =====\n";
    truck.describe();
    cout << "Cost for 200 km: " << truck.fuelCost(200) << endl;


    cout << "\n===== ELECTRIC TRUCK =====\n";
    electricTruck.describe();
    cout << "Cost for 200 km: " << electricTruck.fuelCost(200) << endl;


    cout << "\n===== VAN =====\n";
    van.describe();
    cout << "Cost for 200 km: " << van.fuelCost(200) << endl;


    return 0;
}