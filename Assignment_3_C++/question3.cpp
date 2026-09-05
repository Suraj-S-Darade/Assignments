#include <iostream>
#include <cstring>
using namespace std;

class LogBuffer
{

    char *buffer;
    int capacity;
    int size;
    static int instanceCount;

public:
    LogBuffer(int capacity) : capacity(capacity), size(0)
    {
        buffer = new char[capacity];

        instanceCount++;
    }

    LogBuffer(const LogBuffer &other) : capacity(other.capacity), size(other.size)
    {
        buffer = new char[capacity];

        for (int i = 0; i <= size; i++)
        {
            buffer[i] = other.buffer[i];
        }

        instanceCount++;
    }

    LogBuffer &operator=(const LogBuffer &other)
    {
        if (this != &other)
        {
            delete[] buffer;

            capacity = other.capacity;
            size = other.size;

            buffer = new char[other.capacity];

            for (int i = 0; i <= size; i++)
            {
                buffer[i] = other.buffer[i];
            }
        }

        return *this;
    }

    void append(const char *msg)
    {
        int msgLength = strlen(msg);

        int available = capacity - size - 1;

        int copyLength;

        if (msgLength < available)
            copyLength = msgLength;
        else
            copyLength = available;

        for (int i = 0; i < copyLength; i++)
        {
            buffer[size + i] = msg[i];
        }

        size += copyLength;

        buffer[size] = '\0';
    }

    void print() const 
    {
        cout << buffer << endl;
    }
    
    static int getInstanceCount()
    {
        return instanceCount;
    }

    ~LogBuffer()
    {
        delete[] buffer;

        instanceCount--;
    }
};

int LogBuffer::instanceCount = 0;

int main()
{
    LogBuffer log1(256);

    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");

    log1.print();

    // Copy Constructor
    LogBuffer log2 = log1;

    log2.append(" | Cached response sent");

    cout << "log1 : "; 
    log1.print();

    cout << "log2 : ";
    log2.print();

    // Copy Assignment
    LogBuffer log3(128);

    log3 = log1;

    cout << "log3 : ";
    log3.print();

    cout << "log1 : ";
    log1.print();

    // Self Assignment
    log1 = log1;

    cout << "Live LogBuffer objects : "
         << LogBuffer::getInstanceCount()
         << endl;

    return 0;
}