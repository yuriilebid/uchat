NAME	=	db.a
CFLG	=	-std=c11 $(addprefix -W, all extra error pedantic) -g
SRCD	=	src
INCD	=	inc
OBJD	=	obj
INC		=	db.h
INCS	=	$(addprefix $(INCD)/, $(INC))

SRC		=	mx_add_message.c \
	mx_add_user.c \
	mx_confirm_user.c \
	mx_confirm_users_pasword.c \
	mx_create_table.c \
	mx_createdb.c \
	mx_delete_table.c \
	mx_executedb.c \
	mx_get_all_messages_of_users.c \
	mx_get_data.c \
	mx_get_users_last_message.c \
	mx_insert_data.c \
	mx_show_all_messages.c \
	mx_show_users.c \
	mx_update_data.c \

SRCS	=	$(addprefix $(SRCD)/, $(SRC))
OBJS	=	$(addprefix $(OBJD)/, $(SRC:%.c=%.o))

all: install

install: $(NAME)

$(NAME): $(OBJS)
	@ar rcs $@ $^
	@printf "\r\33[2K$@ \033[32;1mcreated\033[0m\n"

$(OBJD)/%.o: $(SRCD)/%.c $(INCS)
	@clang $(CFLG) -c $< -o $@ -I$(INCD) #-lsqlite3
	@printf "\r\33[2K$(NAME) \033[33;1mcompile \033[0m$(<:$(SRCD)/%.c=%) "

$(OBJS): | $(OBJD)

$(OBJD):
	@mkdir -p $@

clean:
	@rm -rf $(OBJD)
	@printf "$(OBJD)\t   \033[31;1mdeleted\033[0m\n"

uninstall: clean
	@rm -rf $(NAME)
	@printf "$(NAME) \033[31;1muninstalled\033[0m\n"

reinstall: uninstall install
