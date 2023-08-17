#cd ./prohpecy
#sqlite3 roster.db
#.schema
#SELECT * FROM students;
#SELECT student_name, house FROM students WHERE house IS 'Slytherin';
#SELECT student_name, house FROM students WHERE student_name LIKE "%Potter" --searches for any character similar before Potter
#SELECT student_name, house FROM students WHERE student_name LIKE "Harry%" --searches for any characters similar after Harry
#SELECT * FROM students ORDER BY house, student_name; --orders the list of students first by their house and then by the student name in alphabetical order
#SELECT COUNT(*) FROM students; --displays the number of rows
#SELECT COUNT(*) AS number_of_students FROM students; --assasigns count as number_of_students
#SELECT COUNT(*) FROM students WHERE house IS 'Slytherin'; --displays amount of students in the specified house
#SELECT COUNT(*) FROM students GROUP BY house; -- shows number of students grouped by house
#SELECT house, COUNT(*) FROM students GROUP BY house -- shows the name of the house first, and then the number of students grouped by house
#CREATE TABLE house (id INTEGER NOT NULL, house TEXT NOT NULL, head TEXT NOT NULL, PRIMARY KEY(id));  -- creates empty table for houses with subtables for id, house, and head
#INSERT INTO houses (house, head) VALUES ('Gryffindor', 'McGonagall'); -- inserts head and house database from students
#CREATE TABLE assignments (student_id INTEGER )