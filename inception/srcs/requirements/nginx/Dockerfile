# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Dockerfile                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abashir <abashir@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/28 14:28:34 by abashir           #+#    #+#              #
#    Updated: 2024/03/28 14:29:27 by abashir          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Use Alpine Linux as a parent image
FROM alpine:3.19

# Install nginx
RUN apk update
RUN apk add --no-cache --update nginx openssl

# Create a directory to hold the certificate and key
RUN mkdir -p /etc/nginx/ssl

# Generate a self-signed certificate and key
RUN  openssl req -x509 -nodes -days 365 -newkey rsa:2048 \
    -keyout /etc/nginx/ssl/abashir.key -out /etc/nginx/ssl/abashir.crt \
    -subj "/C=AE/ST=Abu Dhabi/L=Abu Dhabi/O=42/CN=abashir"

# Copy the custom server definition file from your host to the container
COPY conf/default.conf /etc/nginx/http.d/default.conf

# Expose port 443
EXPOSE 443

# Start nginx
CMD ["nginx", "-g", "daemon off;"]
