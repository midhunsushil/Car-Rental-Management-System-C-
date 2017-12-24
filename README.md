The mini project ‘Car Rental Management System’ is the sample project for managing car rental. The project aims at developing car rental system using the C++ language that enables an organization to maintain its cars and customers. 

The project demonstrates the creation of a user interface of a system. The application uses basic C++ function to generate login screen, menus, show boxes and print text on the screen. It also effectively applies the various C++ concepts such as file operations, looping and branching constructs and string manipulation functions.
It uses DOS file support as back end to save the records. 

The Structure of the program:
Login Screen
The admin must enter the username and password to login.

Main Menu
The Main Menu contains 8 options where the option number has to be entered to select the option.
The options are:

#####################################

 1. Rent A Car: The customer has to enter the required details along with from and to dates of rent period. After entering the details, the inventory is displayed, and the customer has to choose an available car by entering the serial number. Then the contract is displayed with the options Save and Cancel.

#####################################

 2. Add Car: The administrator is asked about the number of cars to be added and necessary details of the cars to be added will asked as many times.

#####################################

 3. Search and Display: On opening this option 5 more options are displayed.
They are:
a.	Display All Cars: In this option all the details of the cars available in the system are displayed one by one.
b.	Display All Customers: Here the contract of each customer is displayed one by one.
c.	Search Car: In this option any one field among the asked options must be entered to search for a car.
d.	Search Customer: Here any one field among the asked fields must be entered and the contract of that customer will be displayed.
e.	Go Back: To return to the main menu.

###################################### 

  4. Reports: On entering this function
The user is asked to enter the one among the following options: 
a.	View All Car reports: Where the inventory is displayed.
b.	View Customer Report: As the name suggests.
c.	View Customer-Car Report: Here the details of the customers are displayed in a tabular form with only relevant details.
d.	Go Back: To return to the main menu.

####################################

   5. Edit Record: This includes editing of all the record that the system handles with. They are:
a.	Update Car: To Update car details
b.	Update Customer: To update contract.
c.	Delete Car: To delete a car by entering any one among the asked details.
d.	Delete Customer: To delete the contract pf any customer.
e.	Edit Status: This has further options like.
I.	Change all status to Available.
II.	Change all status to Booked
III.	Switch Status.
IV.	Go Back: To return to Edit Record menu.
f.	Go Back: To return to the main menu.

#####################################

6. Return and Billing: This option is to be used when the customer returns the car. 
Any one among the required field must be entered to view the contract.
Then on proceeding to the bill the current date is asked. The billing works in this manner- If it matches with the earlier mentioned to date in the contract the customer would not be fined. Whereas if it’s a late return the 150% of the rent per day will be fined for each day.
But as the dates in the contract are fixed early return will not be refund.

#####################################

7. About: About our company

#####################################

8. Exit.

#####################################

Header Files Used:

#####################################

<fstream.h> <iomanip.h> <stdio.h> <string.h> <stdlib.h> <conio.h> <ctype.h>

#####################################

Special User Defined Functions Used:

#####################################

1.	ventry():

For validated input of a string of specific size (N) which can be passed as argument. This prevents users from inputting invalid characters such as inputting alphabets in a string that stores phone number.
Usage: ventry(string,code,size); //by default size=1
code=0 >> for inputting alphabets(a-Z), space, comma(,) & dot(.)
code=1 >> for inputting numbers(0-9), dot(.) & '/'
code=2 >> for inputting username / ID
code=3 >> for normal input without space, ':' & ';'
code=4 >> for menu input (only numbers 0-9)
#####################################

2.	clear():
For clearing specific character, characters or lines
This function basically uses gotoxy() and outputs space over to clear the specified no. of characters or lines. It's more convenient than the library function clrscr() (clears entire console output) as it can clear specified locations.
Usage: clear(x, y, noc, nol ). //by default nol=1
(x,y) >> Margin/position of first character;
 noc  >> number of characters to clear;
 nol  >> number of lines to clear;
#####################################

3.	border():
For creating border of length l(horizontal) & width w(vertical).
usage: border(x, y, l, w, type)
Where (p,q)-margin (coordinate of top-left vertices of box border);
type >> 0(+ * !);
type >> 1(single border), 4(slow-motion)(* ! +);
type >> 2(double character border)(/); 
#####################################

4.	namecmp():
For checking for a word in a string; Used in the program to find name inside fullname; If string size less than word size function returns (-1);
If the entire word is in the string, function returns (1) else returns (0).
Usage: namecmp(string, word).
