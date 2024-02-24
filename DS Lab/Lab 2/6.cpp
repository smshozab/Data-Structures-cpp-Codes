#include <iostream>
#include <string>
using namespace std;

class DatabaseConnection {
private:
    int* Connection;
    void closeConnection() {
        if (Connection != nullptr) {
            cout << "Closing connection" << endl;
            delete Connection;
            Connection = nullptr;
        }
    }

public:
    DatabaseConnection() : Connection(new int(0)) {
        cout << "Connection established.\n";
        }

    DatabaseConnection(const DatabaseConnection& other) : Connection(new int(*other.Connection)) {
        cout << "Connection copied.\n";
    }

    DatabaseConnection& operator=(const DatabaseConnection& other) {
        cout << "Connection assigned.\n";
        if (this != &other) {
            closeConnection();
            Connection = new int(*other.Connection);
        }
        return *this;
    }
    ~DatabaseConnection() {
        closeConnection();
        cout << "Connection destroyed.\n";
    }
};

int main() {
    DatabaseConnection c1;
    DatabaseConnection c2 = c1;
    DatabaseConnection c3;
    c3 = c2;
    return 0;
}
