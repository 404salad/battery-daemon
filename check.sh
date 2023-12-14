#!/bin/bash
bat=$(acpi | grep -oE "[0-9]{1,}"%)
bat=${bat%?} #strip the last char which is % 
echo $bat

#   if [ $bat -le 20 ]; then
#       echo "battery low"
#   else
#       echo "sufficient battery"
#   fi
