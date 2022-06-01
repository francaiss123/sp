#! /bin/bash

echo "Developer: Kalinovskiy Denis"
echo "Name of programm: Catalogs, users and files"
echo "Description: shows what files the owner has" 

echo "The current directory is:"; pwd
while true; do
echo "/Enter username:/"
read username
if grep $username /etc/passwd
then
 echo "user succesfully found"
 while true; do
 echo "/Enter name of catalogs:/"
 read namecat
 if find $namecat | wc
 then
  echo "$username owns the following number of files:"
  find $namecat -type f -user $username | wc -l
  echo "do you wanna continue? (y/n)"
  read yes
  if [ $yes = y ]
   then continue
   else break
   fi
  else echo "directory not douns, try again? (y/n)"
   read answ
   if [ $answ = y ]
    then continue
    else break
    fi
   fi
  done
else
 echo "user not found! do you wanna try again? (y/n)"
 read answer
 if [ $answer = y ]
 then continue
 else break
 fi
fi
done

