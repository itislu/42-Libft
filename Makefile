# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ldulling <ldulling@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/25 12:48:32 by ldulling          #+#    #+#              #
#    Updated: 2025/03/08 06:29:54 by ldulling         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#TODO Not tracking changes to Makefile yet
# ***************************** CONFIGURATION ******************************** #

NAME			:=	libft.a

# Header files directory:
I				:=	inc/

# Build directories:
B				:=	build/
D				:=	$B_dep/
O				:=	$B_obj/

# Source files directory:
S				:=	src/

# Makefiles in build/ directory with source file listings to be included
# (files that are dependent on others need to be below their dependency):
SOURCELISTS		:=	libft.mk

# Flags:
CC				?=	cc
CFLAGS			?=	-Wall -Wextra -Werror -pedantic -g #-fsanitize=address,undefined,bounds,float-divide-by-zero
INCFLAGS		:=	$(addprefix -I,$I) # TODO `make norm` does not check the private headers
DEBUGFLAGS		:=	-g
ARFLAGS			:=	rcs


# ***************************** BUILD PROCESS ******************************** #

.DEFAULT_GOAL	:=	all

include				$(addprefix $B,$(SOURCELISTS))

OBJ				:=	$(SRC:%.c=$O%.o)
DEP				:=	$(SRC:%.c=$D%.d)
OBJ_SUBDIRS		:=	$(sort $(dir $(OBJ)))
DEP_SUBDIRS		:=	$(sort $(dir $(DEP)))

.PHONY			:	all cleandep cleanobj clean fclean re debug docs norm

all				:	$(NAME)

$(NAME)			:	$(OBJ)
					ar $(ARFLAGS) $(NAME) $(OBJ)

$(OBJ):	$O%.o	:	$S%.c | $(OBJ_SUBDIRS)
					$(CC) $(CFLAGS) $(INCFLAGS) -c $< -o $@

$(DEP):	$D%.d	:	$S%.c | $(DEP_SUBDIRS)
					$(CC) $(CFLAGS) $(INCFLAGS) -M -MP -MF $@ -MT "$O$*.o $@" $<

$(OBJ_SUBDIRS) \
$(DEP_SUBDIRS)	:
					mkdir -p $@

cleandep		:
ifneq (,$(wildcard $(DEP)))
					rm -f $(DEP)
endif
ifneq (,$(wildcard $D))
					-find $(D) -type d -empty -delete
endif

cleanobj		:
ifneq (,$(wildcard $(OBJ)))
					rm -f $(OBJ)
endif
ifneq (,$(wildcard $O))
					-find $(O) -type d -empty -delete
endif

clean			:	cleandep cleanobj

fclean			:	clean
ifneq (,$(wildcard $(NAME)))
					rm -f $(NAME)
endif

re				:	fclean all

debug			:	CFLAGS += $(DEBUGFLAGS)
debug			:	re

# Checks for documentation errors in the source code, like outdated names.
# Only supported by clang.
docs			:	CFLAGS += -Wdocumentation
docs			:	re

norm			:
	@				-norminette -R CheckForbiddenSourceHeader -R CheckDefine \
					$(addprefix $S,$(SRC)) $(foreach dir,$I,$(dir)*.h)

ifeq (,$(filter cleandep cleanobj clean fclean re debug norm,$(MAKECMDGOALS)))
    ifneq (,$(wildcard $O))
        -include	$(DEP)
    endif
endif


# *************************** MAKEFILE DEBUGGING ***************************** #

# Prints the values of the variable given after the minus.
print-%			:
	@				echo $* = $($*)
