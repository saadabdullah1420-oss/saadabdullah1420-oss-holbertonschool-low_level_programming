#include "main.h"

/**
 * check_prime - Checks if a number is divisible by another number.
 * @n: Number to check.
 * @divisor: Current divisor.
 *
 * Return: 1 if prime, otherwise 0.
 */
int check_prime(int n, int divisor)
{
	if (divisor * divisor > n)
		return (1);

	if (n % divisor == 0)
		return (0);

	return (check_prime(n, divisor + 1));
}

/**
 * is_prime_number - Returns 1 if n is prime, otherwise 0.
 * @n: Number to check.
 *
 * Return: 1 if n is prime, otherwise 0.
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);

	return (check_prime(n, 2));
}
