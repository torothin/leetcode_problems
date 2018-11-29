//
//  uniqueEmail.cpp
//  
//
//  Created by Brad Duvall on 9/20/18.
//


#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>

using namespace std;

string reduceEmail(string oldEmail);
int numUniqueEmails(vector<string>& emails);


int main(int argc, char * const argv[])
{
    vector<string> testVector;
    
    testVector.push_back("test.email+alex@leetcode.com");
    testVector.push_back("test.e.mail+bob.cathy@leetcode.com");
    testVector.push_back("testemail+davidfun@lee.tcode.com");
    testVector.push_back("bradford.duvall@gmail.com");

    cout << "numUniqueEmails: " << numUniqueEmails(testVector) << endl;

    return 0;
};

int numUniqueEmails(vector<string>& emails) {


    int emailsSize = emails.size();

    //---------------------------"brute force method"------------------------------------------
    /*

    //loops through vector and replaces emails with a reduced form
    //changes the input vector

    for(int i = 0; i < emailsSize; i++) // O(n) n = number of email addresses
    {
        string oldEmail = emails.back();
        emails.pop_back();  // O(1)?

        string newEmail = reduceEmail(oldEmail);  // O(m) m = size of strings

        emails.emplace(emails.begin(),newEmail);  // O(1)
    }
    
    
    //loops through emails, popping back, comparing to all indexes and back to the front
    //  if there are no copies of back in vector

    
    for(int i = 0; i < emailsSize; i++) // O(n) n = number of email addresses
    {
        string backEmail = emails.back();
        emails.pop_back();

        for(int j = 0; j < emails.size(); j++) // O(n) n = number of email addresses
        {
            if(backEmail == emails[j])
            {
                backEmail = "";
            }
        }
        if(backEmail != "")
        {
            emails.emplace(emails.begin(),backEmail);
        }
        
    }
    */
    //---------------------------"hashmap method"------------------------------------------
    
    //maintains original vector
    
    unordered_set<string> emailsMap;

    for(int i = 0; i < emailsSize; i++) // O(n) n = number of email addresses
    {
        string oldEmail = emails.back();

        emails.pop_back();

        string newEmail = reduceEmail(oldEmail); // O(m)

        emailsMap.insert(newEmail); // O(1)
    }

    return emailsMap.size();
    };

string reduceEmail(string oldEmail)
{
    bool localName = true;
    bool serverName = false;

    string newEmail = "";

    for(int j = 0; j < oldEmail.size(); j++) // O(m) m = size of strings
    {
        if(oldEmail[j] == '@')
        {
            newEmail += oldEmail[j];
            serverName = true;
            localName = false;
        }
        else if(localName && ( oldEmail[j] != '.' && oldEmail[j] != '+') )
        {
            newEmail += oldEmail[j];
        }
        else if(localName && oldEmail[j] == '+')
        {
            localName = false;
        }
        else if(!localName && serverName)
        {
            newEmail += oldEmail[j];
        }
        else
        {
            //skip local name "." and go to next
        }
    }

    return newEmail;
};
