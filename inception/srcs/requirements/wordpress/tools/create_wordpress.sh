# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    create_wordpress.sh                                :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 15:10:24 by abashir           #+#    #+#              #
#    Updated: 2024/03/28 16:00:11 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/sh

# Check if wp-config.php exist
if [ -f ./wp-config.php ]
then
	echo "wordpress already downloaded"
else
	# Download wordpress and all config file
	wget http://wordpress.org/latest.tar.gz
	tar xfz latest.tar.gz
	mv wordpress/* .
	rm -rf latest.tar.gz
	rm -rf wordpress

	# Import env variables in the config file
	sed -i "s/username_here/$MYSQL_USER/g" wp-config-sample.php
	sed -i "s/password_here/$MYSQL_PASSWORD/g" wp-config-sample.php
	sed -i "s/localhost/$MYSQL_HOSTNAME/g" wp-config-sample.php
	sed -i "s/database_name_here/$MYSQL_DATABASE/g" wp-config-sample.php
	cp wp-config-sample.php wp-config.php

	# WordPress Installation
    wp core install --url="https://localhost/" --title="Hello World" --admin_user="${MYSQL_USER}" --admin_password="${MYSQL_PASSWORD}" --admin_email="${WP_EMAIL}" --path=/var/www/html/ --allow-root
	wp user create --allow-root ${WP_USER_LOGIN} ${WP_USER_EMAIL} --user_pass=${WP_USER_PASSWORD}

	# Check if WordPress installed successfully
    if [ $? -eq 0 ]; then
        echo "WordPress installed successfully."
    else
        echo "Error installing WordPress."
        exit 1
    fi
fi

chown -R  www-data:www-data /var/www/html/
chmod -R 755 /var/www/html/
exec "$@"
