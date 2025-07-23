//====================================================================================================================================Car.cpp //Car.cpp #include  

#include "Car.h" 

#include  

#include #include // For tolower #include #include #include using namespace std; 

void Car::inputCar() { cin.ignore(); cout << "Enter car plate number: "; getline(cin, carPlate); transform(carPlate.begin(), carPlate.end(), carPlate.begin(), ::toupper); cout << "Enter Car model :"; getline(cin, model); cout << "Enter Car Color :"; getline(cin, color); cout << "Enter Max Speed (km/h) :"; while (!(cin >> maxSpeed)) { cin.clear(); cin.ignore(numeric_limits::max(), '\n'); cout << "Invalid input! Please enter a number: "; } cout << "Enter price per day RM :"; while (!(cin >> pricePerDay)) { cin.clear(); cin.ignore(numeric_limits::max(), '\n'); cout << "Invalid input! Please enter a number: "; } } 

void Car::displayCar() { 

cout << "| " << left << setw(20) << model 
 
    << "| " << setw(15) << color 
 
    << "| " << setw(15) << maxSpeed 
 
    << "| " << setw(15) << pricePerDay << "|" << endl; 
  

} 

void Car::displayHeader() { cout << "=======================================================================================================================\n"; cout << "| " << left << setw(14) << "Car Plate" << "| " << left << setw(15) << "Model" << "| " << left << setw(10) << "Color" << "| " << left << setw(12) << "Max Speed" << "| " << left << setw(15) << "Price Per Day" << "|\n"; cout << "=======================================================================================================================\n"; } 

void Car::displayCarRow() const{ cout << "| " << setw(14) << carPlate << "| " << left << setw(15) << model << "| " << setw(10) << color << "| " << setw(10) << maxSpeed << "| RM " << fixed << setprecision(2) << setw(15) << pricePerDay << "|\n"; } 

void Car::displayAllCars(Car carList[], int carCount) { if (carCount == 0) { cout << "\nNo cars to display.\n"; return; } 

Car::displayHeader(); 
for (int i = 0; i < carCount; i++) { 
    cout << "| " << left << setw(3) << i + 1; 
    carList[i].displayCarRow(); 
} 
 
cout << "=======================================================================================================================\n"; 
  

} 

void Car::deleteCar(Car carList[], int& carCount, int indexToDelete) { if (indexToDelete < 0 || indexToDelete >= carCount) { cout << "Invalid car index.\n"; return; } 

for (int i = indexToDelete; i < carCount - 1; i++) { 
    carList[i] = carList[i + 1]; // shift 
} 
 
carCount--; 
cout << "Car deleted successfully.\n"; 
  

} 

void Car::searchCar(const Car carList[], int carCount) { if (carCount == 0) { cout << "No cars available to search.\n"; return; } 

cin.ignore(); 
string keyword; 
cout << "Enter model to search: "; 
getline(cin, keyword); 
transform(keyword.begin(), keyword.end(), keyword.begin(), ::toupper); 
 
bool found = false; 
Car::displayHeader(); 
 
for (int i = 0; i < carCount; i++) { 
    string model = carList[i].getModel(); 
    transform(model.begin(), model.end(), model.begin(), ::toupper); 
 
    if (model.find(keyword) != string::npos) { 
        cout << "| " << left << setw(3) << i + 1; 
        carList[i].displayCarRow(); 
        found = true; 
    } 
} 
 
if (!found) { 
    cout << "No matching cars found.\n"; 
} 
 
cout << "=======================================================================================================================\n"; 
  

} 

//---------------- update car void Car::updateCarData() { string input; 

// Car Plate 
while (true) { 
    cout << "Do you want to update the car plate? (Y/N): "; 
    getline(cin, input); 
    if (input == "Y" || input == "y") { 
        cout << "Enter new car plate: "; 
        getline(cin, carPlate); 
        break; 
    } 
    else if (input == "N" || input == "n") { 
        break; 
    } 
    else { 
        cout << "Invalid input. Enter Y or N.\n"; 
    } 
} 
//============================= update --- Model 
while (true) { 
    cout << "Do you want to update the model? (Y/N): "; 
    getline(cin, input); 
    if (input == "Y" || input == "y") { 
        cout << "Enter new model: "; 
        getline(cin, model); 
        break; 
    } 
    else if (input == "N" || input == "n") { 
        break; 
    } 
    else { 
        cout << "Invalid input. Enter Y or N.\n"; 
    } 
} 
 
//============================= update --- Color 
 
while (true) { 
    cout << "Do you want to update the color? (Y/N): "; 
    getline(cin, input); 
    if (input == "Y" || input == "y") { 
        cout << "Enter new color: "; 
        getline(cin, color); 
        break; 
    } 
    else if (input == "N" || input == "n") { 
        break; 
    } 
    else { 
        cout << "Invalid input. Enter Y or N.\n"; 
    } 
} 
 
