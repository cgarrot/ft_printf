# **************************************************************************** #
#                                                           LE - /             #
#                                                               /              #
#    Makefile                                         .::    .:/ .      .::    #
#                                                  +:+:+   +:    +:  +:+:+     #
#    By: cgarrot <marvin@le-101.fr>                 +:+   +:    +:    +:+      #
#                                                  #+#   #+    #+    #+#       #
#    Created: 2018/10/10 19:59:22 by cgarrot      #+#   ##    ##    #+#        #
#    Updated: 2019/03/19 11:41:25 by cgarrot     ###    #+. /#+    ###.fr      #
#                                                          /                   #
#                                                         /                    #
# **************************************************************************** #

.PHONY: all clean fclean re

NAME = main_ft_printf
CC = gcc
FLAGS = -Wall -Wextra -Werror
LIBFT = ./libft/libft.a
INC = $(LIBFT) ft_printf.h

#------------------------------------FILE--------------------------------------#

FILES = ft_printf\

#----------------------------------SOURCE--------------------------------------#

SRC = $(addsuffix .c , $(FILES))

#-----------------------------------RULE---------------------------------------#

all: $(NAME)

$(NAME): $(SRC) $(INC) ./libft/
	@printf $(RED)"                                                                      ___ \n"
	@printf "                                _____________________________________ //  \n"
	@printf "                              / /-----------|  |----------| |--------- \ \n"
	@printf "                            / /             |  |          | |           \ \n"
	@printf "                          / /               |  |          | |           | \n"
	@printf "               _________/ /                 |  |          | |           | \n"
	@printf "      _______"
	@printf $(YELLOW)"("
	@printf $(RED)"|___________\_________________|  |----------===============\          "
	@printf $(W)"(@)\n"
	@printf $(RED)"    /                  |           (=)       |           (=)|            "
	@printf $(YELLOW)"/\ "
	@printf $(RED)"       "
	@printf $(W)"(@) (@)\n"
	@printf $(RED)"  /                   |      "
	@printf $(PURPLE)"cgarrot"
	@printf $(RED)"        |                |           "
	@printf $(YELLOW)"\/"
	@printf $(RED)"\     "
	@printf $(W)"(@) (@)\n"
	@printf $(RED)" /"
	@printf $(YELLOW)"<>"
	@printf $(RED)"      ________    |           "
	@printf $(PURPLE)"ft_printf"
	@printf $(RED)"     |                |________      \     "
	@printf $(W)"(@)\n"
	@printf $(RED)" |      /  "
	@printf $(W)"______"
	@printf $(RED)"  \   |  <==================|===========>  /  "
	@printf $(W)"______"
	@printf $(RED)"  \   -/   "
	@printf $(W)"(@)\n"
	@printf $(RED)" |)    |  "
	@printf $(W)"/ \  / \ "
	@printf $(RED)" |__|_____________________|_____________|  "
	@printf $(W)"/ \  / \ "
	@printf $(RED)" | [ "
	@printf $(W)"(@)\n"
	@printf $(RED)" \____ | "
	@printf $(W)"|   ()   | "
	@printf $(RED)"|______________________________________| "
	@printf $(W)"|   ()   | "
	@printf $(RED)"|_/ \n"
	@printf $(W)"          \_/__\_/                                            \_/__\_/ \n"
	@+make -C libft/
	@ar rcs $(NAME) $(OBJ)

%.o: %.c $(INC)
	@$(CC) -o $@ -c $< -I $(INC)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) 

re: fclean all
