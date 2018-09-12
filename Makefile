# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: psaprono <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/29 11:41:27 by psaprono          #+#    #+#              #
#    Updated: 2018/06/03 12:29:47 by psaprono         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := 	RTv1

SRC :=		main.c binds.c color.c init.c inter_fig.c find_normal.c light.c \
			render.c tools.c parser.c in_fig.c parse_vector.c parse_figures.c \
			in_fig1.c

OBJ =		$(SRC:.c=.o)

LIBFT =			$(LIBFT_DIR)libft.a
LIBFT_DIR :=	libft/
LIBFT_FLAGS :=	-lft -L $(LIBFT_DIR) -lmlx -framework OpenGL -framework AppKit

CC_FLAGS :=		

LINK_FLAGS :=	$(LIBFT_FLAGS)

HEADER_FLAGS :=	-I. -I $(LIBFT_DIR)

CC :=			gcc

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(OBJ) $(LINK_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: %.c rtv1.h
	@$(CC) -O2 -c $< -o $@ $(CC_FLAGS) $(HEADER_FLAGS)

$(LIBFT):
	@make -C $(LIBFT_DIR)

clean:
	@rm -f $(OBJ)
	@make clean -C $(LIBFT_DIR)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)

re: fclean all