//============================= update --- Max Speed 
while (true) { 
    cout << "Do you want to update the max speed? (Y/N): "; 
    getline(cin, input); 
    if (input == "Y" || input == "y") { 
        int newSpeed; 
        cout << "Enter new max speed (km/h): "; 
        while (!(cin >> newSpeed)) { 
            cout << "\t\t\t\tInvalid input. Please enter a number: "; 
            cin.clear(); 
            cin.ignore(100, '\n'); 
        } 
        maxSpeed = newSpeed; 
        cin.ignore(); // flush newline 
        break; 
    } 
    else if (input == "N" || input == "n") { 
        break; 
    } 
    else { 
        cout << "Invalid input. Enter Y or N.\n"; 
    } 
} 
//============================= update --- Price 
while (true) { 
    cout << "Do you want to update the price per day? (Y/N): "; 
    getline(cin, input); 
    if (input == "Y" || input == "y") { 
        float newPrice; 
        cout << "Enter new price per day: "; 
        while (!(cin >> newPrice)) { 
            cout << "\t\t\t\tInvalid input. Please enter a valid price: "; 
            cin.clear(); 
            cin.ignore(100, '\n'); 
        } 
        pricePerDay = newPrice; 
        cin.ignore(); 
        break; 
    } 
    else if (input == "N" || input == "n") { 
        break; 
    } 
    else { 
        cout << "Invalid input. Enter Y or N.\n"; 
    } 
} 
 
cout << "\nCar data updated successfully.\n"; 
  

} 

//===================== sort car void Car::sortByPrice(Car carList[], int carCount, bool ascending) { for (int i = 0; i < carCount - 1; ++i) { for (int j = i + 1; j < carCount; ++j) { bool condition; if (ascending) condition = carList[i].getPricePerDay() > carList[j].getPricePerDay(); else condition = carList[i].getPricePerDay() < carList[j].getPricePerDay(); 

       if (condition) { 
            Car temp = carList[i]; 
            carList[i] = carList[j]; 
            carList[j] = temp; 
        } 
    } 
} 
 
if (ascending) 
    cout << "\nCars sorted by price (Ascending).\n"; 
else 
    cout << "\nCars sorted by price (Descending).\n"; 
  

} 

//---------------------------------------------------------------------------> Customer Section <-----------------------------------------------------------------------------  

// ===============insert section  

void Customer::inputCustomer(float pricePerDay) { cin.ignore(); // clear newline  

while (true) { 
    cout << "Enter Name: "; 
    getline(cin, name); 
    if (name.empty()) { 
        cout << "Name cannot be empty.\n"; 
        continue; 
    } 
    bool valid = true; 
    for (char c : name) { 
        if (isdigit(c)) { 
            valid = false; 
            break; 
        } 
    } 
    if (!valid) { 
        cout << "Name cannot contain numbers.\n"; 
        continue; 
    } 
    break; 
} 
 
// ----------- Age (must be number and >= 18) 
cout << "Enter Age (must be 18+): "; 
while (!(cin >> age) || age < 18) { 
    cin.clear(); 
    cin.ignore(100, '\n'); 
    cout << "Invalid age! Enter a number (18+): "; 
} 
cin.ignore(); // clear newline 
 
// ----------- ID Number (numbers only) 
while (true) { 
    cout << "Enter IC Number: "; 
    getline(cin, idNumber); 
    if (idNumber.empty()) { 
        cout << "IC Number cannot be empty.\n"; 
        continue; 
    } 
    bool allDigits = true; 
    for (char c : idNumber) { 
        if (!isdigit(c)) { 
            allDigits = false; 
            break; 
        } 
    } 
    if (!allDigits) { 
        cout << "IC Number must contain digits only.\n"; 
        continue; 
    } 
    break; 
} 
 
// ----------- Phone Number (non-empty) 
while (true) { 
    cout << "Enter Phone Number: "; 
    getline(cin, phoneNumber); 
    if (phoneNumber.empty()) { 
        cout << "Phone Number cannot be empty.\n"; 
        continue; 
    } 
    break; 
} 
 
cout << "Enter Rental Duration (days): "; 
while (!(cin >> rentalDuration) || rentalDuration <= 0) { 
    cin.clear(); 
    cin.ignore(100, '\n'); 
    cout << "Invalid duration! Enter a positive number: "; 
} 
cin.ignore(); 
 
// ----------- Rental Duration (positive number) 
while (true) { 
    cout << "Enter Date to Rent (DD/MM/YYYY): "; 
    getline(cin, dateOfRent); 
    if (dateOfRent.empty()) { 
        cout << "Date cannot be empty.\n"; 
        continue; 
    } 
    bool valid = true; 
    for (char c : dateOfRent) { 
        if (!isdigit(c) && c != '/') { 
            valid = false; 
            break; 
        } 
    } 
    if (!valid) { 
        cout << "Date must contain digits and '/' only (e.g., 12/06/2025).\n"; 
        continue; 
    } 
    break; 
} 
 
 
// Auto calculate date  
int day, month, year; 
sscanf_s(dateOfRent.c_str(), "%d/%d/%d", &day, &month, &year); 
day += rentalDuration; 
 
dateOfReturn = to_string(day) + "/" + to_string(month) + "/" + to_string(year); 
totalPayment = rentalDuration * pricePerDay; 
 
cout << "\n\n------------Customer inserted successfully.\n\n"; 
cout << "\nStart Date: " << dateOfRent << "\nTotal Payment: RM " << totalPayment << endl; 
  

} 

