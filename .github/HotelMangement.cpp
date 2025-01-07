// For input and output stream
#include <iostream>

// For file handling
#include <fstream>

// For the vector container
#include <vector>

// For the string class
#include <string>

// For numeric operations (e.g., accumulate)
#include <numeric>

// For standard algorithms (e.g., sort, find)
#include <algorithm>

// For time manipulation
#include <ctime>

// For string streams
#include <sstream>

// For output formatting
#include <iomanip>

// For the map container (key-value pairs)
#include <map>

// (Repeated) For the vector container
#include <vector>



using namespace std;

// Define color codes

// Reset color
const string RESET = "\033[0m";

// Black
const string BLACK = "\033[30m";

// Red
const string RED = "\033[31m";

// Green
const string GREEN = "\033[32m";

// Yellow
const string YELLOW = "\033[33m";

// Blue
const string BLUE = "\033[34m";

// Magenta
const string MAGENTA = "\033[35m";

// Cyan
const string CYAN = "\033[36m";

// White
const string WHITE = "\033[37m";

// Bright colors

// Bright Black (Gray)
const string BRIGHT_BLACK = "\033[90m";

// Bright Red
const string BRIGHT_RED = "\033[91m";

// Bright Green
const string BRIGHT_GREEN = "\033[92m";

// Bright Yellow
const string BRIGHT_YELLOW = "\033[93m";

// Bright Blue
const string BRIGHT_BLUE = "\033[94m";

// Bright Magenta
const string BRIGHT_MAGENTA = "\033[95m";

// Bright Cyan
const string BRIGHT_CYAN = "\033[96m";

// Bright White
const string BRIGHT_WHITE = "\033[97m";


// Background colors

// Black Background
const string BACKGROUND_BLACK = "\033[40m";

// Red Background
const string BACKGROUND_RED = "\033[41m";

// Green Background
const string BACKGROUND_GREEN = "\033[42m";

// Yellow Background
const string BACKGROUND_YELLOW = "\033[43m";

// Blue Background
const string BACKGROUND_BLUE = "\033[44m";

// Magenta Background
const string BACKGROUND_MAGENTA = "\033[45m";

// Cyan Background
const string BACKGROUND_CYAN = "\033[46m";

// White Background
const string BACKGROUND_WHITE = "\033[47m";



// Bright Background colors

// Bright Black Background
const string BACKGROUND_BRIGHT_BLACK = "\033[100m";

// Bright Red Background
const string BACKGROUND_BRIGHT_RED = "\033[101m";

// Bright Green Background
const string BACKGROUND_BRIGHT_GREEN = "\033[102m";

// Bright Yellow Background
const string BACKGROUND_BRIGHT_YELLOW = "\033[103m";

// Bright Blue Background
const string BACKGROUND_BRIGHT_BLUE = "\033[104m";

// Bright Magenta Background
const string BACKGROUND_BRIGHT_MAGENTA = "\033[105m";

// Bright Cyan Background
const string BACKGROUND_BRIGHT_CYAN = "\033[106m";

// Bright White Background
const string BACKGROUND_BRIGHT_WHITE = "\033[107m";

// Bold text
const string BOLD = "\033[1m";

// Underlined text
const string UNDERLINE = "\033[4m";


struct Customer
{
    int id;
    string name;
    string contact;
    int age;
    string gender;
    string nationality;
    string occupation;
    string email;
};


struct Hotel
{
    int id;
    string name;
    string location;
    int roomsAvailable;
    int starRating;
    string typeOfHotel;
    string diningOptions;
    bool parking;
    bool wifi;
    string eventSpaces;
    string roomService;
    string housekeeping;
    string transportation;
    string cancellationPolicy;
};


struct Reservation
{
    int id;
    int customerId;
    int hotelId;
    string reservationDate;
    string roomType;
    string bedType;
    int durationOfStay;
    int roomNumber;
    double roomRate;
    string bookingStatus;
};


struct Payment
 {
    int id;
    int reservationId;
    string paymentTime;
    string paymentConfirmationDate;
    double totalAmount;
    string paymentType;
    string paymentStatus;
};


// Function to load hotel data
void loadHotel(vector<Hotel>& hotels)
{
    // Sample hotels
    hotels.push_back({1, "Grand Plaza", "New York", 50, 5, "Luxury", "Restaurant, Bar", true, true, "Conference Room", "24/7", "Daily", "Shuttle Service", "Free cancellation"});
    hotels.push_back({2, "City Inn", "Los Angeles", 100, 3, "Business", "Restaurant", true, true, "Conference Room", "24/7", "Daily", "Shuttle Service", "No cancellation"});
    hotels.push_back({3, "Seaside Resort", "Miami", 30, 4, "Resort", "Restaurant, Bar", true, true, "Banquet Hall", "Limited hours", "Weekly", "Airport Pickup", "Free cancellation"});
    hotels.push_back({4, "Mountain Lodge", "Denver", 10, 4, "Resort", "Restaurant", true, false, "Banquet Hall", "Limited hours", "Daily", "Shuttle Service", "Free cancellation"});
    hotels.push_back({5, "Sunshine Suites", "Orlando", 20, 3, "Luxury", "In-room Dining", false, true, "Conference Room", "24/7", "Daily", "Shuttle Service", "No cancellation"});
}


// Function to load customer data
void loadCustomer(vector<Customer>& customers)
{
    // Sample customers
    customers.push_back({1, "John Doe", "1234567890", 30, "Male", "USA", "Businessman", "john@example.com"});
    customers.push_back({2, "Jane Smith", "0987654321", 25, "Female", "Canada", "Student", "jane@example.com"});
    customers.push_back({3, "Alex Brown", "1122334455", 28, "Male", "UK", "Artist", "alex@example.com"});
    customers.push_back({4, "Maria Garcia", "5566778899", 35, "Female", "Mexico", "Engineer", "maria@example.com"});
    customers.push_back({5, "David Lee", "6677889900", 40, "Male", "Australia", "Teacher", "david@example.com"});
}


// Function to load reservation data
void loadReservation(vector<Reservation>& reservations)
{
    // Sample reservations
    reservations.push_back({1, 1, 2, "2024-12-01", "Single", "King", 2, 101, 150.0, "confirmed"});
    reservations.push_back({2, 2, 3, "2024-12-02", "Double", "Queen", 3, 202, 200.0, "confirmed"});
    reservations.push_back({3, 3, 4, "2024-12-03", "Suite", "King", 5, 303, 300.0, "pending"});
    reservations.push_back({4, 4, 5, "2024-12-04", "Single", "Twin", 1, 404, 120.0, "confirmed"});
    reservations.push_back({5, 5, 1, "2024-12-05", "Double", "Queen", 4, 505, 180.0, "canceled"});
}


// Function to load payment data
void loadPayment(vector<Payment>& payments)
{
    // Sample payments
    payments.push_back({1, 1, "2024-12-01 10:00", "2024-12-01", 300.0, "credit card", "completed"});
    payments.push_back({2, 2, "2024-12-02 12:00", "2024-12-02", 600.0, "credit card", "completed"});
    payments.push_back({3, 3, "2024-12-03 14:00", "2024-12-03", 900.0, "cash", "pending"});
    payments.push_back({4, 4, "2024-12-04 16:00", "2024-12-04", 120.0, "debit card", "completed"});
    payments.push_back({5, 5, "2024-12-05 18:00", "2024-12-05", 360.0, "credit card", "failed"});
}


// Function to save hotel data
void saveHotel(const vector<Hotel>& hotels)
{
    ofstream file("hotels.txt");
    for (const auto& hotel : hotels)
        {
        file << hotel.id << ", " << hotel.name << ", " << hotel.location << ", " << hotel.roomsAvailable << ", "
             << hotel.starRating << ", " << hotel.typeOfHotel << ", " << hotel.diningOptions << ", "
             << hotel.parking << ", " << hotel.wifi << ", " << hotel.eventSpaces << ", " << hotel.roomService << ", "
             << hotel.housekeeping << ", " << hotel.transportation << ", " << hotel.cancellationPolicy << endl;
    }
}


// Function to save customer data
void saveCustomer(const vector<Customer>& customers)
 {
    ofstream file("customers.txt");
    for (const auto& customer : customers)
        {
        file << customer.id << ", " << customer.name << ", " << customer.contact << ", " << customer.age << ", "
             << customer.gender << ", " << customer.nationality << ", " << customer.occupation << ", "
             << customer.email << endl;
    }
}


// Function to save reservation data
void saveReservation(const vector<Reservation>& reservations)
{
    ofstream file("reservations.txt");
    for (const auto& reservation : reservations)
        {
        file << reservation.id << ", " << reservation.customerId << ", " << reservation.hotelId << ", "
             << reservation.reservationDate << ", " << reservation.roomType << ", " << reservation.bedType << ", "
             << reservation.durationOfStay << ", " << reservation.roomNumber << ", " << reservation.roomRate << ", "
             << reservation.bookingStatus << endl;
    }
}


// Function to save payment data
void savePayment(const vector<Payment>& payments)
 {
    ofstream file("payments.txt");
    for (const auto& payment : payments)
        {
        file << payment.id << ", " << payment.reservationId << ", " << payment.paymentTime << ", "
             << payment.paymentConfirmationDate << ", " << payment.totalAmount << ", " << payment.paymentType << ", "
             << payment.paymentStatus << endl;
    }
}


// Function to view customer data
void viewCustomer(std::vector<Customer>& customers)
 {

    std::sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b)
              {
        return a.name < b.name;
    });


    std::cout << "Customer List (Sorted by Name):\n";
    for (const auto& customer : customers)
        {
        std::cout << "ID: " << customer.id
                  << ", Name: " << customer.name
                  << ", Contact: " << customer.contact
                  << ", Age: " << customer.age
                  << ", Gender: " << customer.gender
                  << ", Nationality: " << customer.nationality
                  << ", Occupation: " << customer.occupation
                  << ", Email: " << customer.email
                  << "\n";
    }
}


