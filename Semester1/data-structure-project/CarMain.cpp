//==================================================================================================================CarMain.cpp  

  

//CarMain.cpp  

  

#include <iostream> 

#include <queue> 

#include "Car.h"   

using namespace std; 

const int MAX = 20; 

Car carList[MAX]; 

  

int carCount = 0; 

int customerCount = 0; 

  

void functionSummary(Car carList[], int carCount, Customer customerList[], int customerCount); 

  

  

//--------> car section <---------  

  

void carSystem(); 

int rentedCarIndex[MAX]; 

  

  

  

//-------> customer section < ------  

void deleteCustomer(Customer customerList[], int& customerCount, int index); 

void customerSystem(); 

  

Customer customerList[MAX]; 

CustomerQueueManager queueManager; 

  

  

int main() { 

    int option; 

    for (int i = 0; i < MAX; ++i) { 

        rentedCarIndex[i] = -1; 

    } 

    do { 

        cout << "\n\n\n\t\t\t\t=============================================================\n"; 

  

        cout << "\t\t\t\t                  CAR RENTAL SYSTEM MENU                     \n"; 

  

        cout << "\t\t\t\t=============================================================\n"; 

  

        cout << "\t\t\t\t 1. Car System\n"; 

        cout << "\t\t\t\t 2. Customer System\n"; 

        cout << "\t\t\t\t 3. View System Summary Report\n"; 

        cout << "\t\t\t\t 0. Exit\n"; 

        cout << "\t\t\t\t Enter choice: "; 

        while (!(cin >> option)) { 

            cout << "\t\t\t\t Invalid input. Please enter a number : "; 

            cin.clear(); 

            cin.ignore(1000, '\n'); 

        } 

  

        switch (option) { 

        case 1: 

            system("CLS"); 

            carSystem(); 

            break; 

  

        case 2: 

            system("CLS"); 

            customerSystem(); 

            break; 

  

        case 3: 

            system("CLS"); 

            functionSummary(carList, carCount, customerList, customerCount); 

            cout << "\nPress Enter to return to the Main Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

        case 0: 

  

            cout << "Exiting...\n"; 

            break; 

        default: 

            cout << "Invalid choice.\n"; 

  

        } 

  

  

  

    } while (option != 0); 

    return 0; 

} 

  

