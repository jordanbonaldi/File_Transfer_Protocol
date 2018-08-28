/*
** EPITECH PROJECT, 2018
** c managers
** File description:
** c managers
*/

# include "project.h"

static void client(_)
{
	_client($);
	_220;
	new_client($);
}

void kill_client(_)
{
	CLIENT_LOG = DISCONNECTED;
	close(CLIENT_SOCK);
}

/*

	Waiting for a connection,

	Creating a fork of the client connection

*/

void wait_client(_)
{
	int pid;

	while (true) {
		accept_connection($);
		pid = __(fork(), ERR_FORK);
		if (!pid)
			client($);
		if (pid > 0)
			kill_client($);
	}
}
