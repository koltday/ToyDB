#!/bin/bash

echo Thank you for trying ToyDB.

if [[ -z $TOYDB_FIRST_RUN ]] 
then
  echo "You have not run this before."
else 
  echo "You ran this program at $TOYDB_FIRST_RUN."
  echo "Continuing to run this program with an active database is dangerous."
  echo "If you wish to change defaults, use the \"global\" command to access the config menu."
fi

echo "Answer the following questions to set up your environment."
read -p "Press enter to continue. "
echo "Port number? (default: 10926)"
read port
echo "Is $port ok?"
