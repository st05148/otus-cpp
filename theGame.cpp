#include <iostream>
#include "menu/menu.h"
#include <string>
#include <cstdlib>
#include <ctime>
#include "theGame.h"
#include "functions.h"

void main(int argc,char* argv[])
{    
    int maxRangeArg=0;
    
    switch (parseArguments(argv,argc, maxRangeArg))
    {
        case args::TABLE_FULL_ARG:
            printFullTable(recordFileName);
            return;    
        case args::TABLE_BEST_ARG:
            printBestResultsTable(recordFileName);
            return;    
        case args::WRONG_ARG:
            printError("Wrong arguments. Check usage syntax");
            std::cout << std::endl;
            printHelp();                     
            return;
    }

    int maxRange=maxRangeArg>0?maxRangeArg:DEFAULT_MAX_RANGE;
    
    gameLoop(maxRange);    
}

void gameLoop(int range)
{
    while (true) // Main game loop
    {
        int menuResult=menu::show();
        int secretNumber;
        std::string userName;
        int attemptCounter=0;

        switch (menuResult)
        {
            case menu::menuItems::StartGame:                
                srand(time(nullptr));
                std::cout << "Enter your name \n";
                std::cin >> userName;
                secretNumber = rand() % range;
                int userInput;                
                while (true)
                {
                    std::cout << "Enter you number: ";
                    userInput=getUserInput();                    
                    if (userInput==-1)
                        continue;
                    attemptCounter++;                    
                    if (userInput==secretNumber)
                    {
                        std::cout << userName << " - you won!" << std::endl;
                        writeResults(recordFileName,userName,attemptCounter);
                        return;
                    }
                    std::string msg=(userInput>secretNumber)?"Less than":"More than";
                    std::cout << msg << std::endl;                    
                }
                break;

            case menu::menuItems::ShowResult:
                printBestResultsTable(recordFileName);
                system("pause");
                break;
            
            case menu::menuItems::ShowHelp:
                printHelp();
                system("pause");
                break;            

            case menu::menuItems::ExitGame:
                return;                   
        }
    }
}

