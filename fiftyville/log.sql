-- Keep a log of any SQL queries you execute as you solve the mystery.

--find the date the crime took place
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

--find interviews from witnesses on the date the crime happened
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;

--gets all atm transactions at the location from witnesses (witness says theif will board earliest plane the next day and accessed ATM)
SELECT * FROM atm_transactions WHERE year = 2021 AND month = 7 AND day = 28 AND atm_location = 'Leggett Street';

--gets all earliest flights leaving the next day
SELECT * FROM flights WHERE year = 2021 AND month = 7 AND day = 29 ORDER BY hour, minute LIMIT 1;

--gets all of the passanger information
SELECT p.name, p.phone_number, ps.seat FROM passengers AS ps JOIN people AS p ON ps.passport_number = p.passport_number WHERE ps.flight_id = 36;

--Retrieve license plate from the people where phone number is matching from flights
SELECT license_plate FROM people WHERE phone_number = '(066) 555-9701'; --M51FA04 license plates
SELECT license_plate FROM people WHERE phone_number = '(130) 555-0289'; --G412CB7
SELECT license_plate FROM people WHERE phone_number = '(367) 555-5533'; --94KL13X
SELECT license_plate FROM people WHERE phone_number = '(328) 555-1152'; --130LD9Z
SELECT license_plate FROM people WHERE phone_number = '(499) 555-9472'; --0NTHK55
SELECT license_plate FROM people WHERE phone_number = '(286) 555-6063'; --1106N58
SELECT license_plate FROM people WHERE phone_number = '(389) 555-5198'; --4328GD8

--To retrieve security logs from the bakery security table where the day, month, year, and license plate match
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = 'M51FA04';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = 'G412CB7';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '94KL13X';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '130LD9Z';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '0NTHK55';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '1106N58';
SELECT * FROM bakery_security_logs WHERE day = 28 AND month = 7 AND year = 2021 AND license_plate = '4328GD8';

--thief made a phone call for less than 1 minute
SELECT * FROM phone_calls WHERE ((caller = '(066) 555-9701' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(066) 555-9701' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;
SELECT * FROM phone_calls WHERE ((caller = '(130) 555-0289' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(130) 555-0289' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;
SELECT * FROM phone_calls WHERE ((caller = '(367) 555-5533' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(367) 555-5533' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;
SELECT * FROM phone_calls WHERE ((caller = '(328) 555-1152' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(328) 555-1152' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;
SELECT * FROM phone_calls WHERE ((caller = '(499) 555-9472' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(499) 555-9472' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;
SELECT * FROM phone_calls WHERE ((caller = '(286) 555-6063' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(286) 555-6063' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;
SELECT * FROM phone_calls WHERE ((caller = '(389) 555-5198' AND year = 2021 AND month = 7 AND day = 28) OR (receiver = '(389) 555-5198' AND year = 2021 AND month = 7 AND day = 28)) AND duration < 60;






















