/*
** EPITECH PROJECT, 2018
** cmd
** File description:
** cmd
*/

# include "project.h"

void remove_cmd(_)
{
	cmd_t *tmp;
	cmd_t *tmp2;

	tmp = session->cmd;
	while (tmp) {
		tmp2 = tmp->next;
		free(tmp);
		tmp = tmp2;
	}
	session->cmd = NULL;
}

void action_cmd(_, char *req,
	int (*function)(_, char *req))
{
	if (req && *req)
		req[strlen(req) - 2] = 0;
	__(function($, req), ERR_LAMBDA);
}

void action_data_cmd(_, char *req, int (*function)(_, char *req))
{
	if (DATA_CLIENT.protocol == _UNKNOWN) {
		_xxx(425, "No transfer protocol");
		return;
	}
	if (req && *req)
		req[strlen(req) - 2] = 0;
	if (DATA_CLIENT.protocol == _PASV)
		accept_data_connection($);
	else
		connect_to_data($);
	_150;
	__(function($, req), ERR_LAMBDA);
	stop_data_connection($);
}

void get_cmd(_, char *name, char *request)
{
	cmd_t *tmp;
	bool no_param = false;

	tmp = session->cmd;
	printf("req : %s\n", request);
	printf("name : %s\n", name);
	if (ONE_CMD(name)) {
		name[strlen(name) - 2] = 0;
		no_param = true;
	}
	if (strcmp("USER", name) && strcmp("PASS", name) && !(IS_LOGGED)) {
		_xxx(530, "User not logged.");
		return;
	}
	printf("command : %s\n", name);
	while (tmp) {
		if (!strcmp(tmp->name, name)) {
			tmp->cmd($, no_param ? NULL : request);
			return;
		}
		tmp = tmp->next;
	}
	_xxx(500, "Command not found.");
}

void add_cmd(_, cmd_t cmd)
{
	cmd_t *__cmd;
	cmd_t *tmp;

	__cmd = malloc(sizeof(cmd_t));
	__cmd->name = cmd.name;
	__cmd->cmd = cmd.cmd;
	__cmd->next = NULL;
	if (!session->cmd) {
		session->cmd = __cmd;
	} else {
		tmp = session->cmd;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = __cmd;
	}
}
