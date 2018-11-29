//
//  reverse.cpp
//  
//
//  Created by Brad Duvall on 9/4/18.
//


#include <iostream>

int reverseRight(int x){
    int y = 0; //to be returned reversed int
    bool negInt; //true if the input int is negative
    
    if(x < 0)
    {
        x *= -1;
        negInt = true;
    }

    if(x == 0)
    {
        return x;
    }

    while(x > 0)
    {
        int tempY = y;

        y *= 10;
        y += (x%10);

        if(y/10 != tempY)
        {
            return 0;
        }

        x /= 10;
        
    }

    if( y < 0) //y should always be positive at this point
    {
        return 0;
    }
    
    if(negInt)
    {
        
        return (-1 * y);
    }

    return y;
};


int main(int argc, char * const argv[])
{
    std::cout << "reverseRight 123: " << reverseRight(123) << std::endl;
    // std::cout << "reverseRight -106: " << reverseRight(-106) << std::endl;
    // std::cout << "reverseRight 0: " << reverseRight(0) << std::endl;
    // std::cout << "reverseRight -0: " << reverseRight(-0) << std::endl;
    // std::cout << "reverseRight 1000000006: " << reverseRight(1000000006) << std::endl;
    // std::cout << "reverseRight -1000000006: " << reverseRight(-1000000006) << std::endl;
    // std::cout << "reverseRight 7463847412: " << reverseRight(7463847412) << std::endl;
    // std::cout << "reverseRight 8463847412: " << reverseRight(8463847412) << std::endl;


    return 0;
};

