#include <fstream.h>
#include <conio.h>
 void delay(unsigned short p, unsigned short q = 4) {
  for (unsigned long i = 0; i < (p * 10); i++)
	for (unsigned long j = 0; j < (q * 1000); j++) { /*To delay output*/ }
 }
void welcome() {
 ifstream design, font;
 design.open("design.txt", ios:: in );
 char ch;
 while (design.get(ch)) {
  cout << ch;
  if (ch == '\n') delay(400, 8);
 }
 design.close();
 getch();
 //gotoxy(1,1);
 cout << "\n  WELCOME TO....\n";
 font.open("font.txt", ios:: in );
 while (font.get(ch)) {
  cout << ch;
  delay(20,2);
 }
 font.close();
 getch();
}
