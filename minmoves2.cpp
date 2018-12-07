
//
//  postorderNTree.cpp
//  
//
//  Created by Brad Duvall on 12/4/18.
//


#include <iostream>
#include <vector>
#include <climits>
#include "quicksort.cpp"

using namespace std;

int findMedian(vector<int>& input);
int findMedianHelper(vector<int>& input, int globalPivotIndex, int leftIndex, int rightIndex);

// dont need this now that I am not using average but left it here
int getSum(vector<int>& nums)
{
    int sum = 0;

    for(int i = 0; i < nums.size(); i++)
    {
        sum+=nums[i];
    }

      return sum;
}

int minMoves2(vector<int>& nums) 
{
    // int sum = getSum(nums);

    // //initially thought I needed to use average . . . turns out median is the value to use
    // int average = sum/nums.size();
    // int max = average;
    // int min = average;

    // //finds the min and max values for the input vector
    // for(int i = 0; i < nums.size(); i++)
    // {
    //     if(nums[i] < min)
    //     {
    //         min = nums[i];
    //     }
        
    //     if(nums[i] > max)
    //     {
    //         max = nums[i];
    //     }
    // }

    // int moves = INT_MAX;
    
    // for(int j = min; j <= max; j++)
    // {
    //     int tempMoves = 0;

    //     for(int k = 0; k < nums.size(); k++)
    //     {
    //         int move = j - nums[k];

    //         if(move < 0)
    //         {
    //             move *= -1;
    //         }
    //         tempMoves += move;
    //     }

    //     if(tempMoves < moves)
    //     {
    //         moves = tempMoves;
    //         //cout << j << " " << moves << endl;
    //     }
        
    // }

    // return moves;


    int moves = 0;
    int median = findMedian(nums);

    for(int i = 0; i < nums.size(); i++)
    {
        int tempMoves = nums[i] - median;

        if(tempMoves < 0)
        {
            tempMoves *= -1;
        }

        moves += tempMoves;
    }
    return moves;

}

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

int main(int argc, char * const argv[])
{
    vector<int> input = {203125577,-349566234,230332704,48321315,66379082,386516853,50986744,-250908656,-425653504,-212123143};

    // cout << "Median: " << findMedian(input) << endl;
    
    // quicksort(input, 0, input.size()-1);

    // for(int i = 0; i < input.size(); i++)
    // {
    //     cout << input[i] << " ";
    // }

    // cout << endl << endl;
    cout << "Number of moves2: " << minMoves2(input) << endl;
    

    return 0;
};