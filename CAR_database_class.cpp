#include<windows.h>
#include<fstream.h>
#include<stdio.h>
#include<stdlib.h>
//#include<conio.h>
#include"conionew.h"

int op;
void menu();
void ventry(char[],short,short);
HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);

 class Design
  {
    char usr[12];
    char pss[12];
    //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    public:
    int check();
    void border(int p,int q,int l,int w,int type);
    void crusor();

  }L;

int Design::check()
  { //HANDLE color=GetStdHandle(STD_OUTPUT_HANDLE);
    xx:
    clrscr();
    border(3,2,74,21,2);
    int i=0;
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
    ventry(usr,2,12);
    gotoxy(38,17);

    while((pss[i]=getch())!='\r' && i<12)
     { if(pss[i]=='\b' && i>0)
	     { cout<<'\b'<<' '<<'\b';
          i--;
	     }
	    else if(i!=0 || pss[i]!='\b')
	     { cout << "*";
	       i++;
        }
	  }
    pss[i]='\0';
    gotoxy(38,18);
    cout<<pss<<endl;


    if(strcmp(usr,"admin") == 0 && strcmp(pss,"pass123") == 0)
      {
         cout<<'\a';
	      clrscr();
          return(1);
      }

    else
      {
	textcolor(RED + BLINK);
	gotoxy(22,21);cout<<'\a'<<'\a';
	cprintf("Invalid Username Or Password !!!");
	getch();
	textcolor(WHITE);
	goto xx;
      }
  }

 void line(int p,int q,int l,char type='v',int type2=0)
  {
     int i;char hl,vl;
    /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       type=v - For Vertical Line (default)
       type=h - For Horizontal Line
       l-length(horizontal distance) of border;
    */
    if(type2==1)
    {hl=45;vl=124;}   //hyphen(-)and or (|)

   /* else if(type2==2)
    {hl=205;vl=186;}
    else if(type2==3)
    {hl=205;vl=186;} */

    else
    {hl=196;vl=179;} //border characters

    textcolor(WHITE);
    if(type=='v')
    for(i=0;i<l;i++)  // Vertical line of length l
     { gotoxy(p,q+i);
       cprintf("%c",vl); //'7C'(hyphen); 'DE'(accented i); '7C' (or line); 'B3' (border);
     }
     else
     for(i=0;i<l;i++) // Horizontal Line of length l
      { gotoxy(p+i,q);
       cprintf("%c",hl);
      }
  }

