
//
//  findmedian.cpp
//  
//
//  Created by Brad Duvall on 12/4/18.
//


#include <iostream>
#include <vector>

using namespace std;

int findMedianHelper(vector<int>& input, int globalPivotIndex, int leftIndex, int rightIndex);

int findMedian(vector<int>& input)
{
    
    int globalPivotIndex = input.size()/2;
 

    //recursion linear time method
    return findMedianHelper(input, globalPivotIndex, 0, input.size());

    /*
    //brute force
    for(int i = 0; i < input.size(); i++)
    {
        if(input[i] < pivot)
        {
            lessThanPivot.push_back(input[i]);
        }
        else if(input[i] > pivot)
        {
            greaterThanPivot.push_back(input[i]);
        }
        else
        {
            //cout << "Pivot index hit" << endl;
        }

    }

    int sizeDelta = (lessThanPivot.size() - greaterThanPivot.size());

    if(sizeDelta < 0)
    {
        sizeDelta *= -1;
    }

    if(sizeDelta <= 1)
    {
        return pivot;
    }
    else if(lessThanPivot.size() > greaterThanPivot.size())
    {
        return findMedian(lessThanPivot);
    }
    else if(lessThanPivot.size() < greaterThanPivot.size())
    {
        return findMedian(greaterThanPivot);
    }
    else
    {
        return 0;
    }
    */

};

int findMedianHelper(vector<int>& input, int globalPivotIndex, int leftIndex, int rightIndex)
{
    int localPivotIndex = input.size()/2;
    int newPivotIndex = 0;
    int pivot = input[localPivotIndex];

    vector<int> lessThanPivot;
    vector<int> greaterThanPivot;

    for(int i = 0; i < input.size(); i++)
    {
        if(i != localPivotIndex)
        {
            if(input[i] < pivot)
            {
                lessThanPivot.push_back(input[i]);
            }
            else
            {
                greaterThanPivot.push_back(input[i]);
            }
        }
    }

    newPivotIndex = leftIndex + lessThanPivot.size();

    if(newPivotIndex == globalPivotIndex)
    {
        //cout << "pivot: " << pivot << endl;
        return pivot;
    }
    else if(lessThanPivot.size() == 1 && greaterThanPivot.size() < 1)
    {
        //cout << "lessThanPivot[0]: " << lessThanPivot[0] << endl;
        return lessThanPivot[0];
    }
    else if(lessThanPivot.size() < 1 && greaterThanPivot.size() == 1)
    {
        //cout << "greaterThanPivot[0]: " << greaterThanPivot[0] << endl;
        return greaterThanPivot[0];
    }

    //need a condition where size <=1 for left and right vectors

    if(newPivotIndex > globalPivotIndex)
    {
        //cout << "Looking at left" << endl;
        return findMedianHelper(lessThanPivot, globalPivotIndex, leftIndex, 0);
    }
    else
    {
        //cout << "Looking at right" << endl;
        return findMedianHelper(greaterThanPivot, globalPivotIndex, newPivotIndex + 1, 0);
    }
}