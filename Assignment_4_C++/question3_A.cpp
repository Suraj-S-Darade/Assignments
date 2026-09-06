#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

class DataProcessor
{
public:
    // Pure virtual functions
    virtual void loadData(const string& source) = 0;
    virtual void processData() = 0;
    virtual void exportResult(const string& destination) = 0;
    virtual string processorType() const = 0;
    virtual int recordCount() const = 0;

    // Non-pure virtual function
    virtual void printSummary() const
    {
        cout << "Processor Type: " << processorType() << endl;
        cout << "Record Count: " << recordCount() << endl;
    }

    virtual ~DataProcessor() = default;
};


class CSVProcessor : public DataProcessor
{
private:
    vector<string> records;

public:

    void loadData(const string& source) override
    {
        cout << "Loading CSV data from: " << source << endl;

        records.push_back("suraj,25,pune");
        records.push_back("rahul,30,mumbai");
        records.push_back("amit,28,nashik");
        records.push_back("rohit,22,nagpur");
        records.push_back("sachin,35,ahilyanagar");
    }

    void processData() override
    {
        for (string& record : records)
        {
            for (char& ch : record)
            {
                ch = toupper(static_cast<unsigned char>(ch));
            }
        }
    }

    void exportResult(const string& destination) override
    {
        cout << "[CSV EXPORT -> " << destination << "]" << endl;

        for (const string& record : records)
        {
            cout << record << endl;
        }
    }

    string processorType() const override
    {
        return "CSV Processor";
    }

    int recordCount() const override
    {
        return static_cast<int>(records.size());
    }
};


class SensorStreamProcessor : public DataProcessor
{
private:
    vector<double> readings;

    double mean = 0.0;
    double minimum = 0.0;
    double maximum = 0.0;

public:

    void loadData(const string& source) override
    {
        cout << "Loading sensor data from: " << source << endl;

        readings.push_back(23.4);
        readings.push_back(21.8);
        readings.push_back(25.1);
        readings.push_back(24.6);
        readings.push_back(22.9);
        readings.push_back(26.3);
        readings.push_back(23.7);
        readings.push_back(24.2);
    }

    void processData() override
    {
        if (readings.empty())
        {
            mean = 0.0;
            minimum = 0.0;
            maximum = 0.0;
            return;
        }

        double sum = 0.0;

        minimum = readings[0];
        maximum = readings[0];

        for (double value : readings)
        {
            sum += value;

            if (value < minimum)
            {
                minimum = value;
            }

            if (value > maximum)
            {
                maximum = value;
            }
        }

        mean = sum / readings.size();
    }

    void exportResult(const string& destination) override
    {
        cout << "[SENSOR EXPORT -> " << destination << "]" << endl;

        cout << "Mean: " << mean << endl;
        cout << "Min: " << minimum << endl;
        cout << "Max: " << maximum << endl;
    }

    string processorType() const override
    {
        return "Sensor Stream Processor";
    }

    int recordCount() const override
    {
        return static_cast<int>(readings.size());
    }

    void printSummary() const override
    {
        cout << "Processor Type: " << processorType() << endl;
        cout << "Record Count: " << recordCount() << endl;
        cout << "Mean: " << mean << endl;
        cout << "Min: " << minimum << endl;
        cout << "Max: " << maximum << endl;
    }
};


int main()
{

    vector<DataProcessor*> pipeline;

    pipeline.push_back(new CSVProcessor());
    pipeline.push_back(new SensorStreamProcessor());

    for (auto* p : pipeline)
    {
        p->loadData("source_data");

        p->processData();

        p->printSummary();

        p->exportResult("output_dir");

        cout << "---" << endl;
    }

    for (auto* p : pipeline)
    {
        delete p;
    }

    return 0;
}