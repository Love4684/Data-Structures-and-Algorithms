
.. contents::
   :local:
   :depth: 3
   
Hotel Management System
===============================================================================

use case diagram:
--------------------

.. image:: https://github.com/Love4684/Data-Structures-and-Algorithms/blob/master/DS-ALGO/Low%20Level%20Design/Image/1.png

.. code:: c++

      class Hotel {

         String Name;
         Integer id;
         Location hotelLocation;
         List<Room> roomList;

      }

      class Location {

         Double longitude;
         Double latitude;
      }

      class Room {

         String roomNumber;
         RoomStyle roomStyle;
         RoomStatus roomStatus;
         Double bookingPrice;
         List<RoomKey> roomKeys;
         List<HouseKeepingLog> houseKeepingLogs;

      }

      public enum RoomStyle {

         STANDARD, DELUX, FAMILY_SUITE;
      }

      public enum RoomStatus {

         AVAILABLE, RESERVED, NOT_AVAILBLE, OCCUPIED, SERVICE_IN_PROGRESS;
      }

      class RoomKey {

         String keyId;
         String barCode;
         Date issuedAt;
         Boolean isActive;
         Boolean isMaster;

         public void assignRoom(Room room);

      }

      class HouseKeepingLog {
         String description;
         Date startDate;
         int duration;
         HouseKeeper houskeeper;

         public void addRoom(Room room);
      }

      abstract class Person {

         String name;
         Account accountDetail;
         String phone;
      }

      public class Account {

         String username;
         String password;

         AccountStatus accountStatus;

      }

      public enum AccountStatus {

         ACTIVE, CLOSED, BLOCKED;
      }

      class HouseKeeper extends Person {

         public List<Room> public getRoomsServiced(Date date);
      }

      class Guest extends Person {

         Search searchObj;
         Booking bookingObj;

         public List<RoomBooking> getAllRoomBookings();
         public RoomBooking createBooking();
         public RoomBooking cancelBooking(int bookingId);
      }

      class Receptionist extends Person {

         Search searchObj;
         Booking bookingObj;

         public void checkInGuest(Guest guest, RoomBooking bookingInfo);
         public void checkOutGuest(Guest guest, RoomBooking bookingInfo);

      }

      class admin extends Person {

         public void addRomm(Room roomDetail);
         public Room deleteRoom(String roomId);
         public void editRoom(Room roomDetail);
      }

      class search {

         public List<Room> searchRoom(RoomStyle roomStyle, Date startDate, int duration);

      }

      class RoomBooking {

         String bookingId;
         Date startDate;
         Int durationInDays;
         BookingStatus bookingStatus;
         List<Guest> guestList;
         List<Room> roomInfo;
         BaseRoomCharge totalRoomCharges;
      }


      /**
      *	Decorator pattern is used to decorate the prices here.
      **/

      interface BaseRoomCharge {

         Double getCost();

      }

      class RoomCharge implements BaseRoomCharge {


         double cost;
         Double getCost() {
            return cost;
         }
         void setCost(double cost) {
            this.cost = cost;
         }
      }

      class RoomServiceCharge implements BaseRoomCharge {

         double cost;
         BaseRoomCharge baseRoomCharge;
         Double getCost() {
            baseRoomCharge.setCost(baseRoomCharge.getCost() + cost);
            return baseRoomCharge.getCost();
         }
      }

      class InRoomPurchaseCharges implements BaseRoomCharge {

         double cost;
         BaseRoomCharge baseRoomCharge;
         Double getCost() {
            baseRoomCharge.setCost(baseRoomCharge.getCost() + cost);
            return baseRoomCharge.getCost();
         }
      }

      class Booking {

         public RoomBooking createBooking(Guest guestInfo);
         public RoomBooking cancelBooking(int bookingId);

      }



Library Management System
===============================================================================

use case diagram:
--------------------

.. image:: https://github.com/Love4684/Data-Structures-and-Algorithms/blob/master/DS-ALGO/Low%20Level%20Design/Image/2.png

