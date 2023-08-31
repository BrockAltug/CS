import sqlite3

conn = sqlite3.connect("store.db")
cursor = conn.cursor()

# Create the 'books' table
cursor.execute("""
    CREATE TABLE IF NOT EXISTS books (
        id INTEGER PRIMARY KEY,
        title TEXT NOT NULL,
        author TEXT NOT NULL,
        price REAL NOT NULL
    )
""")

# List of book data
books_data = [
    (1, 'The Great Gatsby', 'F. Scott Fitzgerald', 12.99),
    (2, 'To Kill a Mockingbird', 'Harper Lee', 10.50),
    (3, '1984', 'George Orwell', 11.25),
    (4, 'Pride and Prejudice', 'Jane Austen', 9.75),
    (5, 'The Catcher in the Rye', 'J.D. Salinger', 8.99),
    (6, 'The Hobbit', 'J.R.R. Tolkien', 10.99),
    (7, 'Brave New World', 'Aldous Huxley', 12.00),
    (8, 'Animal Farm', 'George Orwell', 7.25),
    (9, 'Lord of the Rings', 'J.R.R. Tolkien', 15.50),
    (10, 'Harry Potter and the Sorcerer\'s Stone', 'J.K. Rowling', 11.99),
    (11, 'The Hunger Games', 'Suzanne Collins', 9.50),
    (12, 'The Da Vinci Code', 'Dan Brown', 8.75),
    (13, 'The Shining', 'Stephen King', 9.25),
    (14, 'Gone with the Wind', 'Margaret Mitchell', 12.99),
    (15, 'Moby-Dick', 'Herman Melville', 10.25),
    (16, 'The Alchemist', 'Paulo Coelho', 7.99),
    (17, 'The Odyssey', 'Homer', 6.50),
    (18, 'Jane Eyre', 'Charlotte Bronte', 8.99),
    (19, 'One Hundred Years of Solitude', 'Gabriel Garcia Marquez', 11.75),
    (20, 'Frankenstein', 'Mary Shelley', 9.50),
    (21, 'The Picture of Dorian Gray', 'Oscar Wilde', 7.25),
    (22, 'The Road', 'Cormac McCarthy', 8.99),
    (23, 'The Kite Runner', 'Khaled Hosseini', 10.99),
    (24, 'The Lord of the Flies', 'William Golding', 7.50),
    (25, 'Wuthering Heights', 'Emily Bronte', 6.99),
]

# Insert data into the 'books' table
cursor.executemany("INSERT INTO books (id, title, author, price) VALUES (?, ?, ?, ?)", books_data)

# Commit changes and close the connection
conn.commit()
conn.close()

print("Database 'store.db' created and populated with data.")
