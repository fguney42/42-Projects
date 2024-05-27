#include <iostream>
#include <fstream>
#include <string>
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
        infile.open(name);
        outfile.open(name + ".replace");
        if (!infile.is_open())
        std::cerr << "infile is not opened" << std::endl;
        if (!outfile.is_open())
        std::cerr << "infile is not create" << std::endl;
        else if (outfile.is_open() && infile.is_open())
        while (std::getline(infile, line))
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
    }
    infile.close();
    outfile.close();
    return (0);
}