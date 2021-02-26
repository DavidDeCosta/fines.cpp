//<Calculating a fine based on the users speed measured and speedlimit.>
//programmer : <David DeCosta>
//date of last modification: <February 23, 2021>

#include <iostream>
#include <iomanip>
#include <climits>
using namespace std;

//prototype
int fine_calculation(int speedLimit, int speedMeasured);
void print_data(int speed_Limit, int measured_Speed, int fine_Amount);

int main(){

    int speed_Limit, measured_Speed, largest_Fine = 0, fine_Amount, number_Of_Fines = 0;
    float average_Fine_Amount = 0;

    cout << "What was the speed limit?(-1 to end) \n"; // -1 is the sentinel value
    cin >> speed_Limit; //prime read

    while(speed_Limit != -1){
        if(speed_Limit > 0 && speed_Limit < 75){
            cout << "What was your measured speed? \n";
            cin >> measured_Speed;
        }
        else{
            cout << "Enter the speed limit again. Was not between (0-75)\n";
        }
        if(measured_Speed <=150 && measured_Speed > 0){
            if(measured_Speed > speed_Limit && speed_Limit != -1){
            fine_Amount = fine_calculation(speed_Limit, measured_Speed);
            number_Of_Fines++;
        }
            cout << "What was the speed limit? \n";
            cin >> speed_Limit;
        }
        else{
            cout << "Enter the Measured Speed again. Was not between (0-150) \n";
        }
    }

    print_data(speed_Limit,measured_Speed,fine_Amount);
    cout << endl;
    cout << endl << "Total Number of Fines: "<< number_Of_Fines << endl;
    cout << "Largest Fine: " << largest_Fine << endl;
    cout << "Average Fine Amount: " << average_Fine_Amount << endl;





    return 0;
}

/*  
    This function will take in 1 integer for a speed limit and 1 integer for the measured speed and return
    the total fine
*/
int fine_calculation(int speed_Limit, int measured_Speed){
    int total_fine = 0;
    int speed_over = measured_Speed - speed_Limit;

    if(speed_over <= 10){
        total_fine = speed_over * 10;
    }
    else if(speed_over <= 20){
        total_fine = (speed_over - 10) * 15 + 100;
    }
    else{
        total_fine = (speed_over - 20) * 20 + 250;
    }
    
    return total_fine;

}

//This function prints out the Data: Speed Limit, Measured Speed, and Fine Amount

void print_data(int speed_Limit, int measured_Speed, int fine_Amount){

    cout << "Speed Limit" << setw(22) << "Measured Speed" << setw(19) <<  "Fine Amount" << endl;
    cout << setw(6) << speed_Limit << setw(20) << measured_Speed << setw(18) << fine_Amount;

}

