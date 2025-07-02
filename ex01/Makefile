# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: brian <brian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/26 16:58:24 by brian             #+#    #+#              #
#    Updated: 2025/06/18 02:45:00 by brian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFILES = $(wildcard src/*.cpp)
OFILES = $(CFILES:src/%.cpp=%.o)

Compiler = g++
Flags = -Wall -Wextra -Werror -std=c++98
INCLUDES = -Iincludes

NAME = ex01

all: $(NAME)

$(NAME): $(OFILES)
	$(Compiler) $(Flags) $(OFILES) -o $(NAME)

%.o: src/%.cpp
	$(Compiler) $(Flags) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re