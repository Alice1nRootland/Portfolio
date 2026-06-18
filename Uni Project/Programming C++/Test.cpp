
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
using namespace std;

struct Cars {
    string mark[10] = { "Honda", "BMW", "Mercedes", "Audi", "Tesla", "Proton", "Volkswagen", "Perodua", "Toyota" };
    string model[10] = { "2016MS", "2018AS", "2018DS", "2017LA", "2018OW", "2005Ps", "2008PW", "2010MS", "2016JN" };
    string color[10] = { "Red", "Black", "Yellow", "Blue", "Red", "Brown", "Silver", "Black", "Grey" };
    string maxSpeed[10] = { "100 Km/h", "150 Km/h", "150 Km/h", "170 Km/h", "130 Km/h", "140 Km/h", "130 Km/h", "120 Km/h", "150 Km/h" };
    int price[10] = { 250, 400, 400, 500, 900, 150, 430, 230, 200 };
    int year[10] = { 2014, 2012, 2013, 2017, 2020, 2009, 2012, 2010, 2014 };
    int size = 9;
};

struct CustomerInfo {
    string name;
    string icnum;
    string phone;
    int rentDate[3]; // Rent date (year, month, day)
    int days;
    int payment;
    int balance;
};

Cars car;
CustomerInfo customer;

void shiftArrays(int index) {
    for (int i = index; i < car.size - 1; ++i) {
        car.mark[i] = car.mark[i + 1];
        car.model[i] = car.model[i + 1];
        car.color[i] = car.color[i + 1];
        car.maxSpeed[i] = car.maxSpeed[i + 1];
        car.price[i] = car.price[i + 1];
        car.year[i] = car.year[i + 1];
    }
    car.size--;
}

// Function to validate IC number
bool validateICNumber(const string& ic) {
    if (ic.length() != 12) {
        cerr << "\t\t\t\tInvalid IC number! It must have 12 digits.\n";
        return false;
    }

    for (char c : ic) {
        if (!isdigit(c)) {
            cerr << "\t\t\t\tInvalid IC number! It must contain only digits.\n";
            return false;
        }
    }

    // Extract year, month, and day from IC number
    string birthYearStr = ic.substr(0, 2); // First 2 digits: Year
    string birthMonthStr = ic.substr(2, 2); // Next 2 digits: Month
    string birthDayStr = ic.substr(4, 2); // Next 2 digits: Day

    int birthYear = stoi(birthYearStr);
    int birthMonth = stoi(birthMonthStr);
    int birthDay = stoi(birthDayStr);

    // Convert 2-digit year to 4-digit year (assuming the IC format uses 00-99)
    if (birthYear <= 23) { // Assuming users born after 2000 are below 24
        birthYear += 2000;
    }
    else {
        birthYear += 1900;
    }

    // Get the current date
    time_t now = time(0);
    tm local_time;
    localtime_s(&local_time, &now);
    int currentYear = local_time.tm_year + 1900;
    int currentMonth = local_time.tm_mon + 1;
    int currentDay = local_time.tm_mday;

    // Calculate age
    int age = currentYear - birthYear;
    if (birthMonth > currentMonth || (birthMonth == currentMonth && birthDay > currentDay)) {
        age--; // Adjust for not having had a birthday yet this year
    }

    // Check if the user is under 18
    if (age < 18) {
        cerr << "\t\t\t\tYou must be at least 18 years old to rent a car. Your age is: " << age << ".\n";
        return false;
    }

    return true;
}

