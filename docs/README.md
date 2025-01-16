# ROCK the SHOP

## Project Description

**ROCK the SHOP** is a management system for an online store specializing in rock products. It manages product inventory, customer orders, and store personnel, offering complex functionalities for order processing and report generation.

---

## Table of Contents
- [Main Features](#main-features)
- [Project Structure](#project-structure)
- [Classes and Architecture](#classes-and-architecture)
- [How to Use](#how-to-use)
- [Reporting](#reporting)
- [System Requirements](#system-requirements)
- [Feedback and Contributions](#feedback-and-contributions)

---

## Main Features

1. **Employee Management**
   - Add, delete, modify, and display employee data.
   - Dynamic salary calculation based on seniority, employee type, and bonuses.
   - Manage hiring and resignations.
   - Automatic validation of employee data (e.g., unique ID, valid SSN).

2. **Product Inventory Management**
   - Add, delete, and modify products.
   - Dynamic price calculation (including packaging and shipping costs).
   - Store and manage product categories:
     - Apparel.
     - Discs (CDs and vinyl records).
     - Vintage discs (with rarity coefficients).

3. **Order Processing**
   - Automatically receive orders and assign them to available operators.
   - Process orders with simulated execution time.
   - Prioritize completed orders based on total value.

4. **Reporting**
   - Generate detailed reports (.csv):
     - Employees with the highest number of processed orders.
     - Top 3 employees with the most valuable orders.
     - Top 3 employees with the highest salaries.
   - Monitor operator activity in real-time.

5. **Simulation and Testing**
   - Automatically populate with employees and products for testing purposes.
   - External files for simulating orders.

---

## Project Structure

### Folder Architecture:
- `src/` - Source code of the project and header files
- `data/` - Files for data and order initialization.
- `reports/` - Automatically generated report files.
- `docs/` - Extended documentation.

### Key Files:
- `main.cpp` - Application entry point.
- `Angajat.h`/`Angajat.cpp` - Classes for managing employees.
- `Produs.h`/`Produs.cpp` - Classes for managing products.
- `Comanda.h`/`Comanda.cpp` - Classes for managing orders and their flow.

---

## Classes and Architecture

### Main Classes
1. **`Angajat` Class** (base)
   - Attributes: unique ID, first name, last name, SSN, hire date.
   - Virtual methods for salary calculation, display, and SSN modification.
   - Derived classes:
     - `Manager`
     - `OrderOperator`
     - `Assistant`

2. **`Produs` Class** (base)
   - Attributes: unique code, name, stock quantity, base price.
   - Derived classes:
     - `ArtVestimentar`
     - `Disc` (with subclasses for CDs and vinyl records)
     - `VintageDisc` (rarity coefficient and "mint" condition).

3. **`Comanda` Class**
   - Holds a vector of product-quantity pairs.
   - Queues for order processing (based on date and priority).

### Main Functions:
- **Add employee/product.**
- **Modify and delete.**
- **Simulate order processing.**
- **Generate detailed reports.**

---

## How to Use

### Initial Setup
1. Clone the project:
```bash
git clone https://github.com/username/rock-the-shop.git
cd rock-the-shop
```
2. Compile the code:
```bash
g++ -std=c++17 src/*.cpp -o rock-the-shop
```
3. Run the application:
```bash
./rock-the-shop
 ```
   
## Main Functionalities
- Select desired options from the interactive menu.
- Enter data for employees, products, or orders as needed.
- View automatically generated reports in the `reports/` directory.


### Reporting

## Types of Reports Generated:
**Active Employees:**
  - Complete list of employees with personal details and current salaries.
**Processed Orders:**
  - Completed and pending orders.
**Top Performers:**
  - Employees with the most orders or the most valuable contributions.

## System Requirements
- **Compiler:** GCC 9+ with support for C++17.
- **Operating System:** Compatible with Linux, macOS, or Windows.
- **Disk Space:** Minimum 100 MB for project files and generated data.
- **RAM:** Minimum 2 GB (recommended 4 GB for complex simulations).
- **Libraries Used:** 
  - ctime – for managing dates and times.
  - fstream – for reading and writing files.
  - map and vector – for dynamic data structures.
  - algorithm – for sorting and manipulation operations.

---

## Feedback and Contributions

The CONTRIBUTING.md file provides details on how to contribute to the project.
For issues or suggestions, please open an [Issue](https://github.com/username/rock-the-shop/issues).

---

## License

This project is licensed under the MIT License. See the LICENSE file for details.



