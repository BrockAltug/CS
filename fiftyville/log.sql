-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Find the crime scene report for the given date and location
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

-- Find interviews from witnesses for the specified crime scene report
SELECT * FROM interviews WHERE crime_id = 295;

-- Find information about the accomplice
--SELECT * FROM accomplices WHERE name = '<accomplice_name>';



