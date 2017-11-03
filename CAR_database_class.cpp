#include<windows.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include"conionew.h"

int op;
void menu();
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

 class Design
  {
    char usr[30];
    //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    public:
    void check();
    void border(int p,int q,int l,int w,int type);
    void crusor();

  }L;

void Design::check()
  { //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    xx:
    clrscr();
    border(3,2,74,21,2);
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
    border(24,12,27,7,1);
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
     gotoxy(38,18);
     cout<<pss<<endl;


    if(strcmp(usr,"admin") == 0 && strcmp(pss,"pass123") == 0)
      {
         cout<<'\a';
	      clrscr();
          menu();
      }

    else
      {
	textcolor(RED + BLINK);
	gotoxy(22,21);cout<<'\a'<<'\a';
	cprintf("Invalid Username Or Password !!!");
   //crusor();
	getch();
	textcolor(WHITE);
	goto xx;
      }
  }

 void line(int p,int q,int l,char type='v')
  {
     int i;char c;
    /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       type=v - For Vertical Line (default)
       type=h - For Horizontal Line
       l-length(horizontal distance) of border;
    */
    textcolor(WHITE);
    if(type=='v')
    for(i=0;i<l;i++)  // Vertical line of length l
     { gotoxy(p,q+i);
       cprintf("\xDE"); //'7C'(hyphen); 'DE'(accented i);
     }
     else
     for(i=0;i<l;i++) // Horizontal Line of length l
      { gotoxy(p+i,q);
       cprintf("\x2D");
      }
  }

void Design::border(int p,int q,int l,int w,int type)
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

void Design::crusor()
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


