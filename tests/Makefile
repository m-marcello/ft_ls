# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: mmarcell <mmarcell@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2021/05/14 13:09:04 by mmarcell      #+#    #+#                  #
#    Updated: 2021/05/14 15:14:45 by mmarcell      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

include ../src/_files.mk
include ./src/_test_files.mk

OBJ := $(FILES:%.c=../obj/%.o)
TEST_OBJ := $(TEST_FILES:%.c=obj/%.o)

CFLAGS := -Wall -Wextra -Werror

LIBFT_PATH := ../libft
LIBFT := $(LIBFT_PATH)/libft.a

HDR_PATH := ../hdr
CRIT_PATH := ~/.brew/Cellar/criterion/2.3.3/include
INCLUDES := -I $(HDR_PATH) -I $(LIBFT_PATH) -I $(CRIT_PATH)
HDR := $(HDR_PATH)/ft_ls.h $(HDR_PATH)/ft_ls_data.h

PLUS = $$(tput setaf 2)+$$(tput sgr0)
MINUS = $$(tput setaf 1)-$$(tput sgr0)

all: test

test: $(OBJ) $(TEST_OBJ)
	@$(CC) -o $@ $^ -lcriterion $(LIBFT)
	@echo " ${PLUS} $@"

obj/%.o: src/%.c $(HDR) obj
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " ${PLUS} $@"

obj:
	@mkdir -p $@

clean:
	@rm -fv $(TEST_OBJ) | sed "s/^/ $(MINUS) /"

fclean: clean
	@rm -fv test | sed "s/^/ $(MINUS) /"

re: fclean all

.PHONY: all test clean fclean re
