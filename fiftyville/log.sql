-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;


SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;

SELECT p.name, p.phone_number, ps.seat FROM passengers AS ps JOIN people AS p ON ps.passport_number = p.passport_number WHERE ps.flight_id = 36;

SELECT license_plate FROM people WHERE phone_number = '(066) 555-9701'; --M51FA04 license plates
SELECT license_plate FROM people WHERE phone_number = '(130) 555-0289'; --G412CB7
SELECT license_plate FROM people WHERE phone_number = '(367) 555-5533'; --94KL13X
SELECT license_plate FROM people WHERE phone_number = '(328) 555-1152'; --130LD9Z
SELECT license_plate FROM people WHERE phone_number = '(499) 555-9472'; --0NTHK55
SELECT license_plate FROM people WHERE phone_number = '(286) 555-6063'; --1106N58
SELECT license_plate FROM people WHERE phone_number = '(389) 555-5198'; --4328GD8

SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = 'M51FA04';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = 'G412CB7';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '94KL13X';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '130LD9Z';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '0NTHK55';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '1106N58';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '4328GD8';




















