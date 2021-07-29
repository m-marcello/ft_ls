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

SOURCE_PATH := ../src
TEST_SOURCE_PATH := src
include $(SOURCE_PATH)/_files.mk
include $(TEST_SOURCE_PATH)/_test_files.mk

OBJECT_PATH := ../obj
TEST_OBJECT_PATH := obj
OBJECTS := $(C_FILES:%.c=$(OBJECT_PATH)/%.o)
TEST_OBJECTS := $(TEST_FILES:%.c=$(TEST_OBJECT_PATH)/%.o)

LIBFT_PATH := ../libft
LIBFT := $(LIBFT_PATH)/libft.a

HDR_PATH := ../hdr
CRIT_PATH := ~/.brew/Cellar/criterion/2.3.3/include
INCLUDES := -I $(HDR_PATH) -I $(LIBFT_PATH) -I $(CRIT_PATH)
HDR := $(HDR_PATH)/ft_ls.h $(HDR_PATH)/ft_ls_data.h
HEADERS := $(H_FILES:%=$(HDR_PATH)/%)

CFLAGS := -Wall -Wextra -Werror

PLUS = $$(tput setaf 2)+$$(tput sgr0)
MINUS = $$(tput setaf 1)-$$(tput sgr0)

all: test

test: $(OBJECTS) $(TEST_OBJECTS)
	@$(CC) -o $@ $^ -lcriterion $(LIBFT)
	@echo " ${PLUS} $@"

obj/%.o: src/%.c $(HDR) obj
	@$(CC) -c $(CFLAGS) -o $@ $(INCLUDES) $<
	@echo " ${PLUS} $@"

obj:
	@mkdir -p $@

clean:
	@rm -fv $(TEST_OBJECTS) | sed "s/^/ $(MINUS) /"

fclean: clean
	@rm -fv test | sed "s/^/ $(MINUS) /"

re: fclean all

.PHONY: all test clean fclean re
