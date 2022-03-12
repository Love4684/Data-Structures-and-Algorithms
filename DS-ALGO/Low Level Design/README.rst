
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
