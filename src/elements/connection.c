/*
** EPITECH PROJECT, 2018
** connection
** File description:
** conn
*/

# include "project.h"

/*

	Initialize connection PROTOCOL, and getting socket availability

*/

static void pre_local_connection_event(_)
{
	CONNECTION = CONNECTION_INIB {
		.socket = __(socket(AF_INET, SOCK_STREAM, 0), ERR_SOCK),
		.address = ADDRES_INIB {
			.sin_family = AF_INET,
			.sin_addr.s_addr = INADDR_ANY,
			.sin_port = htons(PORT)
		}
	};
}

/*

	Getting port availability
	And launching the server

*/

static void connection_event(_)
{
	__(bind(SOCKET_ID, (struct sockaddr *)&ADDRESS,
						sizeof(ADDRESS)), ERR_BIND);
	__(listen(SOCKET_ID, MAX_CLIENT), ERR_LISTEN);
}

void stop_connection(_)
{
	printf("\nPort : %d released\n", PORT);
	if (SOCKET_ID) {
		printf("Socket : %d released\n", SOCKET_ID);
		close(SOCKET_ID);
		CLIENT_LOG = NONE;
	}
}

void init_session(_)
{
	session->client.socket = 0;
	session->cmd = NULL;
	if (PARAMS.path)
		__(chdir(PARAMS.path), ERR_CWD);
	else
		__error(ERR_CWD);
}

void new_connection(_)
{
	init_session($);
	pre_local_connection_event($);
	connection_event($);
	printf("Server open on port : %d\n", PORT);
}
