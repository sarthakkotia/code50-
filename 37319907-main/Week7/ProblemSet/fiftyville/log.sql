-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Keep a log of any SQL queries you execute as you solve the mystery..t

--show all crime reports
SELECT * FROM crime_scene_reports;
--year =2021
SELECT * FROM crime_scene_reports WHERE year = 2021;
--month = 7
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7;
--day = 28
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28;
--street = "Humphery..."
SELECT * FROM crime_scene_reports WHERE year = 2021 AND month = 7 AND day = 28 AND street = "Humphrey Street";
| 295 | Humphrey Street | Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery. |
-- CRIME NO. ======== 295 in crime_scene_reports 10:15 AM

--Interviews
SELECT * FROM interviews;
-- year = 2021
SELECT * FROM interviews WHERE year = 2021;
-- month =7
SELECT * FROM interviews WHERE year = 2021 AND month = 7;
-- day =28
SELECT * FROM interviews WHERE year = 2021 AND month = 7 AND day = 28;
-- FINAL id 161,162,163
--see secury footage of bakery parking lot as thief got into car in bakeyry parking lot  look for the cars betwwen the time frame of
-- 10:15 - 10:25 AM
-- before robbery i guess ie 10:15 AM ATM on Legett st. as money was withdrawn
--after leaving bakery call someone talked less than a minute planning to take the earliest flight out of fiftyville and asked someone else to purchase the flight ticket
-- the other one is accompliance and this probably happened after 10:25 AM - 10:26 AM

161 | Ruth | Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery parking lot and drive away. If you have security footage from the bakery parking lot, you might want to look for cars that left the parking lot in that time frame.                                                          |
| 162 | Eugene | I don't know the thief's name, but it was someone I recognized. Earlier this morning, before I arrived at Emma's bakery, I was walking by the ATM on Leggett Street and saw the thief there withdrawing some money.        '                                                                                         |
| 163 | Raymond | As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket. |

--BAKERY SECURITY LOGS
-- year= 2021, moth = 7 , day =28
SELECT * FROM bakery_security_logs WHERE day = 28 AND year = 2021 AND month =7;
--FINAL
| 260 | 10   | 16     | exit     | 5P2BI95       | Vanessa
| 261 | 10   | 18     | exit     | 94KL13X       | Bruce
| 262 | 10   | 18     | exit     | 6P58WS2       | Barry
| 263 | 10   | 19     | exit     | 4328GD8       | Luca
| 264 | 10   | 20     | exit     | G412CB7       | Sofia
| 265 | 10   | 21     | exit     | L93JTIZ       | Iman
| 266 | 10   | 23     | exit     | 322W7JE       | Diana
| 267 | 10   | 23     | exit     | 0NTHK55       | Kelsey
| 268 | 10   | 35     | exit     | 1106N58       | Taylor
-- CARS WHICH EXITED AT TIME B/E 10:15 - 10:35 THEIR DETAILS
-- PLATE-----ENTER-----EXIT-----
--5P2BI95----9:15------10:16-----
--94KL13X----8:23------10:18-----
--6P58WS2----9:20------10:18-----
--4328GD8----9:14------10:19-----
--G412CB7----9:28------10:20-----
--L93JTIZ----8:18------10:21-----
--322W7JE----8:36------10:23-----
--0NTHK55----8:42------10:23-----
--1106N58----8:34------10:35-----