//            *****************NEW PROJECT*******************

 class Cars { char carid[6];
              char make[20];
              char model[20];
              unsigned short year;
              char category[20];
              char passengers;
              char description[10];
              short status;
        public:
              void getcar();
              void putcar();
              void CarTable();
              char *retcarid() { return(carid); }
              char *retmodel() { return(model); }
              char *retmake() { return(make); }
              ~Cars(){/*Destructor to distroy this class when the scope is over*/}
             }C;

 void Cars::getcar() {  cout<<"\n\tCarID => ";
                        gets(carid);
                        cout<<"\n\tMAKE => ";
                        gets(make);
                        cout<<"\n\tModel => ";
                        gets(model);
                        cout<<"\n\tYEAR => ";
                        cin>>year;
                        cout<<"\n\tCATEGORY => ";
                        gets(category);
                        cout<<"\n\tPassengers => ";
                        cin>>passengers;
                        cout<<"\n\tDescription[press ENTER to SKIP] => ";
                        gets(description);
                        status=1;
                     }

 void Cars::putcar() { cout<<"\n\tCarID => "<<carid;      // Displayed on Table
                        cout<<"\n\tMAKE => "<<make;       // MAKE+model Displayed on table
                        cout<<"\n\tModel => "<<model;
                        cout<<"\n\tYEAR => "<<year;
                        cout<<"\n\tCATEGORY => "<<category;
                        cout<<"\n\tPassengers => "<<passengers;
                        //cout<<"\n\tDescription[press ENTER to SKIP] => ";
                      }

 void Cars::CarTable(){ L.border(4,3,73,20,1);
                        line(8,4,19);//Vertical line After No.
                        line(16,4,19);//Vertical line After Carid
                        line(35,4,19);//Vertical line After Car
                        line(55,4,19);// After Category
                        line(65,4,19);// After Price
                        line(5,5,72,'h');// Horizontal line
                        gotoxy(5,4);cout<<" No";gotoxy(9,4);cout<<" CarID";gotoxy(25,4);cout<<"CAR";gotoxy(42,4);cout<<"CATEGORY";gotoxy(57,4);cout<<"Price/hr";gotoxy(69,4);cout<<"STATUS";
                        gotoxy(1,1);
                        int i=0,r=7;
                        ifstream carfile("carsdata",ios::in|ios::binary);
                            //Read From File
                        //system("cls");
                        cout<<"\t\t\tDISPLAY AVAILABLE CARS";
                      while(carfile.read((char*)&C, sizeof(Cars)))
                       {
                        gotoxy(6, r);cout<<(i+1);
                        gotoxy(10,r);cout<<C.carid;
                        gotoxy(18,r);cout<<C.make<<" "<<C.model;
                        gotoxy(37,r);cout<<C.category;
                        gotoxy(51,r);//cout<<C.price;
                        gotoxy(67,r);(C.status==1) ? cout<<"Available" : cout<<"BOOKED!";
                        //getch();
                        i++;r++;
                       }
                      }

  void AddCar() { Cars C;
                  int i,N;
                  cout<<"\nEnter no. of cars to be added => ";
                  cin>>N;
                  system("cls");
                  ofstream carfile("carsdata",ios::out|ios::binary|ios::app);
                             //Write TO File
                  cout<<"\n\t\t\tADD NEW CAR";
               for(i=0;i<N;i++)
                 { system("cls");
                   cout<<"\n\n\tAdd Car No. "<<(i+1)<<endl;
                   C.getcar();
                   carfile.write((char*)&C, sizeof(Cars));
                 }
                   carfile.close();
                }

 void UpdateCar() {  int count=0,updatestatus=0,i=0;
                     Cars M[10];
                     char update[20];
                     fstream carfile("carsdata",ios::in|ios::out|ios::binary);
                         //Read from File and Write to File
                     system("cls");
                     cout<<"\nEnter Carid\Model\Make of Car to Update => ";
                     gets(update);
                     while(carfile.read((char*)&C, sizeof(Cars)))
                      { if(strcmp(update,C.retcarid())==0||strcmpi(update,C.retmodel())==0)
                         { cout<<"\nCar Found!";
                           updatestatus=1;
                           carfile.seekg(carfile.tellg()-sizeof(Cars));
                           C.putcar();
                           C.getcar();
                           carfile.write((char*)&C, sizeof(Cars));
                           break;
                         }
                        else if(strcmpi(update,C.retmake())==0) count++;
                      }
                     carfile.clear();
                     carfile.seekg(0);
                     if(count==1)
                      while(carfile.read((char*)&C, sizeof(Cars)))
                        if(strcmpi(update,C.retmake())==0)
                         { cout<<"\nCar Found!";
                           updatestatus=1;
                           carfile.seekg(carfile.tellg()-sizeof(Cars));
                           C.putcar();
                           C.getcar();
                           carfile.write((char*)&C, sizeof(Cars));
                           break;
                         }
                     if(count>1)
                      { cout<<"\nMore than one record found !\a\n";
                        while(carfile.read((char*)&C, sizeof(Cars)))
                         if(strcmpi(update,C.retmake())==0)
                          { M[i]=C;i++; }
                        for(i=0;i<count;i++)
                         { cout<<"\n\t["<<(i+1)<<"]"<<"\tCarID: "<<M[i].retcarid();
                           cout<<"\t\tCAR: "<<M[i].retmake()<<" "<<M[i].retmodel();
                         }
                        cout<<"\n\nOption => ";
                        cin>>::op;
                        carfile.clear();
                        carfile.seekp(0);
                        while(carfile.read((char*)&C, sizeof(Cars)))
                        if(strcmpi(M[::op-1].retcarid(),C.retcarid())==0)
                         { updatestatus=1;
                           carfile.seekg(carfile.tellg()-sizeof(Cars));
                           C.putcar();
                           C.getcar();
                           carfile.write((char*)&C, sizeof(Cars));
                           break;
                         }
                      }
                     if(updatestatus) cout<<"\n\t\tCar Details Updated ! ";
                     else cout<<"\n\t\tCar Not Found !";
                     carfile.close();
                        getch();

                  }

 void DisplayCar() { Cars D;
                     int i=0;
                     ifstream carfile("carsdata",ios::in|ios::binary);
                         //Read From File
                     system("cls");
                     cout<<"\n\t\t\tDISPLAY AVAILABLE CARS";
                     while(carfile.read((char*)&D, sizeof(Cars)))
                      { cout<<"\n\n\tCar No. "<<(i+1)<<endl;
                        D.putcar();
                        getch();
                        i++;
                      }
                     carfile.close();
                   }

 void delay() { for(unsigned long i=0;i<80000000;i++) // Determines speed of loading Animation
                  {/*To delay output*/ }
              }

 void loading(int x,int y) { const char slash[4]={92,196,47,179};
                             for(unsigned int i=0;i<10;i++) // Loading Running delay(1=0.4786 s)
                              for(short j=0;j<4;j++)
                               { gotoxy(x,y);textcolor(RED); // (x,y)-Position of Load Animation
                                 putchar(slash[j]); delay();delay();
                               }
                           }

 void menu() { //char op;
               menu: system("cls");
               cout<<"\t\t\t Main Menu\n\n";
               cout<<"\n\t[1] ADD Car\n";
               cout<<"\n\t[2] Display Car\n";
               cout<<"\n\t[3] Inventory\n";
               cout<<"\n\t[4] Update Car\n";
               cout<<"\n\t[5] Exit\n";
               cout<<"\nEnter your option => ";
               cin>>::op;
            switch(::op)
                { case 1: system("cls");
                            cout<<'\a';
                            AddCar();
                            break;

                  case 2: system("cls");
                            cout<<'\a';
                            DisplayCar();
                            break;

                  case 3: system("cls");
                            cout<<'\a';
                            C.CarTable(); getch();
                            break;

                  case 4: system("cls");
                            cout<<'\a';
                            UpdateCar();
                            break;

                  case 5: exit(0);
                }
               goto menu;
             }


 void main() {
               //loading(4,4);
               L.check();
             }