// Function to display hotels sorted by star rating using Selection Sort
void viewHotels(std::vector<Hotel>& hotels)
 {
    // Selection Sort based on starRating
    for (size_t i = 0; i < hotels.size() - 1; ++i)
        {
        size_t minIndex = i;
        for (size_t j = i + 1; j < hotels.size(); ++j)
        {
            if (hotels[j].starRating < hotels[minIndex].starRating)
             {
                minIndex = j;
            }
        }
        if (minIndex != i)
        {
            std::swap(hotels[i], hotels[minIndex]);
        }
    }

    // Display the sorted hotel list by star rating
    std::cout << "Hotel List (Sorted by Star Rating):\n";
    for (const auto& hotel : hotels) {
        std::cout << "ID: " << hotel.id
                  << ", Name: " << hotel.name
                  << ", Location: " << hotel.location
                  << ", Rooms Available: " << hotel.roomsAvailable
                  << ", Star Rating: " << hotel.starRating
                  << ", Type of Hotel: " << hotel.typeOfHotel
                  << ", Dining Options: " << hotel.diningOptions
                  << ", Parking: " << (hotel.parking ? "Yes" : "No")
                  << ", WiFi: " << (hotel.wifi ? "Yes" : "No")
                  << ", Event Spaces: " << hotel.eventSpaces
                  << ", Room Service: " << hotel.roomService
                  << ", Housekeeping: " << hotel.housekeeping
                  << ", Transportation: " << hotel.transportation
                  << ", Cancellation Policy: " << hotel.cancellationPolicy
                  << "\n";
    }
}

// Function to perform selection sort on reservations by date
void selectionSortReservationsByDate(std::vector<Reservation>& reservations)
{
    int n = reservations.size();
    for (int i = 0; i < n - 1; ++i)
        {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
         {
            if (reservations[j].reservationDate < reservations[minIndex].reservationDate)
                {
                minIndex = j;
            }
        }
        // Swap
        std::swap(reservations[i], reservations[minIndex]);
    }
}


// Function to view reservation data
void viewReservation(const std::vector<Reservation>& reservations)
 {
    // Sort reservations by reservationDate using selection sort
    std::vector<Reservation> sortedReservations = reservations;
    selectionSortReservationsByDate(sortedReservations);

    std::cout << "Viewing Sorted Reservations by Reservation Date:\n";
    for (const auto& reservation : sortedReservations) {
        std::cout << "ID: " << reservation.id
                  << ", Customer ID: " << reservation.customerId
                  << ", Hotel ID: " << reservation.hotelId
                  << ", Reservation Date: " << reservation.reservationDate
                  << ", Room Type: " << reservation.roomType
                  << ", Bed Type: " << reservation.bedType
                  << ", Duration of Stay: " << reservation.durationOfStay
                  << ", Room Number: " << reservation.roomNumber
                  << ", Room Rate: " << reservation.roomRate
                  << ", Booking Status: " << reservation.bookingStatus
                  << "\n";
    }
}


// QuickSort helper function
int partition(std::vector<Payment>& payments, int low, int high)
 {
    std::string pivot = payments[high].paymentTime;  // Pivot is the last element
    int i = low - 1;  // Index of the smaller element

    for (int j = low; j <= high - 1; j++)
        {
        if (payments[j].paymentTime <= pivot)
         {  // Compare payment time
            i++;  // Increment index of smaller element
            std::swap(payments[i], payments[j]);  // Swap
        }
    }
    std::swap(payments[i + 1], payments[high]);
    return (i + 1);
}

// QuickSort function
void quickSort(std::vector<Payment>& payments, int low, int high)
 {
    if (low < high)
        {
        int pi = partition(payments, low, high);  // Partitioning index
        quickSort(payments, low, pi - 1);  // Sort the left part
        quickSort(payments, pi + 1, high);  // Sort the right part
    }
}


// Function to display all payments
void viewPayment(const std::vector<Payment>& payments)
 {
    // Copy the payments vector to a local vector for sorting
    std::vector<Payment> sortedPayments = payments;

    // Apply QuickSort to the payments based on paymentTime
    quickSort(sortedPayments, 0, sortedPayments.size() - 1);

    // Display sorted payments
    std::cout << "Payments (sorted by Payment Time):\n";
    for (const auto& payment : sortedPayments)
        {
        std::cout << "ID: " << payment.id
                  << ", Reservation ID: " << payment.reservationId
                  << ", Payment Time: " << payment.paymentTime
                  << ", Payment Confirmation Date: " << payment.paymentConfirmationDate
                  << ", Total Amount: " << payment.totalAmount
                  << ", Payment Type: " << payment.paymentType
                  << ", Payment Status: " << payment.paymentStatus
                  << "\n";
    }
}


// QuickSort to sort hotels by their id
int partition(vector<Hotel>& hotels, int low, int high)
{
    int pivot = hotels[high].id;
    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (hotels[j].id <= pivot)
        {
            i++;
            swap(hotels[i], hotels[j]);
        }
    }
    swap(hotels[i + 1], hotels[high]);
    return (i + 1);
}

// Function to perform quick sort on hotels
void quickSort(vector<Hotel>& hotels, int low, int high)
{
    if (low < high)
        {
        int pi = partition(hotels, low, high);
        quickSort(hotels, low, pi - 1);
        quickSort(hotels, pi + 1, high);
    }
}


// Binary Search to find a hotel by id
int binarySearch(const vector<Hotel>& hotels, int id)
 {
    int low = 0;
    int high = hotels.size() - 1;
    while (low <= high)
        {
        int mid = low + (high - low) / 2;
        if (hotels[mid].id == id)
         {
            return mid;
        } else if (hotels[mid].id < id)
        {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;  // Return -1 if hotel is not found
}


// Function to edit hotel details
void editHotel(vector<Hotel>& hotels)
 {
    // Sort hotels by id
    quickSort(hotels, 0, hotels.size() - 1);

    int id;
    cout << "Enter the hotel ID you want to edit: ";
    cin >> id;

    // Perform Binary Search to find the hotel
    int index = binarySearch(hotels, id);

    if (index != -1)
        {
        // Hotel found, allow user to edit the details
        Hotel& hotel = hotels[index];

        cout << "Editing hotel with ID: " << hotel.id << endl;

        cout << "Enter new name (current: " << hotel.name << "): ";
        cin.ignore();  // To ignore the leftover newline character
        getline(cin, hotel.name);

        cout << "Enter new location (current: " << hotel.location << "): ";
        getline(cin, hotel.location);

        cout << "Enter new number of rooms available (current: " << hotel.roomsAvailable << "): ";
        cin >> hotel.roomsAvailable;

        cout << "Enter new star rating (current: " << hotel.starRating << "): ";
        cin >> hotel.starRating;

        cout << "Enter new type of hotel (current: " << hotel.typeOfHotel << "): ";
        cin.ignore();
        getline(cin, hotel.typeOfHotel);

        cout << "Enter new dining options (current: " << hotel.diningOptions << "): ";
        getline(cin, hotel.diningOptions);

        cout << "Is parking available? (current: " << (hotel.parking ? "Yes" : "No") << "): ";
        cin >> hotel.parking;

        cout << "Is WiFi available? (current: " << (hotel.wifi ? "Yes" : "No") << "): ";
        cin >> hotel.wifi;

        cout << "Enter new event spaces (current: " << hotel.eventSpaces << "): ";
        cin.ignore();
        getline(cin, hotel.eventSpaces);

        cout << "Enter new room service options (current: " << hotel.roomService << "): ";
        getline(cin, hotel.roomService);

        cout << "Enter new housekeeping options (current: " << hotel.housekeeping << "): ";
        getline(cin, hotel.housekeeping);

        cout << "Enter new transportation options (current: " << hotel.transportation << "): ";
        getline(cin, hotel.transportation);

        cout << "Enter new cancellation policy (current: " << hotel.cancellationPolicy << "): ";
        getline(cin, hotel.cancellationPolicy);

        cout << "Hotel details updated successfully!" << endl;
    }
    else
        {
        cout << "Hotel with ID " << id << " not found." << endl;
    }
}


// Function to delete hotel by id
void deleteHotel(vector<Hotel>& hotels)
{
    // Sort hotels by id
    quickSort(hotels, 0, hotels.size() - 1);

    int id;
    cout << "Enter the hotel ID you want to delete: ";
    cin >> id;

    // Perform Binary Search to find the hotel
    int index = binarySearch(hotels, id);

    if (index != -1)
        {
        // Hotel found, delete it from the vector
        hotels.erase(hotels.begin() + index);
        cout << "Hotel with ID " << id << " deleted successfully!" << endl;
    }
    else
    {
        cout << "Hotel with ID " << id << " not found." << endl;
    }
}

// Linear Search to find customer by id
int linearSearch(const vector<Customer>& customers, int id)
 {
    for (int i = 0; i < customers.size(); i++)
        {
        if (customers[i].id == id)
         {
            return i;  // Return the index of the customer if found
        }
    }
    return -1;  // Return -1 if the customer is not found
}


// Function to edit customer details
void editCustomer(vector<Customer>& customers)
{
    int id;
    cout << "Enter the customer ID you want to edit: ";
    cin >> id;

    // Perform Linear Search to find the customer
    int index = linearSearch(customers, id);

    if (index != -1)
        {
        // Customer found, proceed with editing details
        Customer& customer = customers[index];  // Reference to the customer to modify
        cout << "Editing customer with ID " << id << endl;

        cout << "Enter new name (current: " << customer.name << "): ";
        cin.ignore();  // Clear the buffer from the previous input
        getline(cin, customer.name);

        cout << "Enter new contact (current: " << customer.contact << "): ";
        getline(cin, customer.contact);

        cout << "Enter new age (current: " << customer.age << "): ";
        cin >> customer.age;

        cout << "Enter new gender (current: " << customer.gender << "): ";
        cin.ignore();  // Clear the buffer from the previous input
        getline(cin, customer.gender);

        cout << "Enter new nationality (current: " << customer.nationality << "): ";
        getline(cin, customer.nationality);

        cout << "Enter new occupation (current: " << customer.occupation << "): ";
        getline(cin, customer.occupation);

        cout << "Enter new email (current: " << customer.email << "): ";
        getline(cin, customer.email);

        cout << "Customer details updated successfully!" << endl;
    }
    else
    {
        cout << "Customer with ID " << id << " not found." << endl;
    }
}

// Function to delete a customer
void deleteCustomer(vector<Customer>& customers)
 {
    int id;
    cout << "Enter the customer ID you want to delete: ";
    cin >> id;

    // Perform Linear Search to find the customer
    int index = linearSearch(customers, id);

    if (index != -1)
        {
        // Customer found, proceed with deleting
        customers.erase(customers.begin() + index);  // Erase the customer at the found index
        cout << "Customer with ID " << id << " deleted successfully!" << endl;
    }
    else
        {
        cout << "Customer with ID " << id << " not found." << endl;
    }
}


// Linear Search to find reservation by id
int linearSearchReservation(const vector<Reservation>& reservations, int id)
 {
    for (int i = 0; i < reservations.size(); i++)
        {
        if (reservations[i].id == id)
         {
            return i;  // Return the index of the reservation if found
        }
    }
    return -1;  // Return -1 if the reservation is not found
}

// Bubble Sort to sort reservations by id (you can use other sorting algorithms)
void bubbleSortReservationsById(vector<Reservation>& reservations)
 {
    int n = reservations.size();
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (reservations[j].id > reservations[j + 1].id)
             {
                swap(reservations[j], reservations[j + 1]);  // Swap if the order is incorrect
            }
        }
    }
}


