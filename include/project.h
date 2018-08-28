/*
** EPITECH PROJECT, 2018
** project
** File description:
** project
*/

# ifndef H_CHECK
	# define H_CHECK

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <netdb.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <signal.h>
# include <stdbool.h>
# include <sys/time.h>
# include <errno.h>
# include <stdarg.h>
# include <fcntl.h>

# include "protocol.h"

# include "errors.h"

# include "client.h"

# include "messages.h"

# include "cmd.h"

# define FUNC(c_) ({ c_ a;})

/********* STRUCTS ***********/

typedef struct cmd_s cmd_t;

typedef struct params_s
{
	char const *path;
	int port;
} params_t;

typedef struct error_t
{
	char *type;
	short num;
} error_t;

typedef struct connection_s
{
	struct sockaddr_in address;
	int sockadd_length;
	int socket;
} connection_t;

typedef struct session_s
{
	params_t params;
	error_t error;
	connection_t connection;
	client_t client;
	cmd_t *cmd;
	char **composed_msg;
} session_t;

struct cmd_s
{
	char *name;
	void (*cmd)(_, char *request);
	struct cmd_s *next;
};

/******** PROTOTYPES *********/

// CONNECTION

void new_connection(_);
void stop_connection(_);

// DATA CONNECTION

void stop_data_connection(_);
void pre_connection_event(_);
void new_data_connection(_);

// CONNECTION MANAGER

void connection(_);
void accept_connection(_);
void accept_data_connection(_);
void connect_to_data(_);

// CLIENT MANAGER

void wait_client(_);
void kill_client(_);

// MESSAGE MENAGER

char *receive_from_client(_);
void write_to_client(_);
void write_client_composed(_, int (*action)(_));

// ERRORS_MANAGER

int error_checker_cond(int, error_t, int, _);
int error_checker(int, error_t, _);
void *error_checker_pointer(void *, error_t error, _);

// CLIENT

void new_client(_);

// CMD managers

void remove_cmd(_);
void add_cmd(_, cmd_t cmd);
void get_cmd(_, char *name, char *);
void action_cmd(_, char *req, int (*function)(_, char *req));
void action_data_cmd(_, char *req, int (*function)(_, char *req));

// DEV TOOLS utils

char **split(char *str, char const);
char *get_client_addr(void);

// REGISTERING COMMANDS

void loading_log(_);

// CMDS

	// auths
void command_user(_, char *req);
void command_pass(_, char *req);
void command_quit(_, char *req);
void command_syst(_, char *);

	// misc
void command_noop(_, char *req);
void command_help(_, char *req);
void command_exec(_, char *req);

	//directories
void command_pwd(_, char *req);
void command_cwd(_, char *req);
void command_cdup(_, char *req);

	//file
void command_del(_, char *req);
void command_list(_, char *req);
void command_retr(_, char *req);
void command_stor(_, char *req);

	//transfer protocol
void command_port(_, char *req);
void command_pasv(_, char *req);

# endif
