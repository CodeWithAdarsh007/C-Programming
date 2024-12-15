#include <stdio.h>
void main() 
{
    int choice;
    float num1, num2, result;

    while (1) 
	{
        // Display menu
        printf("\nSimple Calculator Menu:\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        // Handle exit
        if (choice == 5)
		{
            printf("Exiting the program. Goodbye!\n");
            break;
        }

        // Get inputs for operations
        if (choice >= 1 && choice <= 4) 
		{
            printf("Enter two numbers: ");
            scanf("%f %f", &num1, &num2);
        }

        // Perform calculations based on user choice
        switch (choice) 
		{
            case 1:
                result = num1 + num2;
                printf("Result of Addition: %.2f\n", result);
                break;
            case 2:
                result = num1 - num2;
                printf("Result of Subtraction: %.2f\n", result);
                break;
            case 3:
                result = num1 * num2;
                printf("Result of Multiplication: %.2f\n", result);
                break;
            case 4:
                if (num2 == 0)
				{
                    printf("Error: Division by zero is not allowed.\n");
                } else 
				{
                    result = num1 / num2;
                    printf("Result of Division: %.2f\n", result);
                }
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

