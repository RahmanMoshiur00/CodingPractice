#include<bits/stdc++.h>
using namespace std;

#define CM 4.00 //caramel macchiato
# define CE 6.00 // coffee espresso
# define CL 5.00 //caramel latte
# define DE 3.50 //desserts
# define FW 7.00 //flat white
# define SC 4.00 // salted caramel mocha
# define WC 6.00 //white chocolate
# define TAX 0.06

void umobile();
void WiFi();
void age();
double total();
double coffee_espresso();
double salted_caramelmocha();
double caramel_Macchiato();
double white_chocolate();
double coffee_latte();
double Flat_white();
double Dessert();
void matric();
void bill();
void pretty();
int quantity[7] = {0}, option;
char addon;
double cetotal = 0.0, scmtotal = 0.0, wctotal = 0.0, cltotal = 0.0, fwtotal = 0.0, dtotal = 0.0, cmtotal = 0.0;
double subtotal = 0.0, finaltotal = 0.0;

int
main() {
  system("cls");//to clear the screen

  pretty(); // function call tp print line

  cout<<"\n                 welcome to Radiant Star!\n ";
  pretty();

  cout<<"\n     1       coffee espresso                    RM6.00      \n\n";
  cout<<"     2       salted caramel mocha               RM4.00      \n\n";
  cout<<"     3       caramel macchiato                  RM4.00      \n\n";
  cout<<"     4       white chocolate                    RM6.00      \n\n";
  cout<<"     5       coffee latte                       RM5.00      \n\n";
  cout<<"    6       flat white                         RM7.00      \n\n";
  cout<<"    7       Dessert(Ice cream/pie/cake)        RM3.50      \n\n";
  cout<<"     8       Display Total \n\n";// in case if user finished but chose adding on by mistake
  cout<<"     9       End\n\n"; // canceling order and exit from the program

  cout<<"Please Select Your Option from Above Menu : ";
  cin>>option;

  // Each order will transfere user to other functions which ask them about quantity and if they want to add on
  switch (option){
  case 1:
    coffee_espresso();
    break;

  case 2:
    salted_caramelmocha();
    break;

  case 3:
    caramel_Macchiato();
    break;

  case 4:
    white_chocolate();
    break;

  case 5:
    coffee_latte();
    break;

  case 6:
    Flat_white();
    break;

  case 7:
    Dessert();
    break;

  case 8:
    total();
    break;

  case 9:
    cout<<"\n\nthank you for buying hope to see you soon!\n";
    exit(0);// exit from program

  default:
    cout<<"Invalid Input!\n";

  }
}

double coffee_espresso() {
  cout<<"You have selected coffee espresso\n";
  cout<<"Please Enter your Quantity: ";
  if (quantity[0] != 0 && option == 1) {
        int new_quan = 0;
        cin>>new_quan;
        quantity[0] += new_quan;
  } else {
        cin>>quantity[0];
  }
  cetotal = CE * quantity[0]; // coffee espresso total=price X quantity
  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon){
  case 'y':// return user to main which has the menu to choose another thing
    main();
    break;
  case 'n'://'no' means that user is done selecting and they will be transfere to total function
    total();
    break;
  default:
    cout<<"Invalid Number!\n";// if user entred any character other than y/n
    cin>>addon;
  }

}

double salted_caramelmocha() {
  cout<<"You have selected salted caramel mocha\n";
  cout<<"Please Enter your Quantity: ";
  if (quantity[1] != 0 && option == 2) {
        int new_quan = 0;
        cin>>new_quan;
        quantity[1] += new_quan;
  } else {
        cin>>quantity[1];
  }
  scmtotal = SC * quantity[1];
  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon) {
  case 'y':
    main();
    break;
  case 'n':
    total();
    break;
  default:
    cout<<"Invalid Error!\n";
  }

}

double caramel_Macchiato() {
  cout<<"You have caramel macchiato\n";
  cout<<"Please Enter your Quantity: ";
  if (quantity[2] != 0 && option == 3) {
        int new_quan = 0;
        cin>>new_quan;
        quantity[2] += new_quan;
  } else {
        cin>>quantity[2];
  }
  cmtotal = CM * quantity[2];
  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon) {
  case 'y':
    main();
    break;
  case 'n':
    total();
    break;
  default:
    cout<<"Invalid Error!\n";
  }

}

