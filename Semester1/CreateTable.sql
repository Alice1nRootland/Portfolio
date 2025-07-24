-- Student Table
CREATE TABLE Student (
  StudentID VARCHAR2(100) PRIMARY KEY,
  StudentName VARCHAR2(100),
  StudentEmail VARCHAR2(100) UNIQUE,
  Student_Status VARCHAR2(20)
);

-- Tutor Table
CREATE TABLE Tutor (
  TutorID NUMBER PRIMARY KEY,
  TutorName VARCHAR2(100),
  TutorNumphone VARCHAR2(15),
  Tutor_Email VARCHAR2(100) UNIQUE,
  Salary NUMBER(10,2)
);

-- Subject Table
CREATE TABLE Subject (
  SubjectCode VARCHAR2(10) PRIMARY KEY,
  SubjectName VARCHAR2(100),
  Fee NUMBER(10,2)
);

-- Class Table (using straight double quotes)
CREATE TABLE "Class" (
  ClassID NUMBER PRIMARY KEY,
  ClassLocation VARCHAR2(100),
  TutorID NUMBER,
  SubjectCode VARCHAR2(10),
  CONSTRAINT fk_class_tutor FOREIGN KEY (TutorID) REFERENCES Tutor(TutorID),
  CONSTRAINT fk_class_subject FOREIGN KEY (SubjectCode) REFERENCES Subject(SubjectCode)
);

-- Attendance Table (must use "Class" in quotes)
CREATE TABLE Attendance (
  AttendanceID NUMBER PRIMARY KEY,
  StudentID VARCHAR2(100),
  ClassID NUMBER,
  AttendanceStatus VARCHAR2(20),
  AttendanceDate DATE,
  CONSTRAINT fk_attendance_student FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
  CONSTRAINT fk_attendance_class FOREIGN KEY (ClassID) REFERENCES "Class"(ClassID)
);

-- Payment Table
CREATE TABLE Payment (
  PaymentNo NUMBER PRIMARY KEY,
  StudentID VARCHAR2(100),
  SubjectCode VARCHAR2(10),
  PaymentStatus VARCHAR2(20),
  PaymentAmount NUMBER(10,2),
  CONSTRAINT fk_payment_student FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
  CONSTRAINT fk_payment_subject FOREIGN KEY (SubjectCode) REFERENCES Subject(SubjectCode)
);

-- Enrollment Table
CREATE TABLE Enrollment (
  StudentID VARCHAR2(100),
  ClassID NUMBER,
  Enrollment_date DATE,
  PRIMARY KEY (StudentID, ClassID),
  CONSTRAINT fk_enrollment_student FOREIGN KEY (StudentID) REFERENCES Student(StudentID),
  CONSTRAINT fk_enrollment_class FOREIGN KEY (ClassID) REFERENCES "Class"(ClassID)
);
