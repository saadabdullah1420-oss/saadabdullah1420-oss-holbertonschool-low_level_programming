#include <stdio.h>

/**
 * main - simple calculator
 *
 * Return: Always 0
 */
int main(void)
{
	int choice;
	int a;
	int b;
	float result;

	while (1)
	{
		printf("Simple Calculator\n");
		printf("1) Add\n");
		printf("2) Subtract\n");
		printf("3) Multiply\n");
		printf("4) Divide\n");
		printf("0) Quit\n");
		printf("Choice: ");

		scanf("%d", &choice);

		if (choice == 0)
		{
			printf("Bye!\n");
			break;
		}
		else if (choice == 1)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			result = a + b;
			printf("Result: %.0f\n", result);
		}
		else if (choice == 2)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			result = a - b;
			printf("Result: %.0f\n", result);
		}
		else if (choice == 3)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			result = a * b;
			printf("Result: %.0f\n", result);
		}
		else if (choice == 4)
		{
			printf("A: ");
			scanf("%d", &a);

			printf("B: ");
			scanf("%d", &b);

			if (b == 0)
			{
				printf("Error: division by zero\n");
			}
			else
			{
				result = (float)a / b;
				printf("Result: %.1f\n", result);
			}
		}
		else
		{
			printf("Invalid choice\n");
		}
	}

	return (0);
}
