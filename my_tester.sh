#!/bin/bash

#Colors
RESET='\033[0m'
DODGERBLUE1="\033[38;5;33m"
ORANGERED1="\033[38;5;202m"
SPRINGGREEN5="\033[38;5;41m"
GREENYELLOW="\033[38;5;154m"
DEEPPINK6="\033[38;5;125m"
DARKSLATEGRAY2="\033[38;5;87m"
CHARTREUSE6="\033[38;5;64m"
SLATEBLUE1="\033[38;5;99m"

# SEED = 42
read -p "Enter a SEED value: " SEED

#STEP 1 -- test with "STD namespace"
make clean && make std
echo -e "$DODGERBLUE1 Executing ./ft_containers with namespace STD$RESET"
./ft_containers $SEED > std_out

#STEP 2 -- test with "FT namespace"
make clean && make ft
echo -e "$SPRINGGREEN5 Executing ./ft_containers with namespace FT$RESET"
./ft_containers $SEED > ft_out

echo -e "$ORANGERED1 Producing diff file : DIFF_OUT $RESET"
diff std_out ft_out > DIFF_OUT
# echo "Testing with valgrind"
# valgrind -s --leak-check=full --show-leak-kinds=all --track-origins=yes ./ft_containers $SEED

# for n in {0..30}
# do
    # echo "Executing ./ft_containers with n = $n"
    # ./ft_containers $n > ft_out
# done