// Function to edit a reservation
void editReservation(vector<Reservation>& reservations)
 {
    int id;
    cout << "Enter the reservation ID to edit: ";
    cin >> id;

    // Perform Linear Search to find the reservation
    int index = linearSearchReservation(reservations, id);

    if (index != -1)
        {
        // Reservation found, proceed with editing
        Reservation& res = reservations[index];

        cout << "Editing Reservation with ID: " << res.id << endl;
        cout << "Current reservation details:\n";
        cout << "Reservation Date: " << res.reservationDate << endl;
        cout << "Room Type: " << res.roomType << endl;
        cout << "Bed Type: " << res.bedType << endl;
        cout << "Duration of Stay: " << res.durationOfStay << " days\n";
        cout << "Room Number: " << res.roomNumber << endl;
        cout << "Room Rate: " << res.roomRate << endl;
        cout << "Booking Status: " << res.bookingStatus << endl;

        // Ask the user for new values
        cout << "Enter new reservation date: ";
        cin >> res.reservationDate;
        cout << "Enter new room type: ";
        cin >> res.roomType;
        cout << "Enter new bed type: ";
        cin >> res.bedType;
        cout << "Enter new duration of stay (in days): ";
        cin >> res.durationOfStay;
        cout << "Enter new room number: ";
        cin >> res.roomNumber;
        cout << "Enter new room rate: ";
        cin >> res.roomRate;
        cout << "Enter new booking status: ";
        cin >> res.bookingStatus;

        // Optionally sort the reservations after editing (by id)
        bubbleSortReservationsById(reservations);

        cout << "Reservation updated successfully!" << endl;
    }
    else
        {
        cout << "Reservation with ID " << id << " not found." << endl;
    }
}


// Function to delete a reservation
void deleteReservation(vector<Reservation>& reservations)
 {
    int id;
    cout << "Enter the reservation ID to delete: ";
    cin >> id;

    // Perform Linear Search to find the reservation
    int index = linearSearchReservation(reservations, id);

    if (index != -1)
        {
        // Reservation found, proceed with deletion
        reservations.erase(reservations.begin() + index);  // Erase the reservation at the found index
        cout << "Reservation with ID " << id << " has been deleted successfully!" << endl;

        // Optionally sort the remaining reservations (by id)
        bubbleSortReservationsById(reservations);
    }
    else
        {
        cout << "Reservation with ID " << id << " not found." << endl;
    }
}

// Linear Search to find payment by id
int linearSearchPayment(const vector<Payment>& payments, int id)
{
    for (int i = 0; i < payments.size(); i++)
        {
        if (payments[i].id == id)
        {
            return i;  // Return the index of the payment if found
        }
    }
    return -1;  // Return -1 if the payment is not found
}

// Bubble Sort to sort payments by id (optional)
void bubbleSortPaymentsById(vector<Payment>& payments)
{
    int n = payments.size();
    for (int i = 0; i < n - 1; i++)
        {
        for (int j = 0; j < n - i - 1; j++)
         {
            if (payments[j].id > payments[j + 1].id)
            {
                swap(payments[j], payments[j + 1]);  // Swap if the order is incorrect
            }
        }
    }
}


// Function to edit a payment
void editPayment(vector<Payment>& payments)
 {
    int id;
    cout << "Enter the payment ID to edit: ";
    cin >> id;

    // Perform Linear Search to find the payment
    int index = linearSearchPayment(payments, id);

    if (index != -1)
        {
        // Payment found, prompt the user to edit the payment details
        cout << "Editing Payment with ID " << id << ":\n";

        // Edit payment details (this example allows editing totalAmount and paymentStatus)
        cout << "Enter new total amount: ";
        cin >> payments[index].totalAmount;
        cout << "Enter new payment status: ";
        cin.ignore();  // To clear the buffer
        getline(cin, payments[index].paymentStatus);

        cout << "Payment with ID " << id << " has been edited successfully!" << endl;

        // Optionally sort the payments (by id)
        bubbleSortPaymentsById(payments);
    }
     else
        {
        cout << "Payment with ID " << id << " not found." << endl;
    }
}

// Function to delete a payment
void deletePayment(vector<Payment>& payments)
 {
    int id;
    cout << "Enter the payment ID to delete: ";
    cin >> id;

    // Perform Linear Search to find the payment
    int index = linearSearchPayment(payments, id);

    if (index != -1)
        {
        // Payment found, remove it from the vector
        payments.erase(payments.begin() + index);
        cout << "Payment with ID " << id << " has been deleted successfully!" << endl;
    }
    else
        {
        cout << "Payment with ID " << id << " not found." << endl;
    }
}


// Function to view reservations by a specific customer   //Linear search
void viewReservationsByCustomer(const std::vector<Reservation>& reservations, const std::vector<Customer>& customers)
 {
    int customerId;
    std::cout << "Enter customer ID to view their reservations: ";
    std::cin >> customerId;

    bool found = false;
    for (const Reservation& reservation : reservations)
        {
        if (reservation.customerId == customerId)
        {
            std::cout << "Reservation ID: " << reservation.id
                      << ", Hotel ID: " << reservation.hotelId
                      << ", Date: " << reservation.reservationDate
                      << ", Room Type: " << reservation.roomType
                      << ", Bed Type: " << reservation.bedType
                      << ", Duration: " << reservation.durationOfStay
                      << " days, Room Number: " << reservation.roomNumber
                      << ", Rate: $" << reservation.roomRate
                      << ", Status: " << reservation.bookingStatus
                      << std::endl;
            found = true;
        }
    }

    if (!found)
        {
        std::cout << "No reservations found for Customer ID " << customerId << std::endl;
    }
}


// Brute force search to find payments by reservationId
void viewPaymentByReservation(const vector<Payment>& payments, const vector<Reservation>& reservations)
{
    int reservationId;
    cout << "Enter the reservation ID to view its payment details: ";
    cin >> reservationId;

    bool found = false;
    // Brute force search through payments
    for (const Payment& payment : payments)
        {
        if (payment.reservationId == reservationId)
         {
            // If reservationId matches, display payment details
            cout << "Payment ID: " << payment.id << ", Reservation ID: " << payment.reservationId
                 << ", Payment Time: " << payment.paymentTime << ", Confirmation Date: "
                 << payment.paymentConfirmationDate << ", Total Amount: $" << payment.totalAmount
                 << ", Payment Type: " << payment.paymentType << ", Payment Status: " << payment.paymentStatus
                 << endl;
            found = true;
        }
    }

    if (!found)
        {
        cout << "No payment found for reservation ID " << reservationId << endl;
    }
}


// Binary search to find the customer index by id
int binarySearchCustomer(const std::vector<Customer>& customers, int customerId)
 {
    int left = 0, right = customers.size() - 1;
    while (left <= right)
        {
        int mid = left + (right - left) / 2;
        if (customers[mid].id == customerId)
            {
            return mid;
        }
    else if (customers[mid].id < customerId)
        {
            left = mid + 1;
        }
    else
        {
            right = mid - 1;
        }
    }
    return -1;  // Customer not found
}


// Function to view payments by customer using binary search
void viewPaymentByCustomer(const std::vector<Payment>& payments, const std::vector<Customer>& customers)
 {
    int customerId;
    std::cout << "Enter Customer ID: ";
    std::cin >> customerId;

    // Use binary search to find the customer in the customers list
    int customerIndex = binarySearchCustomer(customers, customerId);

    if (customerIndex == -1)
        {
        std::cout << "Customer not found.\n";
        return;
    }

    std::cout << "Payments for Customer ID " << customerId << ":\n";
    bool found = false;

    // Iterate over the payments and display those related to the customerId
    for (const Payment& payment : payments)
        {
        if (payment.reservationId == customerId)
         {  // Match reservationId with customerId
            std::cout << "Payment ID: " << payment.id
                      << ", Payment Time: " << payment.paymentTime
                      << ", Confirmation Date: " << payment.paymentConfirmationDate
                      << ", Amount: " << payment.totalAmount
                      << ", Type: " << payment.paymentType
                      << ", Status: " << payment.paymentStatus << "\n";
            found = true;
        }
    }

    if (!found)
        {
        std::cout << "No payments found for this customer.\n";
    }
}


// Heapify function to maintain the heap property
void heapify(vector<Hotel>& hotels, int n, int i)
 {
    int largest = i; // Initialize largest as root
    int left = 2 * i + 1; // Left child
    int right = 2 * i + 2; // Right child

    // If left child is larger than root
    if (left < n && hotels[left].starRating > hotels[largest].starRating)
        {
        largest = left;
    }

    // If right child is larger than largest
    if (right < n && hotels[right].starRating > hotels[largest].starRating)
        {
        largest = right;
    }

    // If largest is not root, swap and continue heapifying
    if (largest != i)
        {
        swap(hotels[i], hotels[largest]);
        heapify(hotels, n, largest);
    }
}