bool isLeapYear(int year) {
    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int daysSince1900(int year, int month, int day) {
    int days = 0;
    for (int i = 1900; i < year; i++) {
        days += (isLeapYear(i) ? 366 : 365);
    }

    int daysInMonth[] = { 31, (isLeapYear(year) ? 29 : 28), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    for (int i = 0; i < month - 1; i++) {
        days += daysInMonth[i];
    }

    days += day;
    return days;
}

bool validatePhoneNumber(const string& phone) {
    if (phone.empty()) {
        cerr << "Phone number cannot be empty.\n";
        return false;
    }
    if (phone.length() == 10 || phone.length() == 11) {
        for (char c : phone) {
            if (!isdigit(c)) return false;
        }
        return true;
    }
    return false;
}

int parseAmount(const string& amountStr) {

        // This function will remove any non-numeric characters (like "RM") from the string
        string numericStr;
    for (char c : amountStr) {
        if (isdigit(c)) {
            numericStr.push_back(c);
        }
    }

    // Convert the cleaned numeric string to an integer
    try {
        return stoi(numericStr);
    }
    catch (const std::invalid_argument& e) {
        cerr << "Error: Invalid payment value!" << endl;
        return -1;  // Return an error code if the conversion fails
    }
}

int RetCar() {
    ifstream inputFile("CustomerDetails.txt");

    // Check if the file was opened successfully
    if (!inputFile) {
        cerr << "Error: Could not open the file!" << endl;
        return -1;  // Return an error code if the file cannot be opened
    }

    // Display file contents to the user
    string line;
    while (getline(inputFile, line))
    {
        cout << line << endl;
    }
    cout << "\n=========================== END OF CUSTOMER DETAILS ====================\n";

    // Close the file
    inputFile.close();

    // Now, ask for the return date
    int returnYear, returnMonth, returnDay;
    cout << "Enter the return year: ";
    cin >> returnYear;
    cout << "Enter the return month: ";
    cin >> returnMonth;
    cout << "Enter the return day: ";
    cin >> returnDay;

    // Retrieve rental start date from the file (this should ideally be read from the file)
    int rentalYear = 0, rentalMonth = 0, rentalDay = 0;

    inputFile.open("CustomerDetails.txt");  // Reopen the file to read the rental start date
    while (getline(inputFile, line)) {
        if (line.find("Rent Start Date") != string::npos) {
            size_t startPos = line.find(":") + 2;  // Find where the date starts
            string dateStr = line.substr(startPos); // Extract the date substring

            // Parse the date (assuming it's in "YYYY/MM/DD" format)
            size_t firstSlash = dateStr.find('/');
            size_t secondSlash = dateStr.find('/', firstSlash + 1);

            try {
                rentalYear = stoi(dateStr.substr(0, firstSlash));
                rentalMonth = stoi(dateStr.substr(firstSlash + 1, secondSlash - firstSlash - 1));
                rentalDay = stoi(dateStr.substr(secondSlash + 1));
            }
            catch (const std::invalid_argument& e) {
                cerr << "Error: Invalid date format in file!" << endl;
                return -1;  // Return an error code
            }
        }
    }

    // Close the file again after reading the rental date
    inputFile.close();

    // If rental date was not found, print an error message
    if (rentalYear == 0 || rentalMonth == 0 || rentalDay == 0) {
        cerr << "Error: Rental start date not found in the file!" << endl;
        return -1;  // Return an error code
    }

    // Calculate the total days from 1900-01-01 for both dates
    int rentalStartDays = daysSince1900(rentalYear, rentalMonth, rentalDay);
    int returnDays = daysSince1900(returnYear, returnMonth, returnDay);

    // Calculate the number of days used for rental
    int rentalDuration = returnDays - rentalStartDays;

    // Get the initial rental duration from the file (this should be dynamically read from file)
    int initialRentDuration = 0;
    inputFile.open("CustomerDetails.txt");
    while (getline(inputFile, line)) {
        if (line.find("Rent Duration") != string::npos) {
            size_t startPos = line.find(":") + 2;
            try {
                initialRentDuration = stoi(line.substr(startPos));
            }
            catch (const std::invalid_argument& e) {
                cerr << "Error: Invalid rental duration in file!" << endl;
                return -1;  // Return an error code
            }
        }
    }
    inputFile.close();

    // Compare rental duration with the initial rental duration
    int penaltyAmount = 0;
    if (rentalDuration > initialRentDuration) {
        // Calculate the penalty for exceeding days
        int penaltyDays = rentalDuration - initialRentDuration;

            penaltyAmount = penaltyDays * 100; // Example penalty rate (RM 100 per day)
        cout << "You have exceeded your rental period by " << penaltyDays << " days. Penalty: RM " << penaltyAmount << endl;
    }
    else if (rentalDuration < initialRentDuration) {
        // Calculate the refund for unused days
        int unusedDays = initialRentDuration - rentalDuration;
        int refundAmount = unusedDays * 100; // Example refund rate (RM 100 per day)
        cout << "You have unused " << unusedDays << " days. Refund: RM " << refundAmount << endl;
    }
    else {
        // Rental duration is exactly as expected
        cout << endl;
        cout << "Thank you for using our services!\n";
    }

    // Retrieve prior balance from customer details (from file)
    int priorBalance = 0;
    inputFile.open("CustomerDetails.txt");
    while (getline(inputFile, line)) {
        if (line.find("Balance") != string::npos) {
            size_t startPos = line.find(":") + 2;
            priorBalance = parseAmount(line.substr(startPos));
            if (priorBalance == -1) {
                return -1;  // If parsing fails, exit the function
            }
        }
    }
    inputFile.close();

    // Apply prior balance to reduce penalty
    if (penaltyAmount > 0) {
        int remainingPenalty = penaltyAmount - priorBalance;
        int totalPayment = 0;

        if (remainingPenalty > 0) {
            // Case where the prior balance doesn't cover the full penalty
            cout << "You have a remaining penalty of RM" << remainingPenalty << " after applying your prior balance of RM" << priorBalance << ".\n";
            while (totalPayment < remainingPenalty) {
                int payment;
                cout << "\nPlease pay the remaining penalty of RM" << remainingPenalty - totalPayment << ": RM ";
                cin >> payment;

                if (payment <= 0) {
                    cout << "Invalid payment amount. Please enter a valid amount.\n";
                }
                else {
                    totalPayment += payment;
                    if (totalPayment < remainingPenalty) {
                        cout << "You still owe RM" << remainingPenalty - totalPayment << ". Please pay the remaining amount.\n";
                    }
                }
            }
        }
        else {
            // Case where prior balance covers the full penalty, and the customer gets a refund
            int refundAmount = abs(remainingPenalty); // The refund is the surplus prior balance
            cout << "Your prior balance of RM" << priorBalance << " covers the full penalty. You will be refunded RM" << refundAmount << ".\n";
        }

        cout << "\nYour penalty has been fully paid. Thank you!\n";
    }

    return 0;
}


void user_input(int theChoice) {
    ofstream outputFile("CustomerDetails.txt", ios::out);
    if (!outputFile) {
        cerr << "File could not be opened \n";
        exit(1);
    }

    system("CLS");
    cout << "\n\n\n\n\t\t\t\t -----------------------------------------------------\n";
    cout << "\n\t\t\t\t\t Please Provide Your Personal Details  : ";
    cout << "\n\n\t\t\t\t -----------------------------------------------------\n\n";
    cout << "\n\t\t  NOTE: PROVIDE YOUR FULL NAME\n";

    cout << "\t\t\t\t Enter your name: ";
    cin.ignore();
    getline(cin, customer.name);

    // Validate IC Number
    bool validIC = false;
    while (!validIC) {
        cout << "\t\t\t\t Enter your IC number (12 digits, no '-') : ";
        cin >> customer.icnum;

        // Validate the IC number using the validateICNumber function
        validIC = validateICNumber(customer.icnum);
        if (!validIC) {
            cout << "\n\t\t\t\t Please enter a valid IC number.\n";  // Retry message
        }
    }

    // Validate Phone Number
    bool validPhone = false;
    while (!validPhone) {
        cout << "\t\t\t\t Enter your phone number: ";
        cin >> customer.phone;

        // Validate phone number using the validatePhoneNumber function

            validPhone = validatePhoneNumber(customer.phone);
        if (!validPhone) {
            cout << "\t\t\t\tInvalid phone number! Please enter a valid phone number.\n";  // Retry message
        }
    }

    cout << "\t\t\t\tEnter rental start year: ";
    cin >> customer.rentDate[0];

    do {
        cout << "\t\t\t\tEnter rental start month (1-12): ";
        cin >> customer.rentDate[1];
        if (customer.rentDate[1] < 1 || customer.rentDate[1] > 12) {
            cout << "\t\t\t\tInvalid month! Please enter a value between 1 and 12." << endl;
        }
    } while (customer.rentDate[1] < 1 || customer.rentDate[1] > 12);

    do {
        cout << "\t\t\t\tEnter rental start day (1-31): ";
        cin >> customer.rentDate[2];
        if (customer.rentDate[2] < 1 || customer.rentDate[2] > 31) {
            cout << "\t\t\t\tInvalid day!Please enter a value between 1 and 31." << endl;
        }
    } while (customer.rentDate[2] < 1 || customer.rentDate[2] > 31);

    cout << "\t\t\t\t How many days you want to rent: ";
    cin >> customer.days;

    int rp = customer.days * car.price[theChoice - 1];
    cout << "\t\t\t\t Total Price : RM" << rp << endl;

    int totalPayment = 0;
    while (totalPayment < rp) {
        cout << "\t\t\t\t Payment amount: RM ";
        cin >> customer.payment;
        totalPayment += customer.payment;

        if (totalPayment < rp) {
            int remainingAmount = rp - totalPayment;
            cout << "\n\t\t\t\t Payment insufficient! You still owe RM" << remainingAmount << endl;
        }
        else {
            break;
        }
    }

    customer.balance = totalPayment - rp;
    if (customer.balance < 0) {
        customer.balance = abs(customer.balance);
    }

    outputFile << "=========================== CUSTOMER DETAILS ============================\n" << "\n"
        << "\t\tName : " << customer.name << " \n"
        << "\t\tIC : " << customer.icnum << " \n"
        << "\t\tPhone : " << customer.phone << " \n"
        << "\t\tRent Duration : " << customer.days << "\n"
        << "\t\tPayment : RM" << totalPayment << "\n"
        << "\t\tBalance : RM" << customer.balance << "\n"
        << "\t\tRent Start Date : " << customer.rentDate[0] << "/" << customer.rentDate[1] << "/" << customer.rentDate[2] << endl;

    if (totalPayment == rp) {
        cout << "\n\n\t\tRenting process is successful! " << endl;
        outputFile << "\t\tPayment has been done successfully!\n";
    }
    else if (totalPayment > rp) {
        cout << "\n\n\t\t Please claim your balance at the counter : RM" << customer.balance << endl;
        outputFile << "\t\tPlease claim your balance at counter!\n";
    }

    outputFile.close();
}

void Details(int theChoice) {
    system("CLS");
    cout << "\n\n\n\n\t\t\t\t -------------------------------------------\n";
    cout << "\t\t\t\t\t   You have selected " << car.mark[theChoice - 1] << endl;
    cout << "\t\t\t\t -------------------------------------------\n\n\n";
    cout << "\t\t\t\t\t Model : " << car.model[theChoice - 1] << endl;
    cout << "\t\t\t\t\t Color : " << car.color[theChoice - 1] << endl;
    cout << "\t\t\t\t\t Maximum Speed : " << car.maxSpeed[theChoice - 1] << endl;
    cout << "\t\t\t\t\t Price : RM " << car.price[theChoice - 1] << endl << endl;
}


void Menu() {
    int num = 0;
    cout << endl;
    for (int i = 0; i < car.size; ++i) {
        cout << "\t\t\t\t\t\t Enter " << ++num << " to select  -  " << car.mark[i] << endl;
    }
    cout << endl;
}

void rent() {
    string decide = "yes";
    cout << "\n\n\n\n\t\t\t\t ----------------------------------------------------------------";
    cout << "\n\t\t\t\t\t\tMajestic Motors Car Rental Sdn. Bhd. \n";
    cout << "\n\t\t\t\t\tWelcome to Majestic Motors Car Rental Sdn. Bhd. \n";
    cout << "\n\t\t\t\t\t\t  Choose the car brand below : " << endl;
    cout << "\t\t\t\t ----------------------------------------------------------------\n";

    while (decide != "exit") {
        Menu();
        cout << "\n\n\t\t\t\t Please pick a car brand : ";
        int theChoice;

            cin >> theChoice;

        while (cin.fail() || theChoice < 1 || theChoice > 9) {
            // Clear error flag and discard the invalid input
            cin.clear(); // Clears the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discards invalid input

            // Print error message
            cout << "\nInvalid input! Please enter a valid number between 1 and 9: ";
            cin >> theChoice;
        }

        Details(theChoice);
        cout << "\n\t\t\t\t Are you sure to rent this car? (yes / no / exit) : ";
        cin >> decide;

        if (decide == "yes") {
            user_input(theChoice);
            cout << "\t\t\t  Do you want to rent another car? (yes / no) : ";
            cin >> decide;
            shiftArrays(theChoice - 1);
            if (decide == "no")
                exit(0);
        }
        else if (decide == "no") {
            system("CLS");
            cout << "\n\n\n\n\t\t\t\t ----------------------------------------------------------------";
            cout << "\n\t\t\t\t\t\tMajestic Motors Car Rental Sdn. Bhd. \n";
            cout << "\n\t\t\t\t\tWelcome to Majestic Motors Car Rental Sdn. Bhd. \n";
            cout << "\n\t\t\t\t\t\t  Choose the car brand below : " << endl;
            cout << "\t\t\t\t ----------------------------------------------------------------\n";
            continue;
        }
        else if (decide == "exit") {
            cout << "\n\t\t\t\t\t       ENDING PROGRAM....\n\n\t\t\t\tThank you for your interest! May we see you again!\n\n\n";
            exit(0);  // Terminate the entire program
        }
    }
}

int main() {
    int decide = 1;

    while (true)
    {
        cout << "\n\n\n\n\t\t\t\t ---------------------------------------------------------------";
        cout << "\n\n\t\t\t\t\t\tMajestic Motors Car Rental Sdn. Bhd. \n\n";
        cout << "\t\t\t\t ---------------------------------------------------------------" << endl << endl;
        cout << "\n\t\t\t\t Please choose your service :" << endl << endl;
        cout << "\n\t\t\t\t\t\t1. Rent \n";
        cout << "\t\t\t\t\t\t2. Return\n";
        cout << "\t\t\t\t\t\t3. Exit\n\n\n";
        cout << "\t\t\t\t Enter your chosen service : ";
        cin >> decide;

        if (cin.fail()) {
            // Clear the error flag
            cin.clear();

            // Ignore the remaining characters in the input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            // Display error message
            cerr << "\t\t\t\tInvalid input! Please enter a valid number between 1 to 3 \n";
            continue;  // Re-prompt the user for a valid option
        }

        switch (decide) {
        case 1:
            system("CLS");
            rent();
            break;
        case 2:
            system("CLS");
            RetCar();
            exit(0);
        case 3:
            cout << "\n\n\t\t\t\tThank you for being interested in our service! Goodbye!\n\n\n";
            return 0;
        default:
            cerr << "Invalid option. Please try again.\n";
            break;
        }
    }
    return 0;
}