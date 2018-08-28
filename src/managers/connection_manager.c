/*
** EPITECH PROJECT, 2018
** connection
** File description:
** conn
*/

# include "project.h"

/*

	CATCHING SIGINT

		STOP CONNECTION
		EXIT CODE : 84

	CREATE CONNECTION

*/

void connection(_)
{
	signal(SIGINT, FUNC(void a(int sig) {
		(void) sig;
		if (CLIENT_LOG == NONE)
			return;
		stop_connection($);
		printf("Connection forced to stop\n");
		remove_cmd($);
		exit(84);
	}));
	new_connection($);
	wait_client($);
}

/*

	Accepting the client connection

*/

void accept_connection(_)
{
	CONNECTION.sockadd_length = sizeof(struct sockaddr_in);
	CLIENT_SOCK = __(accept(SOCKET_ID, (struct sockaddr *)&ADDRESS,
		(socklen_t *)&(CONNECTION.sockadd_length)), ERR_ACCEPT);
	printf("New client try to connect\n");
}

/*

	Accepting the client connection

*/

void accept_data_connection(_)
{
	DATA_CONNECTION.sockadd_length = sizeof(struct sockaddr_in);
	DATA_SOCK = __(accept(TRANSFER_SOCK, (struct sockaddr *)&DATA_ADRESS,
		(socklen_t *)&(DATA_CONNECTION.sockadd_length)), ERR_ACCEPT);
	printf("New client try to connect\n");
}

/*
	Launch connection to data client
*/

void connect_to_data(_)
{
	pre_connection_event($);
	__(setsockopt(TRANSFER_SOCK, SOL_SOCKET, SO_REUSEADDR,
		(char *)&DATA_CONNECTION.sockadd_length,
					sizeof(int)), ERR_SOCKOPT);
	DATA_TRANSFER.address.sin_port = htons(DATA_CLIENT.port);
	__(connect(TRANSFER_SOCK, (struct sockaddr *)&DATA_ADRESS,
					sizeof(DATA_ADRESS)), ERR_SOCKDATA);
	DATA_SOCK = TRANSFER_SOCK;
}
