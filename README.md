# Message-Encryption

An encryption algorithm that generates a private messaging medium service for two or more users

Created by Alec Leven and Dante Sanaei

## Intro

This algorithm, initially written to be completed by hand, was inspired by cryptographic mechanisms such as the Enigma Machine that rely on a starting configuration on both ends to correctly encrypt and decipher the code. The program allows two users to generate the same unique credentials (username and password) using identical starting parameters to "configure" the algorithm. A detailed walkthrough of the program can be found [here](https://github.com/astral-kuarry/message-encryption/blob/master/resources/Algorithm.pdf)

The two keys used to initialize the program are a MESSAGE and DATE key. Before beginning the process, both users will know the specific source of the MESSAGE key (i.e. the title of the top story on CNN.com or the title of the top trending video on Youtube.com). The first user to generate the credentials is termed the SENDER, and the second user to generate the credentials is termed the RECEIVER. 

The SENDER will input the MESSAGE key from the pre-determined location and a DATE key (a 12 digit numeric date/time code) will be automatically generated and displayed to the user. The code will then generated the credentials using a two part process outlined below, and display the DATE key, the username, and the password. These values will be sent to the RECEIVER, and he will input the MESSAGE key and the DATE key into the program to generate the same exact credentials. 

## Algorithm

#### Part One: Username Generation

The algorithm begins by converting the MESSAGE key into a 10 digit alphanumeric code, and scrambles it using base64 encoding. It then find the exact time the program was run (year/month/day/hour/minute/second) and determines a 12 digit numeric code to act as the DATE key. 

The program runs these keys through a sixty option tree with unique string manipulations and generates a string termed the PLAINTEXT. This is then encrypted using the *Playfair Cipher* to create the CIPHERTEXT. After a final encoding using base64, this string becomes the **username**.

### Part Two: Password Generation

Based on their properties, the PLAINTEXT and CIPHERTEXT are used in one of seven possible mathematical calculations to generate a new 8 digit number called the TARGET key. 

A date conversion algorithm turns this key into a specific date in the Gregorian calendar (last 1000 years). Using [Appendix B](https://github.com/astral-kuarry/message-encryption/blob/master/resources/Appendix%20B.pdf) (a curated list of all major monarch rulers since 1002 A.D.), the nearest reign start date will be found. With the data of this specific monarch, more manipulations will be made, and the final **password** will be created. 

## Examples

Ex. 1:

![ex1](resources\ex1.PNG)

Ex. 2:

![ex2](resources\ex2.PNG)

