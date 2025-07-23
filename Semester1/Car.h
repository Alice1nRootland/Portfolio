// car.h 

#ifndef CAR_H 

#define CAR_H 

  

#include <iostream> 

#include <string> 

#include <iomanip> 

#include <queue> 

  

using namespace std; 

  

// ------------------ Car Class ------------------ 

class Car { 

private: 

    string model; 

    string color; 

    int maxSpeed; 

    float pricePerDay; 

    string carPlate; 

    bool available = true; 

  

public: 

    void inputCar(); 

    void displayCar(); 

    void displayCarRow() const; 

    static void displayHeader(); 

    void updateCarData(); 

  

    void setModel(string m) { model = m; } 

    void setColor(string c) { color = c; } 

    void setMaxSpeed(int s) { maxSpeed = s; } 

    void setCarPlate(string p) { carPlate = p; } 

    void setPrice(float p) { pricePerDay = p; } 

  

    static void searchCar(const Car carList[], int carCount); 

    static void deleteCar(Car carList[], int& carCount, int indexToDelete); 

    static void sortByPrice(Car carList[], int carCount, bool ascending); 

    static void displayAllCars(Car carList[], int carCount); 

  

  

    bool isAvailable() const { return available; } 

    void setAvailable(bool status) { available = status; } 

  

    string getModel() const { return model; } 

    string getCarPlate() const { return carPlate; } 

    float getPricePerDay() const { return pricePerDay; } 

}; 

  

// ------------------ Customer Class ------------------ 

class Customer { 

private: 

    string name; 

    int age; 

    string idNumber; 

    string phoneNumber; 

    int rentalDuration; 

    float totalPayment; 

    string dateOfRent; 

    string dateOfReturn; 

    bool available = true; 

  

public: 

    void inputCustomer(float pricePerDay); 

    void displayCustomer() const; 

    static void displayHeader(); 

  

    int getRentalDuration() const { return rentalDuration; } 

    float getTotalPayment() const { return totalPayment; } 

    string getName() const { return name; } 

    string getDateToRent() const { return dateOfRent; } 

    string getDateToReturn() const { return dateOfReturn; } 

  

    void setName(string n) { name = n; } 

    void setIC(string icNum) { idNumber = icNum; } 

    void setAge(int age) { this->age = age; } 

    void setPh(int ph) { phoneNumber = to_string(ph); } 

    void setRentalDuration(int days) { rentalDuration = days; } 

    void setTotalPayment(float pay) { totalPayment = pay; } 

    void setDateToRent(string date) { dateOfRent = date; } 

    void setDateToReturn(string date) { dateOfReturn = date; } 

  

    bool isAvailable() const { return available; } 

    void setAvailable(bool status) { available = status; } 

  

    static void searchCustomer(const Customer customerList[], int customerCount); 

    static void deleteCustomer(Customer customerList[], int& customerCount, int index); 

    static void sortByName(Customer customerList[], int customerCount, bool ascending); 

}; 

  

// ------------------ Queue Manager Class ------------------ 

class CustomerQueueManager { 

private: 

    queue<Customer> waitingQueue; 

  

public: 

    void addToQueue(); 

    void displayQueue() const; 

    void serveNextCustomer(Customer customerList[], int& customerCount, Car carList[], int carCount); 

    bool isEmpty() const; 

}; 

  

#endif // CAR_H 