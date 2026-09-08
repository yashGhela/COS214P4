FROM ubuntu:latest AS build

#Installs make and c++ compiler
RUN apt-get update && apt-get install -y build-essential valgrind gdb

WORKDIR /app

#copy all the files
COPY . .

RUN make 

CMD ["make","debug"]