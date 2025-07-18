NAME = push_swap

DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m

INCLUDES = includes/
CC = cc #-Wall -Wextra -Werror

LIBS_DIR = libs/
PRINTF_DIR = $(LIBS_DIR)printf/
PRINTF = $(PRINTF_DIR)libftprintf.a

SRC_DIR = src/
OBJ_DIR = obj/

MAIN = main

AUX_DIR = aux_func/
AUX = ft_split ft_strdup ft_strlcpy ft_strlen ft_substr ft_atoi

MEM_DIR = mem_utils/
MEM = callocation memcopy reallocation

SORT_DIR = sort_func/
SORT = sa sb ss pa pb ra rb rr rra rrb rrr brute_force

STACK_DIR = stack_utils/
STACK = add_element clean_list delete_element get_element push_element resize rotate_list rev_rotate_list swap_list new_list get_smallest_element is_sorted

SRC_FILES += $(MAIN)
SRC_FILES += $(addprefix $(AUX_DIR), $(AUX))
SRC_FILES += $(addprefix $(MEM_DIR), $(MEM))
SRC_FILES += $(addprefix $(SORT_DIR), $(SORT))
SRC_FILES += $(addprefix $(STACK_DIR), $(STACK))

SRCS = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJS = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJSF = .cache_exists

all: $(NAME)

$(NAME): $(PRINTF) $(OBJS)
	@$(CC) -g -o $(NAME) $(OBJS) $(PRINTF) -I $(INCLUDES)
	@echo "$(GREEN)Push swap compiled!$(DEF_COLOR)"

$(PRINTF):
	@echo "$(YELLOW)Making printf...$(DEF_COLOR)"
	@make -sC $(PRINTF_DIR)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c | $(OBJSF)
	@echo "$(CYAN)Compiling: $<$(DEF_COLOR)"
	@$(CC) -g -c $< -o $@ -I $(INCLUDES)
	
$(OBJSF):
	@echo "$(MAGENTA)Creating dirs$(DEF_COLOR)"
	@mkdir -p $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)$(AUX_DIR)
	@mkdir -p $(OBJ_DIR)$(MEM_DIR)
	@mkdir -p $(OBJ_DIR)$(SORT_DIR)
	@mkdir -p $(OBJ_DIR)$(STACK_DIR)

bonus : all

clean:
	@echo "$(RED)Removing .o object files...$(DEF_COLOR)"
	@make fclean -sC $(PRINTF_DIR)
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Removing push_swap...$(DEF_COLOR)"
	@rm -f $(NAME)

re: clean all