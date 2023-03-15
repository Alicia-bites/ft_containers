#Colors
RESET=\033[0m
DODGERBLUE1=\033[38;5;33m
ORANGERED1=\033[38;5;202m

# project settings
NAME            :=  ft_containers
NAME_AR         :=  ft_containers.a
C++             :=  c++
CXXFLAGS        :=  -MMD -Wall -Wextra -Werror -std=c++98
# CXXFLAGSADD     :=  -g3
# CXXFLAGSADD   :=  -g3 -D DEBUG=1
STD_FLAG        :=  -DSTD
FT_FLAG         :=  -DFT

IPATH           :=  includes
OPATH           :=  obj

SRCS_PATH       :=  tester_alicia
STACK_PATH		:=	stack
VECTOR_PATH		:= 	vector
MAP_PATH		:= 	map
SET_PATH		:=	set

RM              :=  rm -rf

VECTOR_SRCS		:= 	execute_tests_vector.cpp
STACK_SRCS		:=	execute_tests_stack.cpp
MAP_SRCS		:= 	execute_tests_map.cpp
SET_SRCS		:=	execute_tests_set.cpp

SRCS            :=  42main.cpp \
					$(VECTOR_SRCS) \
					$(STACK_SRCS) \
					$(MAP_SRCS) \
					$(SET_SRCS)
# 
OBJS            :=  $(addprefix $(OPATH)/, $(SRCS:.cpp=.o))
DEPS            :=  $(OBJS:.o=.d)

vpath %.hpp $(IPATH)
vpath %.cpp $(SRCS_PATH)\
			$(SRCS_PATH)/$(VECTOR_PATH) \
			$(SRCS_PATH)/$(STACK_PATH) \
			$(SRCS_PATH)/$(MAP_PATH) \
			$(SRCS_PATH)/$(SET_PATH) \

vpath %.o $(OPATH)

all: ft

std: CXXFLAGSADD += $(STD_FLAG)
std: $(NAME)
	@echo "${DODGERBLUE1} using namespace std${RESET}"

ft: CXXFLAGSADD += $(FT_FLAG)
ft: $(NAME)
	@echo "${ORANGERED1} using namespace ft${RESET}"


$(OPATH)/%.o: %.cpp
	$(C++) $(CXXFLAGS) $(CXXFLAGSADD) -I $(IPATH) -c $< -o $@

$(NAME): $(OBJS)
	$(C++) $(CXXFLAGS) $(CXXFLAGSADD) $(OBJS) -I $(IPATH) -o $(NAME)

$(OBJS): | $(OPATH)

$(OPATH):
	mkdir -p $(OPATH)

clean:
	$(RM) $(OPATH)

fclean:
	make clean
	$(RM) $(NAME)

re:
	make fclean
	make all

-include $(DEPS)

.PHONY: all clean fclean re
