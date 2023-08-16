#cd ./prohpecy
#sqlite3 roster.db
#.schema
#SELECT * FROM students;
#SELECT student_name, house FROM students WHERE house IS 'Slytherin';
#SELECT student_name, house FROM students WHERE student_name LIKE "%Potter" --searches for any character similar before Potter
#SELECT student_name, house FROM students WHERE student_name LIKE "Harry%" --searches for any characters similar after Harry
#SELECT * FROM students ORDER BY house, student_name; --orders the list of students first by their house and then by the student name in alphabetical order