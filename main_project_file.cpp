#include <iostream>
#include <string>
#include <fstream>
#include <thread>
#include <chrono>
#include "Game.cpp"

using namespace std;
using namespace std::this_thread;
using namespace std::chrono;

// Global Variables
int choice = 0;    
int stamina = 100;
int courage = 0;
string Inventory[2] = {"empty", "empty"};    // Declaring an array to store objects obtained during play

//Function Prototypes
void go_out_and_check();
void ask_around();
void stay_in_crowd();
void check_alleyway();
void run_downstairs();
void look_for_sulfur();
void volunteer();
void keep_standing();
void run_from_alley();
void look_for_rod();
void examine();
void stop_running();
void kick();
void stairs();
void rod();
void run_upstairs();
void run_without();
void walk_back();
void breakDoor();


void slow_print (string message, int time)
{
    for (int i = 0; i < message.length(); i++)
    {
        cout << message[i];
        sleep_for (milliseconds(time));
    }
    cout << "\n";
}   

void DisplayWellPlayed()
{
    cout << endl
         << endl
         << endl
         << "\x1b[35m    █████   ███   █████          ████  ████     ███████████  ████                                    █████ " << endl;
    cout << "  ░░███   ░███  ░░███          ░░███ ░░███    ░░███░░░░░███░░███                                   ░░███ " << endl;
    cout << "   ░███   ░███   ░███   ██████  ░███  ░███     ░███    ░███ ░███   ██████   █████ ████  ██████   ███████  " << endl;
    cout << "   ░███   ░███   ░███  ███░░███ ░███  ░███     ░██████████  ░███  ░░░░░███ ░░███ ░███  ███░░███ ███░░███   " << endl;
    cout << "   ░░███  █████  ███  ░███████  ░███  ░███     ░███░░░░░░   ░███   ███████  ░███ ░███ ░███████ ░███ ░███  " << endl;
    cout << "    ░░░█████░█████░   ░███░░░   ░███  ░███     ░███         ░███  ███░░███  ░███ ░███ ░███░░░  ░███ ░███  " << endl;
    cout << "      ░░███ ░░███     ░░██████  █████ █████    █████        █████░░████████ ░░███████ ░░██████ ░░███████" << endl;
    cout << "       ░░░   ░░░       ░░░░░░  ░░░░░ ░░░░░    ░░░░░        ░░░░░  ░░░░░░░░   ░░░░░███  ░░░░░░   ░░░░░░░░ " << endl;
    cout << "                                                                             ███ ░███                   " << endl;
    cout << "                                                                             ░░██████                     \x1b[0m" << endl;
    sleep_for(seconds(3));
}

void breakDoor()
{
    string line;
    ifstream myfile ("ChoicesTextFiles/Choice_use_orb.txt");   // opens file

    if (Inventory[1] == "orb")
    {
        myfile.open("ChoicesTextFiles/Choice_use_orb.txt");

        if (myfile.is_open())
        {
             while (getline (myfile,line))  //Uses a while loop and the slow_print function to print gradually
            {   
                slow_print (line, 24);
                sleep_for(seconds(1));
            }
            myfile.close();
        }

        else { cout << "Unable to open file"; }
        DisplayWellPlayed();
    }
    else
    { 
        myfile.open("ChoicesTextFiles/Choice_no_orb.txt");

        if (myfile.is_open())
        {
             while (getline (myfile,line))  //Uses a while loop and the slow_print function to print gradually
            {   
                slow_print (line, 24);
                sleep_for(seconds(1));
            }
            myfile.close();
        }

        else { cout << "Unable to open file"; }

        cout << "\x1b[33m  Your Inventory does not have the weapon 'orb' since you did not make choices to obtain it \x1b[0m " << endl;

        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
        sleep_for(seconds(3));
    }
    
}

void run_without()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_run_without.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_11();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: if (Inventory[0] == "rod")
                        {
                            myfile.open("ChoicesTextFiles/Choice_rod.txt");

                            if (myfile.is_open())
                            {
                                while (getline (myfile,line))  //Uses a while loop and the slow_print function to print gradually
                                {   
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                                }

                                myfile.close();
                            }

                            else { cout << "Unable to open file"; }
                            DisplayWellPlayed();
                            system("clear");
                        }               

                        else 
                        {
                            cout << "You did not make the choices needed to obtain the rod. You do not have it in the Inventory " << endl;
                            cout << "You'll have to run upstairs" << endl;
                            run_upstairs();
                        }
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: run_upstairs();
                        correct_choice = true;
                        choice = 0;
                        break;

                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

