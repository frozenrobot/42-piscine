#!/bin/sh
cat /etc/passwd | grep -v "#" | sed -n 'n;p' | cut -d ':' -f1 | rev | sort -r | head -n $FT_LINE2 | tail -n +$FT_LINE1 | sed 's/$/, /' | tr -d '\n' | sed 's/, $/\./'