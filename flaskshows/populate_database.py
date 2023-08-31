import sqlite3

# Connect to the database (will create if not exists)
conn = sqlite3.connect('shows.db')
cursor = conn.cursor()

# Create the 'shows' table
cursor.execute('''
    CREATE TABLE IF NOT EXISTS shows (
        id INTEGER PRIMARY KEY,
        title TEXT,
        year INTEGER
    )
''')

# Sample show data
shows_data = [
    (1, 'Stranger Things', 2016),
    (2, 'Game of Thrones', 2011),
    (3, 'Breaking Bad', 2008),
    (4, 'Friends', 1994),
    (5, 'The Office', 2005),
    (6, 'The Simpsons', 1989),
    (7, 'Black Mirror', 2011),
    (8, 'The Crown', 2016),
    (9, 'Sherlock', 2010),
    (10, 'Fargo', 2014),
    (11, 'The Mandalorian', 2019),
    (12, 'The Big Bang Theory', 2007),
    (13, 'Stranger Things', 2016),
    (14, 'Chernobyl', 2019),
    (15, 'Friends', 1994),
    (16, 'Money Heist', 2017),
    (17, 'Breaking Bad', 2008),
    (18, 'The Witcher', 2019),
    (19, 'Parks and Recreation', 2009),
    (20, 'Brooklyn Nine-Nine', 2013),
    (21, 'Rick and Morty', 2013),
    (22, 'Westworld', 2016),
    (23, 'The Office', 2005),
    (24, 'The Crown', 2016),
    (25, 'Narcos', 2015)
]

# Insert sample data into the table
cursor.executemany('INSERT INTO shows (id, title, year) VALUES (?, ?, ?)', shows_data)

# Commit changes and close the connection
conn.commit()
conn.close()

print("Database 'shows.db' created and populated with manual show data.")
