//Temporary Project
#include<windows.h>
#include<iostream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>

HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

 class CAR
  {
    char usr[30];
    //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    public:
    void check();
    void Border(int p,int q,int l,int w,int type);
    void crusor();

  }L;

void CAR::check()
  { //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    xx:
    clrscr();
    Border(3,2,74,21,2);
    int i=0;
    char pss[12];
    textcolor(YELLOW);
    gotoxy(27,4);
    cprintf("WELCOME TO ### CAR RENTAL");
    gotoxy(27,5);
    cprintf("-------------------------");
    gotoxy(33,8);
    cprintf("System Login");
    gotoxy(33,9);
    cprintf("------------");
    Border(24,12,27,7,1);
    gotoxy(27,14);
    //system("COLOR 71");
    SetConsoleTextAttribute(color, 3);
    cout<<"Username : ";
    //cprintf("Username : ");
    gotoxy(27,17);
    cout<<"Password : ";
    //cprintf("Password : ");

    //crusor();
    gotoxy(38,14);
    SetConsoleTextAttribute(color, 10);
    gets(usr);
    gotoxy(38,17);

    do
     {
       pss[i]=getch();
     if(pss[i]=='\r')
	  {
	    break;
	  }
   if(pss[i]=='\b' && i>0)
	  {
       cout<<'\b'<<' '<<'\b';
       i--;
	  }
	else
	  { if(i!=0 || pss[i]!='\b')
	    {cout << "*";
	    i++;}
	  }
      }
    while(i<=11);
    pss[i]='\0';
     gotoxy(32,19);
     cout<<pss<<endl;


    if(strcmp(usr,"admin") == 0 && strcmp(pss,"pass123") == 0)
      {
	clrscr();
      textcolor(GREEN);
      gotoxy(33,11);
     cprintf("TEST SUCCESSFUL");
     crusor();
     Border(21,5,30,10,2);
     getch();
      }

    else
      {
	textcolor(RED + BLINK);
	gotoxy(22,21);
	cprintf("Invalid Username Or Password !!!");
   //crusor();
	getch();
	textcolor(WHITE);
	goto xx;
      }
  }


void CAR::Border(int p,int q,int l,int w,int type)
  { /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       w-width(vertical distance) of border;
       l-length(horizontal distance) of border;
    */
    int i;
    char tl,tr,bl,br,hl,vl;
    if(type==1)
    {tl=218;tr=191;bl=192;br=217;hl=196;vl=179;}

    else
    {tl=201;tr=187;bl=200;br=188;hl=205;vl=186;}

    textcolor(WHITE);
    gotoxy(p,q);
    cprintf("%c",tl);//top-left
    gotoxy(p+l,q);
    cprintf("%c",tr);//top-right
    gotoxy(p,q+w);
    cprintf("%c",bl);//bottom-left
    gotoxy(p+l,q+w);
    cprintf("%c",br);//bottom-right

    for(i=1;i<w;i++)  // Vertical line for width w
     { gotoxy(p,q+i);
       cprintf("%c",vl);
       gotoxy(p+l,q+i);
       cprintf("%c",vl);
     }

     for(i=1;i<l;i++) // Horizontal Line of length l
     { gotoxy(p+i,q);
       cprintf("%c",hl);
       gotoxy(p+i,q+w);
       cprintf("%c",hl);
     }

  }

void CAR::crusor()
{ int x=1,y=1;
  char key;
  do
    { gotoxy(x,y);
      cout<<"      ";
      gotoxy(x,y);
      key=getch();
      if(key==' ')
        x++;
      else if(key=='\b')
       x--;
      else if(key=='\r')
       y++;
      else if(key=='p')
    {  gotoxy(1,1);
       cout<<x<<" "<<y;
    }

      else if(key=='r')
      {
        x=1;y=1;
      }
    }
  while(key!='N');


}

void main()
{
  L.check();

}
