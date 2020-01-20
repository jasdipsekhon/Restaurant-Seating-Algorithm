//
//  main.cpp
//  cmpe130finProject2
//
//  Created by Jasdip Sekhon on 5/3/19.
//  Copyright © 2019 Jasdip Sekhon. All rights reserved.
//

#include <iostream>
using namespace std;

// Function to assign groups to tables
void nextFitAlgo(int tableSize[], int seats, int groupSize[], int people)
{
    // Stores table id of the table assigned to a group
    int sizeAllocation[people];
    
    int j = 0;
    
    // Initially no table is assigned to a group
    memset(sizeAllocation, -1, sizeof(sizeAllocation));
    
    // pick each group and find suitable table
    // according to its size and assign to it
    
    for (int i = 0; i < people; i++)
    {
        // Do not start searching for table from beginning
        while (j < seats)
        {
            
            if (tableSize[j] >= groupSize[i])
            {
                
                // assign table j to groupSize[i] group
                sizeAllocation[i] = j;
    
                // Reduce available table space
                tableSize[j] -= groupSize[i];
                break;
            }
            // mod seats will help in traversing the table from
            // starting table after we reach the end.
            //j = (j + 1) % seats;
            j++;
        }
    }
    
    cout << "Group No.\t\tGroup Size\t\tTable no.\n";
    for (int i = 0; i < people; i++)
    {
        cout << "\t" << i + 1 << "\t\t\t\t" << groupSize[i]
        << "\t\t\t\t";
        if (sizeAllocation[i] != -1)
            cout << sizeAllocation[i] + 1;
        else
            cout << "Can't fit them at a table";
        cout << endl;
    }
}


int main()
{
    int tableSize[] = {20, 11, 20};
    int groupSize[] = {18, 10, 7, 5};
    int seats = sizeof(tableSize) / sizeof(tableSize[0]);
    int people = sizeof(groupSize) / sizeof(groupSize[0]);
    nextFitAlgo(tableSize, seats, groupSize, people);
    
    return 0;
}
