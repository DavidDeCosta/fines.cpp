//<Calculating a fine based on the users speed measured and speedlimit.>
//programmer : <David DeCosta>
//date of last modification: <February 23, 2021>

#include <iostream>
using namespace std;

//prototype
int fine_calculation(int speedLimit, int speedMeasured);

int main(){

    int speed_Limit, measured_Speed, fine_Amount;

    cout << "What was the speed limit? \n";
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
            cout << "What was the speed limit? \n";
            cin >> speed_Limit;
        }
        else{
            cout << "Enter the Measured Speed again. Was not between (0-150) \n";
        }

    }
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