// Function to perform Heap Sort
void heapSort(vector<Hotel>& hotels)
 {
    int n = hotels.size();

    // Build a max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        {
        heapify(hotels, n, i);
    }

    // One by one extract elements from the heap
    for (int i = n - 1; i >= 0; i--)
        {
        // Move current root to end
        swap(hotels[0], hotels[i]);

        // Call max heapify on the reduced heap
        heapify(hotels, i, 0);
    }
}


void displayHotelsByStarRating(const vector<Hotel>& hotels)
 {
    int starRating;
    cout << "Enter the star rating to filter hotels: ";
    cin >> starRating;

    // Filter hotels based on star rating
    vector<Hotel> filteredHotels;
    for (const auto& hotel : hotels)
        {
        if (hotel.starRating == starRating)
        {
            filteredHotels.push_back(hotel);
        }
    }

    if (filteredHotels.empty())
        {
        cout << "No hotels found with " << starRating << " stars." << endl;
        return;
    }

    // Perform Heap Sort on the filtered hotels
    heapSort(filteredHotels);

    // Display hotels sorted by star rating
    cout << "\nHotels with " << starRating << " stars, sorted by rating:\n";
    for (const auto& hotel : filteredHotels)
        {
        cout << "Hotel ID: " << hotel.id
             << ", Name: " << hotel.name
             << ", Location: " << hotel.location
             << ", Star Rating: " << hotel.starRating
             << ", Rooms Available: " << hotel.roomsAvailable
             << ", Type: " << hotel.typeOfHotel << endl;
    }
}





void generateHotelAvailabilityReport(const vector<Hotel>& hotels)
 {
    std::cout << "\nHotel Availability Report:\n";
    std::cout << "------------------------------------------------------------\n";
    std::cout << "Hotel ID | Hotel Name            | Location       | Available Rooms | Star Rating\n";
    std::cout << "------------------------------------------------------------\n";

    for (const auto& hotel : hotels)
        {
        std::cout << hotel.id << " | "
                  << hotel.name << " | "
                  << hotel.location << " | "
                  << hotel.roomsAvailable << " | "
                  << hotel.starRating << "\n";
    }

    std::cout << "------------------------------------------------------------\n";
}


void generateNumberOfRoomsByUsertoFindWhichHotel(std::vector<Hotel>& hotels, int roomCount)
{
    // Step 1: Sort hotels by roomsAvailable using Selection Sort
    for (size_t i = 0; i < hotels.size() - 1; ++i)
        {
        size_t minIndex = i;
        for (size_t j = i + 1; j < hotels.size(); ++j)
        {
            if (hotels[j].roomsAvailable < hotels[minIndex].roomsAvailable)
             {
                minIndex = j;
            }
        }
        std::swap(hotels[i], hotels[minIndex]);
    }

    // Step 2: Perform Linear Search to find hotels with roomsAvailable >= roomCount
    bool found = false;
    for (const auto& hotel : hotels)
        {
        if (hotel.roomsAvailable >= roomCount)
        {
            std::cout << "Hotel: " << hotel.name << ", Available Rooms: " << hotel.roomsAvailable << std::endl;
            found = true;
        }
    }

    // Step 3: If no matching hotels are found
    if (!found)
        {
        std::cout << "No hotels found with at least " << roomCount << " available rooms.\n";
    }
}


// Function to perform Binary Search to find a customer by ID
int binarySearch(const vector<Customer>& customers, int id)
 {
    int low = 0;
    int high = customers.size() - 1;

    while (low <= high)
        {
        int mid = low + (high - low) / 2;

        // Check if the id is present at mid
        if (customers[mid].id == id)
            {
            return mid;
        }

        // If id is smaller, ignore the right half
        if (customers[mid].id > id)
            {
            high = mid - 1;
        }
        // If id is greater, ignore the left half
        else
         {
            low = mid + 1;
        }
    }

    return -1; // Customer not found
}


// Function to update customer age
void updateCustomerAge(vector<Customer>& customers)
 {
    int customerId;
    cout << "Enter the Customer ID whose age you want to update: ";
    cin >> customerId;

    // Sort the customers vector by ID before performing binary search
    sort(customers.begin(), customers.end(), [](const Customer& a, const Customer& b)
          {
        return a.id < b.id;
    });

    // Perform binary search to find the customer by ID
    int index = binarySearch(customers, customerId);

    if (index == -1)
        {
        cout << "Customer with ID " << customerId << " not found." << endl;
    }
    else
    {
        cout << "Customer found: " << customers[index].name << endl;
        cout << "Current age: " << customers[index].age << endl;

        // Get new age from user
        int newAge;
        cout << "Enter new age: ";
        cin >> newAge;

        // Update the age
        customers[index].age = newAge;
        cout << "Age updated successfully!" << endl;
    }
}


void findCustomerByName(const std::vector<Customer>& customers, const std::string& searchName)
{
    // Helper function to build the KMP prefix table
    auto buildKMPTable = [](const std::string& pattern)
     {
        std::vector<int> prefix(pattern.length(), 0);
        int j = 0;
        for (int i = 1; i < pattern.length(); ++i)
            {
            if (pattern[i] == pattern[j])
            {
                prefix[i] = ++j;
            } else if (j > 0)
            {
                j = prefix[j - 1];
                --i; // Maintain i for next loop iteration
            }
        }
        return prefix;
    };

    // Helper function to perform KMP search
    auto kmpSearch = [&](const std::string& text, const std::string& pattern)
     {
        std::vector<int> prefix = buildKMPTable(pattern);
        int j = 0; // Index for pattern
        for (int i = 0; i < text.length(); ++i)
            {
            if (text[i] == pattern[j])
            {
                if (++j == pattern.length())
                 {
                    return true; // Match found
                }
            }
            else if (j > 0)
             {
                j = prefix[j - 1];
                --i; // Maintain i for next loop iteration
            }
        }
        return false;
    };

    // Search for the customer using KMP algorithm
    bool found = false;
    for (const auto& customer : customers)
        {
        if (kmpSearch(customer.name, searchName))
        {
            std::cout << "Customer Found: ID: " << customer.id
                      << ", Name: " << customer.name
                      << ", Age: " << customer.age
                      << ", Email: " << customer.email << std::endl;
            found = true;
        }
    }

    if (!found)
        {
        std::cout << "No customer found with the name containing \"" << searchName << "\".\n";
    }
}

//Linear search
void findHotelByName(const std::vector<Hotel>& hotels, const std::string& hotelName)
 {
    bool found = false;
    for (const auto& hotel : hotels)
        {
        if (hotel.name == hotelName)
        {
            std::cout << "Hotel Found: ID: " << hotel.id
                      << ", Name: " << hotel.name
                      << ", Location: " << hotel.location
                      << ", Rooms Available: " << hotel.roomsAvailable
                      << ", Star Rating: " << hotel.starRating
                      << ", Type of Hotel: " << hotel.typeOfHotel
                      << ", Dining Options: " << hotel.diningOptions
                      << ", Parking: " << (hotel.parking ? "Yes" : "No")
                      << ", WiFi: " << (hotel.wifi ? "Yes" : "No")
                      << ", Event Spaces: " << hotel.eventSpaces
                      << ", Room Service: " << hotel.roomService
                      << ", Housekeeping: " << hotel.housekeeping
                      << ", Transportation: " << hotel.transportation
                      << ", Cancellation Policy: " << hotel.cancellationPolicy
                      << "\n";
            found = true;
            break;
        }
    }
    if (!found)
     {
        std::cout << "No hotel found with the name: " << hotelName << "\n";
    }
}


// Merge Sort to sort hotels by location
void merge(vector<Hotel>& hotels, int left, int right)
 {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge(hotels, left, mid);
        merge(hotels, mid + 1, right);

        int n1 = mid - left + 1;
        int n2 = right - mid;

        vector<Hotel> leftArr(n1);
        vector<Hotel> rightArr(n2);

        for (int i = 0; i < n1; i++) leftArr[i] = hotels[left + i];
        for (int i = 0; i < n2; i++) rightArr[i] = hotels[mid + 1 + i];

        int i = 0, j = 0, k = left;
        while (i < n1 && j < n2)
            {
            if (leftArr[i].location <= rightArr[j].location)
            {
                hotels[k] = leftArr[i];
                i++;
            }
        else
            {
                hotels[k] = rightArr[j];
                j++;
            }
            k++;
        }

        while (i < n1)
            {
            hotels[k] = leftArr[i];
            i++;
            k++;
        }

        while (j < n2)
            {
            hotels[k] = rightArr[j];
            j++;
            k++;
        }
    }
}


// Binary Search to find hotel by location
int binarySearch(const vector<Hotel>& hotels, const string& location)
 {
    int left = 0;
    int right = hotels.size() - 1;

    while (left <= right)
        {
        int mid = left + (right - left) / 2;

        if (hotels[mid].location == location)
            {
            return mid;  // Found the hotel at index mid
        }

        if (hotels[mid].location < location)
            {
            left = mid + 1;
        }
        else
            {
            right = mid - 1;
        }
    }
    return -1;  // Hotel not found
}


void searchHotelByLocation(const vector<Hotel>& hotels, const string& location)
 {
    vector<Hotel> sortedHotels = hotels; // Create a copy of the hotels vector
    merge(sortedHotels, 0, sortedHotels.size() - 1);  // Sort the hotels by location

    int index = binarySearch(sortedHotels, location);

    if (index != -1)
        {
        const Hotel& hotel = sortedHotels[index];
        cout << "Hotel ID: " << hotel.id
             << ", Name: " << hotel.name
             << ", Location: " << hotel.location
             << ", Rooms Available: " << hotel.roomsAvailable
             << ", Star Rating: " << hotel.starRating
             << ", Type: " << hotel.typeOfHotel << endl;
    }
    else
        {
        cout << "No hotel found in location: " << location << endl;
    }
}


