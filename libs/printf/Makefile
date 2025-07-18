# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: acesteve <acesteve@student.42malaga.com>   +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/04/29 19:17:42 by acesteve          #+#    #+#              #
#    Updated: 2025/07/04 14:13:23 by acesteve         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

INCLUDES = includes

CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRCS_DIR = src/
OBJS_DIR = obj/

AUX_DIR = ft_aux/
AUX = ft_strlen ft_isupper ft_isflag ft_atoi ft_isdigit ft_isspecifier ft_numlen

MOD_DIR = ft_flg/
MOD = ft_flgnew ft_flgfind ft_flgadd_front ft_flgadd_back ft_flgclear

PUT_DIR = ft_put/
PUT = ft_putchar_fd ft_putstr_fd ft_putnbr_fd ft_putunbr_fd ft_putoct_fd ft_puthex_fd ft_putdouble_fd ft_putexp_fd ft_putsign_fd

PRINT_DIR = ft_print/
PRINT = ft_printchar ft_printstr ft_printnbr ft_printhex ft_printdec

SRC_FILES += ft_printf
SRC_FILES += $(addprefix $(AUX_DIR),$(AUX))
SRC_FILES += $(addprefix $(MOD_DIR),$(MOD))
SRC_FILES += $(addprefix $(PUT_DIR),$(PUT))
SRC_FILES += $(addprefix $(PRINT_DIR),$(PRINT))

SRCS = $(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN)Printf compiled!$(DEF_COLOR)"

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c | $(OBJSF)
	@$(CC) $(CFLAGS) -I $(INCLUDES) -g -c $< -o $@
	
$(OBJSF):
	@mkdir -p $(OBJS_DIR)
	@mkdir -p $(OBJS_DIR)$(AUX_DIR)
	@mkdir -p $(OBJS_DIR)$(MOD_DIR)
	@mkdir -p $(OBJS_DIR)$(PUT_DIR)
	@mkdir -p $(OBJS_DIR)$(PRINT_DIR)

bonus: all

clean:
	@rm -rf $(OBJS_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re test
