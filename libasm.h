/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libasm.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: calide-n <calide-n@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 14:32:16 by calide-n          #+#    #+#             */
/*   Updated: 2021/01/20 19:12:07 by calide-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBASM_H
# define LIBASM_H

# include <stdio.h>
# include <string.h>
# include <errno.h>

extern int errno;

size_t		ft_strlen(const char *str);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dst, const char *src);
char		*ft_strdup(const char *s1);
ssize_t		ft_write(int fildes, const void *buf, size_t nbytes);
ssize_t		ft_read(int fildes, void *buf, size_t nbytes);
int			ft_list_size(t_list *list);

#endif
