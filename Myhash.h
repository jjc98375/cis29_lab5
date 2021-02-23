#pragma once
#include "List.h"
#include "DuplicateError.h"
#include "Mystring.h"

template<typename T, unsigned buckets>
class Myhash {
    List<T>* hashtable;
    unsigned wordcount;
    unsigned bucketused;

public:
    
    Myhash() : hashtable(new List<T>[buckets] ), wordcount(0), bucketused(0) {};
    ~Myhash();

    void insert(T word) {
        unsigned index = hash(word); //maybe should put unsigned() within it // how do i fix it
        if (hashtable[index].find(word)) {
            throw DuplicateError<Mystring>(word);
        }
        else if (hashtable[index].top() == nullptr) {
            bucketused++;
        }
        hashtable[index].push(word);
        wordcount++;
    };
    
    unsigned size() { return wordcount; };

    double percentofbucketsused() {
        return 1.0 * bucketused / buckets;
    };

    double averagenonemptybucketsize() {
        unsigned total = 0;
        for (unsigned i = 0; i < buckets; i++) {
            total += hashtable[i].length();
        }
        return 1.0 * total / buckets;
    };

    unsigned largestbucketsize() {
        unsigned max = 0;
        for (unsigned i = 0; i < buckets; i++) {
            if (hashtable[i].length() > max) {
                max = hashtable[i].length();
            }
        }
        return max;
    };

    bool find(const T& word) {
        for (unsigned i = 0; i < buckets; i++) {
            if (hashtable[i].find(word)) {
                return true;
            }
        }
        return false;
    };

    unsigned hash(unsigned key) {
        int c2 = 0x27d4eb2d; // a prime or an odd constant
        key = (key ^ 61) ^ (key >> 16);
        key = key + (key << 3);
        key = key ^ (key >> 4);
        key = key * c2;
        key = key ^ (key >> 15);
        return key % buckets;
    };


};

//template<typename T, unsigned buckets>
//inline Myhash<T, buckets>::~Myhash()
//{
//    for (auto i = 0u; i < buckets; i++)
//    {
//        if (hashtable[i].top() != nullptr)
//        {
//            delete hashtable[i];
//        }
//    }
//    delete[] hashtable;
//    hashtable = nullptr;
//}

template<typename T, unsigned buckets>
inline Myhash<T, buckets>::~Myhash()
{
    for (auto i = 0u; i < buckets; i++) {
        delete hashtable[i];
    }
    delete[] hashtable;
    hashtable = nullptr;
}
