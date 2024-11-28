// Task_01.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Task 1: Build a Menu Navigation System
//Objective: Implement a basic menu navigation system similar to what is found in automotive HMI clusters(e.g., settings menu, media options).
//Requirements :
//    Create a hierarchical menu structure using classesand data structures.
//    Example :
//    Main Menu
//    Settings
//    Display Settings
//    Audio Settings
//    Media
//    Radio
//    Bluetooth Audio
//    Use a tree structure(std::vector or custom tree data structure) to represent the hierarchy.
//    Implement the following functionalities :
//Navigate through menu levels(up / down / enter / back).
//Display the current menu options on the console.
//Add keyboard - based interaction(e.g., 1 to navigate down, 2 to navigate up, 3 to enter).
//Deliverables :
//    A C++ program that uses OOP to create the menu structure.
//    Console output demonstrating navigation and interactions.
//

#include <iostream>
#include <vector>
#include <functional> 
using namespace std;


class Main_menu {

public:
    virtual void show() {

        cout << "In Main Screen" << endl;
    }

}main_menu;


class Settings : public Main_menu {

public:
    void show() override {
        cout << "In Settings Screen" << endl;
    }

};




class Display_settings : public Settings {

public:
    void show() override {
        cout << "In display Settings" << endl;
    }

public:
    void cluster_display() {
        cout << "cluster display updated on screen" << endl;

    }
    void night_vision() {
        cout << "night mode on" << endl;

    }
    void language() {

        cout << "language settings updated" << endl;
    }
    void Text_scrolling() {

        cout << "Text scrolling mode on" << endl;
    }

};
class Audio_settings : public  Settings {

public:
    void show() override {
        cout << "In Audio Settings" << endl;
    }

public:
    void bass() {

        cout << "bass mode ON" << endl;
    }
    void treble() {

        cout << "treble mode ON" << endl;
    }
    void equaliser() {

        cout << "your custom eqaliser mode is ON" << endl;
    }
    void max_volume() {

        cout << "Max volume is updated" << endl;
    }

};


class Media : public Main_menu {

public:
    void show() override {

        cout << "In Media Screen" << endl;
    }
};

class Radio : public Media {

public:
    void show() override {

        cout << "In Radio Screen" << endl;
    }

    void AM()
    {
        cout << "AM Mode on.. ";
    }
    void FM()
    {
        cout << "FM Mode on ..";
    }
    void mute()
    {
        cout << "Microphone Muted.. ";
    }


};
class Blutooth_audio : public Media {

public:
    void show() override {

        cout << "In Blutooth audio Screen." << endl;
    }

    void track_name()
    {
        cout << "Track name Devara." << endl;
    }
    void artist_name()
    {
        cout << "Arist name Teja." << endl;
    }



};



int main()
{



    vector<reference_wrapper<Main_menu>> vector;

    Settings s;

    Display_settings ds;
    Audio_settings as;

    Media m;

    Radio r;
    Blutooth_audio ba;

    vector.push_back(ref(s));
    vector.push_back(ref(ds));
    vector.push_back(ref(as));
    vector.push_back(ref(m));
    vector.push_back(ref(r));
    vector.push_back(ref(ba));

    /*for (const auto& item : vector) {
        item.get().show();
    }*/

    int user_input;
    bool exit_user = true;
    bool out = true;

    do {
        cout << "Enter  1.Settings, 2.Media 3.Exit" << "\n";
        cin >> user_input;
        cout << "\n";



        /*switch (user_input)
        {
        case 1:auto a=vector.at(0);
            a.get().show();
            break;

        default:
            break;
        }*/

        do {


            if (user_input == 1)
            {
                const auto& a = vector.at(0);
                a.get().show();
                cout << "\n";
                cout << "1.Display Settings" << "\n" << "2.Audio Settings" << "\n" << "3.Exit" << "\n";

                int u;
                cin >> u;
                cout << "\n";
                bool first = true;
                do {
                    if (u == 1)
                    {
                        const auto& a = vector.at(1);
                        a.get().show();
                        cout << "\n";
                        cout << "1.cluster display to console" << "\n" << "2.Night vision" << "\n" << "3.language settings" << "\n" << "4.Text scorling" << "\n" << "5.Exit " << "\n";
                        int b;
                        cin >> b;
                        switch (b)
                        {
                        case 1: ds.cluster_display();
                            break;
                        case 2: ds.night_vision();
                            break;
                        case 3: ds.language();
                            break;
                        case 4: ds.Text_scrolling();
                            break;
                        case 5: first = false;
                            break;

                        default:
                            break;
                        }

                    }
                    else if (u == 2)
                    {
                        const auto& a = vector.at(2);
                        a.get().show();
                        cout << "1.Bass" << "\n" << "2.treble" << "\n" << "3.equaliser" << "\n" << "4.Maxminum value" << "\n" << "5.Exit" << "\n";
                        int c;
                        cin >> c;
                        switch (c)
                        {
                        case 1: as.bass();
                            break;
                        case 2: as.treble();
                            break;
                        case 3: as.equaliser();
                            break;
                        case 4: as.max_volume();
                            break;
                        case 5: first = false;
                            break;
                        default:
                            break;
                        }
                    }
                    else if (u == 3) {
                        first = false;
                    }
                } while (first);

            }

            else if (user_input == 2)
            {
                const auto& a = vector.at(3);
                a.get().show();
                cout << "1.Radio 2.Blutooth 3.Exit";
                int d;
                cin >> d;
                bool second = true;
                do {
                    if (d == 1) {
                        cout << "1.AM Mode" << "\n" << "2.FM Mode" << "\n" << "3.Mute Audio" << "\n" << "4.Exit" "\n";
                        int e;
                        cin >> e;
                        switch (e)
                        {
                        case 1:r.AM();
                            break;
                        case 2: r.FM();
                            break;
                        case 3: r.mute();
                            break;
                        case 4:second = false;
                            break;
                        default:
                            break;
                        }

                    }
                    else if (d == 2)
                    {
                        cout << "1.Artist name" << "\n" << "2.Track name" << "3.Exit" << "\n";
                        int f;
                        cin >> f;

                        switch (f)
                        {
                        case 1:ba.artist_name();
                            break;
                        case 2: ba.track_name();
                            break;
                        case 3:second = false;
                            break;

                        default:
                            break;
                        }
                    }
                    else if (d == 3)
                    {

                        second = false;
                    }

                } while (second);



            }

            else if (user_input == 3)
            {

                exit_user = false;
            }

        } while (exit_user);




    } while (out);

    return 0;

}