--FIND PEOPLE RELATED TO THESE LICENSE PLATES
id of this table is the primary key and foreign key for bank_accounts ie person_id
+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 221103 | Vanessa | (725) 555-4692 | 2963008352      | 5P2BI95       |
+--------+---------+----------------+-----------------+---------------+
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 686048 | Bruce | (367) 555-5533 | 5773159633      | 94KL13X       |
+--------+-------+----------------+-----------------+---------------+
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 243696 | Barry | (301) 555-4174 | 7526138472      | 6P58WS2       |
+--------+-------+----------------+-----------------+---------------+
+--------+------+----------------+-----------------+---------------+
|   id   | name |  phone_number  | passport_number | license_plate |
+--------+------+----------------+-----------------+---------------+
| 467400 | Luca | (389) 555-5198 | 8496433585      | 4328GD8       |
+--------+------+----------------+-----------------+---------------+
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 398010 | Sofia | (130) 555-0289 | 1695452385      | G412CB7       |
+--------+-------+----------------+-----------------+---------------+
+--------+------+----------------+-----------------+---------------+
|   id   | name |  phone_number  | passport_number | license_plate |
+--------+------+----------------+-----------------+---------------+
| 396669 | Iman | (829) 555-5269 | 7049073643      | L93JTIZ       |
+--------+------+----------------+-----------------+---------------+
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 514354 | Diana | (770) 555-1861 | 3592750733      | 322W7JE       |
+--------+-------+----------------+-----------------+---------------+
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 560886 | Kelsey | (499) 555-9472 | 8294398571      | 0NTHK55       |
+--------+--------+----------------+-----------------+---------------+
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 449774 | Taylor | (286) 555-6063 | 1988161715      | 1106N58       |
+--------+--------+----------------+-----------------+---------------+
-- JUDGING BY THE DATA THE CAR COULD BE OF THE THEIF OR THE ACCOMPLIANCE IT'S PROBABLY OF ACCOMPLIAMCE AS NO PEOPLE OF THEM TRAVELLES IN THE FLIGHT
Bank accounts details
NO for Vanessa
BRUCE
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 49610011       | 686048    | 2010          |
+----------------+-----------+---------------+
BARRY
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 56171033       | 243696    | 2018          |
+----------------+-----------+---------------+
LUCA
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 28500762       | 467400    | 2014          |
+----------------+-----------+---------------+
NO FOR SOFIA
IMAN
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 25506511       | 396669    | 2014          |
+----------------+-----------+---------------+
DIANA
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 26013199       | 514354    | 2012          |
+----------------+-----------+---------------+
NO FOR KELSEY
TAYLOR
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 76054385       | 449774    | 2015          |
+----------------+-----------+---------------+


--ATM TRANSACTIONS
-- year =2021 month =  7 day =28
SELECT * FROM atm_transactions WHERE day =28 AND month = 7 AND year =2021;
--legettstreet
SELECT * FROM atm_transactions WHERE day =28 AND month = 7 AND year =2021 AND atm_location LIKE "Leggett St%";
--WITHDRAWLS FROM ATM
--ID ----ACCOUNT_NUMBER-------AMT
--246----28500762----------48
--264----28296815----------20
--266----76054385----------60
--267----49610011----------50
--269----16153065----------80
--288----25506511----------20
--313----81061156----------30
--336----26013199----------35
+-----+----------------+------+-------+-----+-------
| id  | account_number | transaction_type | amount |
+-----+----------------+------+-------+-----+-------
| 246 | 28500762       | withdraw         | 48     | LUCA IN LECENSE PLATES
| 264 | 28296815       | withdraw         | 20     | KENNY
| 266 | 76054385       | withdraw         | 60     | TAYLOR IN LICENSE PLATES
| 267 | 49610011       | withdraw         | 50     | BRUCE IN LICENSE PLATES
| 269 | 16153065       | withdraw         | 80     | BROOKE
| 288 | 25506511       | withdraw         | 20     |IMAN IN LICENSE PLATES
| 313 | 81061156       | withdraw         | 30     | BENISTA
| 336 | 26013199       | withdraw         | 35     | DIANA IN LICENSE PLATES
+-----+----------------+------+-------+-----+-------
--BANK ACCOUNTS OF ALL THESE PEOPLE---
--WITHDRAW COULD BE FROM ACCOMPLY ATM OR THEIF 'S OWN PROBABLY HIS OWN
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 28296815       | 395717    | 2014          | KENNY
+----------------+-----------+---------------+
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 395717 | Kenny | (826) 555-1652 | 9878712108      | 30G67EN       |
+--------+-------+----------------+-----------------+---------------+
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 16153065       | 458378    | 2012          | BROOKE
+----------------+-----------+---------------+
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 458378 | Brooke | (122) 555-4581 | 4408372428      | QX4YZN3       |
+--------+--------+----------------+-----------------+---------------+
+----------------+-----------+---------------+
| account_number | person_id | creation_year |
+----------------+-----------+---------------+
| 81061156       | 438727    | 2018          | BENISTA
+----------------+-----------+---------------+
+--------+---------+----------------+-----------------+---------------+
|   id   |  name   |  phone_number  | passport_number | license_plate |
+--------+---------+----------------+-----------------+---------------+
| 438727 | Benista | (338) 555-6650 | 9586786673      | 8X428L0       |
+--------+---------+----------------+-----------------+---------------+



