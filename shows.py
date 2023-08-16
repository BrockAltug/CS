#Helpful commands for the shows.db
#sqlite3 shows.db in terminal to use
#.schema to display each table

#In sqlite, we have five datatypes, including:

#  BLOB       -- binary large objects that are groups of ones and zeros
#  INTEGER    -- an integer
#  NUMERIC    -- for numbers that are formatted specially like dates
#  REAL       -- like a float
#  TEXT       -- for strings and the like

#SELECT * FROM people LIMIT 10;
#SELECT * FROM stars LIMIT 10;
#SELECT * FROM genres;
#SELECT * FROM genres WHERE genre = 'Comedy' LIMIT 10;
#SELECT * FROM shows WHERE id = 626124;
#SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy') LIMIT 10;
#SELECT title FROM shows WHERE id IN (SELECT show_id FROM genres WHERE genre = 'Comedy') ORDER BY title LIMIT 10;
#SELECT * FROM people WHERE name = 'Steve Carell';
#SELECT title FROM shows WHERE id IN (SELECT show_id FROM stars WHERE person_id = (SELECT * FROM people WHERE name = 'Steve Carell'));

#------------------------------------------------
#Joining Tables Together

#SELECT * FROM shows JOIN ratings on shows.id = ratings.show_id WHERE title = 'The Office';