void carSystem() { 

    int choice; 

    do { 

  

        cout << "\n\n\t\t\t=============================================================\n"; 

  

        cout << "\t\t\t                    CAR SYSTEM MENU                         \n"; 

  

        cout << "\t\t\t=============================================================\n"; 

  

        cout << "\t\t\t 1. Insert Car Data\n"; 

        cout << "\t\t\t 2. Display Car Data\n"; 

        cout << "\t\t\t 3. Delete Car Data\n"; 

        cout << "\t\t\t 4. Search Car Data\n"; 

        cout << "\t\t\t 5. Update Car Data\n"; 

        cout << "\t\t\t 6. Sort Car Data\n"; 

        cout << "\t\t\t 0. Back to Main Menu\n"; 

        cout << "\t\t\t Enter choice: "; 

        while (!(cin >> choice)) { 

            cout << "\t\t\t\t Invalid Input. Please enter a number : "; 

            cin.clear(); 

            cin.ignore(100, '\n'); 

        } 

  

        switch (choice) { 

            //----------------------------------------> Insert Car Data <---------------------------------------- 

        case 1: 

            system("CLS"); 

            cout << "\n\n\t\t\t=========== Insert Car Data ===========\n\n"; 

            if (carCount < MAX) { 

                carList[carCount].inputCar(); 

                carCount++; 

                cout << "\nSuccessfully inserted...\n"; 

            } 

            else { 

                cout << "Car list is full.\n"; 

            } 

            cout << "\n\nPress Enter to return to the Car Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

            //----------------------------------------> Display Car Data <---------------------------------------- 

        case 2: 

            system("CLS"); 

            cout << "\n\n\t\t\t=========== Display Car Data ===========\n\n"; 

  

            if (carCount == 0) { 

                cout << "No car data available.\n"; 

            } 

            else { 

                carList[0].displayHeader(); // print table header once 

  

                for (int i = 0; i < carCount; i++) { 

                    carList[i].displayCarRow(); // use your simplified row display 

                } 

  

                cout << "=======================================================================================================================\n"; 

            } 

  

            cout << "\nPress Enter to return to the Car Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

            //----------------------------------------> Delete Car Data <---------------------------------------- 

        case 3: 

            system("CLS"); 

            cout << "====================== Delete Car Data ======================\n\n"; 

  

            if (carCount == 0) { 

                cout << "No car data to delete.\n"; 

            } 

            else { 

                // Table-style display 

                cout << "Available Cars:\n\n\n"; 

                cout << "No "; 

                carList[0].displayHeader(); 

                for (int i = 0; i < carCount; i++) { 

                    cout << "| " << left << setw(2) << i + 1; 

                    carList[i].displayCarRow(); 

                } 

                cout << "=======================================================================================================================\n"; 

  

                int deleteIndex; 

                cout << "\nEnter the car number to delete (1 to " << carCount << "): "; 

                while (!(cin >> deleteIndex)) { 

                    cout << "\t\t\t\t Invalid Input. Please enter a number : "; 

                    cin.clear(); 

                    cin.ignore(100, '\n'); 

                } 

  

                if (deleteIndex >= 1 && deleteIndex <= carCount) { 

                    Car::deleteCar(carList, carCount, deleteIndex - 1); 

                } 

                else { 

                    cout << "Invalid car number, back to menu....\n"; 

                } 

            } 

  

            cout << "\n\nPress Enter to return to the Car Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

            //----------------------------------------> Search Car Data <---------------------------------------- 

  

        case 4: 

            system("CLS"); 

            if (carCount == 0) { 

                cout << "No cars available to search.\n"; 

                break; 

            } 

            Car::searchCar(carList, carCount); 

  

            cout << "\nPress Enter to return to the Car Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

  

            //----------------------------------------> Update Car Data <---------------------------------------- 

        case 5: { 

            system("CLS"); 

  

            if (carCount == 0) { 

                cout << "No cars available to update.\n"; 

                break; 

            } 

  

            cout << "=========== Update Car Data ===========\n\n"; 

            cout << "No "; 

            Car::displayHeader(); 

            for (int i = 0; i < carCount; i++) { 

                cout << "| " << left << setw(2) << i + 1; 

                carList[i].displayCarRow(); 

            } 

  

            int updateIndex; 

            cout << "\nEnter the car number to update (1 to " << carCount << "): "; 

            while (!(cin >> updateIndex) || updateIndex < 1 || updateIndex > carCount) { 

                cout << "Invalid input. Try again: "; 

                cin.clear(); 

                cin.ignore(100, '\n'); 

            } 

            cin.ignore(); 

            int index = updateIndex - 1; 

            carList[index].updateCarData();  //  call class  method 

            cout << "\nPress Enter to return to the Car Menu..."; 

            cin.get(); 

            system("CLS"); 

            break; 

        } 

  

              //--------------------------------------------------------------> Sort Car Data <--------------------------------------------------------- 

        case 6: 

            system("CLS"); 

            cout << "=========== Sort Car Data ===========\n"; 

            cout << "1. Ascending (Price Low to High)\n"; 

            cout << "2. Descending (Price High to Low)\n"; 

            cout << "Choose option: "; 

            int sortOption; 

            cin >> sortOption; 

  

            if (sortOption == 1 || sortOption == 2) { 

                bool ascending = (sortOption == 1); 

                Car::sortByPrice(carList, carCount, true); 

  

                // Display sorted results 

                carList[0].displayHeader(); 

                for (int i = 0; i < carCount; i++) { 

                    carList[i].displayCarRow(); 

                } 

                cout << "=======================================================================================================================\n"; 

            } 

            else { 

                cout << "Invalid option.\n"; 

            } 

  

            cout << "\nPress Enter to return to the Car Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

  

        case 0: 

            system("CLS"); 

            break; 

        default: 

            cout << "Invalid choice.\n"; 

        } 

    } while (choice != 0); 

} 

  

