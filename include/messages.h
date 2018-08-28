/*
** EPITECH PROJECT, 2018
** RFC MESSAGES
** File description:
** RFC MESSAGES
*/

# ifndef H_MESSAGE
	# define H_MESSAGE

# define __MSG receive_from_client($)

# define _120 __sendMessage("120 Service ready in nnn minutes.\n")

# define _125 __sendMessage("125 Data connection already open;\
transfer starting.\n")

# define _150 __sendMessage("150 File status okay\n")

# define _200 __sendMessage("200 Command okay.\n")

# define _214 __sendMessage("214 Help message.\n")

# define _220 __sendMessage("220 Service ready for new user.\n")

# define _221 __sendMessage("221 Service closing control connection.\n")

# define _226 __sendMessage("226 Closing data connection.\n")

# define _227 dprintf(CLIENT_SOCK, "227 Entering Passive Mode \
(%s, %s, %s, %s, %d, %d).\n", *ip, ip[1], ip[2], ip[3], \
DATA_CLIENT.port / 256, DATA_CLIENT.port % 256)

# define _230 __sendMessage("230 User logged in, proceed.\n")

# define _250 __sendMessage("250 Requested file action okay, completed.\n")

# define _331 __sendMessage("331 User name okay, need password.\n")

# define _332 __sendMessage("332 Need account for login.\n")

# define _xxx(xxx, err) dprintf(CLIENT_SOCK, "%d %s\n", xxx, err)

# define _2XX_OK(NUM) dprintf(CLIENT_SOCK, "%d Current directory : \
%s\n", NUM, getcwd(cwd, MAX_LENGTH))

# define _2XX_NO(NUM) dprintf(CLIENT_SOCK, "%d Unable to change \
working directory : %s\n", NUM, strerror(errno))

# define _250_DEL_OK dprintf(CLIENT_SOCK, "250 File removed successfully\n")

# define _250_DEL_NO dprintf(CLIENT_SOCK, "550 Unable to remove file %s \
: %s\n", complete_path, strerror(errno))

#endif
