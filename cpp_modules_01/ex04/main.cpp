#include <iostream>
#include <fstream>
#include <string>

void ftFileClose(std::ifstream *infile, std::ofstream *outfile)
{
    infile->close();
    outfile->close();
}

bool ftFileOpen(std::string name, std::ifstream *infile , std::ofstream *outfile)
{
    bool isFileOpen = true;
    infile->open(name);
    if (!infile->is_open())
    std::cerr << "infile is not opened" << std::endl, isFileOpen = false;
    if (isFileOpen == true)
    outfile->open(name + ".replace");
    if (!outfile->is_open())
    std::cerr << "infile is not create" << std::endl ,isFileOpen = false;
    return (isFileOpen);
}

int main(int argc,char **argv)
{
    std::ifstream infile;
    std::ofstream outfile;
    std::string replace, find, name, line;
    size_t pos;
    if (argc != 4)
    std::cerr << "You entered missing or more arguments" << std::endl;
    if (argc == 4)
    {
        name = argv[1];
        find = argv[2];
        replace = argv[3];
        bool isFileOpen = ftFileOpen(name, &infile, &outfile);
        while (isFileOpen == true && std::getline(infile, line))
        {
            pos = line.find(find);
            while (pos != std::string::npos)
            {
                line.erase(pos, find.length());
                line.insert(pos, replace);
                pos = line.find(find, pos + replace.length());
            }
            outfile << line << std::endl;
        }
        ftFileClose(&infile, &outfile);
    }
    return (0);
}