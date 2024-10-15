#include<bits/stdc++.h>
using namespace std;

int total_number_of_seats = 100;
int seats[100] = {0}; // To track if seat is booked (-1 for booked, 0 for available)
int reserve_seats = 0; // Start from 0 for reservation count
int cancel_tickets = 0; // To track cancellations

enum SeatType { WINDOW, AISLE, MIDDLE }; // Enum for seat types

class Flight {
public:
    Flight() {
        start = NULL;
    }

    void book_ticket();
    void cancel_ticket();
    void change_reservation();
    void passenger_details();
    void get_booking_details();

private:
    struct passenger {
        string fname;
        string lname;
        string ID;
        string phone_number;
        string food_menu;
        int seat_number;
        int reservation_number;
        passenger *next;
    };

    passenger *start;  // Start of linked list
    passenger *temp_passenger;
    passenger *temp1;

} flight;

// Validate if the AADHAR ID is exactly 12 digits
bool validate_aadhar_id(const string& id) {
    return id.length() == 12 && all_of(id.begin(), id.end(), ::isdigit);
}

// Validate if the phone number is exactly 10 digits
bool validate_phone_number(const string& phone) {
    return phone.length() == 10 && all_of(phone.begin(), phone.end(), ::isdigit);
}

// Function to show available seats based on type
void show_available_seats(SeatType type) {
    cout << "Available seats (marked with |seat number|):\n";
    for (int i = 0; i < total_number_of_seats; i++) {
        if (seats[i] == 0) {
            if (type == WINDOW && (i % 6 == 0 || (i % 6 == 5 && i != 0))) {
                cout << "| " << i + 1 << " |";
            } else if (type == AISLE && ((i % 6 == 1) || (i % 6 == 4))) {
                cout << "| " << i + 1 << " |";
            } else if (type == MIDDLE && ((i % 6 == 2) || (i % 6 == 3))) {
                cout << "| " << i + 1 << " |";
            }
        }
        if ((i + 1) % 6 == 0) {
            cout << endl; // New row of seats
        }
    }
    cout << endl;
}

// Function to choose a seat based on type and availability
int choose_seat(SeatType type) {
    show_available_seats(type);
    int snumber;
    do {
        cout << "Enter seat number: ";
        cin >> snumber;
        if (snumber < 1 || snumber > total_number_of_seats) {
            cout << "Invalid seat number, enter again." << endl;
        } else if (seats[snumber - 1] == -1) {
            cout << "Seat already booked, choose another seat." << endl;
        } else {
            seats[snumber - 1] = -1; // Mark seat as booked
            return snumber;
        }
    } while (true);
}

void Flight::book_ticket() {
    temp_passenger = new passenger;

    // Enter passenger details
    cout << "Enter your first name: ";
    cin >> temp_passenger->fname;
    cout << "Enter your last name: ";
    cin >> temp_passenger->lname;

    // Validate AADHAR ID
    do {
        cout << "Enter your AADHAR ID (12 digits): ";
        cin >> temp_passenger->ID;
        if (!validate_aadhar_id(temp_passenger->ID)) {
            cout << "Invalid AADHAR ID. Please enter a 12-digit number." << endl;
        }
    } while (!validate_aadhar_id(temp_passenger->ID));

    // Validate phone number
    do {
        cout << "Enter your phone number (10 digits): ";
        cin >> temp_passenger->phone_number;
        if (!validate_phone_number(temp_passenger->phone_number)) {
            cout << "Invalid phone number. Please enter a 10-digit number." << endl;
        }
    } while (!validate_phone_number(temp_passenger->phone_number));

    // Choose seat type
    int seat_type_choice;
    cout << "Choose your preferred seat type:\n";
    cout << "1. Window\n";
    cout << "2. Aisle\n";
    cout << "3. Middle\n";
    cout << "Enter your choice: ";
    cin >> seat_type_choice;

    SeatType chosen_type;
    switch (seat_type_choice) {
        case 1: chosen_type = WINDOW; break;
        case 2: chosen_type = AISLE; break;
        case 3: chosen_type = MIDDLE; break;
        default: cout << "Invalid choice, assigning middle seat by default."; chosen_type = MIDDLE;
    }

    // Choose seat number based on type and availability
    temp_passenger->seat_number = choose_seat(chosen_type);

    // Choose food option
    cout << "Choose your food preference:\n1. Veg\n2. Non-Veg\n3. No Food\n";
    int food_choice;
    cin >> food_choice;
    while (food_choice < 1 || food_choice > 3) {
        cout << "Invalid choice, enter again: ";
        cin >> food_choice;
    }

    if (food_choice == 1) temp_passenger->food_menu = "Veg";
    else if (food_choice == 2) temp_passenger->food_menu = "Non-Veg";
    else temp_passenger->food_menu = "No Food";

    reserve_seats++; // Increment reservation count
    temp_passenger->reservation_number = reserve_seats;

    // Show reservation number and seat allocation
    cout << "Your reservation number is: " << reserve_seats << endl;
    cout << "Your seat number is: " << temp_passenger->seat_number << endl;

    temp_passenger->next = NULL;

    // Add to linked list
    if (start == NULL) {
        start = temp_passenger;
    } else {
        passenger *temp = start;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = temp_passenger;
    }
}

