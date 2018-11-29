//
//  jewelsInStones.cpp
//  
//
//  Created by Brad Duvall on 9/4/18.
//


#include <iostream>
#include <string>
#include <map> //for hashmap

int countJewelsInStones(std::string J, std::string S){

    int count = 0;
    
    // //This is the brute force method --------------------------------------
    // for(int i = 0; i<j.length(); i++)
    // {
    //     for(int k = 0; k < s.length(); k++)
    //     {
    //         if(j[i] == s[k])
    //         {
    //             count++;
    //         }
    //     }
    // }

    //hash map method ---------------------------------------------------------
    std::map <char, int> stonesMap;

    for(int i = 0; i < S.length(); i++)
    {
        //count of 0 means it is not in the hashmap
        if(stonesMap.count(S[i]) == 0)
        {
            stonesMap.insert(std::pair<char,int>(S[i],1));
        }

        else
        {
            stonesMap[S[i]] +=1;
        }
    }
    
    //update count based on string j compared to string s hashmap
    for(int i = 0; i < J.length(); i++)
    {
        //count of 1 means it is in the hashmap
        if(stonesMap.count(J[i]) == 1)
        {
            count+=stonesMap[J[i]];  
        }
    }


    // //prints out hashmap contents
    // std::cout << std::endl;
    // std::map<char,int>::iterator iter = stonesMap.begin();
    // for (iter=stonesMap.begin(); iter!=stonesMap.end(); ++iter)
    // {
    //     std::cout << iter->first << " => " << iter->second << '\n';
    // }
  

    return count;

};


int main(int argc, char * const argv[])
{
    std::cout << "countJewelsInStones: aA, aAAbbbb: " << countJewelsInStones("aA", "aAAbbbb") << " = 3" << std::endl;

    std::cout << "countJewelsInStones: aA, AAAbbbb: " << countJewelsInStones("aA", "AAAbbbb") << " = 3" << std::endl;

    std::cout << "countJewelsInStones: aA, aaabbbb: " << countJewelsInStones("aA", "aaabbbb") << " = 3" << std::endl;

    std::cout << "countJewelsInStones: a, aAabbbb: " << countJewelsInStones("a", "aAabbbb") << " = 2" << std::endl;

    std::cout << "countJewelsInStones: A, aAabbbb: " << countJewelsInStones("A", "aAabbbb") << " = 1" << std::endl;

    std::cout << "countJewelsInStones: A, aaabbbb: " << countJewelsInStones("A", "aaabbbb") << " = 0" << std::endl;


    //std::cout << "countJewelsInStones: z, ZzZbbbb: " << countJewelsInStones("Z", "zzzbbbb") << std::endl;



    return 0;
};

