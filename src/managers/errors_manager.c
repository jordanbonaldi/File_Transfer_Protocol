/*
** EPITECH PROJECT, 2018
** error
** File description:
** errors
*/

# include "project.h"

/*

	Print error ID and Error message

	EXIT CODE : 84

*/

static void exit_error(error_t error, _)
{
	if (error.type && *error.type)
		printf("Unexpected error %d : %s\n", error.num, error.type);
	if (CLIENT_SOCK) {
		CLIENT.log = DISCONNECTED;
		kill_client($);
	}
	perror("Error: ");
	exit(84);
}

/*

	Error checker by condition

*/

int error_checker_cond(int obj, error_t error, int cond, _)
{
	if (obj >= cond)
		exit_error(error, $);
	return obj;
}

/*

	Error checker by pointer

*/

void *error_checker_pointer(void *obj, error_t error, _)
{
	if (!obj)
		exit_error(error, $);
	return obj;
}

/*

	Error checker by int

*/

int error_checker(int obj, error_t error, _)
{
	if (obj < 0)
		exit_error(error, $);
	return obj;
}
