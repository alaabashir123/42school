# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 13:40:19 by abashir           #+#    #+#              #
#    Updated: 2024/03/28 13:56:25 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Build containers using docker-compose and run them in detached mode
all:
	@docker compose -f ./srcs/docker-compose.yml up -d --build

# Stop and remove containers, networks, volumes, and images created by 'make all'
down:
	@docker compose -f ./srcs/docker-compose.yml down

# Rebuild and restart containers
re: clean
	@docker compose -f ./srcs/docker-compose.yml up -d --build

# Stop and remove all containers, networks, volumes, and images
clean:
	@if docker ps -qa | grep -q .; then \
		docker stop $$(docker ps -qa); \
		docker rm $$(docker ps -qa); \
	fi
	@if docker volume ls -q | grep -q .; then \
		docker volume rm $$(docker volume ls -q); \
	fi
	@if docker images -qa | grep -q .; then \
		docker rmi -f $$(docker images -qa); \
	fi
	@if docker network ls --format '{{.Name}}' | grep -v 'bridge\|host\|none' | grep -q .; then \
		docker network rm $$(docker network ls --format '{{.Name}}' | grep -v 'bridge\|host\|none'); \
	fi

.PHONY: all re down clean
