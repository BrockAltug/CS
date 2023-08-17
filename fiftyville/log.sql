-- Keep a log of any SQL queries you execute as you solve the mystery.

--find the date the crime took place and select description from crime scene report --was stolen from the bakery
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

--get interviews from people on the date of the crime related to the bakery
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

--interview says within 10 mins thief took a car and left the parking lot --bakery security logs
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
Where bakery_security_logs.year = 2021;


























