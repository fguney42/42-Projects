#include <iostream>
#include <fstream>
#include <string>

void ftFileClose(std::ifstream *infile, std::ofstream *outfile)
{
    infile->close();
    outfile->close();
}

int ftFileOpen(std::string name, std::ifstream *infile , std::ofstream *outfile)
{
    int a = 0;
    infile->open(name);
    if (!infile->is_open())
    std::cerr << "infile is not opened" << std::endl, a = 1;
    if (a == 0)
    outfile->open(name + ".replace");
    if (!outfile->is_open())
    std::cerr << "infile is not create" << std::endl ,a = 1;
    return (a);
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
        int a = ftFileOpen(name, &infile, &outfile);
        while (std::getline(infile, line) && a == 0)
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