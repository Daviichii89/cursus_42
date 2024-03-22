/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davifer2 <davifer2@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:19:01 by davifer2          #+#    #+#             */
/*   Updated: 2024/03/12 14:24:48 by davifer2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 3
#endif

#include <fcntl.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct s_position
{
	int x;
	int y;
} t_position;

typedef struct s_list
{
	void *mlx_ptr;
	void *window_ptr;
	void *bush;
	void *imgexit;
	void *imgfloor;
	void *npc;
	void *collectible;
	t_position player_position;
	int linecontrol;
	int height_line;
	int width_line;
	int player;
	int exit;
	int wall;
	int floor;
	int x;
	int y;
	int consumible;
	char *big_line;

} t_list;

// typedef struct s_position
// {
// 	int x;
// 	int y;
// } t_position;

// typedef struct s_map
// {
// 	char *map;
// 	int width;
// 	int height;
// } t_map;

// typedef struct s_wall
// {
// 	void *bush;
// 	int n_wall;
// } t_wall;

// typedef struct s_player
// {
// 	void *npc;
// 	int n_player;
// 	t_position position;
// } t_player;

// typedef struct s_exit
// {
// 	void *imgexit;
// 	t_position position;
// 	int n_exit;
// } t_exit;

// typedef struct s_collectible
// {
// 	void *collectible;
// 	int n_consumible;
// 	t_position position;
// } t_collectible;

// typedef struct s_floor
// {
// 	void *imgfloor;
// 	int n_floor;
// 	t_position position;
// } t_floor;

// typedef struct s_list
// {
// 	void *mlx_ptr;
// 	void *window_ptr;
// 	t_map map;
// 	t_wall wall;
// 	t_player player;
// 	t_exit exit;
// 	t_collectible collectible;
// 	t_floor floor;
// 	t_position player_position;
// 	int linecontrol;
// 	int height_line;
// 	int width_line;
// 	int x;
// 	int y;
// 	char *store_line;
// } t_list;

// int main(void);
int main(int argc, char **argv);
int init_data(t_list *mlx, char *map);
void read_map(char *map, t_list *mlx);
void print_map(t_list *mlx);
int check_exit(t_list *data, char letter);
int ft_free(t_list *mlx);
void ft_error(t_list *mlx, int num);
char *get_next_line(int fd);
char *ft_strchr(const char *s, int c);
char *ft_substr(char const *s, int start, int len);
char *ft_strjoin(char const *s1, char const *s2);
int ft_strlen(const char *str);
void *ft_calloc(size_t count, size_t size);
void *ft_memset(void *b, int c, size_t len);
void ft_bzero(void *s, size_t n);

#endif