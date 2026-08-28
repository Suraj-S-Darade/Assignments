#include <iostream>
using namespace std;

void readings(float arr[], int num)
{
    float min = 0;
    float max = 0;
    float sum = 0;

    int validCount = 0;
    int skippedCount = 0;

    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    int firstCriticalIndex = -1;
    float firstCriticalValue = 0;

    cout << fixed << setprecision(1);

    cout << "\nReadings entered : " << num << endl;

    cout << "Valid readings   : ";

    for (int i = 0; i < num; i++)
    {
        // Skip invalid readings
        if (arr[i] < 0)
        {
            skippedCount++;
            continue;
        }

        // Print valid reading
        cout << arr[i] << " ";

        // First valid reading becomes min and max
        if (validCount == 0)
        {
            min = arr[i];
            max = arr[i];
        }

        // Find minimum
        if (arr[i] < min)
        {
            min = arr[i];
        }

        // Find maximum
        if (arr[i] > max)
        {
            max = arr[i];
        }

        // Calculate sum
        sum += arr[i];
        validCount++;

        // Count categories
        if (arr[i] < 30)
        {
            normal++;
        }
        else if (arr[i] < 45)
        {
            warning++;
        }
        else if (arr[i] < 60)
        {
            critical++;
        }
        else
        {
            shutdown++;
        }
    }

    cout << endl;

    cout << "Skipped (errors) : " << skippedCount << endl;

    // Find first reading >= 45
    for (int i = 0; i < num; i++)
    {
        if (arr[i] < 0)
        {
            continue;
        }

        if (arr[i] >= 45)
        {
            firstCriticalIndex = i + 1;   // Index starts from 1
            firstCriticalValue = arr[i];

            break;
        }
    }

    if (firstCriticalIndex != -1)
    {
        cout << "\nFirst CRITICAL   : Index "
             << firstCriticalIndex
             << " -> "
             << firstCriticalValue
             << "°C" << endl;
    }
    else
    {
        cout << "\nFirst CRITICAL   : None" << endl;
    }

    // Average
    float average = 0;

    if (validCount > 0)
    {
        average = sum / validCount;
    }

    cout << "\nMin : " << min << "°C    Max : " << max << "°C    Avg : " << average << "°C" << endl;

    cout << "\nNormal:" << normal << "    Warning:" << warning << "    Critical:" << critical << "    Shutdown:" << shutdown   << endl;
}


int main()
{
    int num;
    float arr[100];

    cout << "Enter number of readings: ";
    cin >> num;

    cout << "Enter readings: ";

    for (int i = 0; i < num; i++)
    {
        cin >> arr[i];
    }

    readings(arr, num);

    return 0;
}
