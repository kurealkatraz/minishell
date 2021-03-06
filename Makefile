# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgras <mgras@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/05 17:03:04 by mgras             #+#    #+#              #
#    Updated: 2016/01/31 15:00:45 by mgras            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_NAME =	ft_core.c\
 			ft_env_0.c\
			ft_error_handling.c\
			ft_sto_manipulation_0.c\
			ft_sto_manipulation_1.c\
			ft_input.c\
			ft_cleaner.c\
			ft_colors.c\
			ft_spliter.c\
			ft_parse.c\
			ft_utility_0.c\
			ft_utility_1.c\
			ft_cmd.c\
			ft_buildtin_env_0.c\
			ft_buildtin_env_1.c\
			ft_exec_cmd.c\
			ft_native_cmd_call.c\
			ft_buildtin_unsetenv.c\
			ft_buildtin_setenv.c\
			ft_buildtin_cd.c\
			ft_signal_handler.c\

OBJ_NAME = $(SRC_NAME:.c=.o)
LIB_NAME = libft

SRC_PATH = ./src/
OBJ_PATH = ./obj/

LIB_PATH = ./libft/
INC_PATH = ./include/ $(LIB_PATH)

SRC      = $(addprefix $(SRC_PATH), $(SRC_NAME))
OBJ      = $(addprefix $(OBJ_PATH), $(OBJ_NAME))
INC      = $(addprefix -I, $(INC_PATH))
LIB      = $(addprefix -L, $(LIB_PATH))

NAME     = minishell
CC       = clang

CFLAGS = -Wall -Wextra -Werror -g -o3
LDFLAGS = -lft

all: libft $(NAME)

.PHONY: libft clean fclean re $(NAME)

libft :
	make -C $(LIB_PATH)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB) $(INC) $(LDFLAGS) -o $(NAME)

$(OBJ_PATH)%.o : $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean :
	@$(RM) -v $(OBJ)
	@$(RM) -rv $(OBJ_PATH)
	make clean -C $(LIB_PATH)

fclean : clean
	@$(RM) -v $(NAME)
	make fclean -C $(LIB_PATH)

re: fclean all
