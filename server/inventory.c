/*
** inventory.c for Zappy in /home/oscar/rendu/PSU_2014_zappy/server
** 
** Made by Oscar Morizet
** Login   <oscar@epitech.net>
** 
** Started on  Mon May 25 15:19:38 2015 Oscar Morizet
** Last update Mon May 25 15:51:11 2015 Oscar Morizet
*/

#include	<stdlib.h>
#include	<string.h>
#include	<strings.h>
#include	<stdio.h>
#include	"server.h"

int		add_item_class_to_inventory(t_player *player, char *item_name)
{
  t_item	*tmp;
  t_item	*new;

  if ((new = malloc(sizeof(t_item))) == NULL)
    return (0);
  bzero(new, sizeof(t_item));
  new->next = NULL;
  strcpy(new->name, item_name);
  if (player->inventory == NULL)
    player->inventory = new;
  else
    {
      tmp = player->inventory;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new;
    }
  return (1);
}

int		init_inventory(t_player *player)
{
  if (!add_item_class_to_inventory(player, "nourriture") ||
      !add_item_class_to_inventory(player, "linemate") ||
      !add_item_class_to_inventory(player, "deraumere") ||
      !add_item_class_to_inventory(player, "sibur") ||
      !add_item_class_to_inventory(player, "mendiane") ||
      !add_item_class_to_inventory(player, "phiras") ||
      !add_item_class_to_inventory(player, "thystame"))
    return (-1);
  return (0);
}

void		change_item_qt(t_player *player, char *item_name, char evo)
{
  t_item	*tmp;

  if (player->inventory == NULL)
    return ;
  tmp = player->inventory;
  while (tmp != NULL)
    {
      if (strcmp(tmp->name, item_name) == 0)
	{
	  if (evo == '+')
	    tmp->qt = tmp->qt + 1;
	  else if (evo == '-' && tmp->qt != 0)
	    tmp->qt = tmp->qt - 1;
	}
      tmp = tmp->next;
    }
}

char		*list_inventory(t_player *player)
{
  char		*dump;
  char		item[32];
  t_item	*tmp;

  if ((dump = malloc(sizeof(char) * 256)) == NULL)
    return (NULL);
  bzero(dump, sizeof(char) * 256);
  if (player->inventory == NULL)
    return (NULL);
  tmp = player->inventory;
  dump[0] = '{';
  while (tmp != NULL)
    {
      bzero(item, sizeof(char) * 32);
      sprintf(item, "%s %d", tmp->name, tmp->qt);
      strcat(dump, item);
      if (tmp->next != NULL)
	strcat(dump, " ");
      else
	strcat(dump, "}\n");
      tmp = tmp->next;
    }
  return (dump);
}
