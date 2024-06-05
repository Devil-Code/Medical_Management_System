# Medicine and Supplier Management System

## Overview

This Medicine and Supplier Management System is a console-based application designed to manage suppliers, medicines, purchases, sales, and more. The system supports adding, listing, searching, editing, and deleting supplier information, as well as managing medicine stock levels, purchases, and sales.

## Features

### Supplier Management

1. **Add Supplier**
   - Allows the user to add new suppliers by entering their name, surname, phone number, and the medicine they supply.

2. **List Suppliers**
   - Displays a list of all suppliers, including their names, contact numbers, and supplied medicines.

3. **Search Supplier**
   - **By Name**: Searches for a supplier by name and surname.
   - **By Phone Number**: Searches for a supplier by phone number.
   - **By Medicine**: Searches for suppliers providing a specific medicine.

4. **Edit Supplier**
   - **Edit Name**: Allows editing the supplier's name and surname.
   - **Edit Phone Number**: Allows editing the supplier's phone number.
   - **Edit Medicine**: Allows editing the medicine supplied by the supplier.

5. **Delete Supplier**
   - Allows the deletion of a supplier after confirmation.

### Medicine Management

1. **Purchase Medicine**
   - Adds stock to an existing medicine.

2. **Sale Medicine**
   - Reduces stock from an existing medicine.

3. **Search Medicine**
   - Searches for a medicine and displays its total stock.

4. **Edit Medicine**
   - Allows editing the stock amount of a medicine.

### User Interface

#### Main Menu
- Navigate to:
  - Supplier Management
  - Customer Management
  - Medicine Management
  - Billing

#### Supplier User Interface (SUI)
- Options to:
  - Add Supplier
  - List Suppliers
  - Search Supplier
  - Edit Supplier
  - Delete Supplier
  - Exit to Main Menu

#### Medicine User Interface (MUI)
- Options to:
  - Purchase Medicine
  - Sale Medicine
  - Search Medicine
  - Edit Medicine
  - Delete Medicine
  - Check Stock

### File Operations

- **supply.txt**: Stores supplier information including name, surname, phone number, and supplied medicine.
- **med.txt**: Stores medicine information including medicine name and total stock.

## Functions

### Supplier Management Functions

1. **sread()**
   - Reads supplier and medicine data from files and initializes the system.

2. **swrite()**
   - Writes the current state of supplier and medicine data back to files.

3. **sadd()**
   - Adds new suppliers to the system.

4. **slist()**
   - Lists all suppliers.

5. **ssearch_name()**
   - Searches suppliers by name and surname.

6. **ssearch_phno()**
   - Searches suppliers by phone number.

7. **ssearch_med()**
   - Searches suppliers by medicine.

8. **sedit_name()**
   - Edits the supplier's name and surname.

9. **sedit_phno()**
   - Edits the supplier's phone number.

10. **sedit_med()**
    - Edits the supplied medicine.

11. **sdel()**
    - Deletes a supplier.

### Medicine Management Functions

1. **mui()**
   - Provides the Medicine User Interface with options for managing medicine stock.

2. **mread()**
   - Reads medicine data from the file.

3. **purchase()**
   - Handles purchasing of medicine.

4. **sale()**
   - Handles the sale of medicine.

5. **msearch()**
   - Searches for medicine stock.

6. **medit()**
   - Edits the medicine stock.

7. **main_ui()**
   - Provides the main user interface for navigating the system.

## Getting Started

### Prerequisites

- A C compiler (e.g., GCC)

### Running the Application

1. Clone the repository or download the source code files.
2. Compile the code using a C compiler:
   ```
   gcc -o med_sup_mgmt main.c
   ```
3. Run the executable:
   ```
   ./med_sup_mgmt
   ```

### File Structure

- **main.c**: Contains the main logic and functions for the application.
- **supply.txt**: Data file for storing supplier information.
- **med.txt**: Data file for storing medicine information.

## Contributing

Contributions are welcome! Please open an issue or submit a pull request for any improvements or bug fixes.

## License

This project is licensed under the GNU General Public License v3.0 . See the LICENSE file for details.

## Contact Information

For any inquiries or issues, please contact:
- **Pritesh Gandhi**
- **Email**: pgandhi1412@gmail.com
- **GitHub**: [GitHubProfile](https://github.com/Devil-Code)

---

This updated `README.md` file provides a comprehensive overview of the features and functionality of the Medicine and Supplier Management System, along with instructions for getting started and contributing to the project.