void run_upstairs()
{
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_runup_stairs.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    else { cout << "Unable to open file" << endl;}

    if (Inventory[0] == "rod")
    {
        cout << "\x1b[36m Your inventory now has:  Rod \x1b[0m ";
        myfile.open("ChoicesTextFiles/Choice_use_rod.txt");

        if (myfile.is_open())
        {
            while (getline (myfile,line))  //Uses a while loop and the slow_print function to print gradually
            {
                slow_print (line, 24);
                sleep_for(seconds(1));
            }

            myfile.close();
        }

        else { cout << "Unable to open file"; }

        breakDoor();
    }

    else 
    {
        myfile.open("ChoicesTextFiles/Choice_cant_breakDoor.txt");

        if (myfile.is_open())  // if the file has been successfully opened, do the following
        {
            while (getline(myfile,line)) 
            {
                slow_print (line, 24);
                sleep_for(seconds(1));
            }
            myfile.close();
        }

        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
        sleep_for(seconds(3));
    }
}

void stairs()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_take_stairs.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_10();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: if (Inventory[0] == "rod")
                        {
                            myfile.open("ChoicesTextFiles/Choice_rod.txt");

                            if (myfile.is_open())
                            {
                                while (getline (myfile,line))  //Uses a while loop and the slow_print function to print gradually
                                {   
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                                }

                                myfile.close();
                            }

                            else { cout << "Unable to open file"; }
                            DisplayWellPlayed();
                        }               

                        else 
                        {
                            cout << "\x1b[33m        You did not make the choices needed to obtain the rod. Your Inventory does not have it." << endl;
                            cout << "You will have to run upstairs, and so are being directed to that choice by default.\x1b[0m" << endl;
                            run_upstairs();
                        }
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: run_upstairs();
                        correct_choice = true;
                        choice = 0;
                        break;

                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

void kick()
{
    cout << endl << "\x1b[32m                        Stamina level decreased to \x1b[31m" << stamina - 10 << "\x1b[32m pnts \x1b[0m" << endl << endl;
    cout << endl << "\x1b[32m                        Courage level has fallen to \x1b[31m" << courage + 30 << "\x1b[32m pnts \x1b[0m" << endl << endl;
    slow_print("You decide to kick the creature again to make sure it stays down.",10);
    slow_print("It whimpers again, and you keep kicking until the whimpering stops.",10);
    slow_print("Its either dead or you've knocked it unconscious. Either way, you're safe, for now.",10);
    cout << endl << endl;

    Game game_object;
    bool correct_choice = false;
    game_object.Choices_8();

    cin >> choice;

    if (cin.fail())    // Input validation
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: examine();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: walk_back();
                        correct_choice = true;
                        choice = 0;
                        break;

                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}
void stop_running()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_stop_running.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_9();      // Calling Choices_9 function of class Game

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: walk_back();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: kick();
                        correct_choice = true;
                        choice = 0;
                        break;

                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

void walk_back()
{
    slow_print("You decide to leave the creature where it is and walk back to the crowd.",10);
    stay_in_crowd();
}

