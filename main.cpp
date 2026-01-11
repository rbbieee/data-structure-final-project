#include <iostream>
#include "MLL.h"
using namespace std;

int main()
{
    listPassenger passengerList;
    listPlane planeList;

    createListPassenger(passengerList);
    createListPlane(planeList);

    int choice = -1;

    cout << "========== Flight Ticket Management System ==========" << endl;

    while (choice != 0){
        cout << "\nMenu" << endl;
        cout << "1. add plane data" << endl;
        cout << "2. add passenger data" << endl;
        cout << "3. show all planes" << endl;
        cout << "4. show all passengers" << endl;
        cout << "5. register passenger to plane" << endl;
        cout << "6. update plane data" << endl;
        cout << "7. update passenger data" << endl;
        cout << "8. find plane with most passengers" << endl;
        cout << "9. find passenger location" << endl;
        cout << "10. show all relations" << endl;
        cout << "11. remove passenger from plane" << endl;
        cout << "12. move passenger to another plane" << endl;
        cout << "0. exit" << endl;
        cout << "Enter menu choice: ";
        cin >> choice;

        if (choice == 1){
            int n;
            infotype planeName;
            cout << "enter number of planes: ";
            cin >> n;
            for (int i = 0; i < n; i++){
                cout << "enter plane name: ";
                cin >> planeName;
                insertFirstPlane(planeList, createElmPlane(planeName));
            }
            cout << "plane input completed" << endl;

        } else if (choice == 2){
            int n;
            infotype passengerName;
            cout << "enter number of passengers: ";
            cin >> n;
            for (int i = 0; i < n; i++){
                cout << "enter passenger name: ";
                cin >> passengerName;
                insertFirstPassenger(passengerList, createElmPassenger(passengerName));
            }
            cout << "passenger input completed" << endl;

        } else if (choice == 3){
            showAllPlane(planeList);
            cout << endl;

        } else if (choice == 4){
            showAllPassenger(passengerList);
            cout << endl;

        } else if (choice == 5){
            infotype passengerName;
            infotype planeName;

            cout << "enter passenger name: ";
            cin >> passengerName;
            cout << endl;

            cout << "register to plane: ";
            cin >> planeName;

            insertRelation_plane_to_passenger(planeList, passengerList, planeName, passengerName);
            cout << endl;

        } else if (choice == 6){
            infotype oldPlaneName;
            infotype newPlaneName;

            cout << "enter plane name to update: ";
            cin >> oldPlaneName;
            cout << endl;

            cout << "enter new plane name: ";
            cin >> newPlaneName;

            updateDataPlane(planeList, oldPlaneName, newPlaneName);
            cout << endl;

        } else if (choice == 7){
            infotype oldPassengerName;
            infotype newPassengerName;

            cout << "enter passenger name to update: ";
            cin >> oldPassengerName;
            cout << endl;

            cout << "enter new passenger name: ";
            cin >> newPassengerName;

            updateDataPassenger(passengerList, oldPassengerName, newPassengerName);
            cout << endl;

        } else if (choice == 8){
            findPassengerMost(planeList);
            cout << endl;

        } else if (choice == 9){
            infotype searchedPassenger;
            cout << "enter passenger name to search: ";
            cin >> searchedPassenger;

            findPassengerWhere(planeList, passengerList, searchedPassenger);
            cout << endl;

        } else if (choice == 10){
            showAllRelation(planeList);
            cout << endl;

        } else if (choice == 11){
            infotype planeName;
            infotype passengerName;
            adrRelation r;

            cout << "enter passenger name to remove: ";
            cin >> passengerName;
            cout << endl;

            cout << "from plane: ";
            cin >> planeName;

            adrPlane p = findPlane(planeList, planeName);
            deleteRelation(p, passengerName, r);

            cout << "passenger removed successfully" << endl;

        } else if (choice == 12){
            infotype passengerName;
            infotype fromPlane;
            infotype toPlane;
            adrRelation r;

            cout << "current plane: ";
            cin >> fromPlane;

            adrPlane p = findPlane(planeList, fromPlane);

            cout << "enter passenger name to move: ";
            cin >> passengerName;

            deleteRelation(p, passengerName, r);

            cout << "move to plane: ";
            cin >> toPlane;

            insertRelation_plane_to_passenger(planeList, passengerList, toPlane, passengerName);
            cout << endl;

        } else if (choice == 0){
            cout << "system terminated" << endl;
        } else {
            cout << "invalid choice" << endl;
        }
    }
    return 0;
}
