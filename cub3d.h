/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abensgui <abensgui@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 16:53:23 by hbouladh          #+#    #+#             */
/*   Updated: 2022/11/16 21:43:35 by abensgui         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <mlx.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <string.h>
# include <math.h>

# define WIN_H 1080.0
# define WIN_W 1920.0
# define MOVESPEED 10.0
# define CUBESIZE 32.0

typedef struct s_vars{
	char	**map;
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	int		f[3];
	int		c[3];
}			t_vars;

typedef struct s_data {
	void	*mlx;
	void	*img;
	void	*mlx_win;
	char	**map;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	direction;
	int		width;
	int		height;
	double	dist;
	double	h_wall;
	double	sd_wall;
	double	xp;
	double	yp;
	double	angle_player;
	double	new_xp_front;
	double	new_yp_front;
	double	new_xp_back;
	double	new_yp_back;
	double	new_xp_left;
	double	new_yp_left;
	double	new_xp_right;
	double	new_yp_right;
	int		x_wall_front;
	int		y_wall_front;
	int		x_wall_back;
	int		y_wall_back;
	int		x_wall_left;
	int		y_wall_left;
	int		x_wall_right;
	int		y_wall_right;
	double	x_ray;
	double	y_ray;
	double	angle_ray;
	int		ray_num;
	int		ifhit_xwall;
	int		ifhit_ywall;
	int		wall_dir;
	void	*img_no;
	int		width_no;
	int		height_no;
	char	*addr_no;
	int		bits_per_pixel_no;
	int		line_length_no;
	int		endian_no;
	void	*img_so;
	int		width_so;
	int		height_so;
	char	*addr_so;
	int		bits_per_pixel_so;
	int		line_length_so;
	int		endian_so;
	void	*img_we;
	int		width_we;
	int		height_we;
	char	*addr_we;
	int		bits_per_pixel_we;
	int		line_length_we;
	int		endian_we;
	void	*img_ea;
	int		width_ea;
	int		height_ea;
	char	*addr_ea;
	int		bits_per_pixel_ea;
	int		line_length_ea;
	int		endian_ea;
	double	w_touch;
	int		color_sky;
	int		color_floor;
	double	h_texture;
}			t_data;

int		ft_mlx(t_data *img, char **av);
int		ft_init_map(t_data *img);
int		ft_event(int key_code, t_data *img);
void	ft_set_player(t_data *img, int i, int j);
char	**ft_readmap(int fd);
char	**ft_split(char const *s, char c);
void	ft_key_moves(int key_code, t_data *img);
void	ray_casting(t_data *img);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	player_view(t_data *img);
void	put_texture(t_data *img, int a, int j, int y);
int		texture_walls(t_data *img, int j);
int		is_far_from_wall(t_data *img, int key_code);
int		check_far_from_wall(t_data *img, int key_code, int x, int y);
int		check_file_name(char *str);
char	*get_next_line(int fd);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *sr);
int		ft_strlen(char *s);
char	*get_next_line(int fd);
t_vars	*ft_map(char **av);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split1(char *s, char c);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
void	check_map(char **s);
void	ft_color(char *s, int *j, int *n);
void	print_error(char *s);
void	rgb_convert(t_vars *data, t_data *img);
char	*ft_joinchar(char *s1, char c);
void	check_element(char **s, int i);
int		if_player(char c);
int		j_wall(int j, char *s, int p);
int		i_wall(int i, int j, char **s, int p);
void	check_wall(char **s, int i, int j);
char	*ft_catstr(char **s, int *j, int i);
int		check_data(t_vars *data);
void	skip_space(char *s, int *i);
char	*open_file(char *av1);
void	ft_ins(t_vars *data);
void	skip_space(char *s, int *i);
int		line_space(char *s);

#endif
