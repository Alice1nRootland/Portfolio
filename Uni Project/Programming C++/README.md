# 🚗 Majestic Motors Car Rental System (C++)

This is a simple console-based car rental system written in C++. It allows users to rent and return cars while handling customer information, payment processing, penalty/refund logic, and age validation based on IC numbers. All data is stored and retrieved from local text files (`CustomerDetails.txt`).

## 🧾 Features

### 1. Car Rental (Rent)
- Displays available car brands and models with specifications.
- Allows users to:
  - Select a car.
  - Enter personal details (name, IC, phone number).
  - Validate IC number for age check (minimum age: 18).
  - Validate phone number.
  - Choose rental start date and rental duration.
  - Calculate rental cost based on selected car's price and days.
  - Accept multiple payments and calculate balance if overpaid.
  - Save all customer details in `CustomerDetails.txt`.

### 2. Return Car (Return)
- Reads customer rental data from file.
- Prompts for return date.
- Calculates actual rental duration.
- Compares with original rental period:
  - If exceeded: applies penalty (RM100 per extra day).
  - If earlier: calculates refund (RM100 per unused day).
- Handles prior balance from the customer.
- Requests additional payment if balance is insufficient.

### 3. Input Validation
- IC Number: Must be 12 digits and user must be 18+ years old.
- Phone Number: 10 or 11 digits only.
- Payment amount is validated.
- Date input (day, month) validated within ranges.

### 4. File Handling
- Stores and retrieves customer details from `CustomerDetails.txt`.

## 📁 File Structure

- `main.cpp` - Main logic of the car rental system.
- `CustomerDetails.txt` - Auto-generated file storing customer rental and payment info.

## 💻 Requirements
- C++ Compiler (e.g. g++)
- Runs on Windows (uses `system("CLS")` for console clearing)

## 🛠 Compilation & Run (Windows CLI)
```bash
g++ main.cpp -o car_rental
./car_rental

