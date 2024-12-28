//Ameer Hamza 0028
//Syed Salman  0037



#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    queue<int> custQ; // Line (queue) of customers
    int simLength;    // Length of simulation (minutes)
    int minute;       // Current minute
    int timeArrived;  // Time dequeued customer arrived
    int waitTime;     // How long dequeued customer waited
    int totalServed = 0; // Total customers served
    int totalWait = 0;   // Total waiting time
    int maxWait = 0;     // Longest wait
    int numArrivals = 0; // Number of new arrivals

    // Seed the random number generator
    srand(time(NULL));

    cout << "Enter the length of time to run the simulator: ";
    cin >> simLength;

    for (minute = 0; minute < simLength; minute++) {
        // Dequeue the first customer in line (if any)
        if (!custQ.empty()) {
            timeArrived = custQ.front();
            custQ.pop();

            waitTime = minute - timeArrived;
            totalWait += waitTime;
            totalServed++;

            if (waitTime > maxWait) {
                maxWait = waitTime;
            }
        }

        //// Determine the number of new customers
        //numArrivals = rand() % 4; // Randomly generate 0-3 customers
        //for (int i = 0; i < numArrivals; i++) {
        //    custQ.push(minute);
        //}
        // Determine the number of new customers
        numArrivals = rand() % 4; // Randomly generate 0-3 customers
        if (numArrivals == 1 || numArrivals == 2) {
            for (int i = 0; i < numArrivals; i++) {
                custQ.push(minute); // Push the current minute for each entry
            }
        }
    }

    double averageWait = totalServed > 0 ? static_cast<double>(totalWait) / totalServed : 0.0;

    cout << "\nCustomers served : " << totalServed << endl;
    cout << "Average wait     : " << fixed << setprecision(2) << averageWait << endl;
    cout << "Longest wait     : " << maxWait << endl;

    // Write results to a text file
    ofstream outFile("simulation_results.txt", ios::app);
    if (outFile.is_open()) {
        if (outFile.tellp() == 0) {
            outFile << "n\tserved\tav_wait\tlongest_wait\n"; // Header line
        }
        outFile << simLength << "\t" << totalServed << "\t" << fixed << setprecision(2) << averageWait << "\t" << maxWait << "\n";
        outFile.close();
        cout << "Results written to simulation_results.txt\n";
    }
    else {
        cerr << "Error: Could not open the file for writing.\n";
    }

    return 0;
}