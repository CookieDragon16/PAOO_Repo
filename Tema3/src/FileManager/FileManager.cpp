#include "FileManager.hpp"
namespace fs = std::experimental::filesystem;

FileManager::FileManager(const fs::path& path, bool clear){
    this->path = path;

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
void FileManager::writeToFile(char* content, bool clear) {
    if (isFile && file && file->is_open() && content != nullptr) {
        if(clear){
            file->close(); 
            std::experimental::filesystem::path filePath = path;
            file = std::make_unique<std::fstream>(path, std::ios::in | std::ios::out | std::ios::trunc);       
        }
        *file << content; 
        file->flush(); 
        std::cout << "Content written to file." << std::endl;
    }
}
FileManager::~FileManager() {
    if (isFile && file->is_open()) {
        file->close(); 
        std::cout << "File stream closed." << std::endl;
    }
}
