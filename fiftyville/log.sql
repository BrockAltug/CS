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

--witness says phone call for less than 1 minute, earliest flight the next day. other person on phone to purchase the flight ticket
--find caller, reciever phone call less than 1 minute on the day

--alter phone call tables to add caller and reciever names
ALTER TABLE phone_calls
ADD caller_name text;

ALTER TABLE phone_calls
ADD receiver_name text;
--update phone calls to get caller and receiver names
UPDATE phone_calls
SET caller_name = people.name
FROM people
WHERE phone_calls.caller = people.phone_number;

UPDATE phone_calls
SET receiver_name = people.name
FROM people
WHERE phone_calls.receiver = people.phone_number;


--now has caller and receiver name displaying as well as calling and receiving phone numbers
SELECT caller, caller_name, receiver, receiver_name FROM phone_calls
WHERE year = 2021
AND month = 7
AND day = 28
AND duration < 60;


































