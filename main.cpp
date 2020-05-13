#include <Windows.h>
#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>

using namespace std;

int main(int argc, char* argv[])
{
    if (argc == 5)
    {
        int min = atoi(argv[1]);
        int max = atoi(argv[2]);
        char option = *argv[3];
        char *fileName = argv[4];

        ofstream outfile;
        outfile.open(fileName);
        if (option == 'r')
        {
            std::vector<int> nmbs;
            for (int i = min; i <= max; ++i)
            {
                nmbs.push_back(i);
            }
            random_shuffle(nmbs.begin(), nmbs.end());
            for (int i = 0; i < nmbs.size(); ++i)
            {
                outfile << nmbs.at(i) << endl;
            }
        }
        else if (option == 'd')
        {
            for (int i = max; i >= 0; --i)
            {
                outfile << i << endl;
            }
        }
        else
        {
            for (int i = min; i <= max; ++i)
            {
                outfile << i << endl;
            }
        }
        outfile.close();
    }
    else
    {
        printf("Error not enough arguments passed.");
    }
}