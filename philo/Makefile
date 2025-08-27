
# ┌────────────────────────────────────────────────────────────┐
# │                     Root-level Makefile                   │
# └────────────────────────────────────────────────────────────┘

# === Compiler and Flags ===
CC      = cc
CFLAGS  = -g -Wall -Wextra -Werror -pthread \
          -Imain \
          -Imain/args \
          -Imain/core \
          -Imain/sync

NAME    = philo
OBJDIR  = obj

# === Sources ===
SRC_APP  = \
	main/app.c \
	main/utils.c \
	main/parse.c

SRC_CORE = \
	main/core/core.c

SRC_SYNC = \
	main/sync/routine.c \
	main/sync/forks.c   \
	main/sync/monitor.c

# === Source & Object Management ===
SRCS = $(SRC_APP) $(SRC_ARGS) $(SRC_CORE) $(SRC_SYNC)
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)

# === Targets ===
all: $(NAME)

$(NAME): $(OBJS)
	@echo " Linking $@"
	$(CC) $(CFLAGS) -o $@ $^

# === Object compilation ===
$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@echo " Compiling $<"
	$(CC) $(CFLAGS) -c $< -o $@

# === Cleaning ===
clean:
	@echo " Cleaning object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo " Removing binary..."
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
