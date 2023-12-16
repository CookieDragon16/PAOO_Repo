#include <iostream>
#include <memory>
#include <fstream>
#include <experimental/filesystem>
#include <string.h>
namespace fs = std::experimental::filesystem;

class FileManager{
    public:
        FileManager(const fs::path& path, bool clear);
        ~FileManager();
        char* readFile();
        void writeToFile(char* content, bool clear);
    private:
        std::unique_ptr<std::fstream> file;
        std::shared_ptr<fs::path> dir;
        std::experimental::filesystem::path path;
        bool isFile;
};