double white_chocolate() {
  cout<<"You have selected white chocolate\n";
  cout<<"Please Enter your Quantity: ";
  if (quantity[3] != 0 && option == 4) {
        int new_quan = 0;
        cin>>new_quan;
        quantity[3] += new_quan;
  } else {
        cin>>quantity[3];
  }
  wctotal = WC * quantity[3];
  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon) {
  case 'y':
    main();
    break;
  case 'n':
    total();
    break;
  default:
    cout<<"Invalid Error!\n";
  }

}

double coffee_latte() {
  cout<<"You have selected coffee latte\n";
  cout<<"Please Enter your Quantity: ";
  if (quantity[4] != 0 && option == 5) {
        int new_quan = 0;
        cin>>new_quan;
        quantity[4] += new_quan;
  } else {
        cin>>quantity[4];
  }
  cltotal = CL * quantity[4];
  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon) {
  case 'y':
    main();
    break;
  case 'n':
    total();
    break;
  default:
    cout<<"Invalid Error!\n";
  }

}

double Flat_white() {
  cout<<"You have selected flat white\n";
  cout<<"Please Enter your Quantity: ";
  if (quantity[5] != 0 && option == 6) {
        int new_quan = 0;
        cin>>new_quan;
        quantity[5] += new_quan;
  } else {
        cin>>quantity[5];
  }
  fwtotal = FW * quantity[5];
  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon) {
  case 'y':
    main();
    break;
  case 'n':
    total();
    break;
  default:
    cout<<"Invalid Error!\n";
  }

}

double Dessert() {
  int des_type;
  cout<<"You have selected Dessert\n";
  cout<<"Please Enter your Dessert:\n1. ice cream\n2. pie\n3. cake\n";
  cin>>des_type;
  switch (des_type){
	  case 1: cout<<"please enter your quantity: ";
  			if (quantity[6] != 0 && option == 7) {
  			      int new_quan = 0;
  			      cin>>new_quan;
  			      quantity[6] += new_quan;
  			} else {
  			      cin>>quantity[6];
  			}
      dtotal = DE * quantity[6]; break;
    case 2:cout<<"please enter your quantity: ";
  			if (quantity[6] != 0 && option == 7) {
  			      int new_quan = 0;
  			      scanf("%d", &new_quan);
  			      quantity[6] += new_quan;
  			} else {
  			      cin>>quantity[6];
  			}
      dtotal = DE * quantity[6]; break;
  	case 3:cout<<"please enter your quantity: ";
  			if (quantity[6] != 0 && option == 7) {
  			      int new_quan = 0;
  			      cin>>new_quan;
  			      quantity[6] += new_quan;
  			} else {
  			      cin>>quantity[6];
  			}
      dtotal = DE * quantity[6]; break;
      default: printf("try again");
      Dessert();
  }

  cout<<"Do you want to add-on?(y,n) ";
  cin>>addon;
  switch (addon) {
  case 'y':
    main();
    break;
  case 'n':
    total();
    break;
  default:
    cout<<"Invalid Input!\n";
  }

}

double total() {
  int dine, pay_method, dis_type;
  double total;

  cout<<"Do you want to dine in or take away?\n";
  cout<<"1. Dine In\n2. Take Away\n";
  cin>>dine;
  cout<<"Select your payment method:\n1. Cash Payment\n2. Credit Card Payment\n";
    // It'll be same price but user will have free drink if subtotal is greater than or equal to 35 and if they paid by credit card Payment
  cin>>pay_method;
  switch (pay_method) {
  case 1:
    subtotal += (cetotal + scmtotal + wctotal + cltotal + fwtotal + dtotal + cmtotal);
    break;
  case 2:
    subtotal += (cetotal + scmtotal + wctotal + cltotal + fwtotal + dtotal + cmtotal);
    break;
  default:
    cout<<"Invalid Input!\n";
  }
  //these options provide offers
    cout<<"Are you one of these (You can choose only one offer) :\n1. IIUM students \n2. old people \n3. umobile\n4.";
	cout<<"none of these\n";
  cin>>dis_type;
  if (dis_type == 1) {
    matric();
  } else if (dis_type == 2) {
    age();
  } else if (dis_type == 3) {
    umobile();
  } else if (dis_type == 4)
      finaltotal = subtotal;

  bill();// function call takes user to the bill
}

void matric() {
  int matric;
  cout<<"enter your matric number please: ";
  cin>>matric;
  if (matric <= 1829999 && matric >= 1410000)//possible matric number for students of IIUM invalid numbers wont have discount
   {
    finaltotal = subtotal - ((0.10) * subtotal);
  } else {
    finaltotal = subtotal;// total wont change because there is no discount
    cout<<"sorry no discount";
  }
  return; //return finaltotal to total()
}

