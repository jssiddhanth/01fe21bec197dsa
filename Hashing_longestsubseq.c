#include <stdio.h>
#include <stdlib.h>


int findLongestSubsequence(int arr[], int n)
{
    int hashTable[1000];
    for (int i = 0; i < 1000; i++)
    {
        hashTable[i] = -1;
    }

    int maxLength = 0;
    int currentLength = 0;

    for (int i = 0; i < n; i++)
        {
        int index = arr[i] % 1000;

        while (hashTable[index] != -1 && hashTable[index] != arr[i])
        {
            index = (index + 1) % 1000;
        }

        if (hashTable[index] == -1)
        {
            currentLength = 1;
        } else
        {
            currentLength++;
        }

        hashTable[index] = arr[i];

        if (currentLength > maxLength)
        {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[1000];
    printf("Enter the elements of the array:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    int longestSubsequence = findLongestSubsequence(arr, n);
    printf("The longest possible subsequence is: %d\n", longestSubsequence);

    return 0;
}


