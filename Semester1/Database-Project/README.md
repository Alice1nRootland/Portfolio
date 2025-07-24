
# 🏫 Tuition Centre Management System – Oracle APEX Database Project

This project is a fully functional Tuition Centre Management System designed to streamline and digitalize the operations of a tuition centre. Built using Oracle APEX and SQL, the system replaces manual, paper-based processes with a structured digital database that improves accuracy, accessibility, and efficiency.

## 🎯 Objectives
- Reduce paper usage by digitalizing student and tutor records
- Minimize data redundancy and loss
- Simplify data retrieval and report generation
- Enable secure and structured management of tuition centre operations

## 🧠 Problem Solved
Manual systems often suffer from:
- Excessive physical storage (file cabinets, racks)
- Unclear and unreliable payment tracking
- Time-consuming data tracing and report generation
- Repetitive data entry into external tools like Excel

This system solves these issues by centralizing all data in a relational database with normalized tables and foreign key relationships.

## 👥 Target Users & Scope

### 👨‍🏫 Tutors
- View class schedules
- Access student lists
- Mark attendance

### 👩‍🎓 Students
- Manage personal profiles
- Enroll in subjects
- View attendance and payment status

### 🧑‍💼 Admins
- Manage users (students, tutors)
- Create and manage class timetables
- Record and track payments
- Monitor attendance

## 🧩 Proposed Modules
- **Student Registration Module**: Add new students, tutors, and subjects; store personal details
- **Scheduling Module**: Create and edit class timetables; prevent tutor/class clashes
- **Attendance Module**: Tutors mark attendance online; system updates records instantly
- **Payment Module**: Generate invoices, record payments, and alert students about unpaid fees

## 🎯 Expected Outcome
- A centralized system that allows admins, tutors, and students to access relevant information based on their roles
- Reduced paperwork and improved data organization
- Faster access to student and tutor records
- Smooth registration, scheduling, payment tracking, and attendance recording

## 🛠️ Technologies Used
- Oracle APEX
- SQL (PL/SQL)

## 📄 Files Included
- `tables.sql`: All CREATE TABLE statements
- `insert_data.sql`: Sample INSERT statements
- `erd.png`: Entity Relationship Diagram

## 📸 ERD Diagram
![ERD Diagram](erd.png)

## 🧪 How to Run
1. Open [Oracle APEX](https://apex.oracle.com/)
2. Run `tables.sql` to create the schema
3. Run `insert_data.sql` to populate sample data
4. Build your APEX app using the created tables

## 👤 Author
Faez | Cybersecurity Student | Malaysia
