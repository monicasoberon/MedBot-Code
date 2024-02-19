# MedBot-Code
Code for IoT-based device designed to address the problem of childhood poisoning by medications.

Smart dispenser of tablets for children without supervision MedBot

M. Soberón Zubía and G. Galván García

Introduction
MedBot is an innovative solution designed to address the critical issue of child poisoning caused by medication overdose. In today's world, over 500,000 children under five experience possible medication-related poisoning annually, with more than 60,000 treated in emergency departments due to unsupervised medication ingestion (source: asthealth.org, 2021).

This project aims to combat the two primary components contributing to this problem: children accessing medicines and errors in medication dosage administration. Inspired by Sustainable Development Goal 3, "Health and Well-being," MedBot seeks to achieve universal health coverage and provide safe and effective medications and vaccines for all.

Features
Dispensing System: Precise circuitry with sensors and actuators for controlled pill dispensing.
Database Integration: MySQL database to log pill dispensation and trigger refill alerts.
API Connectivity: Interaction with APIs using Postman to connect the database to Arduino.
Engaging Design: Attractive robot design to encourage children's interaction.
Project Overview
MedBot uses a robot-shaped device to alert and dispense pills. The LED indicates when it's time to take a pill, and the PIR sensor detects a child's movement for pill dispensation. The pill can only be dispensed when the LED is on. A distance sensor verifies pill availability, and the overall design encourages children to use the robot effectively.

Project Scope
The project focuses on creating, implementing, and evaluating an Internet of Things (IoT) device to address the risk of child poisoning by medications. Key aspects include:

Child Medication Poisoning: Addressing the issue of child poisoning due to unsupervised medication ingestion.
Target Audience: Designed for households with children requiring medication.
Device Design: Includes the physical robot design, sensors (distance sensor, push button, RGB LED), and their integration.
Problem Statement
Safety issues in children's medication packaging have led to accidental overdoses. The lack of child-resistant packaging and errors in medication administration contribute to alarming child poisoning statistics. MedBot aims to provide an innovative and effective solution to prevent accidental overdoses and ensure a safer environment for pediatric medication administration.

Justification
Given the high number of children affected by accidental medication overdoses, the team aimed to develop an economical, child-friendly, and simple solution. MedBot aligns with global goals, offers an innovative solution, and aims to prevent dangerous situations in homes while being cost-effective and accessible.

Hardware Materials
Servo Motor
LED
Button
Distance Sensor
Arduino ESP32 board
Jumper Wires
USB cable
Breadboard

Usage
Clone the repository.
Set up the Arduino IDE and necessary libraries.
Configure the MySQL database and API connection.
Upload the Arduino code to the ESP32 board.

Results
The prototype demonstrated accuracy in dispensing pills and reliable connectivity with the database. Initial tests revealed minimal errors, allowing for continuous improvement and optimization.

Future Enhancements
Implement machine learning for personalized medication schedules.
Explore additional sensors for improved interaction.
Enhance the robot's design for further engagement.
