import sqlite3
import random

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

# Generate random show data
def generate_random_show():
    show_title = f"Show {random.randint(1, 100)}"
    show_year = random.randint(1980, 2023)
    return (None, show_title, show_year)

# Generate 25 random shows
random_shows = [generate_random_show() for _ in range(25)]

# Insert random shows into the table
cursor.executemany('INSERT INTO shows (id, title, year) VALUES (?, ?, ?)', random_shows)

# Commit changes and close the connection
conn.commit()
conn.close()

print("Database 'shows.db' created and populated with random show data.")
