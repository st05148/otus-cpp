#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <string>

void printFullTable(std::string fileName);
void printBestResultsTable(std::string fileName);
int getUserInput();
int parseArguments(char* argv[],int argc,int &maxRange);
void writeResults(std::string fileName,std::string userName,int score);
void printHelp();
void printError(std::string msg);
void printHeader();
void printScoreLine(std::string userName,int userScore);

enum args {TABLE_FULL_ARG=1, TABLE_BEST_ARG,WRONG_ARG};

#endif