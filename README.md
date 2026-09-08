# Docker Commands

DOCKER_BUILDKIT=0 docker build -t taskforge .
docker run -it --cap-add=SYS_PTRACE --security-opt seccomp=unconfined taskforge

# to run in WSL:
go to docker desktop
open settings
general tab
select Use WSL 2 based engine
hit apply

Also go under resources
WSL intergration
toggle on your linux distro

lastly run these commands in wsl:
sudo service docker start
docker ps

the docker ps should show a list of your containers

# Makefile commands:
make - basic build functionality
make valgrind - adds valgrind memory testing to build
make debug - add gdb debugger to build
make clean - removes executable and linker files