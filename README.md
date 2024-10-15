# TRAVELMANIA-FLIGHT-RESERVATION-SYSTEM
This Flight Reservation System project is a C++ application designed to manage the process of booking, cancelling, and modifying flight tickets.

Flight Reservation System Project
This Flight Reservation System project is a C++ application designed to manage the process of booking, cancelling, and modifying flight tickets. The system is aimed at simplifying the reservation process while ensuring that passengers can choose specific types of seats according to their preferences, manage their personal details, and receive all the necessary information about their flight booking. It combines essential functionalities like seat selection, AADHAR ID and phone number validation, and food preferences in a simple yet efficient user interface.

Key Features:
Passenger Details Management:

The system allows users to enter personal details, such as first name, last name, AADHAR ID (validated to ensure 12 digits), and phone number (validated for 10 digits).
These details are stored in a linked list for easy retrieval and management.

Seat Selection:
---------------

The system supports different seat types: Window, Aisle, and Middle.
Passengers can choose their preferred seat type during booking, and the system shows the available seats in each category.
Each seat is marked as booked once reserved, ensuring no duplicate bookings for the same seat.

Reservation System:
-------------------
Passengers can reserve seats by entering their personal information and choosing from available seats.
A unique reservation number is generated for each booking, along with the assigned seat number.
The system displays the reservation number and seat number for the passenger to track their booking.

Food Preferences:
-----------------
Passengers can select their food preference during booking from the following options: Veg, Non-Veg, or No Food.

Ticket Cancellation:
--------------------
Passengers can cancel their reservation by entering their unique reservation number.
Upon cancellation, the reserved seat is freed and made available for future bookings.

Change Reservation:
-------------------
Passengers can modify their existing reservation by selecting a new seat based on availability and their preference for seat type.
The system ensures that the new seat is valid and updates the reservation with the new seat number.

Passenger and Booking Details:
-------------------------------
Passengers can view their booking details, including personal information, seat number, and food preference.
The system also allows administrators to view all booking details, making it easier to manage and track all reservations.

Data Structures:
----------------
The project uses a linked list to store passenger details dynamically, allowing efficient addition, deletion, and modification of records.

Input Validation:
------------------
AADHAR ID and phone numbers are validated to ensure correctness (AADHAR must be 12 digits and phone number must be 10 digits).

How the System Works:
----------------------
Upon starting the system, the user is presented with a menu that offers several options:

Book Ticket: 
--------------
Allows a user to book a seat by entering their personal details and selecting a preferred seat type. The system assigns a reservation number and confirms the booking.

Cancel Ticket:
--------------
A user can cancel a booked ticket by entering their reservation number. The seat is freed, and the booking is removed.

Change Reservation: 
-------------------
Users can modify their seat by selecting a new available seat based on their preferences.

Passenger Details:
------------------
Displays the reservation details for a specific passenger based on the reservation number.
Get Booking Details: Shows all booking information for administrative purposes.
This flight reservation system is a comprehensive solution for managing passenger data, ensuring seat availability, and improving the overall booking experience. Its simple interface and effective use of data structures make it a robust tool for managing flight reservations.
