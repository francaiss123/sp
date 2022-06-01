FROM ubuntu
RUN apt-get update && apt-get install -y g++
COPY lab3.cpp .
RUN g++ lab3.cpp -static
CMD ./a.out
