#include <iostream>
#include <string>
// ai integrate to detect obstacle iot deep learning required parallel processing servo motor for real time

using namespace std;

class NavigationModule {
public:
    void moveForward(int steps) {
        cout << "Moving forward " << steps << " steps." << endl;
    }

    void turn(string direction) {
        if (direction == "left" || direction == "right") {
            cout << "Turning " << direction << "." << endl;
        } else {
            cout << "Invalid direction! Use 'left' or 'right'." << endl;
        }
    }
};

class CleaningModule {
public:
    void startCleaning() {
        cout << "Starting cleaning operation." << endl;
    }

    void stopCleaning() {
        cout << "Stopping cleaning operation." << endl;
    }
};

class ObstacleDetectModule{
    public:


};
class CleaningBot {
private:
    NavigationModule navigation;
    CleaningModule cleaning;

public:
    void cleanRoom() {
        cout << "Initiating room cleaning sequence." << endl;
        navigation.moveForward(5);
        cleaning.startCleaning();
        navigation.turn("right");
        navigation.moveForward(5);
        cleaning.stopCleaning();
        cout << "Room cleaning complete." << endl;
    }

    void displayStatus() {
        cout << "CleaningBot is operational and ready to clean." << endl;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    CleaningBot bot;

    cout << "Welcome to CleaningBot Controller!" << endl;
    bot.displayStatus();

    string command;
    while (true) {
        cout << "Enter a command (clean, status, exit): ";
        cin >> command;

        if (command == "exit") {
            cout << "Shutting down CleaningBot. Goodbye!" << endl;
            break;
        } else if (command == "clean") {
            bot.cleanRoom();
        } else if (command == "status") {
            bot.displayStatus();
        } else {
            cout << "Unknown command!" << endl;
        }
    }

    return 0;
}
