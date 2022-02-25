#include <iostream>
#include <vector>

// cutlery designations
#define fork 0
#define spoon 1
#define knife 2
#define dessert 3
#define plate 4
#define chair 5

// row designation
#define firstRow -1
#define secondRow 5

// location of VIPs
#define VIP1 0
#define VIP2 1


/*!
 * @brief Outputting an array in an understandable form.
 * @param arr - 6 * 12 data array.
 */
void printArray(std::vector<std::vector<int>> arr)
{
    std::string words[] = {"fork", "spoon", "knife", "dessert", "plate", "chair"};

    std::cout
        << "--------------------------------------------------------------------------------------------------------" << std::endl
        << "\t";
    for(int i=0; i<arr.size(); i++) {
        std::cout << (i+1);
        if( (i==0) || (i==1) )
            std::cout << "(VIP)";
        std::cout << "\t";
    }
    std::cout
        << std::endl
        << "--------------------------------------------------------------------------------------------------------" << std::endl;
    for(int j=0; j<arr[0].size(); j++)
    {
        std::cout << words[j] << "\t";
        for(int i=0; i<arr.size(); i++)
            std::cout << arr[i][j] << "\t";
        std::cout << std::endl;
    }
    std::cout
        << "--------------------------------------------------------------------------------------------------------" << std::endl;
}

int main() {
    std::vector<std::vector<int>> dinnerTable = {
            // first row
            {1, 1, 1, 1, 3, 1},
            {1, 1, 1, 1, 3, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            // second row
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
            {1, 1, 1, 0, 2, 1},
    };

    std::cout << std::endl << "Source array:" << std::endl;
    printArray(dinnerTable);

    // 1st event
    std::cout << std::endl << "The lady who came to the 5th place of the first row came with the child and therefore another chair was put in this place." << std::endl;
    dinnerTable[firstRow+5][chair]++;
    printArray(dinnerTable);

    // 2st event
    std::cout << std::endl << "A spoon was stolen from the third seat in the second row in an unknown direction." << std::endl;
    dinnerTable[secondRow+3][spoon]--;
    printArray(dinnerTable);

    // 3st event
    std::cout << std::endl << "After that, one of the VIPs (any) shared his spoon with the one who lost it, and he himself began to eat dessert soup." << std::endl;
    dinnerTable[VIP1][spoon]--;
    dinnerTable[secondRow+3][spoon]++;
    printArray(dinnerTable);

    // 4st event
    std::cout << std::endl << "As unnecessary, the waiter took one dessert plate from him, because eating dessert with a spoon that has already been in the soup is not comme il faut." << std::endl;
    dinnerTable[VIP1][plate]--;
    printArray(dinnerTable);

    return 0;
}
