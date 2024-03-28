#!/bin/sh

# Create MySQL data directory for MariaDB runtime data and db
mkdir -p /run/mysqld && mkdir -p /var/lib/mysql


# Change the ownership of the MySQL data directory to the MySQL server
chown -R mysql:mysql /run/mysqld /var/lib/mysql

# Set up the initial data structure and tables required for MySQL
if [ ! -d /var/lib/mysql/mysql ]; then
    if mysql_install_db --user=mysql --ldata=/var/lib/mysql > /dev/null; then
		echo "[i] MySQL database successfully installed."
	else
		exit 1
    fi
fi

# MYSQL Configuration file
cat << EOF > tmpfile
FLUSH PRIVILEGES;
ALTER USER 'root'@'localhost' IDENTIFIED BY '$MYSQL_ROOT_PASSWORD';
CREATE DATABASE IF NOT EXISTS \`$MYSQL_DATABASE\`;
CREATE USER IF NOT EXISTS '$MYSQL_USER'@'%' IDENTIFIED BY '$MYSQL_PASSWORD';
GRANT ALL PRIVILEGES ON \`$MYSQL_DATABASE\`.* TO '$MYSQL_USER'@'%';
FLUSH PRIVILEGES;
EOF

# Set up initial configuration for MySQL
/usr/bin/mysqld --user=mysql --bootstrap --skip-name-resolve --skip-networking=0 < tmpfile

rm -f tmpfile

exec /usr/bin/mysqld --user=mysql --skip-name-resolve --skip-networking=0 $@