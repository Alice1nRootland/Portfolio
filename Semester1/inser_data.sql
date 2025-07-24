-- Insert Tutors
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (100, 'Charles', '01125467894', 'charles@gmail.com', 5000);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (101, 'Puan Zainab', '01344569821', 'zainab@gmail.com', 4000);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (102, 'Mr. Lim', '01799874521', 'lim.tutor@gmail.com', 4200);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (103, 'Mdm Tan', '01233445566', 'mdmtan@gmail.com', 5200);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (104, 'Encik Rahman', '01022334455', 'rahman77@gmail.com', 4800);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (105, 'Miss Chong', '01655667788', 'chong.miss@gmail.com', 5800);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (106, 'Dr. Siva', '01911223344', 'siva.dr@gmail.com', 6000);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (107, 'Pn. Aishah', '01866778899', 'aishah.pn@gmail.com', 6000);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (108, 'Mr. Wong', '01722334455', 'wong.mr@gmail.com', 5800);
INSERT INTO Tutor (TutorID, TutorName, TutorNumphone, Tutor_Email, Salary) VALUES (109, 'Mdm Lee', '01455667788', 'lee.mdm@gmail.com', 6300);

-- Insert Classes
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (300, 'Lab 1', 100, '201');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (301, 'Lab 2', 100, '200');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (302, 'Lab 3', 102, '202');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (303, 'Lab 4', 103, '203');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (304, 'Lab 5', 104, '204');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (305, 'Lab 6', 105, '200');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (306, 'Lab 7', 106, '205');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (307, 'Lab 8', 107, '206');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (308, 'Lab 9', 108, '207');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (309, 'Lab 10', 109, '208');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (310, 'Lab 10', 101, '209');
INSERT INTO "Class" (ClassID, ClassLocation, TutorID, SubjectCode) VALUES (311, 'Lab 7', 101, '209');

-- Insert Attendance
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (400, '001', 300, 'Attend', TO_DATE('20/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (401, '002', 300, 'Attend', TO_DATE('21/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (402, '001', 302, 'Absent', TO_DATE('23/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (403, '004', 303, 'Attend', TO_DATE('27/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (404, '005', 304, 'Attend', TO_DATE('24/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (405, '006', 305, 'Absent', TO_DATE('22/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (406, '008', 306, 'Attend', TO_DATE('25/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (407, '008', 307, 'Absent', TO_DATE('26/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (408, '009', 308, 'Attend', TO_DATE('28/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (409, '010', 309, 'Absent', TO_DATE('29/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (410, '007', 307, 'Absent', TO_DATE('29/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (411, '007', 301, 'Absent', TO_DATE('30/05/2024', 'DD/MM/YYYY'));
INSERT INTO Attendance (AttendanceID, StudentID, ClassID, AttendanceStatus, AttendanceDate) VALUES (412, '003', 306, 'Absent', TO_DATE('29/05/2024', 'DD/MM/YYYY'));

-- Insert Payments
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (500, '001', '201', 'Paid', 35);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (501, '002', '201', 'Paid', 35);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (502, '003', '205', 'Unpaid', 50);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (503, '004', '203', 'Paid', 25);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (504, '005', '204', 'Unpaid', 28);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (505, '006', '200', 'Paid', 40);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (506, '007', '200', 'Unpaid', 40);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (507, '008', '205', 'Paid', 50);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (508, '009', '207', 'Paid', 42);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (509, '010', '208', 'Unpaid', 40);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (510, '001', '202', 'Paid', 30);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (511, '007', '206', 'Unpaid', 45);
INSERT INTO Payment (PaymentNo, StudentID, SubjectCode, PaymentStatus, PaymentAmount) VALUES (512, '008', '206', 'Unpaid', 45);

-- Insert Enrollments
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('002', 300, TO_DATE('01/04/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('001', 302, TO_DATE('02/04/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('004', 303, TO_DATE('02/04/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('005', 304, TO_DATE('03/04/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('006', 305, TO_DATE('03/04/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('003', 306, TO_DATE('05/04/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('007', 301, TO_DATE('01/05/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('007', 307, TO_DATE('06/05/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('008', 306, TO_DATE('04/05/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('008', 307, TO_DATE('06/05/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('009', 308, TO_DATE('05/05/2024', 'DD/MM/YYYY'));
INSERT INTO Enrollment (StudentID, ClassID, Enrollment_date) VALUES ('010', 309, TO_DATE('06/05/2024', 'DD/MM/YYYY'));