void Design::border(int p,int q,int l,int w,int type) //Use to make borders as the name suggests
  { /* Where (p,q)-margin (coordinate of top-left vertice of box border);
       w-width(vertical distance) of border;
       l-length(horizontal distance) of border;
       type => 2(double border)(default); type => 1(single border)
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

void Design::crusor()//To get position of pointer in console window(for output purpose)
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

 void ventry(char t[],short code=0,short N=10)
/* code=0 >> for inputing alphabets(a-Z), space & underscore(_)
   code=1 >> for inputing numbers(0-9), dot(.) & '/'
   code=2 >> for inputing username
   code=3 >> for normal input without space, ':' & ';'
*/
  { unsigned short i=0;
    if(code==0)
	  { while((t[i]=getch())!='\r' && i<N)
        if((t[i]>=97 && t[i]<=122) || (t[i]>=65 && t[i]<=90) || t[i]==32 || t[i]=='_')
		   { cout << t[i];
		     i++;
	    	}
	     else if(t[i]==8 && i>0)
		   { cout<<"\b \b";
		     i--;
	    	}
	  }
    else if(code==1)
	  { while((t[i]=getch())!='\r' && i<N)
	    if((t[i]>=48 && t[i]<=57) || t[i]==46 || t[i] == '/')
	     { cout<<t[i];
	     	 i++;
        }
	    else if(t[i]==8 && i>0)
        { cout<<"\b \b";
		    i--;
	     }
	  }

    if(code==2)
	  { while((t[i]=getch())!='\r' && i<N)
        if((t[i]>=97 && t[i]<=122) || (t[i]>=46 && t[i]<=57) || (t[i]>=65 && t[i]<=90) || t[i]=='@')
		   { cout << t[i];
		     i++;
	    	}
	     else if(t[i]==8 && i>0)
		   { cout<<"\b \b";
		     i--;
	    	}
     }

    if(code==3)
	  { while((t[i]=getch())!='\r' && i<N)
        if((t[i]>=33 && t[i]<=126) && t[i]!=':' && t[i]!=';')
		   { cout << t[i];
		     i++;
	    	}
	     else if(t[i]==8 && i>0)
		   { cout << "\b \b";
		     i--;
	    	}
	  }
      t[i]='\0';
  }


//            ***************** class Cars *******************

 class Cars { char carid[6];
              char make[20];
              char model[20];
              unsigned short year;
              char category[20];
              char passengers;
              char description[10];
              short status; //1=avail. , 0=booked
        public:
              void getcar();
              void putcar();
              void CarTable();
              void AvailTable(char*&c);
              void switch_status(int op=2);
              char *retcarid() { return(carid); }
              char *retmodel() { return(model); }
              char *retmake() { return(make); }
              ~Cars(){ /*Destructor to distroy this class when the scope is over*/ }
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
                        status=1;//status=1 means available;
                     }

 void Cars::putcar() {  cout<<"\n\tCarID => "<<carid;      // Displayed on Table
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
                        gotoxy(10,r);cout<<carid;
                        gotoxy(18,r);cout<<make<<" "<<model;
                        gotoxy(37,r);cout<<category;
                        gotoxy(51,r);//cout<<C.price;
                        gotoxy(67,r);(status==1) ? cout<<"Available" : cout<<"BOOKED!";
                        //getch();
                        i++;r++;
                       }
                      }

 void Cars::AvailTable(char* &c) { system("color 0E");
                                   system("cls");
                                   L.border(4,4,73,17,1);
                                   line(8,5,16,'v',1);//Vertical line After No.
                                   line(16,5,16,'v',1);//Vertical line After Carid
                                   line(35,5,16,'v',1);//Vertical line After Car
                                   line(55,5,16,'v',1);// After Category
                                   line(65,5,16,'v',1);// After Price
                                   line(5,6,72,'h',1);// Horizontal line
                                   gotoxy(5,5);cout<<" No";gotoxy(10,5);cout<<" Year";gotoxy(25,5);cout<<"CAR";gotoxy(42,5);cout<<"CATEGORY";gotoxy(57,5);cout<<"Price/hr";gotoxy(67,5);cout<<"Passengers";
                                   gotoxy(1,2);
                                   ifstream carfile("carsdata",ios::in|ios::binary);
                                       //Read From File
                                       //system("cls");
                                   int i,r;
                                   cout<<"\t\t\tDISPLAY AVAILABLE CARS";
                                   for(i=1,r=8;carfile.read((char*)&C, sizeof(C));)
                                   if(status==1)
                                    { gotoxy(5, r);cout<<"["<<i<<"]";
                                      gotoxy(10,r);cout<<year;
                                      gotoxy(18,r);cout<<make<<" "<<model;
                                      gotoxy(37,r);cout<<category;
                                      gotoxy(51,r);//cout<<C.price;
                                      gotoxy(67,r);cout<<passengers;
                                      i++,r++;
                                    }
                                   carfile.clear();
                                   carfile.seekg(0);
                                   gotoxy(5,24); cout<<"Select Car No. >> ";cin>>r;
                                   i=1;
                                   while(carfile.read((char*)&C, sizeof(C)))
                                    { if(i==r&&status==1) { strcpy(c,carid);
                                                            break;
                                                          }
                                      if(status==1) { i++; }
                                    }
                                 }

 void Cars::switch_status(int op) { if(op==1) status=1;
                                      else if(op==0) status=0;
                                      else (status==0) ? status=1 : status=0;
                                    }

 void status_edit(char *op="Nothing!") { fstream carfile("carsdata",ios::in|ios::out|ios::binary);
                                         while(carfile.read((char*)&C, sizeof(C)))
                                          { if(*op=='1'&&*(op+1)=='\0') C.switch_status(1);
                                            else if(*op=='0'&&*(op+1)=='\0') C.switch_status(0);
                                            else if(strcmp(C.retcarid(),op)==0)
                                             { C.switch_status();
                                               carfile.seekg(carfile.tellg()-sizeof(C));
                                               carfile.write((char*)&C, sizeof(C));
                                               break;
                                             }
                                            carfile.seekg(carfile.tellg()-sizeof(C));
                                            carfile.write((char*)&C, sizeof(C));
                                          }
                                       }

 void status_editmenu() { menu:
                          system("cls");
                          cout<<"\n\t\t\tEDIT CAR STATUS\n\n";
                          cout<<"\n\t[1] EDIT All Status to [ AVAILABLE ] \n ";
                          cout<<"\n\t[2] EDIT All Status to [ BOOKED! ]\n";
                          cout<<"\n\t[3] Car Status Switch\n";
                          cout<<"\n\t[4] GO BACK\n";
                          cout<<"\nEnter your option => ";
                          cin>>::op;
                          char carid[6];
                          switch(::op)
                           { case 1: system("cls");
                                     cout<<'\a';
                                     status_edit("1");getch();
                                     break;

                             case 2: system("cls");
                                     cout<<'\a';
                                     status_edit("0");getch();
                                     break;

                             case 3: system("cls");
                                     cout<<'\a';
                                     cout<<"\n\tEnter CarID to Update: ";
                                     gets(carid);
                                     status_edit(carid);getch();
                                     break;

                             case 4: system("cls");
                                     menu();
                                     break;

                           }
                          goto menu;
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
                     cout<<"\nEnter Carid/Model/Make of Car to Update => ";
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
                             for(unsigned int i=0;i<4;i++) // Loading Running delay(1=0.4786 s)
                              for(short j=0;j<4;j++)
                               { gotoxy(x,y);textcolor(RED); // (x,y)-Position of Load Animation
                                 putchar(slash[j]); delay();delay();
                               }
                           }

 void inputdesign() { clrscr;
                      SetConsoleTextAttribute(color,9);
                      L.border(3,2,74,21,2);
                      gotoxy(9,8);cout<<"Drv. Lic. #: ";
                      gotoxy(46,8);cout<<"Name: ";
                      gotoxy(9,11);cout<<"Address: ";
                      gotoxy(9,14);cout<<"City: ";
                      gotoxy(46,14);cout<<"ZIPCode: ";
                      gotoxy(9,17);cout<<"Email: ";
                      gotoxy(46,17);cout<<"Rent Car ID: ";
                    }

 class Customer { unsigned long lic_no;
                  char name[25],email[30];
                  char address[100],city[30];
                  char rentcarid[6];
                  unsigned long zipcode;
              public:
                  void getcustomer();
                  void putcustomer();
                  void get_rentcarid() { C.AvailTable(rentcarid); }
                  void test(){cout<<rentcarid;}
                  char *ret_rentcarid() { return rentcarid; }
                  ~Customer() { /*Destructor*/ }
                }N;

 void Customer::getcustomer() { SetConsoleTextAttribute(color,11);
                                gotoxy(22, 8); cin>>lic_no;
                                N:
                                gotoxy(52,8); ventry(name,0,24);
                                if(name[0]==NULL) goto N;
                                flushall();
                                gotoxy(18,11); gets(address);
                                flushall();
                                gotoxy(15,14); gets(city); gotoxy(55,14); cin>>zipcode;
                                gotoxy(16,17); ventry(email,3,26);
                                flushall();
                              }

 void Customer::putcustomer() { SetConsoleTextAttribute(color,11);
                                gotoxy(22, 8); cout<<lic_no; gotoxy(52,8); cout<<name;
                                gotoxy(18,11); cout<<address;
                    				  gotoxy(15,14); cout<<city; gotoxy(55,14); cout<<zipcode;
                  			     gotoxy(16,17); cout<<email; gotoxy(59,17);cout<<rentcarid;
                  			   }

 void AddCustomer() { system("cls");
                      cout<<"\n\t\t\tADD NEW CUSTOMER";
                      system("cls");
                      cout<<"\n\n\tAdd Cust. No. "<<endl;
                      inputdesign();
                      N.getcustomer();
                      N.get_rentcarid();
                      clrscr();
                      inputdesign();
                      N.putcustomer();
                      { SetConsoleTextAttribute(color,138);
                        gotoxy(23,21); cout << " S";
                        SetConsoleTextAttribute(color,142);
                        cout << "ave ";
                      }
                      { SetConsoleTextAttribute(color,140);
                        gotoxy(51,21); cout << " C";
                        SetConsoleTextAttribute(color,142);
                        cout << "ancel ";
                      } S:
                      if(getch()=='s')
                       {     //Write TO File
                         ofstream customer("customer_record",ios::out|ios::binary|ios::app);
                         customer.write((char*)&N, sizeof(Customer));
                         status_edit(N.ret_rentcarid());
                         SetConsoleTextAttribute(color,252);
                         clrscr();                                //124
                         gotoxy(31,12); cout<<" CUSTOMER SAVED ! ";
                         for(int i=0;i<15;i++) { delay();delay();delay(); }
                         customer.close();
                       }
                      else if(getch()=='c') menu();
                      else goto S;
                    }

 void DisplayCust() { Customer D;
                      int i=0;
                      ifstream carfile("customer_record",ios::in|ios::binary);
                         //Read From File
                      system("cls");
                      cout<<"\n\t\t\tDISPLAY AVAILABLE CARS";
                      while(carfile.read((char*)&D, sizeof(D)))
                       { cout<<"\n\n\tCar No. "<<(i+1)<<endl;
                         inputdesign();
                         D.putcustomer();
                         getch();
                         i++;
                       }
                      carfile.close();
                    }

 void menu() {
               menu: system("cls");
               system("color 0F");
               cout<<"\t\t\t Main Menu\n\n";
               cout<<"\n\t[1] ADD Car\n";
               cout<<"\n\t[2] ADD Customer\n";
               cout<<"\n\t[3] Display Car\n";
               cout<<"\n\t[4] Inventory\n";
               cout<<"\n\t[5] Update Car\n";
               cout<<"\n\t[6] Edit Status\n";
               cout<<"\n\t[8] Exit\n";
               cout<<"\nEnter your option => ";
               cin>>::op;
            switch(::op)
                { case 1: system("cls");
                            cout<<'\a';
                            AddCar();
                            break;

                  case 2: system("cls");
                            cout<<'\a';
                            AddCustomer();
                            break;

                  case 3: system("cls");
                            cout<<'\a';
                            DisplayCar();
                            break;

                  case 4: system("cls");
                            cout<<'\a';
                            C.CarTable(); getch();
                            break;

                  case 5: system("cls");
                            cout<<'\a';
                            UpdateCar();
                            break;

                  case 6: system("cls");
                            cout<<'\a';
                            status_editmenu();
                            break;

                  case 7: system("cls");
                            char* str;
                            C.AvailTable(str);
                            cout<<str; getch();
                            break;

                  case 8: exit(0);
                }
               goto menu;
             }




 void main() {
              // loading(4,4);
               L.check();
               //DisplayCust();
               menu();
             }





