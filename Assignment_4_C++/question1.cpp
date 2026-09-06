#include <iostream>
#include <string>
#include <utility>
using namespace std;

class LedgerEntry
{
private:
    string description;
    double* amounts;
    int days;
    static int totalEntries;

public:

    // 1. Constructor
    LedgerEntry(const string& desc, int days)
        : description(desc), days(days)
    {
        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = 0;
        }

        totalEntries++;
    }

    // 2. Copy Constructor - Deep Copy
    LedgerEntry(const LedgerEntry& other)
        : description(other.description), days(other.days)
    {
        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        totalEntries++;
    }

    // 3. Move Constructor
    LedgerEntry(LedgerEntry&& other) noexcept : description(move(other.description)), amounts(other.amounts), days(other.days)
    {
        other.amounts = nullptr;
        other.days = 0;

        totalEntries++;
    }

    // 4. Copy Assignment Operator
    LedgerEntry& operator=(const LedgerEntry& other)
    {
        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        delete[] amounts;

        description = other.description;
        days = other.days;

        amounts = new double[days];

        for (int i = 0; i < days; i++)
        {
            amounts[i] = other.amounts[i];
        }

        return *this;
    }

    // 5. Move Assignment Operator
    LedgerEntry& operator=(LedgerEntry&& other) noexcept
    {
        // Self-assignment check
        if (this == &other)
        {
            return *this;
        }

        delete[] amounts;

        description = move(other.description);
        days = other.days;
        amounts = other.amounts;

        other.amounts = nullptr;
        other.days = 0;

        return *this;
    }

    // Check whether object is empty after move
    bool isEmpty() const
    {
        return amounts == nullptr;
    }

    // 6. Destructor
    ~LedgerEntry()
    {
        delete[] amounts;
        totalEntries--;
    }

    LedgerEntry operator+(const LedgerEntry& other) const
    {
        LedgerEntry result( description + " + " + other.description, days);

        for (int i = 0; i < days; i++)
        {
            result.amounts[i] = amounts[i] + other.amounts[i];
        }

        return result;
    }

    // 8. Equality operator
    // Compare total sum
    bool operator==(const LedgerEntry& other) const
    {
        double total1 = 0;
        double total2 = 0;

        for (int i = 0; i < days; i++)
        {
            total1 += amounts[i];
        }

        for (int i = 0; i < other.days; i++)
        {
            total2 += other.amounts[i];
        }

        return total1 == total2;
    }

    // 9. Greater-than operator
    // Compare total sum
    bool operator>(const LedgerEntry& other) const
    {
        double total1 = 0;
        double total2 = 0;

        for (int i = 0; i < days; i++)
        {
            total1 += amounts[i];
        }

        for (int i = 0; i < other.days; i++)
        {
            total2 += other.amounts[i];
        }

        return total1 > total2;
    }

    // 10. Subscript operator - non-const
    double& operator[](int index)
    {
        return amounts[index];
    }

    // 11. Subscript operator - const
    const double& operator[](int index) const
    {
        return amounts[index];
    }

    // 12. Stream insertion operator
    friend ostream& operator<<( ostream& out, const LedgerEntry& entry);

    // 13. Stream extraction operator
    friend istream& operator>>( istream& in, LedgerEntry& entry );

    // Getter for static member
    static int getTotalEntries()
    {
        return totalEntries;
    }
};


// << operator
ostream& operator<<(ostream& out, const LedgerEntry& entry)
{
    out << "Description: " << entry.description << endl;

    out << "Amounts: ";

    for (int i = 0; i < entry.days; i++)
    {
        out << entry.amounts[i] << " ";
    }

    out << endl;

    return out;
}


// >> operator
istream& operator>>(istream& in, LedgerEntry& entry)
{
    for (int i = 0; i < entry.days; i++)
    {
        in >> entry.amounts[i];
    }

    return in;
}


// Static member definition
int LedgerEntry::totalEntries = 0;


int main()
{
    // Objective 1 - Constructor
    LedgerEntry jan("January Sales", 5);

    jan[0] = 1200.50;
    jan[1] = 3400.00;
    jan[2] = 800.75;
    jan[3] = 2100.00;
    jan[4] = 650.25;

    LedgerEntry feb("February Sales", 5);

    feb[0] = 900.00;
    feb[1] = 2200.50;
    feb[2] = 1750.00;
    feb[3] = 3000.00;
    feb[4] = 475.50;

    cout << "||----------------- RESULT -----------------||" << endl;
    cout << endl;
    
    cout << jan << endl;
    cout << feb << endl;

    // Objective 2 - Operator +
    LedgerEntry combined = jan + feb;

    cout << "Combined: " << combined << endl;

    // Objective 3 - Relational operators
    cout << "Jan == Feb : " << (jan == feb ? "Yes" : "No") << endl;

    cout << "Jan > Feb : " << (jan > feb ? "Yes" : "No") << endl;

    cout << endl;

    // Objective 4 - Move Constructor
    LedgerEntry moved = move(jan);

    cout << "After move, jan.amounts is null: "
         << (jan.isEmpty() ? "YES" : "NO") << endl;

    cout << endl;

    cout << "Moved entry: " << moved << endl;

    // Objective 5 - Move Assignment
    LedgerEntry q1("Q1 Total", 5);

    q1 = move(feb);

    cout << "Q1 (moved from feb): " << q1 << endl;

    // Objective 6 - Static member
    cout << "Live LedgerEntry objects: " << LedgerEntry::getTotalEntries() << endl;


    return 0;
}