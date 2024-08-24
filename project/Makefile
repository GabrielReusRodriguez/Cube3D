# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gabriel <gabriel@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/01 19:39:15 by gabriel           #+#    #+#              #
#    Updated: 2024/08/24 20:21:33 by gabriel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
# Colours
################################################################################

RST				= \033[0;39m
GRAY			= \033[0;90m
RED				= \033[0;91m
GREEN			= \033[0;92m
YELLOW			= \033[0;93m
BLUE			= \033[0;94m
MAGENTA			= \033[0;95m
CYAN			= \033[0;96m
WHITE			= \033[0;97m

################################################################################
#Folders
################################################################################

SRC_DIR			=	./src
INC_DIR			=	./include
BUILD_DIR		=	./build
LIBFT_DIR		=	./libft
MINILIBX_DIR	=	./mlx
GNL_DIR			=	./gnl

################################################################################
# Compiler stuff
################################################################################

CC				=	cc
CFLAGS			=	-Wall -Werror -Wextra
ifdef	CSANITIZE
	SANITIZE_FLAGS	= -g -O3 -fsanitize=address -fsanitize=leak
endif
DEBUG_FLAG		=	-D DEBUG_FLAG=0
DEP_FLAGS		=	-MMD -MP
CFLAGS			+=	${DEP_FLAGS}
#LIBS			=	-lm -lft -lgnl -lmlx_Linux
LIBS			=	-lm -lgnl -lft -lmlx_Linux
LIBS_FOLDERS	=	-L${LIBFT_DIR} -L${MINILIBX_DIR} -L${GNL_DIR}

################################################################################
# Name of exec
################################################################################

NAME	=	cube3d

################################################################################
# Files
################################################################################

SRC				=	main								\
					camera								\
					engine/engine						\
					engine/engine2						\
					engine/engine_render				\
					engine/engine_textures				\
					events/handler_key_events			\
					events/handler_destroy_event		\
					error								\
					geometry/point						\
					geometry/radiants					\
					geometry/vector_arithmetic			\
					geometry/vector						\
					map/map								\
					map/map_loader						\
					map/map_parser						\
					map/tile							\
					screen								

HEADERS			=	camera.h		\
					cub3d.h			\
					engine.h		\
					error.h			\
					events.h		\
					map.h			\
					player.h		\
					point.h			\
					screen.h		\
					texture.h		\
					tile.h			\
					types.h			\
					vector.h

SRCS			=	$(addprefix ${SRC_DIR}/, $(addsuffix .c, ${SRC}))
OBJS			=	$(addprefix ${BUILD_DIR}/, $(addsuffix .o, ${SRC}))
HDRS			=	$(addprefix ${INC_DIR}/, ${HEADERS})
DEPS			=	$(addprefix ${BUILD_DIR}/, $(addsuffix .d, ${SRC}))

################################################################################
# Rules 
################################################################################


#When we call all, we call the rule compile
#This rule calls the libs makefiles and finally we call the make name
#The rule  ${NAME} has as dependency the .a lib and compares the date of 
# the timestamp of ${NAME} with the timestamp of the .a .o and Makefile files to link or not.


all				:	${BUILD_DIR} compile

${NAME}			:	${OBJS} ${LIBFT_DIR}/libft.a ${GNL_DIR}/libgnl.a ${MINILIBX_DIR}/libmlx_Linux.a Makefile
	@echo "${CYAN}Linking all together${RST}"
	${CC} ${CFLAGS} ${SANITIZE_FLAGS} -o ${NAME} ${OBJS} -L/usr/lib -L/usr/local/lib ${LIBS_FOLDERS} ${LIBS} -lXext -lX11 -lz  
	@echo "$(GREEN)Binary $(NAME) compiled! $(RST)"

compile:
	@echo "${CYAN}Making libft...${RST}"
	@make --no-print-directory -C ${LIBFT_DIR}
	@echo "${CYAN}Making get_next_line...${RST}"
	@make --no-print-directory -C ${GNL_DIR}
	@echo "${CYAN}Making minilibx...${RST}"
	@make --no-print-directory -C ${MINILIBX_DIR}
	@echo "${CYAN}Making ${NAME}...${RST}"
	@make --no-print-directory ${NAME}

${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}
	mkdir -p ${BUILD_DIR}/engine
	mkdir -p ${BUILD_DIR}/events
	mkdir -p ${BUILD_DIR}/geometry
	mkdir -p ${BUILD_DIR}/map

${BUILD_DIR}/%.o	:	${SRC_DIR}/%.c Makefile
	@echo "\t${YELLOW}Compiling ${NAME} ->${RST} $<"
#	@mkdir -p ${BUILD_DIR}
	@${CC} ${CFLAGS} -I${INC_DIR} -I${MINILIBX_DIR} -I${LIBFT_DIR}/include -I${GNL_DIR}/include ${DEBUG_FLAG} -c $< -o $@ 

clean			:
	@make --no-print-directory clean -C ${LIBFT_DIR}
	@make --no-print-directory clean -C ${GNL_DIR}
	@make --no-print-directory clean -C ${MINILIBX_DIR}
	@echo "${RED}Cleaning build folder${RST}"
	@rm -rf ${BUILD_DIR}

fclean			:	clean
	@make --no-print-directory fclean -C ${LIBFT_DIR}
	@make --no-print-directory fclean -C ${GNL_DIR}
#	@make --no-print-directory fclean -C ${MINILIBX_DIR}
	@echo "${RED}Cleaning ${NAME}${RST}"
	@rm -f ${NAME}

re				:	fclean all

norm:	
#	$(shell norminette)
	@norminette ${HDRS}
	@norminette ${SRCS}
	
-include ${DEPS}

################################################################################
# Phony
################################################################################

.PHONY	:	all clean fclean re norm