#!/bin/bash

# Get the directory this file is in (the project base)
basedir=$(cd $(dirname $0) && pwd)

mysql=mysql # mysql executable
username=   # mysql user
passwd=     # mysql password

# parse the command line parameters
while getopts 'm:u:p:d:' OPTION 
do case "$OPTION" in
    m)  mysql="$OPTARG"
        ;;
    u)  username="$OPTARG"
        ;;
    p)  passwd="$OPTARG"
        ;;
    ?)  printf "Reloads the MMOServerDB install\n"
        printf ""
        exit 2
        ;;
esac
done
shift $(($OPTIND - 1))

for i in $(find . ! -name . -type d -prune)
do
    if [ ! -f $i/create.sql ]; then
        continue;
    fi
    
    if [ -f $i/create_users.sql ]; then
        $mysql -u $username -p$passwd --default-character-set=utf8 <$i/create_users.sql
        printf "Installing create_users.sql [Done]\n"       
    fi
    
    $mysql -u $username -p$passwd --default-character-set=utf8 <$i/create.sql
    printf "Installing create.sql [Done]\n"
    
    for j in $(find $i/scripts -name *.sql)
    do
    $mysql -u $username -p$passwd --default-character-set=utf8 <$j
        printf "Installing $j [Done]\n"
    done
        
    for j in $(find $i/functions -name *.sql)
    do
    $mysql -u $username -p$passwd --default-character-set=utf8 <$j
        printf "Installing $j [Done]\n"
    done
    
    for j in $(find $i/procedures -name *.sql)
    do
    $mysql -u $username -p$passwd --default-character-set=utf8 <$j
        printf "Installing $j [Done]\n"
    done
done