-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;


SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;

SELECT p.name, ps.seat FROM passengers AS ps JOIN people AS p ON ps.passport_number = p.passport_number WHERE ps.flight_id = 36;













