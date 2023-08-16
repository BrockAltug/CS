-- Define the students table
CREATE TABLE students (
    id INTEGER PRIMARY KEY,
    student_name TEXT,
    house_id INTEGER,
    FOREIGN KEY (house_id) REFERENCES houses(id)
);

-- Define the houses table
CREATE TABLE houses (
    id INTEGER PRIMARY KEY,
    house_name TEXT,
    head TEXT
);

-- Define the house_assignments table
CREATE TABLE house_assignments (
    student_id INTEGER,
    house_id INTEGER,
    PRIMARY KEY (student_id, house_id),
    FOREIGN KEY (student_id) REFERENCES students(id),
    FOREIGN KEY (house_id) REFERENCES houses(id)
);