.. code:: c++

      class Library {

         String name;
         Address location;
         List<BookItem> books;
      }

      class Book {

         String uniqueIdNumber;
         String title;
         List<Author> authors;
         BookType bookType;
      }

      class BookItem extends Book {

         String barcode;
         Date publicationDate;
         Rack rackLocation;
         BookStatus bookStatus;
         BookFormat bookFormat;
         Date issueDate;
      }

      class Address {

         int pinCode //ZipCode
         String street;
         String city;
         String state;
         String country;
      }

      public enum BookType {

         SCI_FI, ROMANTIC, FANTASY, DRAMA;
      }

      public enum BookFormat {

         HARDCOVER, PAPERBACK, NEWSPAPER, JOURNAL;
      }

      public enum BookStatus {

         ISSUED, AVAILABLE, RESERVED, LOST;
      }

      class Rack {

         int number;
         String locationId;

      }

      class Person {

         String firstName;
         String lastName;

      }

      class Author extends Person {

         List<Book> booksPublished;

      }

      class SystemUser extends Person {

         String Email;
         String phoneNumber;
         Account account;
      }

      class Member extends SystemUsers {

         int totalBookCheckedOut;

         Search searchObj;
         BookIssueService issueService;

      }

      class Librarian extends SystemUsers {

         Search searchObj;
         BookIssueService issueService;

         public void addBookItem(BookItem bookItem);
         public BookItem deleteBookItem(String barcode); 
         public BookItem editBookItem(BookItem bookItem);
      }

      class Account {

         String userName;
         String password;
         int accountId;
      }

      class Search {

         public List<BookItem> geBookByTitle(String title);
         public List<BookItem> geBookByAuthor(Author author);
         public List<BookItem> geBookByType(BookType bookType);
         public List<BookItem> geBookByPublicationDate(Date publicationDate);

      }

      class BookIssueService {

         Fine fine;

         public BookReservationDetail getReservationDetail(BookItem book);

         public void updateReservationDetail(BookReservationDetail bookReservationDetail);

         public BookReservationDetail reserveBook(BookItem book, SystemUser user);

         public BookIssueDetail issueBook(BookItem book, SystemUser user);

         // it will internaly call the issueBook function after basic validations
         public BookIssueDetail renewBook(BookItem book, SystemUser user); 

         public void returnBook(BookItem book, SystemUser user);

      }

      class BookLending {

         BookItem book;
         Date startDate;
         SystemUser user;
      }

      class BookReservationDetail extends BookLending {

         ReservationStatus reservationStatus;

      }

      class BookIssueDetail extends BookLending {

         Date dueDate;

      }

      class Fine {

         Date fineDate;
         BookItem book;
         SystemUser user;

         public double calculateFine(int days);
      }

Book My Show
===============================================================================

.. code:: c++

      public class BMSService  {

         List<CinemaHall> cinemas;

         public List<Movie> getMovies(Date date, String city);
         public List<CinemaHall> getCinemalHalls(String city);

      }

      public class CinemaHall {

         int cinemaHallId;
         String cinemaHallName;

         Address address;

         List<Audi>audiList;

         public Map<Date, Movies> getMovies(List<Date> dateList);
         public Map<Date, Show> getShows(List<Date> dateList);

      }

      public class Address {

         int pinCode; //ZipCode
         String street;
         String city;
         String state;
         String country;

      }

      public class Audi {

         int audiId;
         String audiName;
         int totalSeats;

         List<Show> shows;

      }

      public class Show {

         int showId;
         Movie movie;
         Date startTime;
         Date endTime;
         CinemaHall cinemaPlayedAt;
         List<Seat> seats;

      }

      public class Seat {

         int seatId;
         SeatType seatType;
         SeatStatus seatStatus;
         Double price;

      }


      public enum SeatType {

         DELUX, VIP, ECONOMY, OTHER;

      }

      public enum SeatStatus {

         BOOKED, AVAILABLE, RESERVED, NOT_AVAILABLE;

      }

      public class Movie {

         String movieName;
         int movieId;
         int durationInMins;
         String language;
         Genre genre;
         Date releaseDate;
         Map<String, List<Show>> cityShowMap;

      }

      public enum Genre {

         SCI_FI, DRAMA, ROM_COM, FANTASY;
      }

      public class User {

         int userId;
         Search searchObj;

      }

      public class SystemMember extends User {

         Account account;
         String name;
         String email;
         Address address;

      }



      public class Member extends SystemMember {

         public Booking makeBooking(Booking booking);
         public List<Booking> getBooking();

      }

      public class Admin extends SystemMember {

         public boolean addMovie(Movie moivie);
         public boolean addShow(Show show);

      }

      public class Account {

         String userName;
         String password;

      }

      public class Search {

         public List<Movie> searchMoviesByNames(String name);
         public List<Movie> searchMoviesByGenre(Genre genre);
         public List<Movie> searchMoviesByLanguage(String language);
         public List<Movie> searchMoviesByDate(Date releaseDate);
      }

      public class Booking {

         String bookingId;
         Date bookingDate;
         Member member;
         Audi audi;
         Show show;
         BookingStatus bookingStatus;
         double totalAmount;
         List<Seat> seats;
         Payment paymentObj;

         public boolean makePayment(Payment payment);

      }

      public class Payment {

         double amount;
         Date paymentDate;
         int transactionId;
         PaymentStatus paymentStatus;

      }

      public enum BookingStatus {

         REQUESTED, PENDING, CONFIRMED, CANCELLED;
      }

      public enum PaymentStatus {

         UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED;

      }


