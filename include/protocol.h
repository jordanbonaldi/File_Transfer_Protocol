/*
** EPITECH PROJECT, 2018
** def pro
** File description:
** def prot
*/

# ifndef H_PROTO
	# define H_PROTO

/********** CORE PART **********/

# define CONNECTION_PROTOCOL "TCP"

# define PROTOCOL session->connection.connection_type

# define CONNECTION session->connection

# define ADDRESS session->connection.address

# define SOCKET_ID CONNECTION.socket

# define MAX_CLIENT 3

# define _ session_t *session

# define $ session

# define NO_DYNAMIC_SESSION session_t session

# define PARAMS session->params

# define PORT PARAMS.port

# define ADDRES_INIB (struct sockaddr_in)

# define CONNECTION_INIB (connection_t)

/********* CLIENT PART **********/

# define CLIENT session->client

# define CLIENT_SOCK session->client.socket

# define DATA_INIB (conn_t)

# define DATA_CLIENT CLIENT.transfer_data

# define DATA_CONNECTION DATA_CLIENT.connection

# define DATA_TRANSFER DATA_CLIENT.connection

# define DATA_ADRESS DATA_CLIENT.connection.address

# define DATA_LENGTH DATA_CLIENT.connection.sockadd_length

# define DATA_SOCK DATA_CLIENT.socket

# define TRANSFER_SOCK DATA_CLIENT.connection.socket

# define CONNECTED !(CLIENT.log == DISCONNECTED)

# define IS_LOGGED CLIENT_LOG == LOGGED

# define CLIENT_LOG CLIENT.log

# define _CLIENT_SELECT CLIENT.set

# define _CLIENT_TIME _CLIENT_SELECT.time

# define MAX_TIME 200

# define USER "Anonymous"

# define PASS ""

# endif
