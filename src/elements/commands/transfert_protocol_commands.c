/*
** EPITECH PROJECT, 2018
** transfer protocols
** File description:
** transfer protocols
*/

# include "project.h"

void command_pasv(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		char **ip = split(get_client_addr(), '.');
		(void)req;

		new_data_connection($);
		DATA_CLIENT.protocol = _PASV;
		_227;
		return 1;
	}));
}

static void convert_output(_, char *str, ...)
{
	va_list	args;

	va_start(args, str);
	vsnprintf(DATA_CLIENT.ip, sizeof(DATA_CLIENT.ip), str, args);
	va_end(args);
}

void command_port(_, char *req)
{
	__call_action(FUNC(int a(_, char *req) {
		char **args = req ? split(req, ',') : NULL;
		int port = atoi(args ? args[4] : "0") * 256
			+ atoi(args ? args[5] : "0");

		printf("%d\n", atoi(args ? args[4] : "0"));
		printf("%d\n", atoi(args ? args[5] : "0"));
		if (!req || !port) {
			_xxx(520, "No request found");
			return 1;
		}
		convert_output($, "%s.%s.%s.%s", *args,
						args[1], args[2], args[3]);
		DATA_CLIENT.port = port;
		if (DATA_CLIENT.protocol == _PASV)
			stop_data_connection($);
		DATA_CLIENT.protocol = _PORT;
		_200;
		return 1;
	}));
}
