/*
** EPITECH PROJECT, 2018
** main
** File description:
** main
*/

# include "project.h"

/*

	CREATING session

	CHECKING args

		- PORT
		- PATH

	INITILIAZE Params struct

	LAUNCH connection protocols

*/

int	main(int const argc, char const * const * argv)
{
	NO_DYNAMIC_SESSION;

	if (argc < 2)
		return printf("Usage: ./server port path\n");
	session.params = (params_t) {
		.port = atoi(argv[1]),
		.path = argv[2]
	};
	connection(&session);
	return (0);
}
