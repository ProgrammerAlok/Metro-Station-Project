#include<iostream>
using namespace std;


int Menu()
{
    int i=-1;

    cout << "\n::::::::::::::::::::::::::::::::: Welcome To Bhopal Metro ::::::::::::::::::::::::::::::::::::\n";
    cout << "\n.............................................................................................\n";

    cout << " Enter Your Choice :: \n\t1. to know all possible station path from your current station. \n\t2. to know all possible path form your current station to your Destination Station.\n\t3. to know our station list\n\t4. to exit ";
    cout << "\n.............................................................................................\n";

    while ( true )
    {
        cout << "\n >> ";
        cin >> i;

        if( !( i>=1 && i<=4 ) ) {
            cout << "\n   !!!!Enter valid Input (1 to 4)!!!!  \n";
        }
        else {
            break;
        }

    }
    

    return i;
}

int input()
{
    int i;

    

    while ( true )
    {
        cout << "\n >> ";
        cin >> i;

        if( !( i>=0 && i<=52 ) ) {
            cout << "\n   !!!!Enter valid Input (0 to 52)!!!!  \n";
        }
        else {
            break;
        }

    }

    return i;
}


bool Continue()
{

    char i;

    cout << " press b to exit or any key to continue :: ";


    cout << "\n >> ";
    cin >> i;

    return ( i == 'b' ) ? true : false;

}