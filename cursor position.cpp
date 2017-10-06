#include<iostream.h>
#include<conio.h>

void main()
{ int x=1,y=1;
  char key;
  do
    { gotoxy(x,y);
      key=getch();
      if(key==' ')
        x++;
      else if(key=='\b')
       x--;
      else if(key=='\r')
       y++;
      else if(key=='p')
       {gotoxy(1,1);
       cout<<x<<" "<<y;}

      else if(key=='r')
      { clrscr();
        x=1;y=1; }
    }
  while(key!='N');


}
