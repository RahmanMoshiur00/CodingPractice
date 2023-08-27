#include<bits/stdc++.h>
using namespace std;

int main()
{
    int GuestNo,TimeStay;
    cout<<"Enter number of guest(s): ";
    cin >> GuestNo;

	while(GuestNo<1 || GuestNo>6){
		cout<<"Invalid entry.Please enter a value between 1-6 people only." << endl;
		cout<<"Enter number of guest(s): ";
        cin >> GuestNo;
	}

	cout<<"Enter duration of stay: ";
	cin>>TimeStay;
	while(TimeStay<1 || TimeStay>7){
		cout<<"Invalid entry.Duration of stay must be at least 1 and not more than 7."<<endl;
		cin >> TimeStay;
	}

    if(GuestNo>=1 && GuestNo<=2 ){
    	if(TimeStay>=1 && TimeStay <=2){
    		cout<<"You have selected package M"<<endl<<endl;
    		cout<<"You are given a 13% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<300-(300 * 0.13)<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(300-(300 * 0.13)) * TimeStay <<endl<<endl;
		 }
		 else if(TimeStay>=3 && TimeStay <=5){
    		cout<<"You have selected package N"<<endl<<endl;
    		cout<<"You are given a 15% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<400 - 400*0.15<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(400 - 400*0.15) * TimeStay<<endl<<endl;
		 }
		 else if(TimeStay>=6 && TimeStay <=7){
    		cout<<"You have selected package O"<<endl<<endl;
    		cout<<"You are given a 17% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<500-500*.17<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(500-500*.17) * TimeStay<<endl<<endl;
		 }
    }

    else if(GuestNo>=3 && GuestNo<=4){

    	  if(TimeStay>=1 && TimeStay <=2){
    		cout<<"You have selected package P"<<endl<<endl;
    		cout<<"You are given a 14% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<400-400*.14<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(400-400*.14)*TimeStay<<endl<<endl;
		 }
		 else if(TimeStay>=3 && TimeStay <=5){
    		cout<<"You have selected package Q"<<endl<<endl;
    		cout<<"You are given a 16% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is "<<500-500*.16<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<"The total amount to be paid for this package after discount is RM"<<(500-500*.16)*TimeStay<<endl<<endl;
		 }
		 else if(TimeStay>=6 && TimeStay <=7){
    		cout<<"You have selected package R"<<endl<<endl;
    		cout<<"You are given a 18% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<600 - 600*.18<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(600 - 600*.18)*TimeStay<<endl<<endl;
		 }

	}
	else if(GuestNo>=5 && GuestNo<=6){

    	  if(TimeStay>=1 && TimeStay <=2){
    		cout<<"You have selected package S"<<endl<<endl;
    		cout<<"You are given a 14.5% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<700- 700*.145<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(700- 700*.145)*TimeStay<<endl<<endl;
		  }
		 else if(TimeStay>=3 && TimeStay <=5){
    		cout<<"You have selected package T"<<endl<<endl;
    		cout<<"You are given a 16.5% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<800 - 800*.165<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(800 - 800*.165)*TimeStay<<endl<<endl;
		 }
		 else if(TimeStay>=6 && TimeStay <=7){
    		cout<<"You have selected package U"<<endl<<endl;
    		cout<<"You are given a 18.5% discount on hotel reservation."<<endl<<endl;
    		cout<<"The total price for this package after discount is RM "<<850 - 850*.185<<endl<<endl;
    		cout<<"The total duration of stay in this package is "<<TimeStay<<"days"<<endl<<endl;
    		cout<<" The total amount to be paid for this package after discount is RM "<<(850 - 850*.185)*TimeStay<<endl<<endl;
		 }
	}


    return 0;
 }

