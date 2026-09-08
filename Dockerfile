FROM ubuntu:latest AS build

#Installs make and c++ compiler
RUN apt-get update && apt-get install -y build-essential valgrind

WORKDIR /app

#copy all the files
COPY . .

RUN make debug

CMD ["./taskforge"]