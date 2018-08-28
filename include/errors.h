/*
** EPITECH PROJECT, 2018
** errors messages
** File description:
** errors messages
*/

# ifndef H_ERRORS
	# define H_ERRORS

# define __C(obj, error, cond) error_checker_cond(obj, error, cond, $)

# define __(obj, error) error_checker(obj, error, $)

# define __O(obj, error) error_checker_pointer(obj, error, $)

# define __error(error) error_checker(-1, error, $)

# define create_error(id, string) (error_t) { \
					.num = id, \
					.type = string \
				}

# define ERR_P create_error(-1, "No Protocol found")

# define ERR_SOCK create_error(-2, "Unable to create socket")

# define ERR_BIND create_error(-3, "Unable to bind this port")

# define ERR_LISTEN create_error(-4, "Unable to listen this port")

# define ERR_ACCEPT create_error(-5, "Unable to accept client")

# define ERR_FORK create_error(-6, "Unable to fork client connection")

# define ERR_WRITE create_error(-7, "Unable to send a message to the client")

# define ERR_SELECT create_error(-8, "Unable to receive client request")

# define ERR_CLIENTTIMEDOUT create_error(-9, "Client request timed out")

# define ERR_READCLIENT create_error(-10, "Unable to read client's request")

# define ERR_LAMBDA create_error(-11, "Crash doing client request")

# define ERR_PWD create_error(-12, "Unable to get the current directory")

# define ERR_CWD create_error(-13, "Unable to change working directory")

# define ERR_SOCKNAME create_error(-14, "Unable to get the \
transfer socket's datas")

# define ERR_SOCKOPT create_error(-15, "Unable to set socket connection option")

# define ERR_SOCKDATA create_error(-16, "Unable to connect to client data")

# define ERR_DUP create_error(-17, "Unable redirect standart ouput")

# define ERR_OPEN create_error(-18, "Unable to open file")

# define ERR_WRITE_CLIENT create_error(-19, "Unable to write file to client")

# endif