void examine()
{
    Inventory[1] = "orb";
    string line;
    ifstream myfile ("ChoicesTextFiles/Choice_examine.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    cout << "\x1b[32m                        Your Inventory now has a\x1b[34m Orb \x1b[32mweapon \x1b[0m" << endl;

    stay_in_crowd();
}

void look_for_rod()
{
    Inventory[0] = "rod";
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_look_for_rod.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    cout << "\x1b[32m                        Your Inventory now has a \x1b[31m Rod \x1b[32m weapon \x1b[0m" << endl;
    game_object.Choices_8();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: cout << endl << "\x1b[32m                        Strength level increased to \x1b[31m" << stamina + 20 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        cout << endl << "\x1b[32m                        Courage level upgraded to \x1b[31m" << courage + 30 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        examine();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: walk_back();
                        correct_choice = true;
                        choice = 0;
                        break;

                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

void run_from_alley()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_run_from_alley.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_7();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: stop_running();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: myfile.open("ChoicesTextFiles/Choice_keep_running.txt"); // opens the file

                        if (myfile.is_open())  // if the file has been successfully opened, do the following
                        {
                            while (getline(myfile,line)) 
                            {
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                            }
                            myfile.close();
                        }
                        correct_choice = true;
                        choice = 0;

                        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
                        sleep_for(seconds(3));
                        system("clear");
                        break;
                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}
void volunteer()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/ChoicesTextFiles/Choice_volunteer.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_6();     // Calling the Choices_6 function declared in Game.cpp 

    cin >> choice;                      // Waits for user input
 
    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: cout << endl << "\x1b[32m                        Stamina dropped down to \x1b[31m" << stamina - 50 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        stairs();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: myfile.open("ChoicesTextFiles/ChoicesTextFiles/Choice_elevator.txt"); // opens the file

                        if (myfile.is_open())  // if the file has been successfully opened, do the following
                        {
                            while (getline(myfile,line)) 
                            {
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                            }
                            myfile.close();
                        }
                        correct_choice = true;
                        choice = 0;

                        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
                        sleep_for(seconds(3));
                        break;
                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  

}

void look_for_sulfur()
{
    string line;
    ifstream myfile ("ChoicesTextFiles/Choice_looksulfur.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    go_out_and_check();     // Returning control to function go_out_and_check
}

void run_downstairs()
{
    string line;
    ifstream myfile ("ChoicesTextFiles/Choice_run_downstairs.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    go_out_and_check();             // Returning control to function go_out_and_check
}

void check_alleyway()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_check_alleyway.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_5();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: cout << endl << "\x1b[32m                        Stamina level decreased to \x1b[31m" << stamina - 40 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        cout << endl << "\x1b[32m                        Courage level has fallen to \x1b[31m" << courage - 10 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        run_from_alley();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: cout << endl << "\x1b[32m                        Courage level upgraded to \x1b[31m" << courage + 20 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        look_for_rod();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 3: myfile.open("ChoicesTextFiles/Choice_stay_alley.txt"); // opens the file

                        if (myfile.is_open())  // if the file has been successfully opened, do the following
                        {
                            while (getline(myfile,line)) 
                            {
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                            }
                            myfile.close();
                        }
                        correct_choice = true;
                        choice = 0;

                        cout << endl << "\x1b[32m                        Courage level has fallen to \x1b[31m" << courage - 10 << "\x1b[32m pnts \x1b[0m" << endl << endl;

                        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
                        sleep_for(seconds(3));
                        break;
                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

void stay_in_crowd()
{
    Game game_object;           // declaring an object called game_object of class Game
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_stay_in_crowd.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_4();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: cout << endl << "\x1b[32m                        Courage level upgraded to \x1b[31m" << courage + 30 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        volunteer();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: myfile.open("ChoicesTextFiles/Choice_not_volunteer.txt"); // opens the file

                        if (myfile.is_open())  // if the file has been successfully opened, do the following
                        {
                            while (getline(myfile,line)) 
                            {
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                            }
                            myfile.close();
                        }
                        correct_choice = true;
                        choice = 0;
                        cout << endl << "\x1b[32m                        Courage level has fallen down to \x1b[31m" << courage - 40 << "\x1b[32m pnts \x1b[0m";

                        cout << endl << endl << endl << "                                            \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
                        sleep_for(seconds(3));
                        break;
                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

void ask_around()
{
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_ask_around.txt");   // opens file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_3();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: run_downstairs();
                        cout << endl << "\x1b[32m                        Courage level has fallen down to \x1b[31m" << courage - 20 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        cout << endl << "\x1b[32m                        Stamina level has fallen down to \x1b[31m" << stamina - 20 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: cout << endl << "\x1b[32m                        Courage level upgraded to \x1b[31m" << courage + 30 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        look_for_sulfur();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 3: 
                        cout << endl << "\x1b[32m                      Courage level upgraded to \x1b[31m" << courage + 40 << "\x1b[32m pnts \x1b[0m";

                        myfile.open("ChoicesTextFiles/Choice_jumpat.txt"); // opens the file

                        if (myfile.is_open())  // if the file has been successfully opened, do the following
                        {
                            while (getline(myfile,line)) 
                            {
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                            }
                            myfile.close();
                        }
                        correct_choice = true;
                        choice = 0;

                        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
                        sleep_for(seconds(3));
                        break;
                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}
void go_out_and_check()
{   
    Game game_object;
    string line;
    bool correct_choice = false;

    ifstream myfile ("ChoicesTextFiles/Choice_go_out.txt"); // opens the file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line)) 
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }
        myfile.close();
    }

    game_object.Choices_2();

    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: cout << endl << "\x1b[32m                        Courage level upgraded to \x1b[31m" << courage + 30 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        check_alleyway();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: stay_in_crowd();
                        correct_choice = true;
                        choice = 0;
                        break;

                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}


void Initial_choices()
{
    string line;
    ifstream myfile ("ChoicesTextFiles/Choice_keep_sleeping.txt");
    bool correct_choice = false;
    cin >> choice;

    if (cin.fail())
    {
        cout << "That input is incorrect. Restart and enter one integer from the given choices please." << endl;
        cin >> choice;
    }
    else 
    {
        while (correct_choice == false) 
        {
            switch(choice)
            {
                case 1: cout << endl << "\x1b[32m                        Courage level upgraded to  \x1b[31m" << courage + 30 << "\x1b[32m pnts \x1b[0m" << endl << endl;
                        go_out_and_check();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 2: ask_around();
                        correct_choice = true;
                        choice = 0;
                        break;

                case 3: myfile.open("ChoicesTextFiles/Choice_keep_sleeping.txt"); // opens the file

                        if (myfile.is_open())  // if the file has been successfully opened, do the following
                        {
                            while (getline(myfile,line)) 
                            {
                                    slow_print (line, 24);
                                    sleep_for(seconds(1));
                            }
                            myfile.close();
                        }
                        correct_choice = true;
                        choice = 0;

                        cout << endl << "\x1b[32m                Courage level has fallen down to  \x1b[31m" << courage - 20 << "\x1b[32m pnts \x1b[0m";

                        cout << endl << endl << endl << "                                               \x1b[33mThe game has ended. Restart and make better choices. \x1b[0m" << endl << endl;
                        sleep_for(seconds(3));
                        break;
                default:
                       cout << "That input is incorrect. Enter one integer from the above choices please." << endl;
                       cin >> choice;
                       break;
            }
        }
    }  
}

int main(){

    string name;      // String to hold Player name
    char start_char;   // This is the char variable used for beginning/abortion of game
    string line;        // Variable to use in slow_print function to read txt files

    ifstream myfile ("lums_phy_lab_art.txt");  //Reads the art_1 file and prints its contents

    cout << endl << endl << "\x1b[33m LUMS Physics Lab, SBASSE, Tuesday December 1st, 2020 (10:32 PM): \x1b[0m  " ;

    sleep_for (seconds(2));
    cout << "\n\n";

    if (myfile.is_open())
    {
        while (getline(myfile,line))
        {
            slow_print (line,1);
        }
        myfile.close();
    }

    myfile.open("MainStoryTextFiles/Mainstory_part1.txt"); // opens the mainstory file

    if (myfile.is_open())  // if the file has been successfully opened, do the following
    {
        while (getline(myfile,line))  //Uses a while loop and the slow_print function to print the Main Story text gradually
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }

        myfile.close();
    }

    else cout << "Unable to open file";

    Animation blackhole; // object of class Animation called in order to display the blackhole

    myfile.open("MainStoryTextFiles/Mainstory_part2.txt");

    if (myfile.is_open())
    {
        while (getline (myfile,line))  //Uses a while loop and the slow_print function to print the Main Story part 2 gradually
        {
            slow_print (line, 24);
            sleep_for(seconds(1));
        }

        myfile.close();
    }

    else cout << "Unable to open file";

    // Displays the Story name in  a User-friendly way
    cout << endl << endl << "\x1b[36m                         +---------+------------+------------++---------+------------+------------+" << endl;
    cout << "\x1b[34m                         |                                                                        |" << endl;
    cout << "\x1b[31m                         |\x1b[0m       \x1b[32m The Dark Disaster: An RPG by Malaik Kabir and Humaira Fasih    \x1b[0m\x1b[31m |\x1b[0m " << endl;
    cout << "\x1b[34m                         |                                                                        |" << endl;
    cout << "\x1b[36m                         +---------+------------+------------++---------+------------+------------+\x1b[0m " << endl;

    cin >> start_char;   // Waits for player input in order to begin/abort game

    if (start_char != 'P')    // checks player input
    {
        cout << "Aborting program ...." << endl << endl;
        sleep_for(seconds(3));
        system("clear");
        return 1;
    }

    else
    {
       // Take player name
       cout << endl << endl << "\x1b[33m To start the adventure, please enter player name (no spacebars): \x1b[31m ";
       cin >> name;
       cout << endl << "\x1b[33m Hello there, " << name << "!\x1b[0m" << endl << endl;
       sleep_for(seconds(2));

        // Shows player their initial stats
       cout << "\x1b[32m Here are your initial game stats: " << endl << endl;                
       cout << "                    Stamina & Strength : \x1b[31m 100 pnts " << endl;
       cout << "\x1b[32m                        Inventory : \x1b[31m Empty " << endl;
       cout << "\x1b[32m                        Courage : \x1b[31m 0 pnts" << endl << endl;

       Game game_object;   // Creating an object of Game class
       game_object.StartGameArt();   // Calling the StartGameArt function that displays ascii art

       myfile.open("MainStoryTextFiles/Mainstory_part3.txt"); // opens the mainstory part 3 file

       if (myfile.is_open()) // if the file has been successfully opened, do the following
       {
           while (getline(myfile, line))
           {
               slow_print(line, 24);
               sleep_for(seconds(1));
           }
           myfile.close();
        }

        else  { cout << "Unable to open file"; }

        game_object.Choices_1();      // calling the Choices_1 function in class Game
        Initial_choices();       // Calling Initial choices function
    }
return 0;
}