void customerSystem() { 

    int choice; 

    do { 

        cout << "\n\n\t\t\t=============================================================\n"; 

        cout << "\t\t\t                    CUSTOMER SYSTEM MENU                         \n"; 

        cout << "\t\t\t=============================================================\n"; 

        cout << "\t\t\t 1. Insert customer Data\n"; 

        cout << "\t\t\t 2. Display customer Data\n"; 

        cout << "\t\t\t 3. Delete customer  Data\n"; 

        cout << "\t\t\t 4. Search customer Data\n"; 

        cout << "\t\t\t 5. Update customer Data\n"; 

        cout << "\t\t\t 6. Sort customer Data\n"; 

        cout << "\t\t\t 7. Return Car\n"; 

        cout << "\t\t\t 8. View Waiting List\n"; 

        cout << "\t\t\t 9. Waiting List Customer\n"; 

        cout << "\t\t\t 0. Back to Main Menu\n"; 

        cout << "\t\t\t Enter choice: "; 

        while (!(cin >> choice)) { 

            cout << "\t\t\t\t Invalid Input. Please enter a number : "; 

            cin.clear(); 

            cin.ignore(100, '\n'); 

        } 

        switch (choice) { 

        case 1: 

            system("CLS"); 

            if (customerCount < MAX) { 

                if (carCount == 0) { 

                    cout << "No cars available to rent. Please add a car first.\n"; 

                    queueManager.addToQueue(); 

                } 

                else { 

                    bool anyAvailable = false; 

                    for (int i = 0; i < carCount; i++) { 

                        if (carList[i].isAvailable()) { 

                            anyAvailable = true; 

                            break; 

                        } 

                    } 

  

                    if (!anyAvailable) { 

                        cout << "All cars are currently rented. Customer will be added to the waiting queue.\n"; 

                        queueManager.addToQueue(); 

                    } 

                    else { 

                        cout << "\nAvailable Cars:\n"; 

                        carList[0].displayHeader(); 

                        for (int i = 0; i < carCount; i++) { 

                            if (carList[i].isAvailable()) { 

                                cout << "| " << left << setw(3) << i + 1; 

                                carList[i].displayCarRow(); 

                            } 

                        } 

                        cout << "=======================================================================================================================\n"; 

  

                        int selectedCar; 

                        cout << "Select a car number to rent: "; 

                        while (!(cin >> selectedCar)) { 

                            cout << "\t\t\t\t Invalid Input. Please enter a number : "; 

                            cin.clear(); 

                            cin.ignore(100, '\n'); 

                        } 

  

                        if (selectedCar < 1 || selectedCar > carCount || !carList[selectedCar - 1].isAvailable()) { 

                            cout << "Invalid or unavailable car selection.\n"; 

                        } 

                        else { 

                            float selectedPrice = carList[selectedCar - 1].getPricePerDay(); 

                            customerList[customerCount].inputCustomer(selectedPrice); 

                            rentedCarIndex[customerCount] = selectedCar - 1; 

  

                            carList[selectedCar - 1].setAvailable(false); 

                            customerCount++; 

                        } 

                    } 

                } 

            } 

            else { 

                cout << "Customer list is full.\n"; 

            } 

  

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

        case 2: 

            system("CLS"); 

            if (customerCount == 0) { 

                cout << "No customer data available.\n"; 

            } 

            else { 

                customerList[0].displayHeader(); 

                for (int i = 0; i < customerCount; i++) { 

                    cout << left << setw(3) << i + 1 << "| "; 

                    customerList[i].displayCustomer(); 

                } 

                cout << "=======================================================================================================================\n" << endl; 

            } 

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

        case 3: 

            system("CLS"); 

            cout << "====================== Delete Customer Data ======================\n\n"; 

            if (customerCount == 0) { 

                cout << "No customer data to delete.\n"; 

            } 

            else { 

                cout << "Customer List:\n"; 

                cout << "No "; 

                customerList[0].displayHeader(); 

  

                for (int i = 0; i < customerCount; i++) { 

                    cout << "| " << left << setw(3) << i + 1; 

                    customerList[i].displayCustomer(); 

                } 

                cout << "=======================================================================================================================\n"; 

  

                int deleteIndex; 

                cout << "\nEnter the customer number to delete (1 to " << customerCount << "): "; 

                while (!(cin >> deleteIndex)) { 

                    cout << "\t\t\t\t Invalid Input. Please enter a number : "; 

                    cin.clear(); 

                    cin.ignore(100, '\n'); 

                } 

  

                if (deleteIndex >= 1 && deleteIndex <= customerCount) { 

                    Customer::deleteCustomer(customerList, customerCount, deleteIndex - 1);  // Static method call from class 

                } 

                else { 

                    cout << "Invalid customer number.\n"; 

                } 

            } 

  

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

        case 4: 

            system("CLS"); 

            if (customerCount == 0) { 

                cout << "No customer data to search.\n"; 

                break; 

            } 

  

            Customer::searchCustomer(customerList, customerCount); 

  

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

  

        case 5: 

            system("CLS"); 

            if (customerCount == 0) { 

                cout << "No customer data to update.\n"; 

                break; 

            } 

  

            cout << "=========== Update Customer Data ===========\n\n"; 

            cout << "Customer List:\n"; 

            cout << "No "; 

            customerList[0].displayHeader(); 

            for (int i = 0; i < customerCount; i++) { 

                cout << "| " << left << setw(3) << i + 1; 

                customerList[i].displayCustomer(); 

            } 

            cout << "=======================================================================================================================\n"; 

  

            int updateIndex; 

            cout << "\nEnter the customer number to update (1 to " << customerCount << "): "; 

            cin >> updateIndex; 

  

            if (updateIndex >= 1 && updateIndex <= customerCount) { 

                int idx = updateIndex - 1; 

                cin.ignore(); 

  

                cout << "\nCurrent Data:\n"; 

                customerList[0].displayHeader(); 

                cout << "| " << left << setw(3) << updateIndex; 

                customerList[idx].displayCustomer(); 

  

                string input; 

                cout << "\n\n\n----------------- Selectively Update Customer Data -----------------\n"; 

  

  

                while (true) { 

                    cout << "Do you want to update the customer's name? (Y/N): ";                               //update customer name 

                    getline(cin, input); 

                    if (input == "Y" || input == "y") { 

                        string newName; 

                        cout << "Enter new name: "; 

                        getline(cin, newName); 

                        customerList[idx].setName(newName); 

                        break; 

                    } 

                    else if (input == "N" || input == "n") { 

                        cout << "Name not updated.\n"; 

                        break; 

                    } 

                    else { 

                        cout << "Invalid input. Please enter Y or N only.\n"; 

                    } 

                } 

  

                while (true) { 

                    cout << "Do you want to update the customer's IC number? (Y/N): ";                      //---update customer IC 

                    getline(cin, input); 

                    if (input == "Y" || input == "y") { 

                        string newIC; 

                        cout << "Enter new IC number: "; 

                        getline(cin, newIC); 

                        customerList[idx].setIC(newIC); 

                        break; 

                    } 

                    else if (input == "N" || input == "n") { 

                        cout << "IC number not updated.\n"; 

                        break; 

                    } 

                    else { 

                        cout << "Invalid input. Please enter Y or N only.\n"; 

                    } 

                } 

                // ----- update age 

                while (true) { 

                    cout << "Do you want to update the customer's age? (Y/N): "; 

                    getline(cin, input); 

                    if (input == "Y" || input == "y") { 

                        int age; 

                        cout << "Enter new customer age: "; 

                        while (!(cin >> age)) { 

                            cout << "\t\t\t\tInvalid input. Please enter a valid age: "; 

                            cin.clear(); 

                            cin.ignore(100, '\n'); 

                        } 

                        cin.ignore(); // clear leftover newline 

                        customerList[idx].setAge(age); 

                        break; 

                    } 

                    else if (input == "N" || input == "n") { 

                        cout << "Customer ag not updated.\n"; 

                        break; 

                    } 

                    else { 

                        cout << "Invalid input. Please enter Y or N only.\n"; 

                    } 

                } 

  

                while (true) { 

                    cout << "Do you want to update the customer's phone number? (Y/N): ";           //UPdate customer phone number 

                    getline(cin, input); 

                    if (input == "Y" || input == "y") { 

                        int ph; 

                        cout << "Enter new customer phone number: "; 

                        cin >> ph; 

                        customerList[idx].setPh(ph); 

                        break; 

                    } 

                    else if (input == "N" || input == "n") { 

                        cout << "Phone Number not updated.\n"; 

                        break; 

                    } 

                    else { 

                        cout << "Invalid input. Please enter Y or N only.\n"; 

                    } 

                } 

  

                cout << "Do you want to update the rental duration? (Y/N): ";                       //update rental duration 

                getline(cin, input); 

                if (input == "Y" || input == "y") { 

                    float oldTotal = customerList[idx].getTotalPayment(); 

                    float oldDuration = customerList[idx].getRentalDuration(); 

                    float price = oldDuration > 0 ? oldTotal / oldDuration : 0; 

                    int newDuration; 

                    cout << "Enter new rental duration (in days): "; 

                    while (!(cin >> newDuration)) { 

                        cout << "\t\t\t\t Invalid Input. Please enter a valid number of days: "; 

                        cin.clear(); 

                        cin.ignore(100, '\n'); 

                    } 

                    cin.ignore(); 

                    customerList[idx].setRentalDuration(newDuration); 

                    customerList[idx].setRentalDuration(newDuration); 

                    customerList[idx].setTotalPayment(price * newDuration); 

                } 

  

                cout << "\nCustomer data updated successfully.\n"; 

            } 

            else { 

                cout << "Invalid customer number.\n"; 

            } 

  

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

        case 6: 

            system("CLS"); 

            cout << "======== Sort Customers by Name ========\n"; 

            cout << "[1] Sort A from Z\n"; 

            cout << "[2] Sort Z from A\n"; 

            cout << "Choose an option: "; 

            int sortChoice; 

            cin >> sortChoice; 

  

            if (sortChoice == 1 || sortChoice == 2) { 

                bool ascending = (sortChoice == 1); 

                Customer::sortByName(customerList, customerCount, ascending); 

                cout << "\nCustomer list sorted successfully.\n"; 

                cout << "\n========= Sorted Customer List =========\n\n"; 

                Customer::displayHeader(); 

  

                for (int i = 0; i < customerCount; ++i) { 

                    customerList[i].displayCustomer(); 

                } 

            } 

            else { 

                cout << "\nInvalid option.\n"; 

            } 

  

            cout << "\nPress Enter to return to the Customer Menu..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

        case 7: 

            system("CLS"); 

            if (customerCount == 0) { 

                cout << "No customers to return cars.\n"; 

            } 

            else { 

                cout << "========= Customer List =========\n"; 

                cout << "No "; 

                Customer::displayHeader(); 

                for (int i = 0; i < customerCount; i++) { 

                    cout << "| " << left << setw(3) << i + 1; 

                    customerList[i].displayCustomer(); 

                } 

                cout << "=======================================================================================================================\n"; 

  

                int returnIndex; 

                cout << "Enter the customer number who is returning the car: "; 

                while (!(cin >> returnIndex)) { 

                    cout << "Invalid input. Please enter a number: "; 

                    cin.clear(); 

                    cin.ignore(100, '\n'); 

                } 

  

                if (returnIndex >= 1 && returnIndex <= customerCount) { 

                    int rentedIndex = rentedCarIndex[returnIndex - 1]; 

  

                    if (rentedIndex >= 0 && rentedIndex < carCount) { 

                        carList[rentedIndex].setAvailable(true); 

                        rentedCarIndex[returnIndex - 1] = -1; 

                        cout << "\nCar with plate [" << carList[rentedIndex].getCarPlate() 

                            << "] is now available again.\n"; 

                    } 

                    else { 

                        cout << "No car is linked to this customer.\n"; 

                    } 

                } 

                else { 

                    cout << "Invalid customer number.\n"; 

                } 

            } 

  

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

  

        case 8: 

            system("CLS"); 

            queueManager.displayQueue(); 

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

  

        case 9: 

            system("CLS"); 

            queueManager.serveNextCustomer(customerList, customerCount, carList, carCount); 

            cout << "\nPress Enter to return..."; 

            cin.ignore(); 

            cin.get(); 

            system("CLS"); 

            break; 

  

        case 0: 

            system("CLS"); 

            break; 

  

        default: 

            cout << "Invalid choice.\n"; 

        } 

  

    } while (choice != 0); 

} 

  

void functionSummary(Car carList[], int carCount, Customer customerList[], int customerCount) { 

    int availableCars = 0; 

    float totalEarnedPayment = 0.0; 

  

    for (int i = 0; i < carCount; i++) { 

        if (carList[i].isAvailable()) 

            availableCars++; 

    } 

  

    for (int i = 0; i < customerCount; i++) { 

        totalEarnedPayment += customerList[i].getTotalPayment(); 

    } 

  

    cout << "\n========== SYSTEM SUMMARY REPORT ==========\n"; 

    cout << "Total Cars in System : " << carCount << endl; 

    cout << "Available Cars :  " << availableCars << endl; 

    cout << "Rented Cars : " << (carCount - availableCars) << endl; 

    cout << "Total Customers : " << customerCount << endl; 

    cout << "Total Payment : RM" << fixed << setprecision(2) << totalEarnedPayment << endl; 

    cout << "==================================================================\n";; 

} 