void Flight::cancel_ticket() {
    int reservation_number;
    cout << "Enter your reservation number: ";
    cin >> reservation_number;

    temp_passenger = start;
    temp1 = NULL;

    while (temp_passenger != NULL) {
        if (temp_passenger->reservation_number == reservation_number) {
            if (temp1 == NULL) { // Cancel first node
                start = temp_passenger->next;
            } else { // Cancel middle or last node
                temp1->next = temp_passenger->next;
            }

            // Free seat and delete passenger record
            seats[temp_passenger->seat_number - 1] = 0;
            delete temp_passenger;
            cancel_tickets++;
            cout << "Reservation cancelled successfully." << endl;
            return;
        }
        temp1 = temp_passenger;
        temp_passenger = temp_passenger->next;
    }

    cout << "Reservation not found." << endl;
}

void Flight::change_reservation() {
    int current_seat, new_seat;
    cout << "Enter your current seat number: ";
    cin >> current_seat;

    passenger *current_pass = start;
    while (current_pass != NULL) {
        if (current_pass->seat_number == current_seat) {
            break;
        }
        current_pass = current_pass->next;
    }

    if (current_pass == NULL) {
        cout << "Seat not found." << endl;
        return;
    }

    // Ask for the preferred seat type
    int seat_type_choice;
    cout << "Choose your preferred seat type for the new seat:\n";
    cout << "1. Window\n";
    cout << "2. Aisle\n";
    cout << "3. Middle\n";
    cout << "Enter your choice: ";
    cin >> seat_type_choice;

    SeatType chosen_type;
    switch (seat_type_choice) {
        case 1: chosen_type = WINDOW; break;
        case 2: chosen_type = AISLE; break;
        case 3: chosen_type = MIDDLE; break;
        default: cout << "Invalid choice, assigning middle seat by default."; chosen_type = MIDDLE;
    }

    // Choose a new seat
    new_seat = choose_seat(chosen_type);

    // Update seat assignment
    seats[current_pass->seat_number - 1] = 0;
    current_pass->seat_number = new_seat;
    seats[new_seat - 1] = -1;

    cout << "Seat changed successfully to seat number: " << new_seat << endl;
}

void Flight::passenger_details() {
    int reservation_number;
    cout << "Enter your reservation number: ";
    cin >> reservation_number;

    temp_passenger = start;
    while (temp_passenger != NULL) {
        if (temp_passenger->reservation_number == reservation_number) {
            cout << "Reservation Number: " << temp_passenger->reservation_number << endl;
            cout << "First Name: " << temp_passenger->fname << endl;
            cout << "Last Name: " << temp_passenger->lname << endl;
            cout << "AADHAR ID: " << temp_passenger->ID << endl;
            cout << "Phone Number: " << temp_passenger->phone_number << endl;
            cout << "Seat Number: " << temp_passenger->seat_number << endl;
            cout << "Food Preference: " << temp_passenger->food_menu << endl;
            return;
        }
        temp_passenger = temp_passenger->next;
    }

    cout << "Passenger not found." << endl;
}

void Flight::get_booking_details() {
    temp_passenger = start;
    cout << "Booking details:\n";
    while (temp_passenger != NULL) {
        cout << "Reservation Number: " << temp_passenger->reservation_number << endl;
        cout << "First Name: " << temp_passenger->fname << endl;
        cout << "Last Name: " << temp_passenger->lname << endl;
        cout << "AADHAR ID: " << temp_passenger->ID << endl;
        cout << "Phone Number: " << temp_passenger->phone_number << endl;
        cout << "Seat Number: " << temp_passenger->seat_number << endl;
        cout << "Food Preference: " << temp_passenger->food_menu << endl;
        cout << "----------------------------" << endl;
        temp_passenger = temp_passenger->next;
    }
}

void welcome() {
    cout << "\t\t|----------------------------------------------|\n";
    cout << "\t\t|  WELCOME TO TRAVELMANIA FLIGHT RESERVATION   |\n";
    cout << "\t\t|----------------------------------------------|\n";
    cout << "\t\t| 1. BOOK TICKET                              |\n";
    cout << "\t\t| 2. CANCEL TICKET                            |\n";
    cout << "\t\t| 3. CHANGE RESERVATION                       |\n";
    cout << "\t\t| 4. PASSENGER DETAILS                        |\n";
    cout << "\t\t| 5. GET BOOKING DETAILS                      |\n";
    cout << "\t\t| 6. EXIT                                     |\n";
    cout << "\t\t|----------------------------------------------|\n";

    int choice;
    do {
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                system("CLS");
                flight.book_ticket();
                break;
            case 2:
                system("CLS");
                flight.cancel_ticket();
                break;
            case 3:
                system("CLS");
                flight.change_reservation();
                break;
            case 4:
                system("CLS");
                flight.passenger_details();
                break;
            case 5:
                system("CLS");
                flight.get_booking_details();
                break;
            case 6:
                system("CLS");
                exit(0);
            default:
                system("CLS");
                cout << "Invalid choice. Try again." << endl;
        }
    } while (true);
}

int main() {
    welcome();
    return 0;
}
