#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>
#include <experimental/filesystem>
#include "FileManager.hpp" 
#include <pthread.h>



int main() 
{ 
    std::experimental::filesystem::path filePath1 = "test_path/TestFile";
    std::experimental::filesystem::path filePath2 = "test_path";
    FileManager fileObj(filePath1,false);
    //FileManager dirObj(filePath1,false);
    char* fileContent1 = fileObj.readFile();

    std::cout<<fileContent1<<std::endl;
    delete[] fileContent1;
    fileObj.writeToFile("1289361092", false);


    return 0; 
} 