void age() { // using function void cuse  dont return anything
  int age = 0;
  int total = 0;
  //this offer provide various discounts for old people older than or equal to 50 there is no discount for people younger than 50
  cout<<"Enter your age: ";
  cin>>age;
  //processing
  if (age >= 50 && age <= 59) //condition ,compound statement
   {    finaltotal = subtotal - ((0.15) * subtotal);}
  if (age >= 60 && age <= 69)
   {finaltotal = subtotal - ((0.20) * subtotal);}
  if (age >= 70 && age <= 79)
   {     finaltotal = subtotal - ((0.25) * subtotal);}
   if (age >= 80 && age <= 89)
   {     finaltotal = subtotal - ((0.30) * subtotal);}
   if (age >= 90)
   {     finaltotal = subtotal - ((0.35) * subtotal);}
  if(age<50){
    cout<<" sorry no discount";
    finaltotal = subtotal;}

  return;
}

void umobile()//it will not return anything by using void
 {
  char ans = 'y';
  char nums[3];
  int attempt = 0;
  bool correct = false;// You can support your variable with using its header.
  cout<<"Are you using U mobile network (y/n)? ";
  cin>>ans;

  if (ans == 'y') {
    cout<<"Enter the first three numbres of your phone No: ";
    cin>>nums;
    while (attempt < 2) {
      if (strcmp(nums, "011") == 0 || strcmp(nums, "018") == 0) //compares the string with using if .
	  {
        finaltotal = subtotal - ((0.05) * subtotal);
        correct = true;//You can support your variable with using its header.
        break;
      }
      finaltotal = subtotal - ((0.05) * subtotal);
      cout<<"It might be that your Input is wrong Try again please !!\n";
      cout<<"Enter the first three numbres of your phone No: ";
      cin>> nums;
      attempt++;
    }
    if (!correct) {
      cout<<"Thank you";
    }
  } else {
      finaltotal = subtotal;
    }
  return;
}

void WiFi()  //using void because we don't want to return anything
{
  srand(time(NULL)); //  using srand() to seed random function
  int passward[10]; // declaration of the array
  int i;

  for (i = 0; i < 10; i++) {
    passward[i] = 0 + rand() % (9 - 0 + 1);;// using rand() here in condition because we want get a random number
  }
  printf("Wifi Passward: ");
  for (i = 0; i < 10; i++) {
    cout<<passward[i];// display the password for user in bill
  }
  cout<<"\nWifi available for Two hours only\n";

}

void bill() {

  system ("cls");
  time_t rawtime; // set the time to null so it will read the right system data everytime you run the program.
  struct tm * info;
  time( & rawtime);
  info = localtime( & rawtime);
  pretty();
  cout<<"\t\t   Radiant Star coffee";
  pretty();
  cout<<"\n\n\t\t"<< asctime(info); //displaying time and date
  pretty();
  cout<<"\n|  Order\t\t   Quantity    Price\tTotal\n";// if function will only display the orders that user chose (quantity, price per one, quantity * price)
  if (cetotal != 0) printf("|  Coffee espresso\t\t%d\t%.2f\t%.2f\n", quantity[0], CE, cetotal);
  if (scmtotal != 0) printf("|  salted caramel mocha\t\t%d\t%.2f\t%.2f \n", quantity[1], SC, scmtotal);
  if (cmtotal != 0) printf("|  caramel macchiato\t\t%d\t%.2f\t%.2f \n", quantity[2], CM, cmtotal);
  if (wctotal != 0) printf("|  white chocolate\t\t%d\t%.2f\t%.2f \n", quantity[3], WC, wctotal);
  if (cltotal != 0) printf("|  coffee latte\t\t\t%d\t%.2f\t%.2f \n", quantity[4], CL, cltotal);
  if (fwtotal != 0) printf("|  flat white\t\t\t%d\t%.2f\t%.2f \n", quantity[5], FW, fwtotal);
  if (dtotal != 0) printf("|  dessert\t\t\t%d\t%.2f\t%.2f \n", quantity[6], DE, dtotal);
  if (finaltotal >= 35) printf("|  Free Drink\t\t\t1\tFree\t0\n");

  pretty();
  cout<<"Total Price before discount: RM"<<subtotal << endl;// from total function
  cout<<"Total Price after discount: RM" << finaltotal << endl;;// will only change if user choose an offer
  cout<<"Total Price After tax: RM"<< finaltotal + (finaltotal * TAX) << endl;
  pretty();
  WiFi();// function call to display wifi password
  cout<<"\n\nthank you for buying hope to see you soon!";
  return;
}

void pretty(){
  cout<<"\n=======================================================\n";
}

// END
