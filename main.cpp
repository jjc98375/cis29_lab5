#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "Mystring.h"
#include "List.h"
#include "Node.h"
#include "Myhash.h"
#include "DuplicateError.h"

using namespace std;



 int main()
{
    Myhash<Mystring, 1500> dictionary;
    Mystring buffer;

    const string dictionaryfilename = "dictionary.txt";
    const string documentfilename = "ihaveadream.txt";

    ifstream fin(dictionaryfilename.c_str());
    if (!fin)
    {
        cerr << "can't find " << dictionaryfilename << endl;
        exit(-1);
    }
    while (getline(fin, buffer))
    {
        // remove \r if present (this for mac/linux)
        //if (buffer[buffer.size() - 1] == '\r')
        //    buffer.resize(buffer.size() - 1);
        buffer.tolower();
        try
        {
            dictionary.insert(buffer);
        }
        catch (const DuplicateError<Mystring>& error)
        {
            cout << error.what() << endl;
        }
    }

    cout << "number of words in the dictionary = " << dictionary.size() << endl;
    cout << "percent of hash table buckets used = " << setprecision(2) << fixed << 100 * dictionary.percentofbucketsused() << '%' << endl;
    cout << "average non-empty bucket size = " << dictionary.averagenonemptybucketsize() << endl;
    cout << "largest bucket size = " << dictionary.largestbucketsize() << endl;

    fin.close();
    fin.clear();

    // spellcheck
    unsigned misspelledwords = 0;

    fin.open(documentfilename.c_str());
    if (!fin)
    {
        cerr << "can't find " << documentfilename << endl;
        exit(-1);
    }
    while (fin >> buffer)
    {
        buffer.tolower();
        buffer.removePunctuation();
        if (!buffer.size())
            continue;
        if (!dictionary.find(buffer))
        {
            misspelledwords++;
            cout << "not found in the dictionary: " << buffer << endl;
        }
    }
    cout << "total mispelled words = " << misspelledwords << endl;


  
}