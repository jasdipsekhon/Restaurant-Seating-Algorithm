# Restaurant-Seating-Algorithm
Modified next-fit algorithm to efficiently seat groups at tables.

Greedy approximation algorithm - Assigns group to first table where the tableSize[i]  >= groupSize[j].
Checks where to assign the next group starting after the previously assigned table.
If groups are small enough to fit to the same table they are combined.
Not checking every table allows groups to be assigned efficiently.


Running Time: O(n), where the for loop is dominant
Space Requirement: O(1) extra space to process n groups

The approximation ratio for our restaurant seating algorithm is 2
The number of tables used by the algorithm is bounded by twice of the optimal solution

Informal Proof: Consider any two adjacent tables. The sum of groups assigned to these two tables must be 
> c. Otherwise, the algorithm would have put all the groups of second table into the first. The same holds for all other tables. Thus, at most half the space is wasted, and so the algorithm uses at most 2T tables if T is optimal.
