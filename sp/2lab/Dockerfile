FROM ubuntu
RUN apt-get update
RUN apt install gcc gdb gcc-multilib nano -y
COPY lab2.s .
Copy lab2.c .
RUN gcc -m32 lab2.s -o lab2_as
RUN gcc lab2.c -o lab2_c
CMD ./lab2_as && ./lab2_c



