/*
** EPITECH PROJECT, 2018
** client
** File description:
** client
*/

# include "project.h"

static void applay_select_setter(_)
{
	FD_ZERO(&(_CLIENT_SELECT.set));
	FD_SET(CLIENT_SOCK, &(_CLIENT_SELECT.set));

	_CLIENT_TIME = (struct timeval) {
		.tv_sec = MAX_TIME,
		.tv_usec = 0
	};
}

void new_client(_)
{
	int selected;

	while (CONNECTED) {
		applay_select_setter($);
		selected = __(select(CLIENT_SOCK + 1, &_CLIENT_SELECT.set,
					NULL, NULL, &_CLIENT_TIME), ERR_SELECT);
		if (selected > 0) {
			loading_log($);
			session->composed_msg = split(__MSG, ' ');
			__call_cmd(*session->composed_msg, session->composed_msg[1]);
			remove_cmd($);
			free(session->composed_msg);
		} else
			__error(ERR_CLIENTTIMEDOUT);
	}
	exit(EXIT_SUCCESS);
}
