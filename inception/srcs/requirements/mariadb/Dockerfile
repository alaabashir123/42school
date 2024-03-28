# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 14:09:59 by abashir           #+#    #+#              #
#    Updated: 2024/03/28 14:12:51 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19

RUN apk add --no-cache mariadb mariadb-client mariadb-server-utils && \
    rm -f /var/cache/apk/*

ADD tools/setup.sh /
RUN chmod +x /setup.sh

EXPOSE 3306

ENTRYPOINT ["/setup.sh"]
