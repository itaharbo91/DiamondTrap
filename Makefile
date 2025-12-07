# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: itaharbo <itaharbo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/03 23:15:21 by itaharbo          #+#    #+#              #
#    Updated: 2025/10/03 23:28:06 by itaharbo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= borderlands03

CC			= c++
CFLAGS		= -Wall -Wextra -Werror -std=c++98 -Wshadow -Wno-shadow
INCLUDES	= -I includes

SRCDIR		= srcs
OBJDIR		= objs

SRCS		= $(SRCDIR)/main.cpp \
			  $(SRCDIR)/ClapTrap.cpp \
			  $(SRCDIR)/ScavTrap.cpp \
			  $(SRCDIR)/FragTrap.cpp \
			  $(SRCDIR)/DiamondTrap.cpp

OBJS		= $(SRCS:$(SRCDIR)/%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Compiling..."
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "Compiled successfully!"

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJDIR)
	@echo "Clean completed!"

fclean: clean
	@echo "Cleaning..."
	@rm -f $(NAME)
	@echo "Full clean completed!"

re: fclean all

.PHONY: all clean fclean re
