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

void pre_connection_event(_)
{
	DATA_TRANSFER = DATA_INIB {
		.socket = __(socket(AF_INET, SOCK_STREAM, 0), ERR_SOCK),
		.address = ADDRES_INIB {
			.sin_family = AF_INET,
			.sin_addr.s_addr = INADDR_ANY,
			.sin_port = 0
		}
	};
}

/*

	Getting port availability
	And launching the server

*/

static void connection_event(_)
{
	__(bind(TRANSFER_SOCK, (struct sockaddr *)&DATA_ADRESS,
					sizeof(DATA_ADRESS)), ERR_BIND);
	__(listen(TRANSFER_SOCK, MAX_CLIENT), ERR_LISTEN);
	DATA_CONNECTION.sockadd_length = sizeof(DATA_ADRESS);
	__(getsockname(TRANSFER_SOCK, (struct sockaddr *)&DATA_ADRESS,
				(socklen_t *)&DATA_LENGTH), ERR_SOCKNAME);
	DATA_CLIENT.port = ntohs(DATA_ADRESS.sin_port);
}

void stop_data_connection(_)
{
	if (TRANSFER_SOCK) {
		printf("\nTransfer Port : %d released\n", DATA_CLIENT.port);
		printf("Transfer Socket : %d released\n", TRANSFER_SOCK);
		close(TRANSFER_SOCK);
		close(DATA_SOCK);
		DATA_CLIENT.protocol = _UNKNOWN;
		TRANSFER_SOCK = 0;
	}
}

void new_data_connection(_)
{
	pre_connection_event($);
	connection_event($);
	printf("Server open on port : %d\n", DATA_CLIENT.port);
}
