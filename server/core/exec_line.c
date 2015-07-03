/*
** exec_line.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/components
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Thu Jun  4 22:48:37 2015 Oscar
** Last update Tue Jun 23 08:40:32 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"
#include	"execute_line.h"

int		manage_player_cycles_to_death(t_game *game, t_player *player)
{
  if ((player->cycles_to_die % 126) == 0)
    change_item_qt(player, "nourriture", '-');
  --player->cycles_to_die;
  if (player->cycles_to_die == 0)
    {
      if (player_dies(game, player) == -1)
	return (-1);
    }
  return (0);
}

int		instant_exec(t_game *game, t_player *player,
			     t_command command, char *argument)
{
  return ((game->command_action[command])
	  (game, player, argument));
}

int		add_new_task_to_queue(t_game *game, t_player *player,
				      t_command command, char *argument)
{
  t_exec_line	*new;
  t_exec_line	*tmp;
  int		command_duration;

  if ((command_duration = game->command_duration[command]) == 0)
    return (instant_exec(game, player, command, argument));
  if ((new = malloc(sizeof(t_exec_line))) == NULL)
    return (-1);
  new->action = game->command_action[command];
  new->parameter = strdup(argument);
  new->cycles_before_exec = command_duration;
  new->next = NULL;
  if (player->exec_queue == NULL)
    {
      player->exec_queue = new;
      return (0);
    }
  tmp = player->exec_queue;
  while (tmp->next != NULL)
    tmp = tmp->next;
  tmp->next = new;
  return (0);
}

int		player_process_cycle(t_game *game, t_player *player)
{
  int		ret;
  t_exec_line	*task;

  if (manage_player_cycles_to_death(game, player) == -1)
    return (-1);
  task = player->exec_queue;
  if (task == NULL)
    return (0);
  if (task->cycles_before_exec > 1)
    {
      --task->cycles_before_exec;
      return (0);
    }
  if ((ret = task->action(game, player,
			  player->exec_queue->parameter)) == -1)
    return (-1);
  player->exec_queue = player->exec_queue->next;
  free(task);
  return (0);
}

int		init_player_exec_line(t_player *player)
{
  player->exec_queue = NULL;
  return (0);
}