--PHONE CALLS
--year=2021,day=28,month=7
SELECT * FROM phone_calls WHERE day =28 AND month = 7 AND year =2021;
--duration<60
SELECT * FROM phone_calls WHERE day =28 AND month = 7 AND year =2021 AND duration <= 60;
--CALLS
--ID---CALLER----------RECEIVER----------DURATION
  | 221 | (130) 555-0289 | (996) 555-8899 | 51  | SOFIA(CALLER)  IN LICENSE PLATES
  | 224 | (499) 555-9472 | (892) 555-8872 | 36  | KELSEY(CALLER) IN LICENSE PLATES BUT CALLED TWO TIMES LESS LIKELY TO BE A THEIF
  | 233 | (367) 555-5533 | (375) 555-8161 | 45  | BRUCE(CALLER) IN LICENSE PLATES AND BANK ACCOUNT WITHDRAWL
  | 234 | (609) 555-5876 | (389) 555-5198 | 60  | LUCA(RECIEVER) IN LICENSE PLATES AND BANK ACCOUNT WITHDRWALS AS HE IS RECEIVER HE COULD BE THE ACCOMPLY
  | 251 | (499) 555-9472 | (717) 555-1342 | 50  | KELSEY(CALLER) IN LICENSE PLATES
  | 254 | (286) 555-6063 | (676) 555-6554 | 43  | TAYLOR(CALLOR) IN LICENSE PLATESAND BANK ACCOUNT WITHDRWALS
  | 255 | (770) 555-1861 | (725) 555-3243 | 49  | DIANA(CALLER) IN LICENSE PLATES AND BANK ACCOUNT WITHDRAWLS
--| 261 | (031) 555-6622 | (910) 555-3251 | 38  | NO RECORDS YET
  | 279 | (826) 555-1652 | (066) 555-9701 | 55  | NO RECORDS YET
  | 281 | (338) 555-6650 | (704) 555-2131 | 54  | NO RECORDS YET





-- FLIGHT WAS ID = 36
--FLIGHT [PASSENGERS]
SELECT * FROM flights WHERE flight_id = 36;
+-----------+-----------------+------+
| flight_id | passport_number | seat |
+-----------+-----------------+------+
| 36        | 7214083635      | 2A   | DORIS
| 36        | 1695452385      | 3B   | SOFIA <---------
| 36        | 5773159633      | 4A   | BRUCE <---------
| 36        | 1540955065      | 5C   | EDWARD
| 36        | 8294398571      | 6C   | KELSEY <---------
| 36        | 1988161715      | 6D   | TAYLOR <----------
| 36        | 9878712108      | 7A   | KENNY <------------
| 36        | 8496433585      | 7B   | LUCA <-------
+-----------+-----------------+------+

DORIS
+--------+-------+----------------+-----------------+---------------+
|   id   | name  |  phone_number  | passport_number | license_plate |
+--------+-------+----------------+-----------------+---------------+
| 953679 | Doris | (066) 555-9701 | 7214083635      | M51FA04       |
+--------+-------+----------------+-----------------+---------------+
Bank account
EDWARD
+--------+--------+----------------+-----------------+---------------+
|   id   |  name  |  phone_number  | passport_number | license_plate |
+--------+--------+----------------+-----------------+---------------+
| 651714 | Edward | (328) 555-1152 | 1540955065      | 130LD9Z       |
+--------+--------+----------------+-----------------+---------------+
-----------------------------------CITY ESCAPED TO SOLVED-------------------------------------------------------------------|

--FLIGHTS
--day=29,month=7,year=2021
SELECT * FROM flights WHERE day = 29 AND year = 2021 AND month = 7;
orgin airport = 8 = fiftyville airport reference airports nearest flight tomorrow was 8:20
--is
 id | origin_airport_id | destination_airport_id | year | month | day | hour | minute
 36 | 8                 | 4                      | 2021 | 7     | 29  | 8    | 20     |

 id | abbreviation |                full_name                |     city      |
 8  | CSF          | Fiftyville Regional Airport             | Fiftyville
  4  | LGA          | LaGuardia Airport                       | New York City |