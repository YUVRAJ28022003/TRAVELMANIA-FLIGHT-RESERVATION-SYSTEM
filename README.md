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

![Screenshot 2024-10-15 113052](https://github.com/user-attachments/assets/b6897b07-a64e-453e-9bd0-dadd61a72e9b)
![Screenshot 2024-10-15 113033](https://github.com/user-attachments/assets/9cacb78b-fea3-49c1-b54d-854e1aea2236)
![Screenshot 2024-10-15 110900](https://github.com/user-attachments/assets/24dfb421-eaa3-4c01-8307-58cf20f7d42d)
![Screenshot 2024-10-15 110838](https://github.com/user-attachments/assets/b26a47a5-1e67-4bf5-afa4-26322abd4f26)
![Screenshot 2024-10-15 110757](https://github.com/user-attachments/assets/e45f568f-b520-456a-a0c3-ceac57739ccf)
![Screenshot 2024-10-15 110734](https://github.com/user-attachments/assets/23e92e92-9e48-4753-aa7a-a20a19571b94)
![Screenshot 2024-10-15 113210](https://github.com/user-attachments/assets/a6c49d5b-8e39-4515-9f54-ae2e81af2fd7)
![Screenshot 2024-10-15 113153](https://github.com/user-attachments/assets/1c843161-409d-4dcb-9eb8-3a7073d4db7f)
![Screenshot 2024-10-15 113141](https://github.com/user-attachments/assets/91e06c4e-4a0e-426f-b705-a7db584a74f9)
![Screenshot 2024-10-15 113125](https://github.com/user-attachments/assets/da78049a-d60d-4524-be94-ec4e5bac1024)
![Screenshot 2024-10-15 113106](https://github.com/user-attachments/assets/f0f18792-9e94-495a-a7cf-39a1492a3283)