AMAZON SHOPPING WEBSITE
===============================================================================

.. code:: c++

      class Customer {

         ShoppingCart cart;
         Search searchObj;
         int customerId;

         public ShoppingCart getShoppingCart(customerId);
         public void addItemsToShoppingCart(Item item);
         public void updateItemFromShoppingCart(Item item);
         public void removeItemFromShoppingCart(Item item);
      }

      class Guest extends Customer {

         public Account createNewAccount();

      }

      class User extends Customer {

         Account account;

      }

      class Seller extends User {

         public void addProduct(Product product);
      }

      class Buyer extends User {

         Order orderObj;

         public void addReview(ProductReview review);
         public OrderStatus placeOrder(ShoppingCart cart);

      }

      class Account {

         String name;
         String email;
         String phoneNumber;
         String userName;
         String password;

         List<Address> shippingAdresses;

         AccountStatus accountStatus;
      }

      class Address {

         int pinCode; //ZipCode
         String street;
         String city;
         String state;
         String country;
      }

      public enum AccountStatus {

         ACTVE,BLOCKED,INACTIVE;
      }

      class ShoppingCart {

         List<Item> items;
         double cartValue;

         public void addItem(Item item);
         public void updateItem(Item item);
         public void deleteItem(Item item);
         public void checkoutItems();
         public List<Item> getItems();
         public double getCartValue();
      }

      class Item {

         Product product;
         int qty;

      }

      class Product {

         int productId;
         String productDescription;
         String name;
         ProductCategory productCategory;
         Seller seller;
         double cost;

         List<ProductReview> productReviews;

      }

      public enum ProductCategory {

         ELECTRONICS,FURNITURE,GROCERY,MOBILE;
      }

      class ProductReview {

         String details;
         Buyer reviewer;
         int rating;

      }

      class search {

         public List<Product> searchByName(String name);
         public List<Product> searchByCategory(ProductCategory productCategory);
      }

      class Order {

         int orderId;
         List<Item> orderItem;
         double orderValue;
         Buyer buyer;
         Date orderDate;
         NotificationService notificationService;

         List<OrderLog> orderLog;

         public OrderStatus placeOrder();
         public OrderStatus trackOrder();
         public void addOrderLogs();
         public PaymentStatus makePayment(PaymentType paymentType);

      }

      public enum OrderStatus {

         PACKED, SHIPPED, ENROUTE, OUT_FOR_DELIVERY, DELIVERED, CANCELLED;
      }

      public enum PaymentStatus {

         SUCCESS, ERROR, CANCELLED, REFUND_INITIATED, REFUNDED;

      }

      public enum PaymentType {

         CREDIT_CARD, DEBIT_CARD, NET_BANKING, UPI;
      }

      class OrderLog {

         String orderDetail;
         Date createdDate;
         OrderStatus status;
      }

      class NotificationDomain {

         String notificationID;
         NotificationType notificationType;
         User user;

      }

      class NotificationService {



         public boolean sendNotification(NotificationDomain notificationDomain) {

            Notification notificationObject;
            MessageAttribute messageAttribute;

            switch(notificationDomain.getNotificationType()) {


               case NotificationType.EMAIL:
                  notificationObject = new EmailNotification();
                  messageAttribute = new MessageAttribute("abc@abc.com", notificationDomain.getUser().getAccount().getEmail(),"Order Detail ...");
                  break;
               case NotificationType.WHATSAPP:
                  notificationObject = new WhatsappNotification();
                  messageAttribute = new MessageAttribute("9888888888", notificationDomain.getUser().getAccount().getPhoneNumber(),"Order Detail ...");
                  break;
               default:
                  notificationObject = new SMSNotification();
                  messageAttribute = new MessageAttribute("988888888", notificationDomain.getUser().getAccount().getPhoneNumber(),"Order Detail ...");
                  break;
            }

            return notificationObject.sendNotification(messageAttribute);
         }

      }

      class MessageAttributes {

         String to;
         String from;
         String message;

      }

      interface Notification {

         boolean sendNotification(MessageAttribute meesageAttribute);

      }

      class EmailNotification implements Notification {

         boolean sendNotification(MessageAttribute meesageAttribute);
      }

      class WhatsappNotification implements Notification {

         boolean sendNotification(MessageAttribute meesageAttribute);
      }

      class SMSNotification implements Notification {

         boolean sendNotification(MessageAttribute meesageAttribute);

      }


