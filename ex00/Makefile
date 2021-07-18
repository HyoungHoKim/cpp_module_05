CPP = clang++
CPPFLAGS = -Wall -Werror -Wextra -std=c++98 

SRCS = Bureaucrat.cpp main.cpp
OBJS = $(SRCS:.cpp=.o)
NAME = brueaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CPP) $(CPPFLAGS) -o $(NAME) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test