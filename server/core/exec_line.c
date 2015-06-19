/*
** exec_line.c for Zappy in /home/oscar/Projets/PSU_2014_zappy/server/components
** 
** Made by Oscar
** Login   <oscar@epitech.net>
** 
** Started on  Thu Jun  4 22:48:37 2015 Oscar
** Last update Fri Jun 19 18:37:10 2015 Oscar
*/

#include	<stdlib.h>
#include	<string.h>
#include	"server.h"
#include	"execute_line.h"

int		add_new_task_to_queue(t_game *game, t_player *player,
				      t_command command, char *argument)
{
  t_exec_line	*new;
  t_exec_line	*tmp;
  
  if ((new = malloc(sizeof(t_exec_line))) == NULL)
    return (-1);
  new->action = game->command_action[command];
  new->parameter = strdup(argument);
  new->cycles_before_exec = game->command_duration[command];
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

  task = player->exec_queue;
  if (task == NULL)
    return (0);
  if (task->cycles_before_exec > 1)
    {
      --task->cycles_before_exec;
      return (0);
    }
  if ((ret = task->action(game, player, player->exec_queue->parameter)) == -1)
    return (-1);
  print_map(game);
  player->exec_queue = player->exec_queue->next;
  free(task);
  return (0);
}

int		init_player_exec_line(t_game *game, t_player *player)
{
  player->exec_queue = NULL;
  return (0);
}
