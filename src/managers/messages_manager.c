/*
** EPITECH PROJECT, 2018
** messages
** File description:
** messages
*/

# include "project.h"

void write_to_client(_)
{
	__(write(CLIENT_SOCK, _getMessage.message,
					_getMessage.length), ERR_WRITE);
}

char *receive_from_client(_)
{
	memset(_getMessage.message, 0, MAX_LENGTH);
	__(read(CLIENT_SOCK, _getMessage.message, MAX_LENGTH), ERR_READCLIENT);
	return _getMessage.message;
}

void write_client_composed(_, int (*action)(_))
{
	__(action($), ERR_WRITE);
}