void Customer::displayHeader() { cout << left << setw(15) << "Name" << setw(10) << "Age" << setw(15) << "IC Number" << setw(15) << "Phone" << setw(10) << "Days" << setw(15) << "Date to Rent" << setw(15) << "Date to Return" << setw(16) << "Total (RM)" << endl; cout << "=======================================================================================================================\n"; } 

void Customer::displayCustomer()const { cout << left << setw(15) << name << setw(7) << age << setw(15) << idNumber << setw(15) << phoneNumber << setw(10) << rentalDuration << setw(15) << dateOfRent << setw(15) << dateOfReturn << fixed << setprecision(2) << setw(16) << totalPayment << endl; } 

void Customer::deleteCustomer(Customer customerList[], int& customerCount, int index) { if (index < 0 || index >= customerCount) { cout << "Invalid customer index." << endl; return; } 

for (int i = index; i < customerCount - 1; i++) { 
    customerList[i] = customerList[i + 1]; 
} 
 
customerCount--; 
cout << "Customer deleted successfully.\n"; 
  

} 

void Customer::searchCustomer(const Customer customerList[], int customerCount) { if (customerCount == 0) { cout << "No customers available to search.\n"; return; } 

cin.ignore(); 
string keyword; 
cout << "Enter customer name to search: "; 
getline(cin, keyword); 
 
string keywordLower = keyword; 
transform(keywordLower.begin(), keywordLower.end(), keywordLower.begin(), ::tolower); 
 
bool found = false; 
Customer::displayHeader(); 
 
for (int i = 0; i < customerCount; i++) { 
    string name = customerList[i].getName(); 
    transform(name.begin(), name.end(), name.begin(), ::tolower); 
 
    if (name.find(keywordLower) != string::npos) { 
        cout << "| " << left << setw(3) << i + 1; 
        customerList[i].displayCustomer(); 
        found = true; 
    } 
} 
 
if (!found) { 
    cout << "| No matching customers found. |\n"; 
} 
 
cout << "=======================================================================================================================\n"; 
  

} 

void Customer::sortByName(Customer customerList[], int customerCount, bool ascending) { for (int i = 0; i < customerCount - 1; ++i) { for (int j = i + 1; j < customerCount; ++j) { bool condition; if (ascending) { condition = customerList[i].getName() > customerList[j].getName(); } else { condition = condition = customerList[i].getName() < customerList[j].getName(); } if (condition) { swap(customerList[i], customerList[j]); } } } } 

void CustomerQueueManager::addToQueue() { Customer temp; temp.inputCustomer(0); waitingQueue.push(temp); cout << "Customer added to waiting queue.\n"; } 

void CustomerQueueManager::displayQueue() const { if (waitingQueue.empty()) { cout << "No customers in the waiting line.\n"; return; } 

cout << "=========== Waiting Queue ===========\n\n"; 
queue<Customer> tempQueue = waitingQueue; 
Customer::displayHeader(); 
while (!tempQueue.empty()) { 
    Customer c = tempQueue.front(); 
    c.displayCustomer(); 
    tempQueue.pop(); 
} 
  

} 

void CustomerQueueManager::serveNextCustomer(Customer customerList[], int& customerCount, Car carList[], int carCount) { if (waitingQueue.empty()) { cout << "No customer in the waiting list.\n"; return; } 

bool carAvailable = false; 
for (int i = 0; i < carCount; i++) { 
    if (carList[i].isAvailable()) { 
        carAvailable = true; 
        break; 
    } 
} 
 
if (!carAvailable) { 
    cout << "No cars available to assign.\n"; 
    return; 
} 
 
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
cout << "Select a car number to assign to the next waiting customer: "; 
while (!(cin >> selectedCar)) { 
    cout << "Invalid input. Please enter a number: "; 
    cin.clear(); 
    cin.ignore(100, '\n'); 
} 
 
if (selectedCar < 1 || selectedCar > carCount || !carList[selectedCar - 1].isAvailable()) { 
    cout << "Invalid car selection.\n"; 
    return; 
} 
 
float selectedPrice = carList[selectedCar - 1].getPricePerDay(); 
Customer served = waitingQueue.front(); 
waitingQueue.pop(); 
 
cout << "\nServing customer: " << served.getName() << endl; 
served.setTotalPayment(served.getRentalDuration() * selectedPrice); 
carList[selectedCar - 1].setAvailable(false); 
customerList[customerCount++] = served; 
 
cout << "Customer served and added to the system.\n"; 
  

} 

bool CustomerQueueManager::isEmpty() const { return waitingQueue.empty(); } 