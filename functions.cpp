#include "functions.h"
#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <map>

void printFullTable(std::string fileName)
{    
    std::fstream fso;
    fso.open(fileName,std::fstream::in);

    if (!fso.is_open())
    {
        printError("The record file doesn't exist");
        return;
    }
    std::string userName;
    int userScore;
    printHeader();
    while (fso >> userName >> userScore)
        printScoreLine(userName,userScore);
    fso.close();
}

void printHeader()
{
    std::cout << "--Results--" << std::endl;
    std::cout << std::left << std::setw(15) << "Name" << std::setw(10) << "Score" << std::endl;
    std::cout << std::setfill('-') << std::setw(25) << "" << std::endl;
    std::cout << std::setfill(' ');
}

void printScoreLine(std::string userName,int userScore)
{
    std::cout << std::left << std::setw(15) << userName << std::setw(10) << userScore << std::endl;    
}

void printBestResultsTable(std::string fileName)
{
    std::map <std::string,int> scoreMap;
    std::fstream fso;
    fso.open(fileName,std::fstream::in);
    if (!fso.is_open())
    {
        printError("The record file doesn't exist");
        return;
    }
    std::string userName;
    int userScore;    
    while (fso >> userName >> userScore)
    {        
        if (scoreMap.find(userName)==scoreMap.end() || scoreMap[userName]>userScore)
        {
            scoreMap[userName]=userScore;               
        }        
    }
    printHeader();
    for (const auto& mapEntry : scoreMap)
    {
        printScoreLine(mapEntry.first,mapEntry.second);
        //std::cout << mapEntry.first << "  " << mapEntry.second << std::endl;
    }
    fso.close();    
}

void writeResults(std::string fileName,std::string userName,int score)
{
    std::fstream fsi;
    fsi.open(fileName,std::fstream::out | std::fstream::app);
    if (!fsi.is_open())
    {
        printError("Cannot write or create rescord file: "+fileName);
        return;
    }
    fsi << userName << " " << score << std::endl;
    fsi.close();
}

void printHelp()
{
    std::cout << "Usage syntax:" << std::endl
              << "theGame.exe [max N] [table_full] [table_best]" << std::endl
              << "max N - the random number range, where N is an integer" << std::endl
              << "table_full - list all records for all users" << std::endl
              << "table_best - list best scores for each user" << std::endl;
}

int parseArguments(char* argv[],int argc,int &maxRange)
{    
    bool wrongArgument=true;    
    for (int i=1;i<argc;i++)
    {        
        std::string argString=argv[i];
        if (argString=="table_full")
        {                   
            wrongArgument=false;     
            return args::TABLE_FULL_ARG;
        } else if (argString=="table_best")
        {
            wrongArgument=false;
            return args::TABLE_BEST_ARG;
        } else if (argString=="max")
        {
            wrongArgument=false;
            if(i+1<argc)
            {
                try
                {
                    maxRange=std::stoi(argv[i+1]);
                }
                catch(const std::exception& e)
                {              
                    printError("The max argument is not a number. Using default max number.");
                    system("pause");
                }                
            }
            else
            {
                printError("The max argument should be followed by a number, Using default max number.");
                system("pause");
            }
        }
        if (wrongArgument)
            return args::WRONG_ARG;
    }
    return 0;
}

int getUserInput()
{
    int userInput;
    if(std::cin >> userInput)
        {
            return userInput;
        }
        else
        {
            std::cin.clear();        
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            printError("Invalid input. Please enter a valid number.");
            return -1;
        }
}

void printError(std::string msg)
{
    std::cout << "\033[31m" << msg << "\033[0m" << std::endl;
}



