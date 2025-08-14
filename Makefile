# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qdeffaux <qdeffaux@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/07 15:45:00 by qdeffaux          #+#    #+#              #
#    Updated: 2025/08/12 11:05:40 by qdeffaux         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Program name
NAME = push_swap

# Compiler and flags
CC = cc
CFLAGS = -Wall -Wextra -Werror -g
DEBUG_FLAGS = -g3 -fsanitize=address

# Directories
OBJDIR = obj
LIBFTDIR = libft

# Source files
SRCS = src/main.c \
       src/parsing.c \
       src/parsing2.c \
       src/stack_operations.c \
       src/base_operations.c \
       src/operation_wrapper.c \
       src/operation_wrapper2.c \
       src/operation_wrapper3.c \
       src/sort_small.c \
       src/utils.c \
       src/turk_algorithm.c \
       src/turk_push_operations.c \
       src/turk_cost_calculation.c
       #radix_sort.c

# Object files (in obj directory)
OBJS = $(SRCS:src/%.c=$(OBJDIR)/%.o)

# Libraries
LIBFT = $(LIBFTDIR)/libft.a
LIBS = -L$(LIBFTDIR) -lft

# Include paths
INCLUDES = -I. -I$(LIBFTDIR)

# Colors for output
GREEN = \033[0;32m
RED = \033[0;31m
YELLOW = \033[1;33m
NC = \033[0m # No Color

# Rules
all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
	@echo "$(YELLOW)Linking $(NAME)...$(NC)"
	@$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)
	@echo "$(GREEN)✓ $(NAME) compiled successfully!$(NC)"

# Create object directory and compile
$(OBJDIR)/%.o: src/%.c | $(OBJDIR)
	@echo "$(YELLOW)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Create object directory
$(OBJDIR):
	@mkdir -p $(OBJDIR)

# Compile libft
$(LIBFT):
	@echo "$(YELLOW)Compiling libft...$(NC)"
	@$(MAKE) -C $(LIBFTDIR)
	@echo "$(GREEN)✓ libft compiled!$(NC)"

# Debug version
debug: CFLAGS += $(DEBUG_FLAGS)
debug: fclean all

# Clean object files
clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(OBJDIR)/*.o
	@$(MAKE) -C $(LIBFTDIR) clean

# Clean everything
fclean: clean
	@echo "$(RED)Cleaning $(NAME)...$(NC)"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean

# Rebuild everything
re: fclean all

# Phony targets
.PHONY: all debug clean fclean re
