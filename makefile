NAME = minitalk
BNS = minitalk 

SRC_sv = server.c
SRC_cl = client.c
SRC_svb = server_bonus.c
SRC_clb = client_bonus.c 

OBJ_sv = ${SRC_sv:.c=.o} 
OBJ_cl = ${SRC_cl:.c=.o}
OBJ_svb = ${SRC_svb : .c=.o}
OBJ_clb = ${SRC_clb : .c = .o}

all : ${NAME}
FLAGS: -Wall -Wextra -Werror 

bonus : server_bonus client_bonus

${NAME} : server client  
${BNS_S} : server_bonus 
${BNS_c} : client_bonus


%.o:%.c
	cc -Wall -Wextra -Werror  -c $<

server: ${OBJ_sv}
	CC ${FLAGS} ${OBJ_sv} -o server 
client: ${OBJ_cl}
	CC ${FLAGS} ${OBJ_cl} -o client
BNS_S : ${OBJ_svb}
	CC ${FLAGS} ${OBJ_svb} server_bonus.c -o server_bonus
BNS_c : ${OBJ_clb} 
	CC ${FLAGS} ${OBJ_clb} client_bonus.c -o client_bonus
clean : 
	rm -f ${OBJ_cl} ${OBJ_clb} ${OBJ_sv} ${OBJ_svb}
	
fclean : clean
	rm -rf server server_bonus client client_bonus

re : fclean all bonus