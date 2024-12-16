# Bank Data Management System

This is a simple console-based Bank Account Management System implemented in C++. The system allows users to create accounts, deposit and withdraw money, and check account details. The data is persisted using file handling in C++.

## Features

1. **Create Account**:
   - Generates a unique account number.
   - Collects user details such as name, father's name, Aadhar number, phone number, email, and initial deposit amount.
   - Saves the data to a file (`data.txt`).

2. **Deposit Amount**:
   - Allows the user to deposit money into their account.
   - Updates the account balance in the file.

3. **Withdraw Amount**:
   - Allows the user to withdraw money from their account.
   - Updates the account balance in the file.

4. **Check Account Info**:
   - Displays detailed information about the account, including the current balance.

## File Structure

- **`data.txt`**: Stores the account details of all users.
- **`data1.txt`**: Temporary file used for updating account details.

## How to Run

1. Clone the repository:
    ```bash
    git clone https://github.com/your-username/Bank_Data_Management_System.git
    cd Bank_Data_Management_System
    ```

2. Compile the program using a C++ compiler:
    ```bash
    g++ -o bank_management main.cpp
    ```

3. Run the program:
    ```bash
    ./bank_management
    ```

## Usage

### Main Menu

1. **Login Account**:
   - Enter your account number to access account operations.
   - Options:
     - Deposit Amount
     - Withdraw Amount
     - Check Account Info

2. **Create Account**:
   - Enter your details to create a new account.
   - Save the generated account number for future access.

3. **Exit**:
   - Exit the application.

### Inside Account Operations

- Deposit or withdraw money and check your account details after logging in with your account number.

## Example Workflow

1. Start the program.
2. Choose **Create Account** and fill in your details.
3. Use the generated account number to log in.
4. Perform operations such as deposit, withdraw, or check account info.

## Code Highlights

- **Random Account Number Generation**:
  - Generates a unique account number using `rand()` and `time()`.

- **File Handling**:
  - Uses `fstream` to read and write account details from/to files.

- **Data Persistence**:
  - All account data is stored in `data.txt`, ensuring data is retained between program runs.

## Limitations

- The program does not handle concurrency or multiple users accessing the system simultaneously.
- Limited error handling (e.g., does not validate input data rigorously).

## Future Enhancements

- Add encryption for sensitive data.
- Implement a more robust file format (e.g., JSON or database integration).
- Add input validation and error handling.
- Provide a graphical user interface (GUI).

## Dependencies

- Standard C++ libraries: `<iostream>`, `<fstream>`, `<cstdlib>`, `<ctime>`.


