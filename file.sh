ls -lt --time=creation | awk '{print NR, $6, $7, $8, $9}'
