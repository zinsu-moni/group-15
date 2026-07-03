# Wage Calculator: Lecturer Questions & Preparation Guide
A complete list of common questions a lecturer might ask about your project, plus sample answers!

---

## Table of Contents
- [🎯 Design & Architecture](#-design--architecture)
- [🏗️ Classes & OOP](#-classes--oop)
- [🛡️ Input Handling & Validation](#-input-handling--validation)
- [🧮 Calculations & Logic](#-calculations--logic)
- [📝 C++ Best Practices](#-c-best-practices)
- [🔧 Build System & Project Structure](#-build-system--project-structure)
- [🚀 Improvements & Extensions](#-improvements--extensions)

---

## 🎯 Design & Architecture

### 1. Why did you use object-oriented programming (OOP) instead of writing everything in one file?
**Answer:**
OOP makes the code organized, maintainable, and reusable! Each class has a single, clear job (like InputHandler only handles input, WageCalculator only does math). If I need to update something later (like the tax rate), I only have to change it in one place—not hunt through a messy single file. It also follows the "separation of concerns" principle, which makes the code easier to read and debug!

---

### 2. What is "separation of concerns" and how does your project implement it?
**Answer:**
"Separation of concerns" means each part of the code handles one specific job, not multiple. My project does this with:
- InputHandler: Only talks to the user and gets input
- InputValidator: Only checks if input is valid
- Employee: Only stores employee data
- WageCalculator: Only does the math
- Payslip: Only formats and displays the payslip
This way, a bug in one part is less likely to break another part!

---

### 3. Why did you split code into .h (header) and .cpp (implementation) files?
**Answer:**
Header files (.h) are like a "table of contents"—they declare what classes/functions exist, but not how they work. Implementation files (.cpp) have the actual code! This:
1. Makes compilation faster (if I change one .cpp file, I don't have to recompile everything)
2. Hides implementation details (encapsulation!)
3. Lets other files use the classes without seeing all the code

---

## 🏗️ Classes & OOP

### 4. What does the `Employee` class do, and what data does it store?
**Answer:**
The `Employee` class models a real employee! It stores:
- Name, ID, Department
- Hourly rate, Hours worked
It has getters (safe read-only access to data) and setters (change data with built-in validation—like making sure an ID is positive).

---

### 5. What does `const` mean in your getters (e.g., `std::string getName() const`)?
**Answer:**
The `const` keyword means "this function won't change the object!" It's a safety feature—so when we call `employee.getName()`, we know it won't accidentally alter the employee's data. It also lets us use these functions with `const Employee` objects!

---

### 6. What is encapsulation, and how does your project use it?
**Answer:**
Encapsulation means hiding internal data and only letting users interact with it through controlled methods. My `Employee` class does this by making all member variables private! You can't change `name` or `hourlyRate` directly—you have to use the setters, which validate the data first! This prevents bugs like accidentally setting a negative hourly rate.

---

## 🛡️ Input Handling & Validation

### 7. How does your program handle invalid input (like letters instead of numbers)?
**Answer:**
When we read input with `std::cin`, if the user enters something wrong (like "abc" for a number), `std::cin` goes into an error state. We fix this by:
1. `std::cin.clear()`: Resets the error state
2. `std::cin.ignore(...)`: Throws away all the bad input in the buffer
Then we ask the user to try again!

---

### 8. Why did you add maximum value limits (like max ID of 999999)?
**Answer:**
To prevent mistakes (like a user accidentally entering 100000 instead of 100) and make the program robust! Extremely large numbers can cause unexpected behavior (like integer overflow), so setting reasonable limits keeps everything safe and predictable.

---

### 9. What's the point of having both InputHandler AND InputValidator?
**Answer:**
Single responsibility principle! InputValidator only knows how to check if data is valid (it doesn't talk to the user). InputHandler only knows how to talk to the user and use InputValidator to check the input. This way, if I need to use validation logic in another program, I can reuse InputValidator without bringing all the input-handling code with it!

---

## 🧮 Calculations & Logic

### 10. What's the formula for overtime pay in your program?
**Answer:**
Overtime pay = max(hours worked - 40, 0) × 1.5 × hourly rate
We use `std::max(hours - 40, 0)` to make sure we don't calculate negative overtime if someone works less than 40 hours!

---

### 11. Why is the tax rate a `static constexpr` in `WageCalculator`?
**Answer:**
`static constexpr` means it's a compile-time constant—it never changes, and it's shared by all WageCalculator objects! This is good practice because:
1. It's clear what the tax rate is
2. It's easy to update later (just change the number in one place!)
3. It's efficient (the compiler can optimize it)
4. It can't be accidentally changed at runtime

---

### 12. How do you calculate total deductions and net pay?
**Answer:**
Total deductions = tax (5% of gross pay) + pension + loan + insurance + other
Net pay = gross pay - total deductions

---

## 📝 C++ Best Practices

### 13. Did you use any C++17 features? If so, why?
**Answer:**
Yes! We used C++17 as our standard (set in Makefile with `-std=c++17`). We also used lambda functions in InputHandler (the `[this](int value) { ... }` parts)—lambdas make it easy to pass small validation functions directly where we need them, without writing separate named functions!

---

### 14. How do you prevent memory leaks in your code?
**Answer:**
We don't use any dynamic memory allocation (`new`/`delete`) in this program—all objects are created on the stack! That means C++ automatically cleans them up when they go out of scope, so there's no risk of memory leaks. We also use RAII (Resource Acquisition Is Initialization) by default with stack-allocated objects!

---

### 15. What is RAII, and how does it apply here?
**Answer:**
RAII stands for "Resource Acquisition Is Initialization"—it means resources (like memory, files, etc.) are tied to object lifetimes. In our program, all our objects are stack-allocated, so their destructors run automatically when they go out of scope, cleaning up any resources they own (though in our simple program, there's no special cleanup needed)!

---

## 🔧 Build System & Project Structure

### 16. Why did you provide both a Makefile and CMakeLists.txt?
**Answer:**
Make is simple and widely available on macOS/Linux, but it doesn't work as well on Windows. CMake is cross-platform—it can generate Makefiles, Visual Studio projects, or whatever build system is needed for the OS! Having both makes the project easy to compile on any platform!

---

### 17. What is the purpose of `main.cpp`?
**Answer:**
`main.cpp` is the entry point of the program—it orchestrates the whole thing! It:
1. Creates an InputHandler to get user input
2. Creates an Employee from the input
3. Gets deduction input
4. Creates a WageCalculator to do the math
5. Creates a Payslip and displays it

---

### 18. What's the point of the `Utils.h/cpp` files if they're empty?
**Answer:**
They're a placeholder for future utility functions! If I want to add things like date handling, string formatting, or file saving later, I can put them in Utils without cluttering up other classes. It's a good practice to plan for expansion!

---

## 🚀 Improvements & Extensions

### 19. What's one thing you'd add or improve about this program if you had more time?
**Answer:** (Pick one or more!)
1. **Save payslips to a text file:** So users can keep records
2. **Multiple payslips menu:** Let users calculate multiple payslips without restarting
3. **Tax brackets:** Instead of a flat 5%, use real tax brackets
4. **Unit tests:** Write tests to make sure calculation functions always work correctly
5. **GUI:** Add a graphical user interface with Qt or SFML
6. **Deduction presets:** Let users save common deduction sets

---

### 20. How would you add a feature to save payslips to a text file?
**Answer:**
I'd add a `saveToFile(const std::string& filename)` method to the Payslip class! It would use `std::ofstream` to write the same formatted text that `display()` prints, but to a file instead of the console. I'd also add validation to make sure the filename is valid and the file opens correctly!

---

### 21. How would you handle multiple employees instead of just one?
**Answer:**
I'd:
1. Add a menu loop in `main()` that lets users keep entering employees
2. Create a `std::vector<Employee>` or `std::vector<Payslip>` to store all the employees/payslips
3. Add options like "Add employee", "View all payslips", "Save all payslips to file", and "Exit"

---

## Bonus: Quick Recap of Key Features to Mention
- ✅ Object-oriented design with single-responsibility classes
- ✅ Robust input validation with retry logic
- ✅ Const-correctness
- ✅ No manual memory management (stack-only allocation)
- ✅ Cross-platform support
- ✅ Clear, formatted output
- ✅ Well-documented code

---

## 💡 Tip for Your Presentation
Walk through the program flow step-by-step:
1. User runs program
2. InputHandler asks for employee info
3. InputValidator checks every answer
4. Employee object is created
5. InputHandler asks for deductions
6. WageCalculator does the math
7. Payslip is displayed
This shows you really understand how the code connects together!