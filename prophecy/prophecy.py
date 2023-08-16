#cd ./prohpecy
#sqlite3 roster.db
#.schema
#SELECT * FROM students;
#SELECT student_name, house FROM students WHERE house IS 'Slytherin';
#SELECT student_name, house FROM students WHERE student_name LIKE "%Potter" --searches for any character similar before Potter
##SELECT student_name, house FROM students WHERE student_name LIKE "Harry%" --searches for any characters similar after Harry