parking lot
===============================================================================

.. code:: c++


      Requirements for Parking Lot 
      • There should be multiple floors in the Parking Lot . 
      • There should be multiple gates in the paring lot . 
      • There should be a parking attendant at each gate . 
      • The entry gates should process parking ticket . 
      • The exit gate should process payment on an hourly basis . 
      • The parking lot should have parking facility for different types of vehicles . 
      • There should be display boards at each floor showing the detail of vacant spots on the floor .
      class ParkingLot {

         List<ParkingFloor> parkingFloors;
         List<Entrance> entrances;
         List<Exit> exits;

         Address address; 

         String parkingLotName;

         public boolean isParkingSpaceAvailableForVehicle(Vehicle vehicle);
         public boolean updateParkingAttndant(ParkingAttendant parkingAttendant, int gateId)

      }

      class ParkingFloor {

         int levelId;
         List<ParkingSpace> parkingSpaces;

         ParkingDisplayBoard parkingDisplayBoard;

      }

      class Gate {

         int gateId;
         ParkingAttendant parkingAttendant;

      }

      class Entrance extends Gate {

         public ParkingTicket getParkingTicket(Vehicle vehicle);

      }

      class Exit extends Gate {

         public ParkingTicket payForParking(ParkingTicket parkingTicket, PaymentType paymentType);

      }


      class Address {

         String country;
         String state;
         String city;
         String street;
         String pinCode; //ZipCode
      }

      class ParkingSpace {

         int spaceId;
         boolean isFree;
         double costPerHour;
         Vehicle vehicle;
         ParkingSpaceType parkingSpaceType;

      }

      class ParkingDisplayBoard {

         Map<ParkingSpaceType, Integer> freeSpotsAvailableMap;

         public void updateFreeSpotsAvailable(ParkingSpaceType parkingSpaceType, int spaces);

      }


      class Account {

         String name;
         String email;
         String password;
         String empId;
         Address address;

      }

      class Admin extends Account {

         public boolean addParkingFloor(ParkingLot parkingLot, ParkingFloor floor);
         public boolean addParkingSpace(ParkingFloor floor, ParkingSpace parkingSpace);
         public boolean addParkingDisplayBoard(ParkingFloor floor, ParkingDisplayBoard parkingDisplayBoard);
         .
         .
         .

      }

      class ParkingAttendant extends Account {

         Payment paymentService;

         public boolean processVehicleEntry(Vehicle vehicle);
         public PaymentInfo processPayment(ParkingTicket parkingTicket, PaymentType paymentType);

      }

      class Vehicle {

         String licenseNumber;
         VehicleType vehicleType;
         ParkingTicket parkingTicket;
         PaymentInfo paymentInfo;

      }

      class ParkingTicket {

         int ticketId;
         int levelId;
         int spaceId;
         Date vehicleEntryDateTime;
         Date vehicleExitDateTime;
         ParkingSpaceType parkingSpaceType;
         double totalCost;
         ParkingTicketStatus parkingTicketStatus;

         public void updateTotalCost();
         public void updateVehicleExitTime(Date vehicleExitDateTime);

      } 

      public enum PaymentType {

         CASH, CEDIT_CARD, DEBIT_CARD, UPI;
      }

      public enum ParkingSpaceType {

         BIKE_PARKING, CAR_PARKING, TRUCK_PARKING

      }

      class Payment {

         public PaymentInfo makePayment(ParkingTicket parkingTicket, PaymentType paymentType);
      }

      public class PaymentInfo {

         double amount;
         Date paymentDate;
         int transactionId;
         ParkingTicket parkingTicket;
         PaymentStatus paymentStatus;

      }

      public enum VehicleType {

         BIKE, CAR, TRUCK;
      }

      public enum ParkingTicketStatus {

         PAID, ACTIVE;
      }

      public enum PaymentStatus {

         UNPAID, PENDING, COMPLETED, DECLINED, CANCELLED, REFUNDED;

      }
