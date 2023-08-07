#include "menu.h"
#include <iostream>


namespace menu{

    int show()
    {           
        while (true)
        {            
            system("cls");
            std::cout << "Select menu item:" << std::endl
                      << "1-Start game:" << std::endl
                      << "2-Show result" << std::endl
                      << "3-Show help" << std::endl
                      << "4-Exit game" << std::endl;

            int userInput=0;
            std::cin >> userInput;            

            switch (userInput)
            {
                case 1:
                    return menu::menuItems::StartGame;            
                case 2:
                    return menu::menuItems::ShowResult;
                case 3:
                    return menu::menuItems::ShowHelp;
                case 4:
                    return menu::menuItems::ExitGame;                    
                default:
                    std::cout << "Wrong input. Please press any key and enter valid option numer..." << std::endl;
                    std::cin.clear();  // Clear any error flags from std::cin
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    system("pause");
                    break;
            }
        }
        return 0;   
    }
}