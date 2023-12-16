#include "FileManager.hpp"
namespace fs = std::experimental::filesystem;

FileManager::FileManager(const fs::path& path, bool clear){
    this->path = path;
    pthread_mutex_init(&lock, NULL);
    if (fs::is_directory(path)) {
        dir = std::make_shared<fs::path>(path);
        std::cout << "Directory path '" << *dir << "' assigned." << std::endl;
        isFile=false;
    } else {
        if(clear){
            file = std::make_unique<std::fstream>(path, std::ios::in | std::ios::out | std::ios::trunc);
        }else{
            file = std::make_unique<std::fstream>(path, std::ios::in | std::ios::out);
        }
        if (file->is_open()) {
            std::cout << "File '" << path << "' exists and is open." << std::endl;
        } else {
            std::cout << "Failed to create file '" << path << "'." << std::endl;
        }
    }
}
char* FileManager::readFile() {
    if(isFile){
        if (file->is_open()) {
            std::stringstream contentStream;
            contentStream << file->rdbuf(); 

            std::string content = contentStream.str();
            char* charContent = new char[content.size() + 1];
            strcpy(charContent, content.c_str());
            return charContent;
        } else {
            return nullptr;
        }
    }
}

void FileManager::writeToFile() {
    pthread_mutex_lock(&lock); 
    if (isFile && file && file->is_open() && this->writeContent != nullptr) {
        if(this->writeClear){
            file->close(); 
            std::experimental::filesystem::path filePath = path;
            file = std::make_unique<std::fstream>(path, std::ios::in | std::ios::out | std::ios::trunc);       
        }
        *file << this->writeContent; 
        file->flush(); 
        std::cout << "Content written to file." << std::endl;
    }
    pthread_mutex_unlock(&lock); 
}

void FileManager::setWriteData(char* content,bool clear){
    writeContent = content;
    writeClear = clear;
}
FileManager::~FileManager() {
    if (isFile && file->is_open()) {
        file->close(); 
        std::cout << "File stream closed." << std::endl;
    }
    pthread_mutex_destroy(&lock); 
    delete[] writeContent;
}
