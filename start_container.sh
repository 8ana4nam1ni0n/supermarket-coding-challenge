#!/bin/zsh
docker run -it -v $(pwd):/root/supermarket-coding-challenge -w /root/supermarket-coding-challenge cpp-container-w-valgrind .
