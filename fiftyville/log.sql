-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the crime scene report for the given date and location
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Find interviews from witnesses for the specified crime scene report
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

--3 witnesses say
--(1. within 10 minutes of the theft, the thief got into a car in the bakery parking lot)
--(2. before going to bakery thief withdrew money from LEGGET STREET atm)
SELECT * FROM atm_transactions WHERE atm_location = 'Leggett Street' AND year = 2021 AND month = 7 AND day = 28; --account number
--(3. thief made a phone call less than 1 minute after the robbery as they left bakery planning to take earliest flight out of the city the next day)
-- Find information about the accomplice based on interview taking the earliest flight out of Fiftyville the next day, and asked other person to purchase a flight ticket
SELECT * FROM flights WHERE month = 7 AND day = 29;





