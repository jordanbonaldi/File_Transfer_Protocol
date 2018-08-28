/*
** EPITECH PROJECT, 2018
** client h
** File description:
** client h
*/

# ifndef H_CLIENT
	# define H_CLIENT

# include <sys/select.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>

# define _transfer (transfer_t) { \
				.sock = 0, \
				.port = 0, \
				.ip = 0, \
				.protocol = _UNKNOWN \
			}

# define _client(session) CLIENT = (client_t) { \
				.socket = CLIENT_SOCK, \
				.log = NONE \
			}

# define _setMessage(msg) CLIENT.message = (message_t) { \
					.message = msg, \
					.length = strlen(msg) \
				}

# define ONE_CMD(C) C[strlen(C) - 1] == '\n'

# define _getMessage CLIENT.message

# define __sendMessage(msg) _setMessage(msg), write_to_client($)

# define __sendComposed(act) write_client_composed($, act)

# define MAX_LENGTH 1024

typedef struct message_s
{
	char message[MAX_LENGTH];
	int length;
} message_t;

typedef enum log_s
{
	NONE,
	LOGGING,
	LOGGED,
	DISCONNECTED
} log_t;

typedef enum transfer_protocol_s
{
	_UNKNOWN,
	_PASV,
	_PORT
} transfer_protocol_t;

typedef struct select_datas_s
{
	struct timeval time;
	fd_set set;
} select_datas_t;

typedef struct conn_s
{
	struct sockaddr_in address;
	int sockadd_length;
	int socket;
} conn_t;

typedef struct transfer_s
{
	char ip[20];
	int socket;
	int port;
	conn_t connection;
	transfer_protocol_t protocol;
} transfer_t;

typedef struct client_s
{
	int socket;
	log_t log;
	message_t message;
	select_datas_t set;
	transfer_t transfer_data;
} client_t;

#endif