void computeLPSArray(const string& pattern, vector<int>& lps)
{
    int length = 0;
    lps[0] = 0; // LPS[0] is always 0
    int i = 1;
    while (i < pattern.size())
    {
        if (pattern[i] == pattern[length])
        {
            length++;
            lps[i] = length;
            i++;
        }
        else
        {
            if (length != 0)
            {
                length = lps[length - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }
}


bool KMPSearch(const string& text, const string& pattern)
{
    int n = text.size();
    int m = pattern.size();
    vector<int> lps(m);
    computeLPSArray(pattern, lps);

    int i = 0; // Index for text
    int j = 0; // Index for pattern
    while (i < n)
    {
        if (pattern[j] == text[i])
        {
            j++;
            i++;
        }
        if (j == m)
        {
            return true; // Match found
        }
        else if (i < n && pattern[j] != text[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return false; // No match
}


void searchCustomersByOccupation(const vector<Customer>& customers, const string& occupationPattern)
{
    cout << "Searching for customers with occupation matching: " << occupationPattern << endl;
    bool found = false;

    for (const auto& customer : customers)
    {
        if (KMPSearch(customer.occupation, occupationPattern))
        {
            cout << "Customer ID: " << customer.id << "\n"
                 << "Name: " << customer.name << "\n"
                 << "Contact: " << customer.contact << "\n"
                 << "Age: " << customer.age << "\n"
                 << "Gender: " << customer.gender << "\n"
                 << "Nationality: " << customer.nationality << "\n"
                 << "Occupation: " << customer.occupation << "\n"
                 << "Email: " << customer.email << "\n\n";
            found = true;
        }
    }

    if (!found)
    {
        cout << "No customers found with the specified occupation pattern.\n";
    }
}


void searchReservationsByStatusBoyerMoore(const vector<Reservation>& reservations, const string& status)
{
    auto preprocessBadChar = [](const string& pattern, vector<int>& badChar)
    {
        int m = pattern.size();
        for (int i = 0; i < 256; ++i) badChar[i] = -1;
        for (int i = 0; i < m; ++i) badChar[pattern[i]] = i;
    };

    bool found = false;
    cout << "\n[Boyer-Moore] Reservations with status '" << status << "':\n";
    cout << "-----------------------------------------------------\n";

    for (const auto& reservation : reservations)
        {
        const string& text = reservation.bookingStatus;
        int n = text.size();
        int m = status.size();
        vector<int> badChar(256);
        preprocessBadChar(status, badChar);

        int shift = 0;
        while (shift <= n - m)
            {
            int j = m - 1;
            while (j >= 0 && status[j] == text[shift + j])
            {
                j--;
            }

            if (j < 0) {
                found = true;
                cout << "Reservation ID: " << reservation.id << ", Booking Status: " << reservation.bookingStatus << "\n";
                shift += (shift + m < n) ? m - badChar[text[shift + m]] : 1;
            }
             else
                {
                shift += max(1, j - badChar[text[shift + j]]);
            }
        }
    }

    if (!found)
        {
        cout << "No reservations found with status '" << status << "'.\n";
    }
}


// Quick Sort Implementation for Sorting Reservations by ID
void quickSort(vector<Reservation>& reservations, int low, int high)
 {
    if (low < high)
        {
        int pivot = reservations[high].id; // Pivot is the last element
        int i = low - 1;

        for (int j = low; j < high; ++j)
            {
            if (reservations[j].id <= pivot)
             {
                ++i;
                swap(reservations[i], reservations[j]);
            }
        }
        swap(reservations[i + 1], reservations[high]);
        int partitionIndex = i + 1;

        quickSort(reservations, low, partitionIndex - 1);
        quickSort(reservations, partitionIndex + 1, high);
    }
}


// Binary Search to Find Reservation by ID
int binarySearchReservation(const vector<Reservation>& reservations, int id)
{
    int low = 0, high = reservations.size() - 1;

    while (low <= high)
        {
        int mid = low + (high - low) / 2;

        if (reservations[mid].id == id) return mid;
        else if (reservations[mid].id < id) low = mid + 1;
        else high = mid - 1;
    }
    return -1; // Not found
}

// Linear Search to Find Hotel by ID
int linearSearchHotel(const vector<Hotel>& hotels, int hotelId)
 {
    for (size_t i = 0; i < hotels.size(); ++i)
        {
        if (hotels[i].id == hotelId)
         {
            return i;
        }
    }
    return -1; // Not found
}


void ExtendReservationDuration(vector<Reservation>& reservations, vector<Hotel>& hotels)
{
    // Sort reservations by ID using Quick Sort
    quickSort(reservations, 0, reservations.size() - 1);

    int reservationId;
    cout << "Enter Reservation ID to extend duration: ";
    cin >> reservationId;

    // Find the reservation using Binary Search
    int reservationIndex = binarySearchReservation(reservations, reservationId);
    if (reservationIndex == -1)
        {
        cout << "Reservation ID not found.\n";
        return;
    }

    // Find the associated hotel using Linear Search
    int hotelIndex = linearSearchHotel(hotels, reservations[reservationIndex].hotelId);
    if (hotelIndex == -1)
        {
        cout << "Associated hotel not found.\n";
        return;
    }

    // Check if the hotel has available rooms
    if (hotels[hotelIndex].roomsAvailable <= 0)
        {
        cout << "No rooms available to extend the reservation.\n";
        return;
    }

    int additionalDays;
    cout << "Enter additional days to extend: ";
    cin >> additionalDays;

    if (additionalDays <= 0)
        {
        cout << "Invalid number of additional days.\n";
        return;
    }

    // Extend the duration and update room rate
    reservations[reservationIndex].durationOfStay += additionalDays;
    reservations[reservationIndex].roomRate += (additionalDays * reservations[reservationIndex].roomRate / reservations[reservationIndex].durationOfStay);

    cout << "Reservation extended successfully!\n";
    cout << "Updated Duration: " << reservations[reservationIndex].durationOfStay << " days\n";
    cout << "Updated Total Room Rate: $" << fixed << setprecision(2) << reservations[reservationIndex].roomRate << "\n";

    // Update available rooms in the hotel
    hotels[hotelIndex].roomsAvailable -= 1;
}


// Function to perform Selection Sort on the payments vector based on the payment ID
void selectionSort(vector<Payment>& payments)
 {
    for (int i = 0; i < payments.size() - 1; ++i) {
        int minIdx = i;
        for (int j = i + 1; j < payments.size(); ++j) {
            if (payments[j].id < payments[minIdx].id) {
                minIdx = j;
            }
        }
        // Swap the elements
        swap(payments[i], payments[minIdx]);
    }
}


// Binary Search function to find payment by ID
int binarySearch(const vector<Payment>& payments, int paymentId)
 {
    int low = 0, high = payments.size() - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (payments[mid].id == paymentId)
        {

            return mid;
        }
        else if (payments[mid].id < paymentId)
        {

            low = mid + 1;
        }
        else
            {
            high = mid - 1;
            }
    }
    return -1; // Not found
}


// Boyer-Moore Algorithm for string search (optional for status match)
int boyerMooreSearch(const string& text, const string& pattern)
{
    int m = pattern.size();
    int n = text.size();

    if (m > n)
    {
        return -1;
    }
    int badChar[256];
    fill(begin(badChar), end(badChar), -1);

    for (int i = 0; i < m; i++)
        {
        badChar[pattern[i]] = i;
    }

    int s = 0;
    while (s <= (n - m))
        {
        int j = m - 1;
        while (j >= 0 && pattern[j] == text[s + j])
        {
            j--;
        }

        if (j < 0)
            {
            return s;  // Match found
            s += (s + m < n) ? m - badChar[text[s + m]] : 1;
        }
        else
            {
            s += max(1, j - badChar[text[s + j]]);
        }
    }
    return -1;  // No match found
}


// Function to update the payment status using the above algorithms
void updatePaymentStatus(vector<Payment>& payments, int paymentId, const string& newStatus)
{
    // Step 1: Sort payments by payment ID using Selection Sort
    selectionSort(payments);

    // Step 2: Search for the payment using Binary Search
    int index = binarySearch(payments, paymentId);
    if (index != -1)
        {
        // Step 3: Update payment status
        payments[index].paymentStatus = newStatus;
        cout << "Payment status updated successfully!" << endl;
    }
    else
        {
        cout << "Payment ID not found!" << endl;
    }
}


// Merge Sort Function
void merge(vector<Hotel>& hotels, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<Hotel> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = hotels[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = hotels[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (L[i].parking <= R[j].parking)
            hotels[k++] = L[i++];
        else
            hotels[k++] = R[j++];
    }

    while (i < n1)
        hotels[k++] = L[i++];
    while (j < n2)
        hotels[k++] = R[j++];
}


// Merge Sort to sort hotels based on parking availability
void mergeSort(vector<Hotel>& hotels, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(hotels, left, mid);
        mergeSort(hotels, mid + 1, right);
        merge(hotels, left, mid, right);
    }
}

// Binary Search Function to find hotels with parking
vector<Hotel> binarySearch(const vector<Hotel>& hotels)
{
    int low = 0, high = hotels.size() - 1;
    vector<Hotel> result;

    // Binary search for first hotel with parking
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (hotels[mid].parking)
        {
            result.push_back(hotels[mid]);
            // Continue checking for other hotels with parking in the left and right parts
            int left = mid - 1;
            while (left >= 0 && hotels[left].parking)
            {
                result.push_back(hotels[left]);
                left--;
            }
            int right = mid + 1;
            while (right < hotels.size() && hotels[right].parking)
            {
                result.push_back(hotels[right]);
                right++;
            }
            break;
        }
        else if (hotels[mid].parking == false)
            high = mid - 1;
    }

    return result;
}


// Function to find hotels with parking using Merge Sort and Binary Search
void findHotelsWithParking(vector<Hotel>& hotels)
{
    // Step 1: Sort hotels based on parking availability using Merge Sort
    mergeSort(hotels, 0, hotels.size() - 1);

    // Step 2: Use Binary Search to find hotels with parking
    vector<Hotel> hotelsWithParking = binarySearch(hotels);

    // If no hotels with parking are found
    if (hotelsWithParking.empty())
    {
        cout << "No hotels found with parking available." << endl;
        return;
    }

    // Display the hotels with parking
    cout << "Hotels with parking available:\n";
    for (const auto& hotel : hotelsWithParking)
    {
        cout << "Hotel Name: " << hotel.name << ", Location: " << hotel.location
             << ", Rooms Available: " << hotel.roomsAvailable << ", Star Rating: "
             << hotel.starRating << " stars\n";
    }
}

void UpdateHotelRoomAvailability(vector<Hotel>& hotels, vector<Reservation>& reservations)
 {
    int hotelId;
    cout << "Enter the Hotel ID to update room availability: ";
    cin >> hotelId;

    // Find the hotel by ID
    auto hotelIt = find_if(hotels.begin(), hotels.end(), [hotelId](const Hotel& hotel)
                            {
        return hotel.id == hotelId;
    });

    if (hotelIt != hotels.end())
        {
        Hotel& hotel = *hotelIt;

        // Display current availability
        cout << "Current rooms available for " << hotel.name << ": " << hotel.roomsAvailable << endl;

        // Option to either add or remove rooms based on reservations
        string action;
        cout << "Do you want to (1) Add rooms or (2) Remove rooms based on reservations? (Enter 1 or 2): ";
        cin >> action;

        if (action == "1")
            {
            // Add rooms (for example, when rooms become available after cancellation)
            int roomsToAdd;
            cout << "Enter number of rooms to add: ";
            cin >> roomsToAdd;
            hotel.roomsAvailable += roomsToAdd;
            cout << "Rooms added. New availability: " << hotel.roomsAvailable << endl;
        } else if (action == "2")
        {
            // Remove rooms based on confirmed reservations
            int roomsToRemove;
            cout << "Enter number of rooms to remove (based on confirmed reservations): ";
            cin >> roomsToRemove;

            if (roomsToRemove <= hotel.roomsAvailable)
                {
                hotel.roomsAvailable -= roomsToRemove;
                cout << "Rooms removed. New availability: " << hotel.roomsAvailable << endl;
            }
            else
                {
                cout << "Error: Not enough rooms available to remove." << endl;
            }
        }
        else
            {
            cout << "Invalid action selected." << endl;
        }

        // Optionally, update the reservations based on changes in availability
        cout << "Do you want to update room availability based on reservations? (yes/no): ";
        string updateReservations;
        cin >> updateReservations;

        if (updateReservations == "yes")
            {
            for (auto& reservation : reservations)
             {
                if (reservation.hotelId == hotel.id)
                 {
                    if (reservation.bookingStatus == "confirmed" && hotel.roomsAvailable > 0)
                    {
                        hotel.roomsAvailable--;  // Decrease availability for confirmed reservations
                        cout << "Updated availability for reservation " << reservation.id << ". Rooms available: " << hotel.roomsAvailable << endl;
                    }
        else if (reservation.bookingStatus == "canceled")
            {
                        hotel.roomsAvailable++;  // Increase availability for canceled reservations
                        cout << "Updated availability for canceled reservation " << reservation.id << ". Rooms available: " << hotel.roomsAvailable << endl;
                    }
                }
            }
        }

    }
    else
        {
        cout << "Hotel not found with ID " << hotelId << endl;
    }
}


// Bubble Sort function to sort hotels by their id
void bubbleSort(vector<Hotel>& hotels)
 {
    int n = hotels.size();
    for (int i = 0; i < n - 1; i++)
        {
        // Last i elements are already in place
        for (int j = 0; j < n - i - 1; j++)
        {
            if (hotels[j].id > hotels[j + 1].id)
             {
                swap(hotels[j], hotels[j + 1]);
            }
        }
    }
}


// Function to find and display hotels with WiFi and sort them by id
void HotelWithWifi(vector<Hotel>& hotels)
 {
    vector<Hotel> hotelsWithWifi;

    // Filter hotels that have WiFi
    for (const auto& hotel : hotels)
        {
        if (hotel.wifi)
         {
            hotelsWithWifi.push_back(hotel);
        }
    }

    // If there are hotels with WiFi, sort them by id using Bubble Sort
    if (!hotelsWithWifi.empty())
        {
        bubbleSort(hotelsWithWifi);

        // Display the sorted hotels with WiFi
        cout << "Hotels with WiFi:\n";
        for (const auto& hotel : hotelsWithWifi)
            {
            cout << "ID: " << hotel.id << ", Name: " << hotel.name
                 << ", Location: " << hotel.location
                 << ", Star Rating: " << hotel.starRating << endl;
        }
    }
    else
        {
        cout << "No hotels found with WiFi.\n";
    }
}


// Rabin-Karp algorithm for pattern matching (string search)
int rabinKarpSearch(const vector<Customer>& customers, const string& targetName)
 {
    const int d = 256;  // Number of characters in the input alphabet
    const int q = 101;  // A prime number for hashing

    int m = targetName.length();
    int n = customers.size();
    int h = 1;

    // Calculate hash value for the target string
    int patternHash = 0;
    for (int i = 0; i < m; i++)
        {
        patternHash = (d * patternHash + targetName[i]) % q;
    }

    // Calculate hash value for the first window of text
    int currentHash = 0;
    for (int i = 0; i < m; i++)
     {

        currentHash = (d * currentHash + customers[i].name[i]) % q;
    }

    // Precompute the value of d^(m-1) for use in removing the leading character
    for (int i = 0; i < m - 1; i++)
        {
        h = (h * d) % q;
    }

    // Slide the window over the string
    for (int i = 0; i <= n - m; i++)
        {
        if (patternHash == currentHash)
         {
            // If the hash values match, check for the actual substring match
            if (customers[i].name.substr(0, m) == targetName)
            {
                return i;  // Found the customer with the matching name
            }
        }

        // If we haven't reached the end of the text, slide the window
        if (i < n - m)
            {
            currentHash = (d * (currentHash - customers[i].name[0] * h) + customers[i + 1].name[m - 1]) % q;
            if (currentHash < 0)
            {
                currentHash = (currentHash + q);
            }
        }
    }
    return -1;  // Customer not found
}


// Function to update customer email using Rabin-Karp algorithm
void UpdateCustomerEmail(vector<Customer>& customers)
 {
    string targetName;
    string newEmail;

    // Ask user for the customer's name to update
    cout << "Enter the customer's name to update email: ";
    cin.ignore();  // To ignore any leftover newline character
    getline(cin, targetName);

    // Use Rabin-Karp algorithm to find the customer by name
    int index = rabinKarpSearch(customers, targetName);

    if (index != -1)
        {
        // Customer found, ask for new email
        cout << "Enter the new email for customer " << customers[index].name << ": ";
        cin >> newEmail;

        // Update the email
        customers[index].email = newEmail;
        cout << "Email updated successfully for customer " << customers[index].name << "!" << endl;
    }
    else
        {
        // Customer not found
        cout << "Customer with name " << targetName << " not found!" << endl;
    }
}


// Dijkstra's Algorithm to find the customer with the most urgent pending payment
void dijkstraPaymentReminder(const vector<Reservation>& reservations, const vector<Payment>& payments, vector<Customer>& customers)
{
    // Create a priority queue to hold customers with "pending" payments
    vector<pair<int, string>> reminderQueue;  // Pair: (priority, customer name)

    // Set a priority based on booking status and payment status
    for (const auto& payment : payments)
        {
        if (payment.paymentStatus == "pending")
        {
            for (const auto& reservation : reservations)
             {
                if (reservation.id == payment.reservationId)
                 {
                    for (const auto& customer : customers)
                    {
                        if (customer.id == reservation.customerId)
                        {
                            // Use reservation duration as priority (longer durations = higher priority)
                            int priority = reservation.durationOfStay;
                            reminderQueue.push_back(make_pair(priority, customer.name));
                        }
                    }
                }
            }
        }
    }

    // Sort customers by priority (highest first)
    sort(reminderQueue.begin(), reminderQueue.end(), greater<pair<int, string>>());

    // Send reminders to customers with the highest priority
    for (const auto& reminder : reminderQueue)
        {
        cout << "Sending payment reminder to " << reminder.second << " with priority " << reminder.first << endl;
    }
}


// Function to send a payment reminder to customers
void SendPaymentRemindertoCustomer(vector<Reservation>& reservations, vector<Payment>& payments, vector<Customer>& customers)
{
    // Call Dijkstra-like algorithm for payment reminders
    dijkstraPaymentReminder(reservations, payments, customers);
}

// Function to find hotels with room service
void FindHotelsWithRoomService(const vector<Hotel>& hotels)
{
    // Vector to store hotels that offer room service
    vector<Hotel> hotelsWithRoomService;

    // Linear search to find hotels with room service
    for (const auto& hotel : hotels)
    {
        if (hotel.roomService != "No room service" && hotel.roomService != "")
        {
            hotelsWithRoomService.push_back(hotel);
        }
    }

    // If no hotels with room service are found
    if (hotelsWithRoomService.empty())
    {
        cout << "No hotels with room service available.\n";
        return;
    }

    // Selection Sort: Sort the hotels by name
    for (size_t i = 0; i < hotelsWithRoomService.size() - 1; ++i)
    {
        size_t minIndex = i;
        for (size_t j = i + 1; j < hotelsWithRoomService.size(); ++j)
        {
            if (hotelsWithRoomService[j].name < hotelsWithRoomService[minIndex].name)
            {
                minIndex = j;
            }
        }
        // Swap the hotels if needed
        swap(hotelsWithRoomService[i], hotelsWithRoomService[minIndex]);
    }

    // Print the list of hotels with room service, sorted by name
    cout << "Hotels with Room Service:\n";
    for (const auto& hotel : hotelsWithRoomService)
    {
        cout << hotel.name << " - " << hotel.location << " - " << hotel.roomService << endl;
    }
}

vector<int> preprocessBadCharacter(const string& pattern)
{
    map<char, int> badCharTable;
    int m = pattern.size();

    // Fill the bad character table with default values
    for (int i = 0; i < m; i++)
    {
        badCharTable[pattern[i]] = i;
    }

    vector<int> badCharShift(256, m); // Default shift is the length of the pattern
    for (int i = 0; i < m; i++)
    {
        badCharShift[pattern[i]] = m - i - 1;
    }

    return badCharShift;
}

void ViewCustomerContactInformationByName(const vector<Customer>& customers, const string& searchName)
{
    for (const auto& customer : customers)
    {
        int position = boyerMooreSearch(customer.name, searchName);
        if (position != -1) // Found the pattern in the customer's name
        {
            cout << "Customer Contact Information:" << endl;
            cout << "--------------------------------" << endl;
            cout << "Name: " << customer.name << endl;
            cout << "Contact: " << customer.contact << endl;
            cout << "Email: " << customer.email << endl;
            cout << "--------------------------------" << endl;
            return;
        }
    }

    cout << "Customer with name containing \"" << searchName << "\" not found." << endl;
}


void SearchHotelsbyDiningOptions(const vector<Hotel>& hotels, const string& diningOption)
{
    // Boyer-Moore Helper Function
    auto boyerMooreSearch = [](const string& text, const string& pattern) -> bool
     {
        int m = pattern.size();
        int n = text.size();

        if (m > n) return false;

        // Preprocessing: Create the bad character table
        vector<int> badChar(256, -1);
        for (int i = 0; i < m; ++i)
            {
            badChar[pattern[i]] = i;
        }

        // Searching
        int shift = 0;
        while (shift <= (n - m))
            {
            int j = m - 1;

            // Move from right to left
            while (j >= 0 && pattern[j] == text[shift + j])
                {
                j--;
            }

            // If pattern is found
            if (j < 0)
                {
                return true;
            }
            else
                {
                // Shift the pattern using the bad character table
                shift += max(1, j - badChar[text[shift + j]]);
            }
        }

        return false;
    };

    // Searching Hotels
    cout << "Hotels with dining option '" << diningOption << "':\n";
    bool found = false;
    for (const auto& hotel : hotels)
        {
        if (boyerMooreSearch(hotel.diningOptions, diningOption))
        {
            cout << "Hotel ID: " << hotel.id << ", Name: " << hotel.name
                 << ", Location: " << hotel.location << ", Dining Options: " << hotel.diningOptions << endl;
            found = true;
        }
    }

    if (!found)
        {
        cout << "No hotels found with the dining option: " << diningOption << endl;
    }
}

void SearchReservationsbyRoom(const vector<Reservation>& reservations, const string& roomType)
 {
    // KMP Helper Function
    auto kmpSearch = [](const string& text, const string& pattern) -> bool
     {
        int m = pattern.size();
        int n = text.size();

        // Compute the LPS array
        vector<int> lps(m, 0);
        int len = 0;
        for (int i = 1; i < m;)
            {
            if (pattern[i] == pattern[len])
             {
                lps[i++] = ++len;
            }
        else if (len > 0)
            {
                len = lps[len - 1];
            }
        else
            {
                lps[i++] = 0;
            }
        }

        // Perform KMP search
        int i = 0, j = 0;
        while (i < n)
            {
            if (pattern[j] == text[i])
            {
                i++;
                j++;
            }
            if (j == m)
            {
                return true;
            } else if (i < n && pattern[j] != text[i])
             {
                if (j > 0)
                 {
                    j = lps[j - 1];
                }
        else
            {
                    i++;
                }
            }
        }

        return false;
    };

    // Searching Reservations
    cout << "Reservations with room type '" << roomType << "':\n";
    bool found = false;
    for (const auto& reservation : reservations)
        {
        if (kmpSearch(reservation.roomType, roomType))

 {
            cout << "Reservation ID: " << reservation.id
                 << ", Customer ID: " << reservation.customerId
                 << ", Hotel ID: " << reservation.hotelId
                 << ", Room Type: " << reservation.roomType
                 << ", Bed Type: " << reservation.bedType
                 << ", Duration: " << reservation.durationOfStay << " days"
                 << ", Room Number: " << reservation.roomNumber
                 << ", Booking Status: " << reservation.bookingStatus << endl;
            found = true;
        }
    }

    if (!found)
        {
        cout << "No reservations found for the room type: " << roomType << endl;
    }
}

void SearchHotelsbyCancellationPolicy(const vector<Hotel>& hotels, const string& cancellationPolicy)
{
    // Boyer-Moore Helper Function
    auto boyerMooreSearch = [](const string& text, const string& pattern) -> bool
     {
        int m = pattern.size();
        int n = text.size();

        // Build the bad character table
        vector<int> badChar(256, -1);
        for (int i = 0; i < m; i++)
            {
            badChar[pattern[i]] = i;
        }

        int s = 0; // Shift of the pattern over text
        while (s <= (n - m))
            {
            int j = m - 1;

            // Match the pattern from right to left
            while (j >= 0 && pattern[j] == text[s + j])
                {
                j--;
            }

            // If the pattern is found
            if (j < 0)
                {
                return true;
            }
            else
                {
                // Shift the pattern
                s += max(1, j - badChar[text[s + j]]);
            }
        }
        return false;
    };

    // Searching Hotels by Cancellation Policy
    cout << "Hotels with cancellation policy '" << cancellationPolicy << "':\n";
    bool found = false;
    for (const auto& hotel : hotels)
        {
        if (boyerMooreSearch(hotel.cancellationPolicy, cancellationPolicy))
        {
            cout << "Hotel ID: " << hotel.id
                 << ", Name: " << hotel.name
                 << ", Location: " << hotel.location
                 << ", Rooms Available: " << hotel.roomsAvailable
                 << ", Star Rating: " << hotel.starRating
                 << ", Cancellation Policy: " << hotel.cancellationPolicy << endl;
            found = true;
        }
    }

    if (!found)
        {
        cout << "No hotels found with the cancellation policy: " << cancellationPolicy << endl;
    }
}


int partition(vector<Customer>& customers, int low, int high)
 {
    int pivot = customers[high].age; // Use age as the pivot
    int i = low - 1;                // Index for smaller element

    for (int j = low; j < high; j++)
        {
        if (customers[j].age <= pivot)
         {
            i++;
            swap(customers[i], customers[j]); // Swap if element is smaller than pivot
        }
    }
    swap(customers[i + 1], customers[high]); // Place pivot in the correct position
    return i + 1;                            // Return pivot index
}

void quickSort(vector<Customer>& customers, int low, int high)
 {
    if (low < high)
        {
        int pivotIndex = partition(customers, low, high); // Get the pivot index
        quickSort(customers, low, pivotIndex - 1);        // Recursively sort left of pivot
        quickSort(customers, pivotIndex + 1, high);       // Recursively sort right of pivot
    }
}



void SearchCustomersbyAge(vector<Customer>& customers, int minAge, int maxAge)
 {
    // Sort customers by age
    quickSort(customers, 0, customers.size() - 1);

    // Filter customers within the specified age range
    vector<Customer> matchingCustomers;
    for (const auto& customer : customers)
        {
        if (customer.age >= minAge && customer.age <= maxAge)
        {
            matchingCustomers.push_back(customer);
        }
    }

    // Display results
    if (matchingCustomers.empty())
        {
        cout << "No customers found in the specified age range.\n";
    }
    else
        {
        cout << "Customers between ages " << minAge << " and " << maxAge << ":\n";
        for (const auto& customer : matchingCustomers)
        {
            cout << "Customer ID: " << customer.id
                 << ", Name: " << customer.name
                 << ", Contact: " << customer.contact
                 << ", Age: " << customer.age
                 << ", Gender: " << customer.gender
                 << ", Nationality: " << customer.nationality
                 << ", Occupation: " << customer.occupation
                 << ", Email: " << customer.email << endl;
        }
    }
}


// Function to perform Selection Sort on reservations based on duration of stay
void selectionSort(vector<Reservation>& reservations)
{
    int n = reservations.size();
    for (int i = 0; i < n - 1; i++)
        {
        int minIdx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (reservations[j].durationOfStay < reservations[minIdx].durationOfStay)
            {
                minIdx = j;
            }
        }
        // Swap the found minimum element with the first element
        swap(reservations[i], reservations[minIdx]);
    }
}

// Function to update the reservation duration
void UpdateReservationDuration(vector<Reservation>& reservations)
 {
    // First, sort the reservations based on duration of stay using selection sort
    selectionSort(reservations);

    // Display the sorted reservations
    cout << "Sorted Reservations (by Duration of Stay):\n";
    for (const auto& reservation : reservations)
        {
        cout << "ID: " << reservation.id
             << ", Duration of Stay: " << reservation.durationOfStay << " days\n";
    }

    // Get the Reservation ID to update
    int reservationId;
    cout << "\nEnter the Reservation ID to update its duration: ";
    cin >> reservationId;

    // Find the reservation by its ID
    bool found = false;
    for (auto& reservation : reservations)
        {
        if (reservation.id == reservationId)
        {
            found = true;

            // Get new duration from the user
            int newDuration;
            cout << "Enter the new duration of stay (in days): ";
            cin >> newDuration;

            // Update the duration
            reservation.durationOfStay = newDuration;

            cout << "Reservation updated successfully!\n";
            cout << "Updated Reservation ID: " << reservation.id
                 << ", New Duration of Stay: " << reservation.durationOfStay << " days\n";
            break;
        }
    }

    if (!found)
        {
        cout << "Reservation with ID " << reservationId << " not found.\n";
    }
}


// Selection Sort function to sort payments by reservationId
void selectionSortPayments(vector<Payment>& payments)
{
    int n = payments.size();
    for (int i = 0; i < n - 1; i++)
        {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (payments[j].reservationId < payments[minIndex].reservationId)
             {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(payments[i], payments[minIndex]);
        }
    }
}

void CalculateTotalRevenuebyHotel(const vector<Hotel>& hotels, vector<Reservation>& reservations, vector<Payment>& payments)
{
    // Initialize a map to store total revenue for each hotel
    map<int, double> hotelRevenue;

    // Ensure that the payments are only counted if completed
    for (const auto& payment : payments)
        {
        if (payment.paymentStatus == "completed")
         {
            // Find the corresponding reservation for this payment
            auto it = find_if(reservations.begin(), reservations.end(),
                              [&payment](const Reservation& res) { return res.id == payment.reservationId; });

            if (it != reservations.end())
                {
                // Find the corresponding hotel for the reservation
                auto hotelIt = find_if(hotels.begin(), hotels.end(),
                                       [&it](const Hotel& hotel) { return hotel.id == it->hotelId; });

                if (hotelIt != hotels.end())
                    {
                    // Add the payment's totalAmount to the corresponding hotel revenue
                    hotelRevenue[hotelIt->id] += payment.totalAmount;
                }
            }
        }
    }

    // Output the total revenue per hotel
    for (const auto& hotel : hotels)
        {
        double totalRevenue = hotelRevenue[hotel.id]; // Get the total revenue for this hotel
        cout << "Hotel: " << hotel.name << " | Total Revenue: $" << fixed << setprecision(2) << totalRevenue << endl;
    }
}


int main()
 {
    vector<Hotel> hotels;
    vector<Customer> customers;
    vector<Reservation> reservations;
    vector<Payment> payments;

    // Load data from files
    loadHotel(hotels);
    loadCustomer(customers);
    loadReservation(reservations);
    loadPayment(payments);

    // Save data back to files (for testing purposes)
    saveHotel(hotels);
    saveCustomer(customers);
    saveReservation(reservations);
    savePayment(payments);

    int choice;
     do {
        std::cout<<RED <<BOLD<<BOLD<<BOLD<<BOLD<<BOLD<<BOLD<<"\nHotel Management System\n"<<RESET;
        std::cout << "1. Customers\n";
        std::cout <<"2. Hotels\n";
        std::cout <<"3. Reservations\n";
        std::cout <<"4. Payments\n";
        std::cout  <<"5. Edit Hotel\n ";
        std::cout  <<"6.Delete Hotel\n";
        std::cout<<"7. Edit Customer\n";
        std::cout <<"8. Delete Customer\n";
        std::cout <<"9. Edit Payment\n";
        std::cout <<"10.Delete Payment\n";
        std::cout<<"11. Edit Reservation\n";
        std::cout<<"12. Delete Reservation\n";
        std::cout  <<"13. View Reservations by Customer\n";
        std::cout << "14. View Payment by Reservation\n";
        std::cout << "15. View Payment by Customer\n";
        std::cout << "16. Generate Hotel Availability Report\n";
        std::cout <<"17. Display Hotels by Star Rating\n";
        std::cout <<"18. Find Hotels Based on Room Availability\n";
        std::cout<<"19. Update Customer Age\n";
        std::cout <<"20. Find Customer by Name\n";
        std::cout <<"21. Find Hotel by Name\n";
        std::cout <<"22. Search Hotels by Location\n";
        std::cout <<"23. Search Customers by Occupation\n";
        std::cout<<"24.Enter the reservation status to search for\n";
        std::cout <<"25.ExtendReservationDuration\n";
        std::cout<<"26.updatePaymentStatus\n";
        std::cout <<"27.findHotelsWithParking\n";
        std::cout <<"28.UpdateHotelRoomAvailability\n";
        std::cout<<"29.Hotel with wifi\n";
        std::cout<<"30.Update customer email\n";
        std::cout << "31.Send Payment Remainder To Customer\n";
        std::cout <<"32. View Hotels with Room Service\n";
        std::cout <<"33. View Customer Contact Information by Name(John Doe or Jane Smith or Alex Brown or Maria Garcia or David Lee\n";
        std::cout<<"34.SearchHotelsbyDiningOptions(Restaurent or Restaurent, Bar or In-room Dining)\n";
        std::cout<<"35.SearchReservationsbyRoom(Single or Double or Suite) \n";
        std::cout<<"36.SearchHotelsbyCancellationPolicy   (Free cancellatin or no cancellation)\n";
        std::cout<<"37.SearchCustomersbyAge\n";
        std::cout<<"38.UpdateReservationDuration\n";
        std::cout<<"39.Calculate Total Revenue by Hotel\n";
        std::cout <<"40.Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice)
         {
            case 1:
                {


                viewCustomer(customers);
                break;
                }
            case 2:
                {


                viewHotels(hotels);
                break;
                }
            case 3:
                {


                viewReservation(reservations);
                break;
                }
            case 4:
                {


                viewPayment(payments);
                break;
                }
            case 5:
                {


                editHotel(hotels);
                break;
                }
            case 6:
                {


                deleteHotel(hotels);
                break;
                }
            case 7:
                {


                editCustomer(customers);
                break;
                }
            case 8:
                {


                deleteCustomer(customers);
                break;
                }
            case 9:
                {


                editPayment(payments);

                break;
                }
            case 10:
                {

                 deletePayment(payments);
                break;
                }
            case 11:
                {


                editReservation(reservations);
                break;
                }
            case 12:
                {


                deleteReservation(reservations);
                break;
                }
            case 13:
                {
                viewReservationsByCustomer(reservations, customers);
                break;
                }
            case 14:
             {
                viewPaymentByReservation(payments, reservations);
                break;
             }
            case 15:
                {
                viewPaymentByCustomer(payments, customers);
                break;
                }
            case 16:
                {
                generateHotelAvailabilityReport(hotels);
                break;
                }
            case 17:
                {


                displayHotelsByStarRating(hotels);
                break;
                }
            case 18:
                 {
                int roomCount;
                std::cout << "Enter the number of rooms you are looking for: ";
                std::cin >> roomCount;
                generateNumberOfRoomsByUsertoFindWhichHotel(hotels, roomCount);
                break;
            }
            case 19:
                updateCustomerAge(customers);
                break;
            case 20:
                 {
                std::string nameToSearch;
                std::cout << "Enter the name to search for: ";
                std::cin.ignore();  // Clear leftover input
                std::getline(std::cin, nameToSearch);
                findCustomerByName(customers, nameToSearch);
                break;
            }
            case 21:
                 {
                std::string hotelNameToSearch;
                std::cout << "Enter the hotel name to search for: ";
                std::cin.ignore();  // Clear leftover input
                std::getline(std::cin, hotelNameToSearch);
                findHotelByName(hotels, hotelNameToSearch);  // Call function to find hotel by name
                break;
            }
            case 22:
                {
                string locationToSearch;
                cout << "Enter the location to search for hotels: ";
                cin.ignore();  // Clear leftover input
                getline(cin, locationToSearch);
                searchHotelByLocation(hotels, locationToSearch);
                break;
            }
                case 23:  // Assigning case 23 for searching customers by occupation
    {
        std::string occupationPattern;
        std::cout << "Enter the occupation to search for: ";
        std::cin.ignore();  // Clear leftover input
        std::getline(std::cin, occupationPattern);
        searchCustomersByOccupation(customers, occupationPattern);
        break;
    }
    case 24: {
    string status;
    cout << "Enter the reservation status to search for (e.g., 'confirmed', 'pending', 'canceled'): ";
    cin.ignore(); // Clear input buffer
    getline(cin, status);
    searchReservationsByStatusBoyerMoore(reservations, status); // Corrected function call
    break;
}
      // New case for extending reservation duration
    case 25:
        {
            ExtendReservationDuration(reservations, hotels);
            break;
        }
     case 26:
    {
        // New case for updating payment status
        int paymentId;
        string newStatus;

        std::cout << "Enter the payment ID to update: ";
        std::cin >> paymentId;
        std::cin.ignore();  // Clear leftover input

        std::cout << "Enter the new payment status: ";
        std::getline(std::cin, newStatus);

        // Call the updatePaymentStatus function
        updatePaymentStatus(payments, paymentId, newStatus);
        break;
    }
     case 27:  // Add the case for finding hotels with parking
    {
        findHotelsWithParking(hotels);
        break;
    }
    case 28:  // Update hotel room availability
        {
            UpdateHotelRoomAvailability(hotels, reservations);  // Call the function to update room availability
            break;
        }
       case 29:
           {
               // Call the function to display hotels with WiFi
                HotelWithWifi(hotels);
                break;


           }
           case 30:
              {

                // Call the UpdateCustomerEmail function
                UpdateCustomerEmail(customers);
                break;
              }
              case 31:
                  {

                // Call the SendPaymentRemindertoCustomer function
                SendPaymentRemindertoCustomer(reservations, payments, customers);
                break;
                  }
                   case 32:
                       {

                            // Call the function to find hotels with room service
                            FindHotelsWithRoomService(hotels);
                            break;
                       }
                       case 33: // New case for viewing customer contact information by name
{
    string searchName;
    cout << "Enter the customer name (or part of the name) to search for: ";
    cin.ignore(); // Clear the input buffer
    getline(cin, searchName);

    ViewCustomerContactInformationByName(customers, searchName);
    break;
}
           case 34: {
    string diningOption;
    cout << "Enter the dining option to search for: ";
    cin.ignore();
    getline(cin, diningOption);
    SearchHotelsbyDiningOptions(hotels, diningOption);
    break;
}
           case 35: {
    string roomType;
    cout << "Enter the room type to search for: ";
    cin.ignore();
    getline(cin, roomType);
    SearchReservationsbyRoom(reservations, roomType);
    break;
}
          case 36: {
    string cancellationPolicy;
    cout << "Enter the cancellation policy to search for: ";
    cin.ignore();
    getline(cin, cancellationPolicy);
    SearchHotelsbyCancellationPolicy(hotels, cancellationPolicy);
    break;
}
          case 37: {
    int minAge, maxAge;
    cout << "Enter the minimum age: ";
    cin >> minAge;
    cout << "Enter the maximum age: ";
    cin >> maxAge;

    SearchCustomersbyAge(customers, minAge, maxAge);
    break;
}
          case 38:
    {
        UpdateReservationDuration(reservations);  // Call the UpdateReservationDuration function
        break;
    }
    case 39:
        {

                CalculateTotalRevenuebyHotel(hotels, reservations, payments);
                break;
        }




            case 40:
                std::cout << "Exiting...\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while (choice != 40);  // Exit when the user chooses 30



    return 0;
}












