#include<stdio.h>
int digitSum(int num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}
int maxDigitSumPair(int nums[], int size) {
    int maxSum = -1;
    for (int i = 0; i < size; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (i != j) {
                int sum_i = digitSum(nums[i]);
                int sum_j = digitSum(nums[j]);

                if (sum_i == sum_j) {
                    int currentSum = nums[i] + nums[j];
                    if (currentSum > maxSum) {
                        maxSum = currentSum;
                    }
                }
            }
        }
    }
    return maxSum;
}
int main() {
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int nums[size];
    printf("Enter the array elements:\n");
    for (int i = 0; i < size; ++i) {
        scanf("%d", &nums[i]);
    }
    int result = maxDigitSumPair(nums, size);
    printf("Maximum sum of digits for two numbers: %d\n", result);
    return 0;
}
