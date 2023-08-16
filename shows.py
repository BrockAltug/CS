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
#SELECT title FROM people JOIN stars ON people.id = stars.person_id JOIN shows ON stars.show_id = shows.id WHERE name = `Steve Carell`;
#SELECT title FROM people, stars, shows WHERE people.id = stars.person_id AND stars.show_id = shows.id AND name = 'Steve Carell';
#SELECT * FROM people WHERE name LIKE 'Steve C%';       //shows all people whos names are with Steve C

#--------------------------------------------------
#Creating Index
#.timer on (type into sqlite)
#SELECT * FROM shows WHERE title = 'The Office';
#CREATE INDEX title_index on shows (title);        //creates new index
#SELECT * FROM shows WHERE title = 'The Office';   //this now runs much more quickly
#Unfortunately, indexing all columns would result in utilizing more storage space. Therefore, there is a tradeoff for enhanced speed.
