-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Keep a log of any SQL queries you execute as you solve the mystery.

--cd fiftyville
--sqlite3 fiftyville.db
--cat log.sql | sqlite3 fiftyville.db


--find the date the crime took place and select description from crime scene report --was stolen from the Humphrey Street bakery at 10:15am
SELECT description FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = 'Humphrey Street';

--get interviews from people on the date of the crime related to the bakery
SELECT transcript FROM interviews WHERE year = 2021 AND month = 7 AND day = 28 AND transcript LIKE '%bakery%';

--interview says within 10 mins thief took a car and left the parking lot --bakery security logs retrieves activities, license plates, and names from security logs
SELECT bakery_security_logs.activity, bakery_security_logs.license_plate, people.name FROM people
JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
Where bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25;

--8 possible suspects

--get the peoples name and atm transactions type from people, joining bank accounts on person id and atm transactions on account number searching for the date and location from witnesses
SELECT people.name, atm_transactions.transaction_type FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number =
bank_accounts.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw";

--get the caller and reciever information on calls less than 1 minute on the date of the crim
--SELECT caller, caller_name, receiver, receiver_name  FROM phone_calls
--WHERE year = 2021
--AND month = 7
--AND day = 28
--AND duration < 60;

--add for caller name and reciever name to phone calls
--ALTER TABLE phone_calls
--ADD caller_name text;

--ALTER TABLE phone_calls
--ADD receiver_name text;


--update phone calls to get caller and receiver 
UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;

--get the caller and reciever information on calls less than 1 minute on the date of the crim
SELECT caller, caller_name, receiver, receiver_name  FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;

--get origin and destination based on time (1 day after crime earliest flight that day) --returns ID 36 ONLY
SELECT id, hour, minute, origin_airport_id, destination_airport_id
FROM flights
WHERE year = 2021
AND month = 7
AND day = 29
ORDER BY hour ASC
LIMIT 1;
--origin 8
--destination 4

--left from Fiftyville to New York City
SELECT * FROM airports;


--8 possible suspects
SELECT flights.destination_airport_id, name, phone_number, license_plate from people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE flights.id = 36
ORDER BY flights.hour ASC;


--CS50 duck theft took place at 10:15 at Humphrey Street Bakery
--security logs show 8 possible suspects
--atm transactions show 8 possible suspect
--call log shows 9 possible suspects
--flight shows 8 possible suspects
--get the name
SELECT name FROM people
JOIN passengers ON people.passport_number = passengers.passport_number
JOIN flights ON flights.id = passengers.flight_id
WHERE (flights.year = 2021 AND flights.month = 7 AND flights.day = 29 AND flights.id = 36)
AND name IN
(SELECT phone_calls.caller_name FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60)
AND name IN
(SELECT people.name FROM people
JOIN bank_accounts ON bank_accounts.person_id = people.id
JOIN atm_transactions ON atm_transactions.account_number =
bank_accounts.account_number
WHERE atm_transactions.year = 2021
AND atm_transactions.month = 7
AND atm_transactions.day = 28
AND atm_location = "Leggett Street"
AND atm_transactions.transaction_type = "withdraw")
AND name IN
(SELECT people.name FROM people JOIN bakery_security_logs ON bakery_security_logs.license_plate = people.license_plate
Where bakery_security_logs.year = 2021
AND bakery_security_logs.month = 7
AND bakery_security_logs.day = 28
AND bakery_security_logs.hour = 10
AND bakery_security_logs.minute >= 15
AND bakery_security_logs.minute <= 25);








































