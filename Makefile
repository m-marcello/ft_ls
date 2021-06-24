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

include src/_files.mk

NAME := ft_ls

OBJ := $(FILES:%.c=obj/%.o) obj/main.o

CFLAGS := -Wall -Wextra -Werror -g

LIBFT_PATH := libft
LIBFT := $(LIBFT_PATH)/libft.a

HDR_PATH := hdr
INCLUDES := -I $(HDR_PATH) -I $(LIBFT_PATH)
HDRS := $(HDR_PATH)/ft_ls.h

PLUS := $$(tput setaf 2)+$$(tput sgr0)
MINUS := $$(tput setaf 1)-$$(tput sgr0)

MAX_PARALLEL = 6

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	@$(CC) $(CFLAGS) -o $@ $^ $(LIBFT)
	@echo " $(PLUS) $@"

obj/%.o: src/%.c $(HDRS) obj
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " $(PLUS) $@"

obj:
	@mkdir -p $@

multi:
	@$(MAKE) -j$(MAX_PARALLEL) all

$(LIBFT):
	@+make -C $(LIBFT_PATH) | sed "s/^/libft: /"

clean: lclean
	@+make clean -C $(LIBFT_PATH) | sed "s/^/libft: /"

lclean:
	@rm -rfv obj | sed "s/^/ $(MINUS) /"

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

test: $(OBJ) $(HDRS)
	@$(MAKE) all
	@make re -C tests && ./tests/test

style:
	astyle --style=allman --indent=force-tab src/*.c tests/src/*.c

.PHONY: all clean fclean lclean lfclean lre test re multi $(LIBFT)
