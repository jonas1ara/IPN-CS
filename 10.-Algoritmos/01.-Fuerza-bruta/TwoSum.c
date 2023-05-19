#include <stdio.h>

void twoSum(int nums[], int n, int target, int* resultado) 
{
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        {
            if (nums[i] + nums[j] == target) 
            {
                resultado[0] = i;
                resultado[1] = j;
                return;
            }
        }
    }
}

int main() 
{
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int resultado[2];

    twoSum(nums, sizeof(nums) / sizeof(nums[0]), target, resultado);

    printf("Indices de los numeros que suman el objetivo: [%d, %d]\n", resultado[0], resultado[1]);

    return 0;
}