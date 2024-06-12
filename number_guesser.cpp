#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <chrono>
#include <thread>

using namespace std;

void delay() {
    this_thread::sleep_for(chrono::seconds(2));
}

void promptAndWait(const string& message) {
    cout << message << endl;
    cout << ">> Press 0 to continue." << endl;
    int input;
    cin >> input;
    if (input != 0) {
        cout << "INVALID INPUT" << endl;
        exit(1);
    }
}

int main() {
    int n, ch;
    float ans;

    cout << "===================WELCOME==================" << endl;
    cout << "Game Choice:\n\t\t\t\t\tNumber Guesser" << endl;

    do {
        cout << "Enter 0 to play" << endl;
        cout << "Enter 1 to exit" << endl;
        cin >> ch;

        if (ch == 0) {
            promptAndWait("\n\n1 - Think of a number from 0 to 99 and consider it to be your cash in hand.");
            promptAndWait("\n\n2 - Now borrow the same amount from a friend (Say you took the number 20, now add another 20 to your total making your total cash in hand to be 40).");

            srand(time(0));
            n = (rand() % 100) + 1;
            ans = static_cast<float>(n) / 2;
            promptAndWait("\n\n3 - You got a bonus of " + to_string(n) + " from your boss! (Add it to your current total)");
            promptAndWait("\n\n4 - You have now found a man in desperate need of half your money (Divide your total by 2).");
            promptAndWait("\n\n5 - It is time to return the money you borrowed from your friend. (Subtract your original number from your current total)");

            cout << "\n\nIs the amount left in hand....";
            delay();
            cout << ans << "?" << endl;
        }
    } while (ch != 1);

    return 0;
}
