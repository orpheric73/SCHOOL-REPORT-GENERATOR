# 📚 SCHOOL-REPORT-GENERATOR
# 📌 Overview
School Report Generator is a structured C program that manages academic data and automatically generates formatted RTF reports.
It supports:
- Multiple classes
- Multiple students per class
- Multiple subjects per student
- Multiple grades per subject
- Weighted averages
- Automatic statistical analysis
- Folder and file generation

The project demonstrates advanced use of dynamic memory allocation, nested structures, and file system manipulation.
# ⚙️ Features
- Multi-class management
- Multi-student management
- Multi-subject system
- Weighted average calculation
- Subject validation system
- PASS / FAIL decision (≥ 12)
- Highest & lowest subject detection
- Highest & lowest student per class
- Automatic folder creation
- Automatic RTF report generation
- Cross-platform compatibility (Windows/Linux)
# 🖥 Compilation
- Windows (MinGW)
   - gcc main.c -o report.exe
- Linux
   - gcc main.c -o report
# ▶ Execution
- Windows
    - report.exe
- Linux
    - ./report
# 🧮 Grading Rules
- Grades range: 0 – 20
- Subject validated if average ≥ 12
- Student passes if general mean ≥ 12
# 🛡 Memory Management
The program uses:
- Calloc() for dynamic allocation
- Multi-level nested memory handling
- Proper free() calls to prevent leaks
# 📄 RTF Reports Include
- School name and academic year
- Class statistics
- Student statistics
- Subject details
- Weighted averages
- Final decision
- Structured formatting
# 🎓 Educational Value
This project demonstrates:
- Advanced dynamic memory management
- Nested data structures
- File handling in C
- Cross-platform directory creation
- Structured program logic
- Error handling
- Statistical computation
- Suitable for:
- University-level C programming
- Data structures practice
- File system manipulation training
- Academic evaluation system simulation
# 🚀 Future Improvements
- Refactor repeated memory cleanup into functions
- Improve error-handling centralization
- Modularize into multiple source files
- Add input validation abstraction
- Add CSV or PDF export support
# 📜 License
This project is licensed under the MIT License - see the LICENSE file for details.
