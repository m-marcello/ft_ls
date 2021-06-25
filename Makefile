# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/10 18:00:23 by mmarcell      #+#    #+#                  #
#    Updated: 2021/05/14 15:16:24 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SOURCE_PATH := src
include $(SOURCE_PATH)/_files.mk

NAME := ft_ls

OBJECT_PATH := obj
OBJECTS := $(C_FILES:%.c=$(OBJECT_PATH)/%.o) $(OBJECT_PATH)/main.o

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

HDR_PATH := hdr
HEADERS := $(H_FILES:%=$(HDR_PATH)/%)

CFLAGS := -Wall -Wextra -Werror -g

ALL_SRCS := $(C_FILES:%.c=$(SOURCE_PATH)/%.c) $(SOURCE_PATH)/main.c $(HEADERS)

INCLUDES := -I $(HDR_PATH) -I $(LIBFT_PATH)

PLUS := $$(tput setaf 2)+$$(tput sgr0)
MINUS := $$(tput setaf 1)-$$(tput sgr0)

MAX_PARALLEL = 6

all: $(NAME)

$(NAME): $(OBJECTS) $(LIBFT)
	@$(CC) $(CFLAGS) -o $@ $+
	@echo " $(PLUS) $@"

$(OBJECT_PATH)/%.o: $(SOURCE_PATH)/%.c $(HEADERS) $(OBJECT_PATH)
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " $(PLUS) $@"

$(OBJECT_PATH):
	@mkdir -p $@

multi:
	@$(MAKE) -j$(MAX_PARALLEL) all

$(LIBFT):
	@+make -C $(LIBFT_PATH) | sed "s/^/libft: /"

clean: lclean
	@+make clean -C $(LIBFT_PATH) | sed "s/^/libft: /"

lclean:
	@rm -rfv $(OBJECT_PATH) | sed "s/^/ $(MINUS) /"
	echo "$(HEADERS)"

fclean: clean lfclean
	@rm -fv $(LIBFT) | sed "s/^/ $(MINUS) /"

lfclean: lclean
	@rm -fv $(NAME) $() | sed "s/^/ $(MINUS) /"

re:
	$(MAKE) fclean
	$(MAKE) all

lre:
	$(MAKE) lfclean
	$(MAKE) all

test: $(OBJECTS) $(HEADERS)
	@$(MAKE) all
	@make re -C tests && ./tests/test

style:
	astyle --style=allman --indent=force-tab $(ALL_SRCS)

.PHONY: all clean fclean lclean lfclean lre test re multi $(LIBFT)
