#include <bits/stdc++.h>
using namespace std;


struct customer{
    string name;
    string description;
    double rate_per_hour;
    int hour;
    double bill;
};

void read_data(customer arr[], int n, string file_name)
{
    freopen("customer_data.txt","r",stdin); // reading input from customer_data.txt

    for(int i=0; i<n; i++){
        cin >> arr[i].name >> arr[i].description >> arr[i].rate_per_hour >> arr[i].hour;
    }
}

void calcNet(customer arr[], int n)
{
    for(int i=0; i<n; i++){
        arr[i].bill = arr[i].rate_per_hour * arr[i].hour;
    }
}

void print_data(customer arr[], int n)
{
    cout << left << setw(15) << "Name" << left << setw(20) << "Description" << left << setw(15) << "Rate/Hour" << left << setw(15) << "Hours" << left << setw(15) << "Payment" << endl;
    cout << "------------------------------------------------------------------------" << endl;

    for(int i=0; i<n; i++){
        cout << left << setw(15) << arr[i].name << left << setw(20) << arr[i].description << left << setw(15) << arr[i].rate_per_hour << left << setw(15) << arr[i].hour << left << setw(15) << arr[i].bill << endl;
    }
}

int main()
{
    customer *arr = new customer[10]; //1-dimensional array of struct customer

    cout << "The customers' data being read....." << endl;
    read_data(arr, 10, "customer_data.txt"); // read_data() is called from main() with 3 arguments and returns void
    cout << "\nThe customers' data have been read successfully." << endl;

    calcNet(arr, 10); // calcNet() is called from main() with 2 arguments and returns void

    cout << "\nBelow is the customer's details report including the payment.....\n" <<  endl;
    print_data(arr, 10); // print_data() is called from main() and returns void

    return 0;
}
