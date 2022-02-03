# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rtracee <rtracee@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/16 22:42:59 by rtracee           #+#    #+#              #
#    Updated: 2021/09/16 22:45:22 by rtracee          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				=	minitalk

CL					=	client
CL_ISP			=	client.c

SV					=	server
SV_ISP			=	server.c

CL_ISP_BONUS	=	clientbonus.c cl_bon_2.c
SV_ISP_BONUS	=	serverbonus.c

CC					=	gcc
FLAGS				=	-Wall -Wextra -Werror
RM					=	rm -rf

all: $(NAME)

$(NAME): $(CL) $(SV)

$(CL): $(CL_ISP)
	$(CC) $(FLAGS) $(CL_ISP) -o $(CL)

$(SV): $(SV_ISP)
	$(CC) $(FLAGS) $(SV_ISP) -o $(SV)

bonus: cl_bonus sv_bonus

cl_bonus: $(CL_ISP_BONUS)
	$(CC) $(FLAGS) $(CL_ISP_BONUS) -o $(CL)

sv_bonus: $(SV_ISP_BONUS)
	$(CC) $(FLAGS) $(SV_ISP_BONUS) -o $(SV)

clean:
	@$(RM) $(SV) $(CL)

fclean: clean
	@$(RM) $(SV) $(CL) $(SV_BONUS) $(CL_BONUS)

re: fclean all

 .PHONY: all clean sv cl fclean re sv_bonus cl_bonus $(NAME)