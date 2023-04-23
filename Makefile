##
## EPITECH PROJECT, 2023
## Public_Library
## File description:
## Template Makefile for a library
##

Y				=	\033[1;33m
B				=	\033[1;34m
G				=	\033[1;32m
R				=	\033[1;31m
RST				=	\033[0m

SRCS			=	char_anum.c								\
					char_print.c							\
					foo_to_sort.c							\
					talloc.c								\
					len.c									\
					schange.c								\
					scopy.c									\
					slen.c									\
					smake.c									\
					ssearch.c								\
					read.c									\
					sgf.c									\
					sgf_type.c								\
					fpf.c									\
					sp.c									\
					spf.c									\
					pretty_log.c							\
					color_plus.c							\
					gline.c									\
					loop.c									\
					char_xl.c

CFLAGS			=	-W -Wall -Wextra -Wpedantic -Iinclude

LNAME			=	libmy.a

TSRCS			:=	$(addprefix tests/, $(SRCS:.c=_tests.c))

SRCS			:=	$(addprefix src/, $(SRCS))

TOBJS			=	$(TSRCS:.c=.o)

OBJS			=	$(SRCS:.c=.o)

$(LNAME):	$(OBJS)
	@ar rcs $@ $(OBJS)
	@echo -e "\n$(G)$(LNAME) $(Y)[$(G)✓$(Y)]$(RST)"

all:		$(LNAME)

%.o:		%.c
	@gcc -o $@ -c $< $(CFLAGS)
	@echo -en "$(Y)$@ [$(G)✓$(Y)]$(RST) "

clean:
	@rm -f $(OBJS) $(TOBJS) src/demo.o vgcore.* coding-style-reports.log
	@rm -f src/*.gcda src/*.gcno src/*.gcov src/vgcore.*
	@rm -f tests/*.gcda tests/*.gcno tests/*.gcov tests/vgcore.*
	@echo -e "$(Y)Temp Files [$(R)✗$(Y)]$(RST)"

fclean:		clean
	@rm -f $(LNAME) unit_tests valdebug vsdebug demo a.out
	@echo -e "$(R)$(LNAME) $(Y)[$(R)✗$(Y)]$(RST)"

re:			fclean all

unit_tests:	CFLAGS += -lcriterion -lgcov --coverage
unit_tests:	clean $(TOBJS) $(OBJS)
	@gcc -o $@ $(TOBJS) $(OBJS) $(CFLAGS)
	@echo -e "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)"

tests_run:	unit_tests
	@./$< -j1 --verbose

vsdebug:	CFLAGS += -g
vsdebug:	clean $(OBJS) src/demo.o
	@gcc -o $@ $(OBJS) src/demo.o $(CFLAGS)
	@echo -e "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)"

valdebug:	CFLAGS += -g3
valdebug:	clean $(OBJS) src/demo.o
	@gcc -o $@ $(OBJS) src/demo.o $(CFLAGS)
	@echo -e "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)"

val_run:	valdebug
	@valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$<

demo:		clean $(OBJS) src/demo.o
	@gcc -o $@ $(OBJS) src/demo.o $(CFLAGS)
	@echo -e "\n$(G)$@ $(Y)[$(G)✓$(Y)]$(RST)"

run_demo:	demo
	@./$<

covr:		tests_run
	@gcovr --exclude tests/
	@gcovr --exclude tests/ --branches

.PHONY: all clean fclean re tests_run
