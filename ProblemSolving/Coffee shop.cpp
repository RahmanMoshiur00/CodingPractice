#include<bits/stdc++.h>

using namespace std;

#define TOTAL_ITEMS     7
#define TAX             0.06

struct info {
   string name;
   string address;
} customer;


double bill[TOTAL_ITEMS][2] =  {{4.0, 0},
                                {6.0, 0},
                                {5.0, 0},
                                {3.5, 0},
                                {7.0, 0},
                                {4.0, 0},
                                {6.0, 0}};
string item[TOTAL_ITEMS] = {"Caramel Macchiato", "Coffee Espresso", "Caramel Latte", "Desserts", "Flat White",
"Salted Caramel Mocha", "White Chocolate"};


void lines();
void welcome();
void menu(int);
void cancel_orders();
void goodbye();
void after_no_add_on();
void add_on();
double count_total_bill();
void show_current_price();
void billing();
void store_billing_in_files();


int main()
{
    cout << "Enter your name: ";
	getline(cin, customer.name);
	cout << "Enter your address: ";
    getline(cin, customer.address);

    welcome();
    menu(0);
    goodbye();

    return 0;
}

void lines()
{
    cout << "-----------------------------------------------------" << endl;
}

void welcome()
{
    lines();
    cout << endl << setw(35) << "Hello, " << customer.name << "! Welcome to Coffee Shop" << endl << endl;
    lines();
}

void menu(int order_no)
{
    system("clear");
    cout<<"\nItem Code------Item--------------------Price"<<endl;
    cout << "1       Caramel Macchiato           RM 4.0" << endl;
    cout << "2       Coffee Espresso             RM 6.0" << endl;
    cout << "3       Caramel Latte               RM 5.0" << endl;
    cout << "4       Desserts                    RM 3.5" << endl;
    cout << "5       Flat White                  RM 7.0" << endl;
    cout << "6       Salted Caramel Mocha        RM 4.0" << endl;
    cout << "7       White Chocolate             RM 6.0" << endl;
    if(order_no == 0){
        cout << "0       EXIT" << endl;
    }
    else{
        cout << "8       Current Total Amount" << endl;
        cout << "9       Cancel item-wise orders" << endl;
        cout << "10      Confirm Orders" << endl;
        cout << "0       Cancel all orders and EXIT" << endl;
    }
    lines();

    int menu_code;
    double quantity;

    cout << "Please select your desired item code from above menu: ";
    cin >> menu_code;
    if(menu_code>=1 && menu_code<=7){
        cout << "Please enter quantity of " << item[menu_code-1] <<": ";
        cin >> quantity;
        bill[menu_code-1][1] += quantity;
        add_on();
    }
    else if(menu_code == 8 && order_no != 0){
        show_current_price();
        cout << endl;
        add_on();
    }
    else if(menu_code == 9 && order_no != 0){
        cancel_orders();
        add_on();
    }
    else if(menu_code == 10 && order_no != 0){
        billing();
    }
    else if(menu_code == 0){
        goodbye();
        exit(0);
    }
    else{
        cout << "You've selected invalid item code. Please select again." << endl;
        menu(order_no);
    }
}

void add_on()
{
    string temp;
    cout << "Do you want to add-on[y/n]: ";
    cin >> temp;
    if(temp=="y" or temp=="Y" or temp=="YES" or temp=="yes" or temp=="Yes"){
        menu(1);
    }
    else{
        system("clear");
        after_no_add_on();
    }
}

void cancel_orders()
{
    show_current_price();
    cout << "\nPlease enter serial number of the ordered item and it's quantity: ";

    int serial_no;
    double quantity;
    cin >> serial_no;
    cin >> quantity;

    int idx = 1;
    for(int i=0; i<TOTAL_ITEMS; i++){
        if(bill[i][1] > 0){
            if(idx == serial_no) bill[i][1] = quantity;
            idx++;
        }
    }
}

void after_no_add_on()
{
    cout << "\nOptions" << endl;
    lines();
    cout << "1       Confirm orders" << endl;
    cout << "2       Current Total Amount" << endl;
    cout << "3       Cancel item-wise orders" << endl;
    cout << "0       Cancel all orders and EXIT" << endl;
    lines();
    cout << "Please select your desired item code from above menu: ";

    int menu_code;
    cin >> menu_code;

    if(menu_code == 1){
        billing();
    }
    else if(menu_code == 2){
        show_current_price();
        after_no_add_on();
    }
    else if(menu_code == 3){
        cancel_orders();
        after_no_add_on();
    }
    else if(menu_code == 0){
        goodbye();
        exit(0);
    }
    else{
	     cout << "Please select options 0, 1, 2, or 3." << endl;
	     after_no_add_on();
    }
}


double count_total_bill()
{
    double total_amount = 0;
    for(int i=0; i<TOTAL_ITEMS; i++){
        if(bill[i][1] > 0){
            total_amount += (bill[i][0] * bill[i][1]) + (bill[i][0] * bill[i][1] * TAX);
        }
    }

    return total_amount;
}

void show_current_price()
{
    system("clear");
    cout << "\nNo.    Item                Quantity    Price" << endl;
    lines();

    int idx = 1;
    double total_amount = 0, item_price = 0;
    for(int i=0; i<TOTAL_ITEMS; i++){
        if(bill[i][1] > 0){
            item_price = (bill[i][0] * bill[i][1]) + (bill[i][0] * bill[i][1] * TAX);
            cout << idx++ << "      " << setw(21) << left << item[i] << bill[i][1] << "         " << item_price << endl;
        }
    }
}

void billing()
{
    system("clear");
    cout << "Order receiving method:\n";
    cout << "1.Dine-in\n2.Take away\n";
    cout << "\nChoose any of this two: ";
    int x; cin >> x;


    cout << "\n\nCustomer name: " << customer.name << "      Customer address: " << customer.address << endl;
    cout << "\nNo.    Item                Quantity    Price" << endl;
    lines();

    int idx = 1;
    double total_amount = 0, item_price = 0;
    for(int i=0; i<TOTAL_ITEMS; i++){
        if(bill[i][1] > 0){
            item_price = (bill[i][0] * bill[i][1]) + (bill[i][0] * bill[i][1] * TAX);
            cout << idx++ << "      " << setw(21) << left << item[i] << bill[i][1] << "         " << item_price << endl;
        }
    }

    lines();
    cout << setw(38) << right << "Total = " << count_total_bill() << endl;

    goodbye();

    store_billing_in_files();
}


void store_billing_in_files()
{
    freopen("billing.txt","w",stdout);
    show_current_price();
    lines();
    cout << setw(38) << right << "Total = " << count_total_bill() << endl;
}

void goodbye()
{
    cout << "\n\nThank you! Please, come again. Have a good day. :)" << endl;
}
