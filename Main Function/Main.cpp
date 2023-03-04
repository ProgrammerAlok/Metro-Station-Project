
#include "../Class/pro.cpp"
#include "../Components/All_Component.cpp"

using namespace std;


int main()
{
    int i, flag=0;
    int number_of_station = 53;
    int number_of_edge = 53;
    

    Graph g;
    g.createGraph(number_of_station, number_of_edge);

    
    int s, d;

    while ( true )
    {
        switch ( Menu() )
        {
        case 1: 

            cout << "Enter Your Source Station code :: " << endl;
            g.printAllPath( input() );

            break;

        case 2:

            cout << "Enter Your Source Station code :: " << endl;
            s = input();

            cout << "Enter Your Destination Station code :: " << endl;
            d = input();

            if(s!=d)
                g.printAllPath( s, d );
            else
                cout << "\n  You are in destination/ source.\n"; 

            break;

        case 3:

            g.printStationList();
            break;

        case 4:

            flag = 1;
            cout << "\n....Thank You For Using MyApp....\n";
            break; 

        }
        

        if(flag)
            break;
        else
            cout<<endl;



        if( Continue() ) {
            cout << "\n....Thank You For Using MyApp....\n";
            break;
        }


    } 

    return 0;
}
