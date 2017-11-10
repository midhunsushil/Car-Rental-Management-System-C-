# helOnubyproject
CS project Car rental
There are 3 functions
Login, cursor and border
You can run .exe file or run the code from compiler
Since there is colour (windows.h) you cant use  old compilers. Here is the link to the compiler that I used
https://drive.google.com/file/d/0B-K40pdvhf1tUHpOZVpScXo1YTg/view?usp=drivesdk
Cursor function allows you to the address of the cursor in the output screen
So you can use gotoxy()
Run the cursor function you space to move forward and enter to move to the next line and backspace to move back. Pressing p will output the current position of the cursor and pressing r resets the cursor to the start
Try testCAR. Its the login
Login username : admin
Password : pass123
And border function creates the border if you specify the margin and length(horizontal space) and width (no of lines ie vertical space). Note that the width will be more than length. If you input 4 4 the output won't be a square it will be a vertical rectangle. The values inside square brackets are previous inputs so that you can compare.

UPDATE 2 => main program UpdateCar() function updated. Now you can search in update using carid / make / model;
            If more than one record found, program will ask to select.

UPDATE 3 => included ADDCustomer, Carstatusedit() and improved efficiency