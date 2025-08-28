# ┌────────────────────────────────────────────────────────────┐
# │                     Root-level Makefile                   │
# └────────────────────────────────────────────────────────────┘

# === Compiler and Flags ===
CC      = cc
CFLAGS  = -g -Wall -Wextra -Werror -pthread \
          -Imain \
          -Imain/init \
          -Imain/core \
          -Imain/core/sim \
          -Imain/core/sync

NAME    = philo
OBJDIR  = obj

# === Sources ===
SRC_APP  = \
	main/app.c \
	main/utils.c

SRC_INIT = \
	main/init/parse.c \
	main/init/init_default.c

SRC_CORE = \
	main/core/core.c \

SRC_SIM  = \
	main/core/sim/sim_join.c \
	main/core/sim/sim_spawm.c \
	main/core/sim/sim_state.c

SRC_SYNC = \
	main/core/sync/action.c \
	main/core/sync/forks.c \
	main/core/sync/monitor.c \
	main/core/sync/routine.c

# === Source & Object Management ===
SRCS = $(SRC_APP) $(SRC_INIT) $(SRC_CORE) $(SRC_SIM) $(SRC_SYNC)
OBJS = $(SRCS:%.c=$(OBJDIR)/%.o)
DEPS = $(OBJS:.o=.d)

# Precompute all obj subdirectories and ensure they exist
OBJ_SUBDIRS := $(sort $(dir $(OBJS)))

# === Targets ===
all: $(NAME)

$(NAME): $(OBJS)
	@echo " Linking $@"
	$(CC) $(CFLAGS) -o $@ $^

# Create obj subdirectories first (order-only prerequisite)
$(OBJS): | $(OBJ_SUBDIRS)

$(OBJ_SUBDIRS):
	@mkdir -p $@

# Pattern rule: src.c -> obj/src.o (with dep files)
$(OBJDIR)/%.o: %.c
	@echo " Compiling $<"
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

# === Cleaning ===
clean:
	@echo " Cleaning object files..."
	@rm -rf $(OBJDIR)

fclean: clean
	@echo " Removing binary..."
	@rm -f $(NAME)

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re
