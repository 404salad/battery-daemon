#!/bin/bash
bat=$(acpi | grep -oE "[0-9]{1,}"%)
bat=${bat%?} #strip the last char which is % 
echo $bat
