# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 14:50:28 by abashir           #+#    #+#              #
#    Updated: 2024/03/28 15:07:47 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

FROM alpine:3.19

RUN apk update 

RUN apk add php83 php83-cli php83-fpm php83-mysqli \
    php83-json php83-openssl php83-curl php83-zlib \
    php83-xml php83-phar php83-intl php83-dom curl \
    wget tar openrc vim php83-cgi php83-mbstring \
    && ln -s /usr/bin/php83 /usr/bin/php

# Directory for PHP-FPM to store the pid file
RUN mkdir -p /run/php

# Copy the .conf to the right directory
COPY ./conf/www.conf /etc/php83/php-fpm.d

# Copy the script, give the right to launch
COPY ./tools/create_wordpress.sh /usr/local/bin/
RUN chmod +x /usr/local/bin/create_wordpress.sh
ENTRYPOINT ["/usr/local/bin/create_wordpress.sh"]

# User used by web servers and PHP-FPM processes to execute PHP scripts securely
RUN adduser -S www-data -G www-data

# Install wp_cli and put it in the right directory
RUN curl -O https://raw.githubusercontent.com/wp-cli/builds/gh-pages/phar/wp-cli.phar \
    && chmod +x wp-cli.phar \
    && mv wp-cli.phar /usr/local/bin/wp \
    && chown www-data:www-data /usr/local/bin/wp

# Set the working directory
WORKDIR /var/www/html/

# Expose the port 9000
EXPOSE 9000

# Launch PHP FPM in foreground and ignore deamonize from conf file (-F)
CMD ["/usr/sbin/php-fpm83", "-F"]
