#include <stdio.h> 
#include <stdlib.h> 
#include <fstream>
#include <experimental/filesystem>
#include "FileManager.hpp" 
#include <pthread.h>

pthread_t tid[2]; 
void* writeSafe(void* context) {
    FileManager* fileManager = static_cast<FileManager*>(context);
    fileManager->writeToFile(); 
    return nullptr;
}

int main() 
{ 
    std::experimental::filesystem::path filePath1 = "test_path/TestFile";
    std::experimental::filesystem::path filePath2 = "test_path";
    FileManager fileObj(filePath1,false);
    //FileManager dirObj(filePath1,false);
    char* fileContent1 = fileObj.readFile();

    std::cout<<fileContent1<<std::endl;
    delete[] fileContent1; 
    int error;
    fileObj.setWriteData("1234124 --> ", false);
    error = pthread_create(&(tid[0]), NULL, &writeSafe, &fileObj); 
    if (error != 0) 
        printf("\nThread can't be created :[%s]", strerror(error)); 
    fileObj.setWriteData("new_data ", false);
    error = pthread_create(&(tid[0]), NULL, &writeSafe, &fileObj); 
    if (error != 0) 
        printf("\nThread can't be created :[%s]", strerror(error)); 
        
    pthread_join(tid[0], NULL); 
    pthread_join(tid[1], NULL); 

    return 0; 
} 